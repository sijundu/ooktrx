
// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import scala.util.Random

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

class TopSimulatorIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  //val txin = Flipped(Decoupled(UInt(p.dataWidth.W)))
  val txout = Decoupled(UInt(p.dataWidth.W))
  val rxin = Flipped(Decoupled(UInt(p.dataWidth.W)))
  val rxout = Decoupled(UInt(p.dataWidth.W))
  val preamble = Input(UInt(p.preambleWidth.W))
  val frameIndex = Input(UInt(p.frameIndexWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
  val error = Input(Bool())
  val hostIn = Flipped(Decoupled(UInt(p.dataWidth.W)))
}

class TopSimulator[T <: Data](gen: T, p: OOKTRXparams) extends Module{ 

  val io = IO(new TopSimulatorIO(gen, p))

  val tx = Module(new TopControl(gen, p))
  val rx = Module(new TopControl(gen, p))

  // Simulating the data transmission in air
  val dataInAir = RegNext(Mux(io.error, !tx.io.bitTx, tx.io.bitTx))
  val dataInAirB = RegNext(rx.io.bitTx)


  // Host definition
  val host = Module(new HostMem(gen, p))
  io.hostIn <> host.io.hostIn
  
  tx.io.in <> host.io.hostOut

  // TX
  tx.io.preamble := io.preamble
  tx.io.divisor := io.divisor
  tx.io.frameIndex := io.frameIndex
  tx.io.out <> io.txout
  tx.io.bitRx := dataInAirB

  
  // RX
  rx.io.preamble := io.preamble
  rx.io.divisor:= io.divisor
  rx.io.frameIndex := io.frameIndex
  rx.io.in <> io.rxin
  rx.io.out <> io.rxout
  rx.io.bitRx := dataInAir
  

}

