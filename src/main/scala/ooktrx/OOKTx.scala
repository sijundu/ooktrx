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

class OOKTxIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(gen))
  val out = Output(Bool())
  val preamble = Input(UInt(p.preambleWidth.W))
  val frameIndex = Input(UInt(p.frameIndexWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
  val crcPassAsRx = Input(Bool())
  val crcFailAsRx = Input(Bool())
  val resendAsTx = Input(Bool())
  val sendAsTx = Input(Bool())
}

class OOKTx[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new OOKTxIO(gen, p))

  val crcEncode = Module(new CRCEncode(gen, p))
  val frameStackTx = Module(new FrameStack(gen, p, p.txStackSize))
  val frameSend = Module(new FrameSend(gen, p))

  // IOs of OOK TX
  io.out := frameSend.io.out
  crcEncode.io.in <> io.in
  crcEncode.io.divisor := io.divisor
  crcEncode.io.preamble := io.preamble
  crcEncode.io.frameIndex := io.frameIndex
  frameSend.io.preamble := io.preamble
  frameSend.io.crcPassAsRx := io.crcPassAsRx
  frameSend.io.crcFailAsRx := io.crcFailAsRx
  frameSend.io.resendAsTx := io.resendAsTx
  frameSend.io.sendAsTx := io.sendAsTx

  // Interfaces between CRCEncode and Frame Stack
  crcEncode.io.out <> frameStackTx.io.in

  // Interfaces between Frame Stack and FrameSend
  frameStackTx.io.out <> frameSend.io.in

}
