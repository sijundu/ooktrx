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

class CRCEncodeIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt(p.dataWidth.W)))
  val out = Decoupled(UInt(p.frameWidth.W))
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val frameIndex = Input(UInt(p.frameIndexWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
}

class CRCEncode[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new CRCEncodeIO(gen, p))

  val counter = RegInit(0.U((log2Ceil(p.dataWidth+p.divisorWidth-1).toInt).W))

  val dataExtended = RegInit(0.U((p.dataWidth+p.divisorWidth-1).W))

  val requestData = RegInit(Bool(), true.B)
  io.in.ready := requestData

  val validOut = RegInit(Bool(), false.B)
  io.out.valid := validOut

  val frameBitsBuffer = RegInit(0.U(p.frameBitsWidth.W))
  val frameIndexBuffer = RegInit(0.U(p.frameIndexWidth.W))
  val dataInBuffer = RegInit(0.U(p.dataWidth.W))

  val frameOut = RegInit(0.U(p.frameWidth.W))
  io.out.bits := frameOut

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

  when(io.out.ready && requestData && io.in.valid){
    frameBitsBuffer := io.frameBits
    frameIndexBuffer := io.frameIndex
    dataInBuffer := io.in.bits
    dataExtended := io.in.bits << (p.divisorWidth - 1)
    requestData := false.B
    counter := 0.U
    validOut := false.B
  }.elsewhen(!validOut && !requestData){
    when(dataExtended < (1.U << (p.divisorWidth-1))){
      frameOut := Cat(frameBitsBuffer, frameIndexBuffer, dataInBuffer, dataExtended(p.divisorWidth-2, 0))
      validOut := true.B
      requestData := true.B
    }.elsewhen(dataExtended === io.divisor){
      frameOut := Cat(frameBitsBuffer, frameIndexBuffer, (dataInBuffer << (p.divisorWidth-1)))
      validOut := true.B
      requestData := true.B
    }.otherwise{
      counter := counter + 1.U
      validOut := false.B
      when(dataExtended((p.dataWidth+p.divisorWidth-1).asUInt-1.U-counter) === 1.U){
        when(counter === 0.U){
          dataExtended := Cat((dataExtended(p.dataWidth+p.divisorWidth-2, p.dataWidth-1)) ^ io.divisor, dataExtended(p.dataWidth-2, 0))
        }.otherwise{
          val headData = "b0".asUInt(1.W) << (counter-1.U)
          val xored = ((dataExtended<<counter)(p.dataWidth+p.divisorWidth-2,0)>>(p.dataWidth-1)) ^ io.divisor
          val tailData = ((dataExtended << (p.divisorWidth.U+counter))(p.dataWidth+p.divisorWidth-2, 0))>>(p.divisorWidth.U+counter)
          dataExtended := Cat(headData, xored)<<((p.dataWidth+p.divisorWidth-1).asUInt-p.divisorWidth.asUInt-counter) | tailData
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
