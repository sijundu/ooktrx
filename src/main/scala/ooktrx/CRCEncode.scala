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

class CRCEncode (
                 val frameWidth: Int,
                 val frameBitsWidth: Int,
                 val frameIndexWidth: Int,
                 val dataWidth: Int,
                 val divisorWidth: Int
                 ) extends Module {

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth >= 8, s"Data bit width must be >= 8, got $dataWidth")
  require(divisorWidth >= 2, s"Divider bit width must be >= 2, got $divisorWidth")
  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  val io = IO(new Bundle{
    val divisor = Input(UInt(divisorWidth.W))
    val frameBits = Input(UInt(frameBitsWidth.W))
    val frameIndex = Input(UInt(frameIndexWidth.W))
    val dataIn = Input(UInt(dataWidth.W))
    val validIn = Input(Bool())
    val requestIn = Input(Bool())
    val frameOut = Output(UInt(frameWidth.W))
    val validOut = Output(Bool())
    val requestData = Output(Bool())
    //val debugXor = Output(UInt(divisorWidth.W))
  })

  //require(io.divisor(divisorWidth-1) === true.B, "The MSB of divisor must be 1")

  val counter = RegInit(0.U((log2Ceil(dataWidth+divisorWidth-1).toInt).W))

  val dataExtended = RegInit(0.U((dataWidth+divisorWidth-1).W))

  val requestData = RegInit(Bool(), true.B)
  io.requestData := requestData

  val validOut = RegInit(Bool(), false.B)
  io.validOut := validOut

  val frameBitsBuffer = RegInit(0.U(frameBitsWidth.W))
  val frameIndexBuffer = RegInit(0.U(frameIndexWidth.W))
  val dataInBuffer = RegInit(0.U(dataWidth.W))

  val frameOut = RegInit(0.U(frameWidth.W))
  io.frameOut := frameOut

  /*
  val debugXor = RegInit(0.U(divisorWidth.W))
  io.debugXor := debugXor
  val debugDataExtended = RegInit(0.U((dataWidth+divisorWidth-1).W))
  io.debugDataExtended := debugDataExtended 
  val debugDataXor = RegInit(0.U((dataWidth+divisorWidth-1).W))
  debugDataXor := Cat(debugXor, Fill(dataWidth-3, 0.U))
  io.debugDataXor := debugDataXor 
  */
  
  /*
  when(io.validIn){
    dataExtended := io.dataIn << (divisorWidth-1)
    requestData := false.B
  }
  */

  when(io.requestIn && requestData && io.validIn){
    frameBitsBuffer := io.frameBits
    frameIndexBuffer := io.frameIndex
    dataInBuffer := io.dataIn
    dataExtended := io.dataIn << (divisorWidth - 1)
    requestData := false.B
    counter := 0.U
    validOut := false.B
  }.elsewhen(!validOut && !requestData){
    when(dataExtended < (1.U << (divisorWidth-1))){
      frameOut := Cat(frameBitsBuffer, frameIndexBuffer, dataInBuffer, dataExtended(divisorWidth-2, 0))
      validOut := true.B
      requestData := true.B
    }.elsewhen(dataExtended === io.divisor){
      frameOut := Cat(frameBitsBuffer, frameIndexBuffer, (dataInBuffer << (divisorWidth-1)))
      validOut := true.B
      requestData := true.B
    }.otherwise{
      counter := counter + 1.U
      validOut := false.B
      when(dataExtended((dataWidth+divisorWidth-1).asUInt-1.U-counter) === 1.U){
        when(counter === 0.U){
          //debugXor := (dataExtended(dataWidth+divisorWidth-2, dataWidth-1)) ^ io.divisor
          dataExtended := Cat((dataExtended(dataWidth+divisorWidth-2, dataWidth-1)) ^ io.divisor, dataExtended(dataWidth-2, 0))
        }.otherwise{
          val headData = "b0".asUInt(1.W) << (counter-1.U)
          val xored = ((dataExtended<<counter)(dataWidth+divisorWidth-2,0)>>(dataWidth-1)) ^ io.divisor
          val tailData = ((dataExtended << (divisorWidth.U+counter))(dataWidth+divisorWidth-2, 0))>>(divisorWidth.U+counter)
          dataExtended := Cat(headData, xored)<<((dataWidth+divisorWidth-1).asUInt-divisorWidth.asUInt-counter) | tailData
          //debugXor := xored
        }
      //}.otherwise{
      //  dataExtended := dataExtended >> 1
      }
    }
  }.otherwise{
    validOut := false.B
  }

}
