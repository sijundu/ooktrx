
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

class TopSimulatorIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt((p.frameIndexWidth + p.dataWidth).W)))
  val out = Valid(UInt((1 + p.frameIndexWidth + p.dataWidth).W))
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
}

class TopSimulator[T <: Data](gen: T, p: OOKTRXparams) extends Module{ 

  val io = IO(new TopSimulatorIO(gen, p))

  val tx = Module(new TopControl(gen, p))
  val rx = Module(new TopControl(gen, p))

  // Simulating the data transmission in air
  val dataInAir = RegNext(tx.io.bitTx)

  // TX
  tx.io.frameBits := io.frameBits
  tx.io.divisor := io.divisor
  tx.io.txMode := true.B
  tx.io.dataTx <> io.in
  tx.io.bitRx := false.B
  
  // RX
  rx.io.frameBits := io.frameBits
  rx.io.divisor:= io.divisor
  rx.io.txMode := false.B
  rx.io.dataTx.bits := 0.U
  rx.io.dataTx.valid := false.B
  rx.io.bitRx := dataInAir
  io.out <> rx.io.dataRx
  

}

