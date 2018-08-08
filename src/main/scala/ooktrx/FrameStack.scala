// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import chisel3.core.requireIsChiselType

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

class FrameStackIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt(p.frameWidth.W)))
  val out = Decoupled(UInt(p.frameWidth.W))
}

class FrameStack[T <: Data](gen: T, p: OOKTRXparams, stackSize: Int) extends Module {

  val io = IO(new FrameStackIO(gen, p))

  val frameOut = RegInit(0.U(p.frameWidth.W))
  io.out.bits := frameOut
  val frameValidOut = RegInit(Bool(), false.B)
  io.out.valid := frameValidOut

  val readMemIndex = RegInit(0.U(log2Ceil(stackSize).toInt.W))
  val writeMemIndex = RegInit(0.U(log2Ceil(stackSize).toInt.W))

  val stack = Mem(stackSize, UInt(p.frameWidth.W))

  val stackUsed = RegInit(0.U(log2Ceil(stackSize+1).toInt.W))

  io.in.ready := !(stackUsed === stackSize.asUInt)

  when(io.in.ready && io.in.valid){
    stack.write(writeMemIndex, io.in.bits)
    stackUsed := stackUsed + 1.U
    frameValidOut := false.B
    writeMemIndex := Mux(writeMemIndex === (stackSize-1).asUInt, 0.U, writeMemIndex + 1.U)
  }.elsewhen(io.out.ready && !frameValidOut && stackUsed > 0.U){
    frameOut := stack.read(readMemIndex)
    stackUsed := stackUsed - 1.U
    frameValidOut := true.B
    readMemIndex := Mux(readMemIndex === (stackSize-1).asUInt, 0.U, readMemIndex + 1.U)
  }.otherwise{
    frameValidOut := false.B
  }


}
