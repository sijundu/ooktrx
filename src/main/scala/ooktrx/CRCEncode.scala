
package ooktrx

import chisel3._
import chisel3.util._

class CRCEncode (val dataWidth: Int,
                 val divisorWidth: Int
                 ) extends Module {

  require(divisorWidth >= 2, s"Divider bit width must be >= 2, got $divisorWidth")
  require(dataWidth >= 8, s"Data bit width must be >= 8, got $dataWidth")
  require(dataWidth > divisorWidth, "Data bitwidth must be greater than divisor bitwidth")

  val io = IO(new Bundle{
    val divisor = Input(UInt(divisorWidth.W))
    val dataIn = Input(UInt((dataWidth - divisorWidth + 1).W))
    val validIn = Input(Bool())
    val dataOut = Output(UInt(dataWidth.W))
    val validOut = Output(Bool())
    val requestData = Output(Bool())
  })

  //require(io.divisor(divisorWidth-1)===true.B, "The MSB of divisor must be 1")

  val counter = RegInit(0.U((log2Ceil(dataWidth).toInt).W))

  val dataExtended = RegInit(0.U(dataWidth.W))

  val requestData = RegInit(Bool(), true.B)
  io.requestData := requestData

  val validOut = RegInit(Bool(), false.B)
  io.validOut := validOut

  /*
  when(io.validIn){
    dataExtended := io.dataIn << (divisorWidth-1)
    requestData := false.B
  }
  */

  when(requestData && io.validIn){
    dataExtended := io.dataIn << (divisorWidth - 1)
    requestData := false.B
    counter := 0.U
  }.elsewhen(!validOut){
    when(dataExtended < io.divisor){
      io.dataOut(dataWidth-1, divisorWidth-1) := io.dataIn
      io.dataOut(divisorWidth-2, 0) := dataExtended(divisorWidth-2, 0)
      validOut := true.B
      requestData := true.B
    }.elsewhen(dataExtended === io.divisor){
      io.dataOut := io.dataIn << (divisorWidth-1)
      validOut := true.B
      requestData := true.B
    }.otherwise{
      counter := counter + 1.U
      validOut := false.B
      when(dataExtended(dataWidth-1-counter) === 1.U){
        dataExtended(dataWidth-1-counter, dataWidth-counter-divisorWidth) ^= io.divisor
      }.otherwise{
        dataExtended := dataExtended >> 1
      }
    }
  }.otherwise{
    validOut := false.B
  }

  /*
  (0 until dataWidth-divisorWidth+1){ index =>
    interData(index) := dataExtended >> index
    when(interData())
  }
  */

  
  //io.dataOut := dataExtended | (dataExtended % io.divisor)

}
