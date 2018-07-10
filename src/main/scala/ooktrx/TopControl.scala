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


class TopControl (
             val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
             val txStackSize: Int,
             val txMemSize: Int,
             val rxStackSize: Int,
             val rxMemSize: Int
            ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")
  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")
  require(txStackSize >= 16, s"TX Stack Mem size should be >=16, got $txStackSize")
  require(rxStackSize > 0, s"RX Stack Mem size should be >= 1, got $rxStackSize")

  val io = IO(new Bundle{
    val frameBits = Input(UInt(frameBitsWidth.W))
    val divisor = Input(UInt(divisorWidth.W))

    val txMode = Input(Bool()) // '1' for TX, '0' for RX, default '0'

    // TX related
    val dataToSend = Input(UInt((frameIndexWidth + dataWidth).W))
    val dataToSendValid = Input(Bool())
    val bitTx = Output(Bool())
    val txMemFull = Output(Bool())

    // RX related
    val bitRx = Input(Bool())
    val dataRx = Output(UInt((1 + frameIndexWidth + dataWidth).W))
    val dataRxReady = Output(Bool())
  })

  // Implementation of TX and RX blocks)
  val txControl = Module(new TxControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, txStackSize, txMemSize))
  val rxControl = Module(new RxControl(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, rxStackSize, rxMemSize))


  // TX interfaces
  txControl.io.frameBits := io.frameBits
  txControl.io.divisor := io.divisor
  txControl.io.txEn := io.txMode
  txControl.io.dataIn := io.dataToSend
  txControl.io.dataInValid := io.dataToSendValid
  io.txMemFull := txControl.io.txMemFull
  io.bitTx := txControl.io.out
  
  // RX interfaces
  rxControl.io.frameBits := io.frameBits
  rxControl.io.divisor:= io.divisor
  rxControl.io.rxEn := !io.txMode
  rxControl.io.in := io.bitRx
  io.dataRx := rxControl.io.dataOut
  io.dataRxReady := rxControl.io.dataOutReady
  
  /*
  val sIdle :: sRxStart :: sTxStart :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  switch(state){
    is(sIdle){
      when(
    }
    is(sRxStart){
    }
    is(sTxStart){
    }
  }
  */

}

