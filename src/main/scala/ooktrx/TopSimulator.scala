
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


class TopSimulator (
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

  val tx = Module(new TopControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, txStackSize, txMemSize, rxStackSize, rxMemSize))
  val rx = Module(new TopControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, txStackSize, txMemSize, rxStackSize, rxMemSize))

  // Simulating the data transmission in air
  val dataInAir = RegNext(tx.io.bitTx)

  // TX
  tx.io.frameBits := io.frameBits
  tx.io.divisor := io.divisor
  tx.io.txMode := true.B
  tx.io.dataToSend := io.dataIn
  tx.io.dataToSendValid := io.dataInValid
  tx.io.bitRx := false.B
  
  // RX
  rx.io.dataToSend := 0.U
  rx.io.dataToSendValid := 0.U
  rx.io.frameBits := io.frameBits
  rx.io.divisor:= io.divisor
  rx.io.txMode := false.B
  rx.io.bitRx := dataInAir
  io.dataOut := rx.io.dataRx
  io.dataOutReady := rx.io.dataRxReady
  

}

