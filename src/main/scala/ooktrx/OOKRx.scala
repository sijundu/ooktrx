// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// Frame example 32-bit in total
//   0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0
//  |       A        |    B   |                  C                 |    D  |
//
//  A+B+C+D @frameWidth = 32
//  A       @preambleWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary

class OOKRxIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Input(Bool())
  val preamble = Input(UInt(p.preambleWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
  val out = Decoupled(UInt(p.dataWidth.W))
  val dataOutIndex = Output(UInt(p.frameIndexWidth.W))
  val crcPass = Output(Bool())
  val crcPassAsTx = Output(Bool())
  val crcFailAsTx = Output(Bool())
}

class OOKRx[T <: Data](gen: T, p: OOKTRXparams) extends Module {

  val io = IO(new OOKRxIO(gen, p))

  val frameSync = Module(new FrameSync(gen, p))
  val frameStackRx = Module(new FrameStack(gen, p, p.rxStackSize))
  val crcCheck = Module(new CRCCheck(gen, p))

  // IOs of OOKRx
  frameSync.io.in := io.in
  frameSync.io.preamble := io.preamble
  crcCheck.io.divisor := io.divisor
  io.out <> crcCheck.io.out
  io.dataOutIndex := crcCheck.io.dataOutIndex
  io.crcPass := crcCheck.io.crcPass
  io.crcPassAsTx := frameSync.io.crcPass
  io.crcFailAsTx := frameSync.io.crcFail

  // Interfaces between FrameSync and FrameStackRx
  frameSync.io.out <> frameStackRx.io.in

  // Interfaces between FrameStackRx and CRCCheck
  frameStackRx.io.out <> crcCheck.io.in
  

}

