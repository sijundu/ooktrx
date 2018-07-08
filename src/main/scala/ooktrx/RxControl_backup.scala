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


class RxControl_backup (
             val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
             val rxStackSize: Int,
             val rxMemSize: Int
            ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")

  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  val io = IO(new Bundle{
    val rxEn = Input(Bool())
    val in = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    val divisor = Input(UInt(divisorWidth.W))
    val frameCount = Input(UInt((log2Ceil(rxMemSize).toInt).W))

    val readDataRequest = Input(Bool())

    val rxBusy = Output(Bool())
    val dataOut = Output(UInt((1 + frameIndexWidth + dataWidth).W))
    val dataOutValid = Output(Bool())
  })

  // Output initilization
  val dataOut = RegInit(0.U((1 + frameIndexWidth + dataWidth).W))
  io.dataOut := dataOut
  val dataOutValid = RegInit(Bool(), false.B)
  io.dataOutValid := dataOutValid
  val rxBusy = RegInit(Bool(), false.B)
  io.rxBusy := rxBusy
  

  ///////////////////////////////////////////////////////////////////////////////////
  // Implement data ram to store received data
  // rxMem data structure:
  //    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  //  |  |           |                                                |
  //   A      B                             C
  //   A: crcPass flag (1.W)
  //   B: frame index, used to request resending data if crcPass flag is de-asserted. (frameIndexWidth.W)
  //   C: information data. (dataWidth.W)
  val rxMem = Mem(rxMemSize, UInt((1 + frameIndexWidth + dataWidth).W))
  ///////////////////////////////////////////////////////////////////////////////////


  val rxDataAddr = RegInit(0.U((log2Ceil(rxMemSize+1).toInt).W))

  val bitIn = Wire(Bool())
  bitIn := Mux(io.rxEn, io.in, false.B)

  // Implementation of OOKRx block
  val ookrx = Module(new OOKRx(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, rxStackSize))
  ookrx.io.in := bitIn
  ookrx.io.frameBits := io.frameBits
  ookrx.io.divisor := io.divisor

  val frameCount = RegInit(0.U((log2Ceil(rxMemSize).toInt).W))

  // Assert rxEnReg when io.rxEn changes from low to high
  val rxEnReg = RegInit(Bool(), false.B)
  val rxEnNext = RegNext(io.rxEn)
  when(io.rxEn && (io.rxEn ^ rxEnNext)){
    rxEnReg := true.B
    frameCount := io.frameCount
  }.elsewhen(rxEnReg && rxDataAddr === (frameCount )){
    rxEnReg := false.B
  }


  val readDataEn = RegInit(Bool(), false.B)
  val readDataNext = RegNext(io.readDataRequest)
  when(io.readDataRequest && (io.readDataRequest ^ readDataNext)){
    readDataEn := true.B
  }.elsewhen(readDataEn && rxDataAddr === (frameCount - 1.U)){
    readDataEn := false.B
  }


  when(rxEnReg){
    when(ookrx.io.dataOutReady){
      when(rxDataAddr < frameCount){
        rxBusy := true.B
        rxMem.write(rxDataAddr, Cat(ookrx.io.crcPass, ookrx.io.dataOutIndex, ookrx.io.dataOut))
        when(rxDataAddr === (frameCount - 1.U)){
          rxBusy := false.B
          rxDataAddr := 0.U
        }.otherwise{
          rxDataAddr := rxDataAddr + 1.U
        }
      }
    }
  }.elsewhen(readDataEn && !rxBusy){
    when (rxDataAddr < frameCount){
      dataOut := rxMem.read(rxDataAddr)
      dataOutValid := true.B
      when(rxDataAddr === (frameCount - 1.U)){
        rxDataAddr := 0.U
      }.otherwise{
        rxDataAddr := rxDataAddr + 1.U
      }
    }
  }

}
