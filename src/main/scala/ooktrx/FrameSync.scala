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


class FrameSync (val frameBitsWidth: Int,
                 val frameWidth: Int
                 //val frameIndexWidth: Int
                ) extends Module {

  require(frameBitsWidth > 2, s"Frame Bits Width must be > 2, got $frameBitsWidth")
  require(frameWidth > 15, s"Frame Width must be > 15, got $frameWidth")

  val io = IO(new Bundle{
    val in = Input(Bool())
    val requestFrame = Input(Bool())
    val frameBits = Input(UInt(frameBitsWidth.W))
    //val frameIndex = Input(UInt(frameIndexWidth.W))
    //val syncOk = Output(Bool())
    val frameReady = Output(Bool())
    val frameOut = Output(UInt(frameWidth.W))
  })

  val frameReady = RegInit(Bool(), false.B)
  io.frameReady := frameReady

  val frameOut = RegInit(0.U(frameWidth.W))
  io.frameOut := frameOut

  val bitCounter = RegInit(0.U(log2Ceil(frameWidth).toInt.W))

  val frameBitsReg = RegInit(0.U(frameBitsWidth.W))

  val syncOk = Wire(Bool())
  syncOk := (frameBitsReg === io.frameBits)

  when(io.requestFrame){
    when(!syncOk){
      frameBitsReg := (frameBitsReg  << 1) | io.in
      bitCounter := 0.U
    }.elsewhen(bitCounter === 0.U){
      bitCounter := bitCounter + 1.U
      //frameOut := (Cat(io.frameBits, io.frameIndex) << 1) | io.in
      frameOut := (io.frameBits << 1) | io.in
    //}.elsewhen(bitCounter < (frameWidth-frameBitsWidth-frameIndexWidth).asUInt){
    }.elsewhen(bitCounter < (frameWidth-frameBitsWidth).asUInt){
      bitCounter := bitCounter + 1.U
      frameOut := (frameOut << 1) | io.in
      //when(bitCounter === (frameWidth-frameBitsWidth-frameIndexWidth-1).asUInt){
      when(bitCounter === (frameWidth-frameBitsWidth-1).asUInt){
        frameReady := true.B
        frameBitsReg := 0.U
      }
    }
  }.otherwise{
    bitCounter := 0.U
    frameOut := 0.U
    frameReady := 0.U
  }

  when(frameReady && io.requestFrame){
    bitCounter := 0.U
    frameOut := 0.U
    frameReady := false.B
  }
    


}
