// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._


/*
case class FrameSyncParams (
  frameBitsWidth: Int
) {
  require(frameBitsWidth > 0, s"Frame Bits Width must be > 2, got $frameBitsWidth")
}
*/


class FrameSync (val frameBitsWidth: Int) extends Module {

  require(frameBitsWidth > 0, s"Frame Bits Width must be > 2, got $frameBitsWidth")

  val io = IO(new Bundle{
    val in = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    val syncOk = Output(Bool())
  })

  val fifoReg = RegInit(0.U(frameBitsWidth.W))

  fifoReg := (fifoReg << 1) | io.in

  when (fifoReg === io.frameBits){
    io.syncOk := true.B
  }.otherwise {
    io.syncOk := false.B
  }
}
