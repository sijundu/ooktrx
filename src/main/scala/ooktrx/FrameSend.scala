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


class FrameSend (val frameWidth: Int
                ) extends Module {

  require(frameWidth > 15, s"Frame Width must be > 15, got $frameWidth")

  val io = IO(new Bundle{
    val frameIn = Input(UInt(frameWidth.W))
    val frameInValid = Input(Bool())
    val sendEn = Input(Bool())
    val out = Output(Bool())
    val requestFrame = Output(Bool())
  })

  val out = RegInit(Bool(), false.B)
  io.out := out

  val requestFrame = RegInit(Bool(), false.B)
  io.requestFrame := requestFrame

  val frameBuffer = RegInit(0.U(frameWidth.W))

  val counter = RegInit(0.U(log2Ceil(frameWidth+1).toInt.W))

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

}
