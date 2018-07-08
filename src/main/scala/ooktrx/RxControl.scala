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


class RxControl (
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
    val rxStart = Input(Bool())
    val in = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    val divisor = Input(UInt(divisorWidth.W))
    val frameCount = Input(UInt((log2Ceil(rxMemSize).toInt).W))

    val readDataRequest = Input(Bool())

    val dataOut = Output(UInt((1 + frameIndexWidth + dataWidth).W))
    val dataOutValid = Output(Bool())
  })

  // Output initilization
  val dataOut = RegInit(0.U((1 + frameIndexWidth + dataWidth).W))
  io.dataOut := dataOut
  val dataOutValid = RegInit(Bool(), false.B)
  io.dataOutValid := dataOutValid
  

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


  val writeAddr = RegInit(0.U((log2Ceil(rxMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(rxMemSize).toInt).W))
  
  // Gated input bits with "enable"
  val bitInEn = RegInit(Bool(), false.B)
  val bitIn = Wire(Bool())
  bitIn := Mux(bitInEn, io.in, false.B)

  // Implementation of OOKRx block
  val ookrx = Module(new OOKRx(frameWidth, frameBitsWidth, frameIndexWidth, dataWidth, divisorWidth, rxStackSize))
  ookrx.io.in := bitIn
  ookrx.io.frameBits := io.frameBits
  ookrx.io.divisor := io.divisor

  // Internal registers
  val frameCount = RegInit(0.U((log2Ceil(rxMemSize).toInt).W))
  val memUsage = RegInit(0.U((log2Ceil(rxMemSize+1).toInt).W))

  // Stat Machine definition
  val sIdle :: sRx :: sLoad :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  //////////////////// State machine implementation //////////////////
  switch(state){
    is(sIdle){
      when(io.rxStart){
        frameCount := io.frameCount
        bitInEn := true.B
        state := sRx
      }.elsewhen(io.readDataRequest){
        frameCount := io.frameCount
        state := sLoad
      }
    }
    is(sRx){
      when((memUsage < rxMemSize.asUInt) && (frameCount > 0.U)){
        when(ookrx.io.dataOutReady){
          rxMem.write(writeAddr, Cat(ookrx.io.crcPass, ookrx.io.dataOutIndex, ookrx.io.dataOut))
          writeAddr := Mux(writeAddr === (rxMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          memUsage := memUsage + 1.U
          frameCount := frameCount - 1.U
        }
      }.elsewhen(io.readDataRequest){
        frameCount := io.frameCount
        bitInEn := false.B
        state := sLoad
      }.otherwise{
        bitInEn := false.B
        state := sIdle
      }
    }
    is(sLoad){
      when((memUsage > 0.U) && (frameCount > 0.U)){
        dataOut := rxMem.read(readAddr)
        dataOutValid := true.B
        readAddr := Mux(readAddr === (rxMemSize-1).asUInt, 0.U, readAddr + 1.U)
        memUsage := memUsage - 1.U
        frameCount := frameCount - 1.U
      }.elsewhen(io.rxStart){
        frameCount := io.frameCount
        state := sRx
      }.otherwise{
        state := sIdle
      }
    }
  }
}
