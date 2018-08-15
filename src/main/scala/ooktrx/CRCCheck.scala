// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// Frame example 32-bit in total
//   0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0
//  |       A        |    B   |                  C                 |    D  |
//
//  A+B+C+D @frameWidth = 32
//  A       @PreambleWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary

class CRCCheckIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt(p.frameWidth.W)))
  val out = Decoupled(gen)
  val divisor = Input(UInt(p.divisorWidth.W))
  val dataOutIndex = Output(UInt(p.frameIndexWidth.W))
  val crcPass = Output(Bool())
}

class CRCCheck[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new CRCCheckIO(gen, p))

  val dataOutValid = RegInit(Bool(), false.B)
  io.out.valid := dataOutValid

  val crcPass = RegInit(Bool(), false.B)
  io.crcPass := crcPass

  val requestFrame = RegInit(Bool(), false.B)
  io.in.ready := requestFrame

  val frameIndex = RegInit(0.U(p.frameIndexWidth.W))

  val frameIn = RegInit(0.U(p.frameWidth.W))
  io.out.bits := frameIn(p.dataWidth+p.divisorWidth-2, p.divisorWidth-1)
  io.dataOutIndex := frameIn(p.frameIndexWidth+p.dataWidth+p.divisorWidth-2, p.dataWidth+p.divisorWidth-1)

  val dataCal = RegInit(0.U((p.dataWidth+p.divisorWidth-1).W))

  val counter = RegInit(0.U((log2Ceil(p.dataWidth+p.divisorWidth-1).toInt).W))

  // State Machine definition
  val sIdle :: sChecking :: sDone :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  //////////////////// State machine implementation //////////////////
  switch(state){
    // requesting frame
    is(sIdle){
      dataOutValid := false.B
      requestFrame := true.B
      when(io.in.valid){
        requestFrame := false.B
        frameIn := io.in.bits
        dataCal := io.in.bits(p.dataWidth+p.divisorWidth-2, 0)
        frameIndex := io.in.bits(p.dataWidth+p.divisorWidth+p.frameIndexWidth-2, p.dataWidth+p.divisorWidth-1)
        counter := 0.U
        state := sChecking
      }.otherwise{
        requestFrame := true.B
      }
    // CRC is now working 
    }
    is(sChecking){
      when((dataCal === 0.U | dataCal === io.divisor)){
        crcPass := true.B
        state := sDone
      }.elsewhen(dataCal < io.divisor){
        crcPass := false.B
        state := sDone
      }.otherwise{
        counter := counter + 1.U
        when(dataCal((p.dataWidth+p.divisorWidth-1).asUInt-1.U-counter) === 1.U){
          when(counter === 0.U){
            dataCal := Cat((dataCal(p.dataWidth+p.divisorWidth-2, p.dataWidth-1)) ^ io.divisor, dataCal(p.dataWidth-2, 0))
          }.otherwise{
            val headData = "b0".asUInt(1.W) << (counter-1.U)
            val xored = ((dataCal<<counter)(p.dataWidth+p.divisorWidth-2,0)>>(p.dataWidth-1)) ^ io.divisor
            val tailData = ((dataCal << (p.divisorWidth.U+counter))(p.dataWidth+p.divisorWidth-2, 0))>>(p.divisorWidth.U+counter)
            dataCal := Cat(headData, xored)<<((p.dataWidth+p.divisorWidth-1).asUInt-p.divisorWidth.asUInt-counter) | tailData
          }
        }
      }
    // CRC is done and the data either pass or fail the checking
    }
    is(sDone){
      when(io.out.ready && !dataOutValid){
        dataOutValid := true.B
        state := sIdle
      }
    }
  }

}
