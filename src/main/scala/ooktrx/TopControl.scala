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

class TopControlIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val preamble = Input(UInt(p.preambleWidth.W))
  val frameIndex = Input(UInt(p.frameIndexWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))

  // TX interface
  val bitTx = Output(Bool())

  // RX interface
  val bitRx = Input(Bool())

  val in = Flipped(Decoupled(UInt(p.dataWidth.W)))
  val out = Decoupled(UInt(p.dataWidth.W))
}

class TopControl[T <: Data](gen: T, p: OOKTRXparams) extends Module{
  
  val io = IO(new TopControlIO(gen, p))

  // FSM definition
  val sIdle :: sRx :: sRead :: sTx :: sLoad :: sCrcPassAsRx :: sCrcFailAsRx :: sCrcPassAsTx :: sCrcFailAsTx :: Nil = Enum(9)
  val state = Reg(init = sIdle)

  // Implementation of TX and RX blocks
  val ooktx = Module(new OOKTx(gen, p))
  val ookrx = Module(new OOKRx(gen, p))

  // Implementations of TxMemory and RxMemory
  val txMemory = Module(new DataMemory(gen, p, p.txMemSize))
  val rxMemory = Module(new DataMemory(gen, p, p.rxMemSize))

  // Counter to send a data as TX
  val counter = RegInit(0.U(10.W))
  val countValue = 10.U * p.frameWidth.asUInt
  when(state === sCrcPassAsTx || state === sCrcFailAsTx){
    counter := 0.U
  }.otherwise{
    counter := counter + 1.U
  }
  // Indicate if this is the first data to send as TX
  val firstTx = RegInit(Bool(), true.B)
  when(state === sCrcPassAsTx || state === sCrcFailAsTx){
    firstTx := false.B
  }.elsewhen(txMemory.io.out.valid && !RegNext(txMemory.io.out.valid)){
    firstTx := true.B
  }

  val txMode = RegInit(Bool(), false.B) // '1' for TX, '0' for RX, default '0'
  when(txMemory.io.out.valid){
    txMode := true.B
  }.elsewhen(ookrx.io.out.valid){
    txMode := false.B
  }

  // TX interfaces
  ooktx.io.preamble <> io.preamble
  ooktx.io.frameIndex <> io.frameIndex
  ooktx.io.divisor <> io.divisor
  io.bitTx := ooktx.io.out
  
  // RX interfaces
  ookrx.io.preamble <> io.preamble
  ookrx.io.divisor <> io.divisor
  ookrx.io.in <> io.bitRx

  // Internal registers

  // sIdle state
  ookrx.io.out.ready := Mux(state === sIdle, true.B, false.B)

  // sRx state
  rxMemory.io.in.bits := ookrx.io.out.bits
  rxMemory.io.in.valid := Mux(state === sRx, true.B, false.B)
  
  // sRead state
  io.out.bits := rxMemory.io.out.bits
  io.out.valid := Mux(state === sRead, true.B, false.B)
  rxMemory.io.out.ready := Mux(state === sRead, true.B, false.B)

  // sTx state
  ooktx.io.in.bits := txMemory.io.out.bits
  ooktx.io.in.valid := Mux(state === sTx, true.B, false.B)
  txMemory.io.out.ready := Mux(state === sTx, true.B, false.B)

  // sLoad state
  //txMemory.io.in.bits := loadDataBuffer
  txMemory.io.in.bits := io.in.bits
  txMemory.io.in.valid := Mux(state === sLoad, true.B, false.B)
  io.in.ready := Mux(state === sLoad, true.B, false.B)

  // CRC hazzards As Rx
  ooktx.io.crcPassAsRx := Mux(state === sCrcPassAsRx, true.B, false.B)
  ooktx.io.crcFailAsRx := Mux(state === sCrcFailAsRx, true.B, false.B)

  // CRC hazzards As Tx
  ooktx.io.resendAsTx := Mux(state === sCrcFailAsTx, true.B, false.B)
  ooktx.io.sendAsTx := Mux(state === sCrcPassAsTx, true.B, false.B)
  
  // Hazzard flags
  val crcPassAsTx = RegInit(Bool(), false.B)
  val crcFailAsTx = RegInit(Bool(), false.B)
  when(ookrx.io.crcPassAsTx || (counter === countValue && firstTx)){
    crcPassAsTx := true.B
  }.elsewhen(state === sCrcPassAsTx){
    crcPassAsTx := false.B
  }
  when(ookrx.io.crcFailAsTx || (counter === countValue && !firstTx)){
    crcFailAsTx := true.B
  }.elsewhen(state === sCrcFailAsTx){
    crcFailAsTx := false.B
  }


  ////////////////////// FSM Implementation ///////////////////////
  switch(state){
    is(sIdle){
      when(crcPassAsTx && txMode){
        state := sCrcPassAsTx
      }.elsewhen(crcFailAsTx && txMode){
        state := sCrcFailAsTx
      }.elsewhen(ookrx.io.out.valid && !txMode){
        when(ookrx.io.crcPass){
          state := sCrcPassAsRx
        }.otherwise{
          state := sCrcFailAsRx
        }
      }.elsewhen(io.out.ready && rxMemory.io.out.valid){
        state := sRead
      }.elsewhen(ooktx.io.in.ready && txMemory.io.out.valid){
        state := sTx
      }.elsewhen(io.in.valid && txMemory.io.in.ready){
        //loadDataBuffer := io.in.bits
        state := sLoad
      }
    }
    is(sRx){
      state := sIdle
    }
    is(sRead){
      state := sIdle
    }
    is(sTx){
      state := sIdle
    }
    is(sLoad){
      state := sIdle
    }
    is(sCrcPassAsRx){
      state := sRx
    }
    is(sCrcFailAsRx){
      state := sIdle
    }
    is(sCrcPassAsTx){
      state := sIdle
    }
    is(sCrcFailAsTx){
      state := sIdle
    }
  }
}

