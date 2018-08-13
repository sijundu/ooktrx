
package ooktrx

import chisel3._
import chisel3.util._
import scala.util.Random

class HostMemIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val hostIn = Flipped(Decoupled(UInt(p.dataWidth.W)))
  val hostOut = Decoupled(UInt(p.dataWidth.W))
}

class HostMem[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new HostMemIO(gen, p))

  val mem = SyncReadMem(p.txMemSize, UInt(p.dataWidth.W))
  val memUsage = RegInit(0.U((log2Ceil(p.txMemSize+1).toInt).W))
  val writeAddr = RegInit(0.U((log2Ceil(p.txMemSize).toInt).W))
  val readAddr = RegInit(0.U((log2Ceil(p.txMemSize).toInt).W))
  io.hostOut.bits := mem.read(readAddr, true.B)
  io.hostOut.valid := Mux((memUsage > 0.U && !io.hostIn.valid), true.B, false.B)
  io.hostIn.ready := true.B
  when(io.hostIn.valid && memUsage < (p.txMemSize-1).asUInt){
    mem.write(writeAddr, io.hostIn.bits)
    writeAddr := Mux(writeAddr === (p.txMemSize-1).asUInt, 0.U, writeAddr + 1.U)
    memUsage := memUsage + 1.U
  }.elsewhen(io.hostOut.ready && (memUsage > 0.U)){
    readAddr := Mux(readAddr === (p.txMemSize-1).asUInt, 0.U, readAddr + 1.U)
    memUsage := memUsage - 1.U
  }

}


