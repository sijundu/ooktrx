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


class OOKRx (val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
             val stackSize: Int
            ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")

  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  val io = IO(new Bundle{
    val in = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    val divisor = Input(UInt(divisorWidth.W))
    val dataOut = Output(UInt(dataWidth.W))
    val dataOutReady = Output(Bool())
    val dataOutIndex = Output(UInt(frameIndexWidth.W))
    val crcPass = Output(Bool())
  })

  /*
  // Define output registers
  val dataOut = RegInit(0.U(dataWidth.W))
  io.dataOut := dataOut
  val dataOutReady = RegInit(Bool(), false.B)
  io.dataOutReady := dataOutReady
  val dataOutIndex = RegInit(0.U(frameIndexWidth.W))
  io.dataOutIndex := dataOutIndex
  val crcPass = RegInit(Bool(), false.B)
  io.crcPass := crcPass
  */

  val frameSync = Module(new FrameSync(frameBitsWidth, frameWidth))
  val frameStackRx = Module(new FrameStackRx(frameWidth, stackSize))
  val crcCheck = Module(new CRCCheck(frameWidth, frameIndexWidth, dataWidth, divisorWidth))

  // IOs of OOKRx
  frameSync.io.in := io.in
  frameSync.io.frameBits := io.frameBits
  crcCheck.io.divisor := io.divisor
  io.dataOut := crcCheck.io.dataOut
  io.dataOutReady := crcCheck.io.dataOutReady
  io.dataOutIndex := crcCheck.io.dataOutIndex
  io.crcPass := crcCheck.io.crcPass

  // Interfaces between FrameSync and FrameStackRx
  frameSync.io.requestFrame := frameStackRx.io.requestOut
  frameStackRx.io.in := frameSync.io.frameOut
  frameStackRx.io.frameValidIn := frameSync.io.frameReady

  // Interfaces between FrameStackRx and CRCCheck
  frameStackRx.io.requestIn := crcCheck.io.requestFrame
  crcCheck.io.frameIn := frameStackRx.io.out
  crcCheck.io.frameValid := frameStackRx.io.frameValidOut
  

}

