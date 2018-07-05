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
    val dataOutIndex = Output(UInt(frameIndexWidth.W))
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

  val frameIn = RegInit(0.U(frameWidth.W))
  io.dataOut := frameIn(dataWidth+divisorWidth-2, divisorWidth-1)
  io.dataOutIndex := frameIn(frameIndexWidth+dataWidth+divisorWidth-2, dataWidth+divisorWidth-1)

  val dataCal = RegInit(0.U((dataWidth+divisorWidth-1).W))

  val counter = RegInit(0.U((log2Ceil(dataWidth+divisorWidth-1).toInt).W))

  // Loading frame
  when(io.frameValid && requestFrame){
    frameIn := io.frameIn
    dataCal := io.frameIn(dataWidth+divisorWidth-2, 0)
    frameIndex := io.frameIn(dataWidth+divisorWidth+frameIndexWidth-2, dataWidth+divisorWidth-1)
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
      when(dataCal((dataWidth+divisorWidth-1).asUInt-1.U-counter) === 1.U){
        when(counter === 0.U){
          dataCal := Cat((dataCal(dataWidth+divisorWidth-2, dataWidth-1)) ^ io.divisor, dataCal(dataWidth-2, 0))
        }.otherwise{
          val headData = "b0".asUInt(1.W) << (counter-1.U)
          val xored = ((dataCal<<counter)(dataWidth+divisorWidth-2,0)>>(dataWidth-1)) ^ io.divisor
          val tailData = ((dataCal << (divisorWidth.U+counter))(dataWidth+divisorWidth-2, 0))>>(divisorWidth.U+counter)
          dataCal := Cat(headData, xored)<<((dataWidth+divisorWidth-1).asUInt-divisorWidth.asUInt-counter) | tailData
        }
      }
    } 
  }.otherwise{
    dataOutReady := false.B
  }

}
