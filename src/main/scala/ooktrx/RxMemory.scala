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

/*
class DataMemoryIO[T <: Data](gen: T, p: OOKTRXparams, depth: Int) extends Bundle{
  val in = Flipped(Decoupled(gen))
  val out = Decoupled(gen)
}

class DataMemory[T <: Data](gen: T, p: OOKTRXparams, depth: Int) extends Module{

  val io = IO(new DataMemoryIO(gen, p, depth))

  ///////////////////////////////////////////////////////////////////////////////////
  // Implement data ram to store received data
  // rxMem data structure:
  //    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  //  |  |           |                                                |
  //   A      B                             C
  //   A: crcPass flag (1.W)
  //   B: frame index, used to request resending data if crcPass flag is de-asserted. (frameIndexWidth.W)
  //   C: information data. (dataWidth.W)
  val rxMem = SyncReadMem(depth, gen)
  ///////////////////////////////////////////////////////////////////////////////////

  val writeAddr = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))

  io.out.bits := rxMem.read(readAddr)

  // Internal registers
  val frameCount = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))
  val memUsage = RegInit(0.U((log2Ceil(p.rxMemSize+1).toInt).W))

  // Stat Machine definition
  val sIdle :: sRx :: sRead :: Nil = Enum(3)
  val state = Reg(init = sIdle)

  //val dataToSave = Wire(UInt((1 + p.frameIndexWidth + p.dataWidth).W))
  //dataToSave := Cat(ookrx.io.crcPass, ookrx.io.dataOutIndex, ookrx.io.out.bits)

  //////////////////// State machine implementation //////////////////
  switch(state){
    is(sIdle){
      when(io.rxEn){
        state := sRx
      }
    }
    is(sRx){
      when(memUsage < p.rxMemSize.asUInt){
        when(ookrx.io.out.valid){
          dataOutReady := false.B
          rxMem.write(writeAddr, Cat(ookrx.io.crcPass, ookrx.io.dataOutIndex, ookrx.io.out.bits))
          //rxMem.write(writeAddr, dataToSave)
          writeAddr := Mux(writeAddr === (p.rxMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          memUsage := memUsage + 1.U
        }.elsewhen(memUsage > 0.U){
          //dataOut := rxMem.read(readAddr)
          state := sRead
          //dataOutReady := true.B
          readAddr := Mux(readAddr === (p.rxMemSize-1).asUInt, 0.U, readAddr + 1.U)
          memUsage := memUsage - 1.U
        }.otherwise{
          dataOutReady := false.B
        }
      }.elsewhen(memUsage === p.rxMemSize.asUInt){
        //dataOut := rxMem.read(readAddr)
        state := sRead
        //dataOutReady := true.B
        readAddr := Mux(readAddr === (p.rxMemSize-1).asUInt, 0.U, readAddr + 1.U)
        memUsage := memUsage - 1.U
      }.otherwise{
        dataOutReady := false.B
      }
      when(memUsage === 0.U && !io.rxEn){
        state := sIdle
        dataOutReady := false.B
      }
    }
    is(sRead){
      dataOutReady := true.B
      state := sRx
    }
  }
}
*/
