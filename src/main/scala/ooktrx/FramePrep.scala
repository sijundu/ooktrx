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


class FramePrep (val frameWidth: Int,
                 val frameBitsWidth: Int,
                 val frameIndexWidth: Int
                ) extends Module {

  require(frameBitsWidth > 2, s"Frame Bits Width must be > 2, got $frameBitsWidth")
  require(frameWidth > 15, s"Frame Width must be > 15, got $frameWidth")

  val io = IO(new Bundle{
    val dataIn = Input(UInt((frameWidth-frameBitsWidth-frameIndexWidth).W))
    val dataInValid = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    val frameIndex = Input(UInt(frameIndexWidth.W))
    val requestIn = Input(Bool())
    val frameOut = Output(UInt(frameWidth.W))
    val dataOutValid = Output(Bool())
    val requestOut = Output(Bool())
  })

  io.frameOut := Cat(io.frameBits, io.frameIndex, io.dataIn)
  io.dataOutValid := io.dataInValid
  io.requestOut := io.requestIn

}
