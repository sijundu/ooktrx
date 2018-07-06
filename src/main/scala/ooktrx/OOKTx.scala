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


class OOKTx (val frameWidth: Int,
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
    val dataIn = Input(UInt(dataWidth.W))
    val dataInValid = Input(Bool())
    val divisor = Input(UInt(divisorWidth.W))
    val frameBits = Input(UInt(frameBitsWidth.W))
    val frameIndex = Input(UInt(frameIndexWidth.W))
    val sendEn = Input(Bool())
    val requestData = Output(Bool())
    val out = Output(Bool())
  })

  val crcEncode = Module(new CRCEncode(dataWidth, divisorWidth))
  val framePrep = Module(new FramePrep(frameWidth, frameBitsWidth, frameIndexWidth))
  val frameStackTx = Module(new FrameStack(frameWidth,stackSize))
  val frameSend = Module(new FrameSend(frameWidth))

  // IOs of OOK TX
  io.out := frameSend.io.out
  io.requestData := crcEncode.io.requestData
  frameSend.io.sendEn := io.sendEn
  crcEncode.io.dataIn := io.dataIn
  crcEncode.io.validIn := io.dataInValid
  crcEncode.io.divisor := io.divisor
  framePrep.io.frameBits := io.frameBits
  framePrep.io.frameIndex := io.frameIndex

  // Interfaces between CRC Encode and Frame Preparation
  framePrep.io.dataIn := crcEncode.io.dataOut
  framePrep.io.dataInValid := crcEncode.io.validOut
  crcEncode.io.requestIn := framePrep.io.requestOut

  // Interfaces between Frame Preparation and Frame Stack
  frameStackTx.io.in := framePrep.io.frameOut
  frameStackTx.io.frameValidIn := framePrep.io.dataOutValid
  framePrep.io.requestIn := frameStackTx.io.requestOut

  // Interfaces between Frame Stack and FrameSend
  frameStackTx.io.requestIn := frameSend.io.requestFrame
  frameSend.io.frameIn := frameStackTx.io.out
  frameSend.io.frameInValid := frameStackTx.io.frameValidOut

}
