// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import scala.math._

// Frame example 32-bit in total
//   0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0
//  |       A        |    B   |                  C                 |    D  |
//
//  A+B+C+D @frameWidth = 32
//  A       @PreambleWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary


class FrameSyncIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Input(Bool())
  val preamble = Input(UInt(p.preambleWidth.W))
  val out = Decoupled(UInt(p.frameWidth.W))
  val crcPass = Output(Bool())
  val crcFail = Output(Bool())
}

class FrameSync[T <: Data](gen:T, p: OOKTRXparams) extends Module{
  val io = IO(new FrameSyncIO(gen, p))

  // FSM definition
  val sIdle :: sReceive :: sValid :: sCrcFail :: sCrcPass :: sResend :: Nil = Enum(6)
  val state = Reg(init = sIdle)

  io.out.valid := Mux(state === sValid, true.B, false.B)

  val wholeFrame = RegInit(0.U(p.frameWidth.W))
  io.out.bits := wholeFrame

  val bitCounter = RegInit(0.U(log2Ceil(p.frameWidth).toInt.W))

  val preambleReg = RegInit(0.U(p.preambleWidth.W))

  val syncOk = Wire(Bool())
  syncOk := (preambleReg === io.preamble)
  
  io.crcPass := Mux(state === sCrcPass, true.B, false.B)
  io.crcFail := Mux(state === sCrcFail, true.B, false.B)

  val resendFrame = Cat(io.preamble, p.resendFrame)
  val nextFrame = Cat(io.preamble, p.nextFrame)

  ////////////////////// FSM Implementation ///////////////////////
  switch(state){
    is(sIdle){
      when(!syncOk){
        preambleReg := (preambleReg  << 1) | io.in
        bitCounter := 0.U
      }.otherwise{
        bitCounter := bitCounter + 1.U
        wholeFrame := (io.preamble << 1) | io.in
        state := sReceive
      }
    }
    is(sReceive){
      when(bitCounter < (p.frameWidth-p.preambleWidth).asUInt){
        bitCounter := bitCounter + 1.U
        wholeFrame := (wholeFrame << 1) | io.in
      }.elsewhen(bitCounter >= (p.frameWidth-p.preambleWidth-1).asUInt){
        bitCounter := bitCounter + 1.U
        preambleReg := 0.U
        when(wholeFrame === nextFrame){
          state := sCrcPass
        }.elsewhen(wholeFrame === resendFrame){
          state := sCrcFail
        }.elsewhen(bitCounter > (p.frameWidth-p.preambleWidth).asUInt){
          state := sValid
        }
      }
    }
    is(sValid){
      when(io.out.ready){
        bitCounter := 0.U
        wholeFrame := 0.U
        state := sIdle
      }
    }
    is(sCrcFail){
      bitCounter := 0.U
      wholeFrame := 0.U
      state := sIdle
    }
    is(sCrcPass){
      bitCounter := 0.U
      wholeFrame := 0.U
      state := sIdle
    }
  }

  /*
  when(io.out.ready){
    when(!syncOk){
      preambleReg := (preambleReg  << 1) | io.in
      bitCounter := 0.U
    }.elsewhen(bitCounter === 0.U){
      bitCounter := bitCounter + 1.U
      wholeFrame := (io.preamble << 1) | io.in
    //}.elsewhen(bitCounter < (p.frameWidth-preambleWidth-frameIndexWidth).asUInt){
    }.elsewhen(bitCounter < (p.frameWidth-p.preambleWidth).asUInt){
      bitCounter := bitCounter + 1.U
      wholeFrame := (wholeFrame << 1) | io.in
      when(bitCounter === (p.frameWidth-p.preambleWidth-1).asUInt){
        when(wholeFrame === p.crcPass){

        }
        outValid := true.B
        preambleReg := 0.U
      }
    }
  }.otherwise{
    bitCounter := 0.U
    wholeFrame := 0.U
    outValid := 0.U
  }

  when(outValid && io.out.ready){
    bitCounter := 0.U
    wholeFrame := 0.U
    outValid := false.B
  }
   */ 
}
