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
  val mem = SyncReadMem(depth, gen)
  ///////////////////////////////////////////////////////////////////////////////////


  // Internal registers
  val memUsage = RegInit(0.U((log2Ceil(depth).toInt).W))
  val writeAddr = RegInit(0.U((log2Ceil(depth).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(depth).toInt).W))

  io.out.valid := Mux(memUsage === 0.U, false.B, true.B)
  io.out.bits := mem.read(readAddr, true.B)
  io.in.ready := Mux(memUsage === depth.asUInt, false.B, true.B)

  when(io.in.ready){
    when(io.in.valid){
      mem.write(writeAddr, io.in.bits)
      writeAddr := Mux(writeAddr === (depth-1).asUInt, 0.U, writeAddr + 1.U)
      memUsage := memUsage + 1.U
    }.elsewhen(io.out.valid && io.out.ready){
      readAddr := Mux(readAddr === (depth-1).asUInt, 0.U, readAddr + 1.U)
      memUsage := memUsage - 1.U
    }
  }.otherwise{
    when(io.out.ready){
      readAddr := Mux(readAddr === (depth-1).asUInt, 0.U, readAddr + 1.U)
      memUsage := memUsage - 1.U
    }
  }
}
