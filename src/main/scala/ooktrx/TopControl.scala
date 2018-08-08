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

class TopControlIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
  val txMode = Input(Bool()) // '1' for TX, '0' for RX, default '0'

  // TX interface
  val dataTx = Flipped(Decoupled(UInt((p.frameIndexWidth + p.dataWidth).W)))
  val bitTx = Output(Bool())

  // RX interface
  val dataRx = Valid(UInt((1 + p.frameIndexWidth + p.dataWidth).W))
  val bitRx = Input(Bool())
}

class TopControl[T <: Data](gen: T, p: OOKTRXparams) extends Module{
  
  val io = IO(new TopControlIO(gen, p))

  // Implementation of TX and RX blocks)
  val txControl = Module(new TxControl(gen, p))
  val rxControl = Module(new RxControl(gen, p))


  // TX interfaces
  txControl.io.frameBits <> io.frameBits
  txControl.io.divisor <> io.divisor
  txControl.io.txEn <> io.txMode
  txControl.io.in <> io.dataTx
  io.bitTx <> txControl.io.out
  
  // RX interfaces
  rxControl.io.frameBits <> io.frameBits
  rxControl.io.divisor <> io.divisor
  rxControl.io.rxEn <> !io.txMode
  rxControl.io.in <> io.bitRx
  io.dataRx <> rxControl.io.out
  
  /*
  val sIdle :: sRxStart :: sTxStart :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  switch(state){
    is(sIdle){
      when(
    }
    is(sRxStart){
    }
    is(sTxStart){
    }
  }
  */

}

