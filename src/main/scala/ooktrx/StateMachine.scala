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


class StateMachine (
               val frameWidth: Int,
               val frameBitsWidth: Int,
               val frameIndexWidth: Int,
               val dataWidth: Int,
               val divisorWidth: Int,
               val sysRamSize: Int = 16,
               val sysRamWidth: Int = 32,
               val dataRamSize: Int = 128
              ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")

  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  
  val io = IO(new Bundle{
    val powerOn = Input(Bool())

    val dataIn = Input(UInt(dataWidth.W))
    val dataInValid = Input(Bool())
    val dataInIndex = Input(UInt(frameIndexWidth.W))
    val crcPass = Input(Bool())
    val sendDone = Input(Bool())
    
    val frameBits = Output(UInt(frameBitsWidth.W))
    val divisor = Output(UInt(divisorWidth.W))
    val dataOut = Output(UInt(dataWidth.W))
    val dataOutValid = Output(Bool())
    val dataOutIndex = Output(UInt(frameIndexWidth.W))
    val sendEn = Output(Bool())
  })

  /*
  ////////////  Output initilization  /////////////
  val frameBits = RegInit(0.U(frameBitsWidth.W))
  io.frameBits := frameBits

  val dataOutIndex = RegInit(0.U(frameIndexWidth.W))
  io.dataOutIndex := dataOutIndex

  val divisor = RegInit(0.U(divisorWidth.W))
  io.divisor := divisor

  val dataOut = RegInit(1.U(dataWidth.W))
  io.dataOut := dataOut

  val dataOutValid = RegInit(Bool(), false.B)
  io.dataOutValid := dataOutValid

  val dataOutIndex = RegInit(0.U(frameIndexWidth.W))
  io.dataOutIndex := dataOutIndex

  val sendEn = RegInit(Bool(), false.B)
  io.sendEn := sendEn
  ////////////////////////////////////////////////

  // definition of specific instructions
  val startSendCode = Fill(dataWidth, 1.U) // "b11...111"
  val requestResendCode = 0.U(dataWidth.W) // "b00...000"


  // Data RAM initilization
  val dataRam = Mem(dataRamSize, UInt(dataWidth.W))
  val rxDataAddr = RegInit(0.U(log2Ceil(dataRamSize).toInt.W))
  val txDataAddr = RegInit((log2Ceil(dataRamSize).toInt.W))

  // System RAM initilization
  val sysRam = Mem(sysRamSize, sysRamWidth.W)
  val frameBitsAddr = 0.U(log2Ceil(sysRamSize).toInt.W)
  val frameStartIndexAddr = 1.U(log2Ceil(sysRamSize).toInt.W)
  val divisorAddr = 2.U(log2Ceil(sysRamSize).toInt.W)
  val rxDataStartAddr = 3.U(log2Ceil(sysRamSize).toInt.W)
  val txDataStartAddr = 4.U(log2Ceil(sysRamSize).toInt.W)


  // RequestResend registers
  val dataToBeResend = RegInit(0.U(dataWidth.W))
  val indexToBeResend = RegInit(0.U(frameIndexWidth.W))

  // State Machine deifinition
  val sIdle :: sInit :: sReceive :: sRequestResend :: sResend :: sSend :: Nil = Enum(6)
  val state = Reg(init = sIdle)

  //////////////////// State machine implementation //////////////////
  switch(state) {
    // Idea state when powerOn is deasserted. 
    is(sIdle){
      sendEn := false.B
      when(io.powerOn){
        state := sInit
      }
    // Init the system with some global definitions
    } is(sInit) {
      sendEn := false.B
      when(!io.powerOn){
        state := sIdle
      }.otherwise{
        start := sReceive
        frameBits := sysRam.read(frameBitsAddr)
        dataOutIndex := sysRam.read(frameStartIndexAddr)
        divisor := sysRam.read(divisorAddr)
        rxDataAddr := sysRam.read(rxDataStartAddr)
        txDataAddr := sysRam.read(txDataStartAddr)
      }
    // Receiving data
    } is(sReceive){
      when(!io.powerOn){
        state := sIdle
        sendEn := false.B
      }elsewhen(io.dataInValid){
        when(io.cscPass){
          when(io.dataIn === startSendCode){
            state := sSend
            sendEn := true.B
          //}.elsewhen(io.dataIn === requestResendCode){
          //  state : sResend
          //  sendEn := true.B
          }.elsewhen(rxDataAddr < txDataStartAddr){
            dataram.write(rxDataAddr, io.dataIn)
            rxDataAddr := rxDataAddr + 1.U
          }
        }.otherwise{
          state := sRequestResend
          indexToBeResend := io.dataInIndex
          sendEn := true.B
        }
      }
    // Transmit one single frame to request a data which didn't pass CRC
    } is(sRequestResend){
      when(!io.powerOn){
        state := sIdle
        sendEn := false.B
      }.otherwise{
        dataOutIndex := indexToBeResend
        dataOut := requestResendCode
        when(io.sendDone){
          state := sReceive
          sendEn := false.B
        }
      }
    //} is(sResend){
    //  when(!io.powerOn){
    //    state := sIdle
    //    sendEn := false.B
    // }.otherwise{
    //    dataOut
    // Transmitting data pre-stored in data RAM
    } is(sSend){
      when(!io.powerOn){
        state := sIdle
        sendEn := false.B
      }elsewhen(txDataAddr < dataRamSize.asUInt){
        txDataAddr := txDataAddr + 1.U
        dataOut := dataRam.read(txDataAddr)
        dataOutValid := true.B
      }.otherwise{
        state := sReceive
        dataOutValid := false.B
        sendEn := false.B
      }
    }
  }
  */


}
