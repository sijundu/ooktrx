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

class TxControlIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt((p.frameIndexWidth + p.dataWidth).W)))
  val out = Output(Bool())
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
  val txEn = Input(Bool())
}

class TxControl[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new TxControlIO(gen, p))

  // Output initilization
  val dataInBuffer = RegInit(0.U((p.frameIndexWidth + p.dataWidth).W))
  

  ///////////////////////////////////////////////////////////////////////////////////
  // Implement data ram to store received data
  // rxMem data structure:
  //    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  //   |           |                                                |
  //         A                             B
  // A: frame index, used to request resending data if crcPass flag is de-asserted. (frameIndexWidth.W)
  // B: information data. (dataWidth.W)
  val txMem = Mem(p.txMemSize, UInt((p.frameIndexWidth + p.dataWidth).W))
  ///////////////////////////////////////////////////////////////////////////////////

  val writeAddr = RegInit(0.U((log2Ceil(p.txMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(p.txMemSize).toInt).W))
  
  // Implementation of OOKRx block
  val ooktx = Module(new OOKTx(gen, p))
  io.out := ooktx.io.out
  ooktx.io.frameBits := io.frameBits
  ooktx.io.divisor := io.divisor
  val dataToSend = RegInit(0.U((p.frameIndexWidth + p.dataWidth).W))
  ooktx.io.in.bits := dataToSend(p.dataWidth-1, 0)
  ooktx.io.frameIndex := dataToSend(p.frameIndexWidth+p.dataWidth-1, p.dataWidth)
  val dataToSendReady = RegInit(Bool(), false.B)
  ooktx.io.in.valid := dataToSendReady
  //val sendEn = RegInit(Bool(),false.B)
  //ooktx.io.sendEn := sendEn


  // Internal registers
  val frameCount = RegInit(0.U((log2Ceil(p.txMemSize).toInt+1).W))
  val memUsage = RegInit(0.U((log2Ceil(p.txMemSize+1).toInt).W))

  // Stat Machine definition
  val sIdle :: sTx :: Nil = Enum(2)
  val state = Reg(init = sIdle)

  io.in.ready := Mux(memUsage < p.txMemSize.asUInt, true.B, false.B)

  
  //////////////////// State machine implementation //////////////////
  switch(state){
    is(sIdle){
      when(io.txEn){
        state := sTx
      }
    }
    is(sTx){
      when(memUsage < p.txMemSize.asUInt){
        when(io.in.valid){
          txMem.write(writeAddr, io.in.bits)
          writeAddr := Mux(writeAddr === (p.txMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          memUsage := memUsage + 1.U
          dataToSendReady := false.B
        }.elsewhen(memUsage > 0.U && ooktx.io.in.ready && !dataToSendReady){
          dataToSend := txMem.read(readAddr)
          dataToSendReady := true.B
          readAddr := Mux(readAddr === (p.txMemSize-1).asUInt, 0.U, readAddr + 1.U)
          memUsage := memUsage - 1.U
        }.otherwise{
          dataToSendReady := false.B
        }
      }.elsewhen(memUsage === p.txMemSize.asUInt){
        when(ooktx.io.in.ready && !dataToSendReady){
          dataToSend := txMem.read(readAddr)
          dataToSendReady := true.B
          readAddr := Mux(readAddr === (p.txMemSize-1).asUInt, 0.U, readAddr + 1.U)
          memUsage := memUsage - 1.U
        }.otherwise{
          dataToSendReady := false.B
        }
      }.otherwise{
        dataToSendReady := false.B
      }
      //when(memUsage == 0.U && !txEn){
      when(!io.txEn){
        dataToSendReady := false.B
        state := sIdle
      }
    }
  }

}
