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

/*
class RxControlIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Input(Bool())
  val out = Valid(UInt((1 + p.frameIndexWidth + p.dataWidth).W))
  val rxEn = Input(Bool())
  val preamble = Input(UInt(p.preambleWidth.W))
  val divisor = Input(UInt(p.divisorWidth.W))
}

class RxControl[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new RxControlIO(gen, p))

  // Output initilization
  //val dataOut = RegInit(0.U((1 + p.frameIndexWidth + p.dataWidth).W))
  //io.out.bits := dataOut
  val dataOutValid = RegInit(Bool(), false.B)
  io.out.valid := dataOutValid


  ///////////////////////////////////////////////////////////////////////////////////
  // Implement data ram to store received data
  // rxMem data structure:
  //    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  //  |  |           |                                                |
  //   A      B                             C
  //   A: crcPass flag (1.W)
  //   B: frame index, used to request resending data if crcPass flag is de-asserted. (frameIndexWidth.W)
  //   C: information data. (dataWidth.W)
  val rxMem = SyncReadMem(p.rxMemSize, UInt((1 + p.frameIndexWidth + p.dataWidth).W))
  ///////////////////////////////////////////////////////////////////////////////////


  val writeAddr = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))

  // Implementation of OOKRx block
  val ookrx = Module(new OOKRx(gen, p))
  ookrx.io.in := Mux(io.rxEn, io.in, false.B)
  ookrx.io.preamble := io.preamble
  ookrx.io.divisor := io.divisor

  //dataOut := rxMem.read(readAddr)
  io.out.bits := rxMem.read(readAddr)

  // Internal registers
  val frameCount = RegInit(0.U((log2Ceil(p.rxMemSize).toInt).W))
  val memUsage = RegInit(0.U((log2Ceil(p.rxMemSize+1).toInt).W))

  // Stat Machine definition
  val sIdle :: sRx :: Nil = Enum(2)
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
          dataOutValid := false.B
          rxMem.write(writeAddr, Cat(ookrx.io.crcPass, ookrx.io.dataOutIndex, ookrx.io.out.bits))
          //rxMem.write(writeAddr, dataToSave)
          writeAddr := Mux(writeAddr === (p.rxMemSize-1).asUInt, 0.U, writeAddr + 1.U)
          memUsage := memUsage + 1.U
        }.elsewhen(memUsage > 0.U){
          //dataOut := rxMem.read(readAddr)
          dataOutValid := true.B
          readAddr := Mux(readAddr === (p.rxMemSize-1).asUInt, 0.U, readAddr + 1.U)
          memUsage := memUsage - 1.U
        }.otherwise{
          dataOutValid := false.B
        }
      }.elsewhen(memUsage === p.rxMemSize.asUInt){
        //dataOut := rxMem.read(readAddr)
        dataOutValid := true.B
        readAddr := Mux(readAddr === (p.rxMemSize-1).asUInt, 0.U, readAddr + 1.U)
        memUsage := memUsage - 1.U
      }.otherwise{
        dataOutValid := false.B
      }
      when(memUsage === 0.U && !io.rxEn){
        state := sIdle
        dataOutValid := false.B
      }
    }
  }
}
*/
