// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// dataWidth: the width of the whole frame, excluding the frame sync head
//            including the information data and extension for CRC

class CRCCheck (val frameWidth: Int,
                val frameIndexWidth: Int,
                val dataWidth: Int,
                val divisorWidth: Int 
                ) extends Module {

  require(divisorWidth > 2, s"Divider bit width must be > 2, got $divisorWidth")

  val io = IO(new Bundle{
    val frameIn = Input(UInt(frameWidth.W)) 
    val frameValid = Input(Bool())
    val divisor = Input(UInt(divisorWidth.W))
    val dataOut = Output(UInt(dataWidth.W)) //data only with frame index, without frame bits or CRC
    val dataOutReady = Output(Bool())
    val crcPass = Output(Bool())
    val requestFrame = Output(Bool())
  })


  val dataOutReady = RegInit(Bool(), false.B)
  io.dataOutReady := dataOutReady

  val crcPass = RegInit(Bool(), false.B)
  io.crcPass := crcPass

  val requestFrame = RegInit(Bool(), false.B)
  io.requestFrame := requestFrame

  val frameIndex = RegInit(0.U(frameIndexWidth.W))

  val dataIn = RegInit(0.U(dataWidth.W))
  io.dataOut := dataIn

  val dataCal = RegInit(0.U(dataWidth.W))

  val counter = RegInit(0.U((log2Ceil(dataWidth).toInt).W))

  // Loading frame
  when(io.frameValid && requestFrame){
    dataIn := io.frameIn(dataWidth-1, 0)
    dataCal := io.frameIn(dataWidth-1, 0)
    frameIndex := io.frameIn(dataWidth+frameIndexWidth-1, dataWidth)
    counter := 0.U
    requestFrame := false.B
    dataOutReady := false.B
    crcPass := false.B
  }.elsewhen(!dataOutReady && !requestFrame){
    when(dataCal === 0.U | dataCal === io.divisor){
      dataOutReady := true.B
      requestFrame := true.B
      crcPass := true.B
    }.elsewhen(dataCal < io.divisor){
      dataOutReady := true.B
      requestFrame := true.B
      crcPass := false.B
    }.otherwise{
      counter := counter + 1.U
      dataOutReady := false.B
      when(dataCal(dataWidth.asUInt-1.U-counter) === 1.U){
        when(counter === 0.U){
          dataCal := Cat((dataCal(dataWidth-1, dataWidth-divisorWidth)) ^ io.divisor, dataCal(dataWidth-divisorWidth-1, 0))
        }.otherwise{
          val headData = "b0".asUInt(1.W) << (counter-1.U)
          val xored = ((dataCal<<counter)(dataWidth-1,0)>>(dataWidth-divisorWidth)) ^ io.divisor
          val tailData = ((dataCal << (divisorWidth.U+counter))(dataWidth-1, 0))>>(divisorWidth.U+counter)
          dataCal := Cat(headData, xored)<<(dataWidth.asUInt-divisorWidth.asUInt-counter) | tailData
        }
      }
    } 
  }.otherwise{
    dataOutReady := false.B
  }

}
