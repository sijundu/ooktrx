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


class FrameStackRx//[T <: Data]
                   (//val gen: T,
                    val frameWidth: Int,
                    val StackSize: Int
                   ) extends Module {

  require(frameWidth > 15, s"Frame Width must be > 15, got $frameWidth")

  val io = IO(new Bundle{
    val in = Input(UInt(frameWidth.W))
    val frameValidIn = Input(Bool())
    val requestIn = Input(Bool())
    val out = Output(UInt(frameWidth.W))
    val frameValidOut = Output(Bool())
    val requestOut = Output(Bool())
  })

  val frameOut = RegInit(0.U(frameWidth.W))
  io.out := frameOut

  val frameValidOut = RegInit(Bool(), false.B)
  io.frameValidOut := frameValidOut

  val readMemIndex = RegInit(0.U(log2Ceil(StackSize).toInt.W))
  val writeMemIndex = RegInit(0.U(log2Ceil(StackSize).toInt.W))

  val stack = Mem(StackSize, UInt(frameWidth.W))

  val stackUsed = RegInit(0.U(log2Ceil(StackSize+1).toInt.W))

  io.requestOut := !(stackUsed === StackSize.asUInt)

  when(io.requestOut && io.frameValidIn){
    //stack(writeMemIndex) := io.in
    stack.write(writeMemIndex, io.in)
    stackUsed := stackUsed + 1.U
    frameValidOut := false.B
    writeMemIndex := Mux(writeMemIndex === (StackSize-1).asUInt, 0.U, writeMemIndex + 1.U)
  }.elsewhen(io.requestIn && stackUsed > 0.U){
    //frameOut := stack(readMemIndex)
    frameOut := stack.read(readMemIndex)
    stackUsed := stackUsed - 1.U
    frameValidOut := true.B
    readMemIndex := Mux(readMemIndex === (StackSize-1).asUInt, 0.U, readMemIndex + 1.U)
  }.otherwise{
    frameValidOut := false.B
  }


}

