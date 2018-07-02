// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// dataWidth: the width of the whole frame, excluding the frame sync head
//            including the information data and extension for CRC

class CRCCheck (val dataWidth: Int,
                val divisorWidth: Int 
                ) extends Module {

  require(divisorWidth > 2, s"Divider bit width must be > 2, got $divisorWidth")

  val io = IO(new Bundle{
    val divisor = Input(UInt(divisorWidth.W))
    val data = Input(UInt(dataWidth.W))
    val dataOk = Output(Bool())
  })

  io.dataOk := io.data % io.divisor === 0.U
}
