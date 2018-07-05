// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import chisel3.core.requireIsChiselType

class FrameStackRx[T <: Data]
                   (val gen: T,
                    val frameWidth: Int,
                    val StackSize: Int
                   ) extends Module {

  require(frameWidth > 15, s"Frame Width must be > 15, got $frameWidth")

  val io = IO(new Bundle{
    val in = Input(Valid(gen.cloneType))
    //val frameValidIn = Input(Bool())
    val requestIn = Input(Bool())
    val out = Output(Valid(gen.cloneType))
    //val frameValidOut = Output(Bool())
    val requestOut = Output(Bool())
  })

  val frameOut = RegInit(0.U(frameWidth.W))
  io.out.bits := frameOut

  val frameValidOut = RegInit(Bool(), false.B)
  io.out.valid := frameValidOut

  val readMemIndex = RegInit(0.U(log2Ceil(StackSize).toInt.W))
  val writeMemIndex = RegInit(0.U(log2Ceil(StackSize).toInt.W))

  val stack = Mem(StackSize, gen)

  val stackUsed = RegInit(0.U(log2Ceil(StackSize+1).toInt.W))

  io.requestOut := !(stackUsed === StackSize.asUInt)

  when(io.requestOut && io.in.valid){
    stack(writeMemIndex) := io.in.bits
    stackUsed := stackUsed + 1.U
    frameValidOut := false.B
    writeMemIndex := Mux(writeMemIndex === (StackSize-1).asUInt, 0.U, writeMemIndex + 1.U)
  }.elsewhen(io.requestIn && stackUsed > 0.U){
    frameOut := stack(readMemIndex)
    stackUsed := stackUsed - 1.U
    frameValidOut := true.B
    readMemIndex := Mux(readMemIndex === (StackSize-1).asUInt, 0.U, readMemIndex + 1.U)
  }.otherwise{
    frameValidOut := false.B
  }


}

