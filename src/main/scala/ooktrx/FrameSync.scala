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
//  A       @frameBitsWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary


class FrameSyncIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Input(Bool())
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val out = Decoupled(UInt(p.frameWidth.W))
}

class FrameSync[T <: Data](gen:T, p: OOKTRXparams) extends Module{
  val io = IO(new FrameSyncIO(gen, p))


  val outValid = RegInit(Bool(), false.B)
  io.out.valid := outValid

  val wholeFrame = RegInit(0.U(p.frameWidth.W))
  io.out.bits := wholeFrame

  val bitCounter = RegInit(0.U(log2Ceil(p.frameWidth).toInt.W))

  val frameBitsReg = RegInit(0.U(p.frameBitsWidth.W))

  val syncOk = Wire(Bool())
  syncOk := (frameBitsReg === io.frameBits)

  when(io.out.ready){
    when(!syncOk){
      frameBitsReg := (frameBitsReg  << 1) | io.in
      bitCounter := 0.U
    }.elsewhen(bitCounter === 0.U){
      bitCounter := bitCounter + 1.U
      wholeFrame := (io.frameBits << 1) | io.in
    //}.elsewhen(bitCounter < (p.frameWidth-frameBitsWidth-frameIndexWidth).asUInt){
    }.elsewhen(bitCounter < (p.frameWidth-p.frameBitsWidth).asUInt){
      bitCounter := bitCounter + 1.U
      wholeFrame := (wholeFrame << 1) | io.in
      when(bitCounter === (p.frameWidth-p.frameBitsWidth-1).asUInt){
        outValid := true.B
        frameBitsReg := 0.U
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
    


}
