// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// Frame example 32-bit in total
//   0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0
//  |       A        |    B   |                  C                 |    D  |
//
//  A+B+C+D @frameWidth = 32
//  A       @frameBitsWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary

class FrameSendIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt(p.frameWidth.W)))
  val out = Output(Bool())
}

class FrameSend[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new FrameSendIO(gen, p))

  val out = RegInit(Bool(), false.B)
  io.out := out

  val requestFrame = RegInit(Bool(), false.B)
  io.in.ready := requestFrame

  val frameBuffer = RegInit(0.U(p.frameWidth.W))

  val counter = RegInit(0.U(log2Ceil(p.frameWidth+1).toInt.W))

  val sIdle :: sSend :: Nil = Enum(2)
  val state = Reg(init = sIdle)

  switch(state){
    is(sIdle){
      requestFrame := true.B
      out := false.B
      counter := 0.U
      when(requestFrame && io.in.valid){
        frameBuffer := io.in.bits
        requestFrame := false.B
        counter := 0.U
        state := sSend
      }
    }
    is(sSend){
      when(counter < p.frameWidth.asUInt){
        out := frameBuffer(p.frameWidth.asUInt - counter - 1.U)
        counter := counter + 1.U
        when(counter === (p.frameWidth-1).asUInt){
          requestFrame := true.B
          state := sIdle
        }
      }
    }
  }

  /*
  when(io.sendEn){
    when(requestFrame && io.frameInValid){
      frameBuffer := Reverse(io.frameIn)
      requestFrame := false.B
      counter := 0.U
    }.elsewhen(counter < frameWidth.asUInt){
      out := frameBuffer(counter)
      counter := counter + 1.U
      when(counter === (frameWidth-1).asUInt){
        requestFrame := true.B
      }
    }otherwise{
      out := false.B
    }
  }.otherwise{
    out := false.B
    requestFrame := false.B
    counter := 0.U
    frameBuffer := io.frameIn
  }
  */

}
