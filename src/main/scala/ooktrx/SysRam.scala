// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import chisel3.core.requireIsChiselType

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

class Ram   (val frameWidth: Int,
             val frameBitsWidth: Int,
             val frameIndexWidth: Int,
             val dataWidth: Int,
             val divisorWidth: Int,
             val sysRamSize: Int,
             val sysRamWidth: Int
            ) extends Module{

  require(frameWidth > 19, s"Frame Width must be at least 20, got $frameWidth")
  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")
  require(frameWidth == (frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth -1), s"The total frame width must be legal")

  val io = IO(new Bundle{
    val wrData = Input(UInt(sysRamWidth.W))
    val wrAddr = Input(UInt(log2Ceil(sysRamSize).toInt.W))
    val wrEn = Input(Bool())
    val rdAddr = Input(UInt(log2Ceil(sysRamSize).toInt.W))

    val rdData = Output(UInt(frameWidth.W))
  })


}
