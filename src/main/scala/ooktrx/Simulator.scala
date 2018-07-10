
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


class Simulator (
             val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
             val rxStackSize: Int,
             val rxMemSize: Int,
             val txStackSize: Int,
             val txMemSize: Int
            ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")
  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  val io = IO(new Bundle{
    val frameBits = Input(UInt(frameBitsWidth.W))
    val divisor = Input(UInt(divisorWidth.W))
    val dataIn = Input(UInt((frameIndexWidth + dataWidth).W))
    val dataInValid = Input(Bool())

    val dataOut = Output(UInt((1 + frameIndexWidth + dataWidth).W))
    val dataOutReady = Output(Bool())
  })

  val txControl = Module(new TxControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, txStackSize, txMemSize))
  val rxControl = Module(new RxControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, rxStackSize, rxMemSize))

  // Simulating the data transmission in air
  val dataInAir = RegNext(txControl.io.out)
  rxControl.io.in := dataInAir

  io.dataOut := rxControl.io.dataOut
  io.dataOutReady := rxControl.io.dataOutReady

  txControl.io.frameBits := io.frameBits
  txControl.io.divisor := io.divisor
  txControl.io.txEn := true.B
  txControl.io.dataIn := io.dataIn
  txControl.io.dataInValid := io.dataInValid
  
  rxControl.io.rxEn := true.B
  rxControl.io.frameBits := io.frameBits
  rxControl.io.divisor:= io.divisor
  

}

