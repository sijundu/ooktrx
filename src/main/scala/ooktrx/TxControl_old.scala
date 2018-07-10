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


class TxControl_old (
             val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
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

    val txStart = Input(Bool())
    val dataIn = Input(UInt((frameIndexWidth + dataWidth).W))
    val dataInValid = Input(Bool())
    val frameCount = Input(UInt((log2Ceil(txMemSize).toInt+1).W))

    val txMemFull = Output(Bool())
    val out = Output(Bool())
    //val requestData = Output(Bool())
  })

  // Output initilization
  val dataInBuffer = RegInit(0.U((frameIndexWidth + dataWidth).W))
  

  ///////////////////////////////////////////////////////////////////////////////////
  // Implement data ram to store received data
  // rxMem data structure:
  //    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  //   |           |                                                |
  //         A                             B
  // A: frame index, used to request resending data if crcPass flag is de-asserted. (frameIndexWidth.W)
  // B: information data. (dataWidth.W)
  val txMem = Mem(txMemSize, UInt((frameIndexWidth + dataWidth).W))
  ///////////////////////////////////////////////////////////////////////////////////

  val writeAddr = RegInit(0.U((log2Ceil(txMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(txMemSize).toInt).W))
  
  // Implementation of OOKRx block
  val ooktx = Module(new OOKTx(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, txStackSize))
  io.out := ooktx.io.out
  ooktx.io.frameBits := io.frameBits
  ooktx.io.divisor := io.divisor
  val dataToSend = RegInit(0.U((frameIndexWidth + dataWidth).W))
  ooktx.io.dataIn := dataToSend(dataWidth-1, 0)
  ooktx.io.frameIndex := dataToSend(frameIndexWidth+dataWidth-1, dataWidth)
  val dataToSendValid = RegInit(Bool(), false.B)
  ooktx.io.dataInValid := dataToSendValid
  //val sendEn = RegInit(Bool(),false.B)
  //ooktx.io.sendEn := sendEn


  // Internal registers
  val frameCount = RegInit(0.U((log2Ceil(txMemSize).toInt+1).W))
  val memUsage = RegInit(0.U((log2Ceil(txMemSize+1).toInt).W))

  // Stat Machine definition
  val sIdle :: sLoad :: sTx :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  io.txMemFull := Mux(memUsage < txMemSize.asUInt, false.B, true.B)

  //////////////////// State machine implementation //////////////////
  switch(state){
    // Waiting for data to be sent
    is(sIdle){
      when(io.txStart){
        state := sLoad
        when(io.dataInValid){
          txMem.write(writeAddr, io.dataIn)
          writeAddr := Mux(writeAddr === (txMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          frameCount := io.frameCount - 1.U
          memUsage := memUsage + 1.U
        }.otherwise{
          frameCount := io.frameCount
        }
      }
    }
    // Load data into Tx memory for sending
    is(sLoad){
      when(memUsage < txMemSize.asUInt && (frameCount > 0.U)){
        when(io.dataInValid){
          txMem.write(writeAddr, io.dataIn)
          writeAddr := Mux(writeAddr === (txMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          memUsage := memUsage + 1.U
          frameCount := frameCount - 1.U
        }
      }.elsewhen(ooktx.io.requestData){
        //sendEn := true.B
        state := sTx
      }
    }
    // Sequentially (FIFO) send data store in Tx memory
    is(sTx){
      when(memUsage > 0.U){
        when(ooktx.io.requestData && !dataToSendValid){
          dataToSend := txMem.read(readAddr)
          dataToSendValid := true.B
          readAddr := Mux(readAddr === (txMemSize-1).asUInt, 0.U, readAddr + 1.U)
          memUsage := memUsage - 1.U
        }.otherwise{
          dataToSendValid := false.B
        }
      }.otherwise{
        //sendEn := false.B
        dataToSendValid := false.B
        state := sIdle
      }
    }
  }

}
