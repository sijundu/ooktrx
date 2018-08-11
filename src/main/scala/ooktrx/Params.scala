// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._
import scala.math._

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


case class OOKTRXparams 
(
  frameBitsWidth: Int,
  frameIndexWidth: Int,
  dataWidth: Int,
  divisorWidth: Int
){

  val frameWidth: Int = frameBitsWidth + frameIndexWidth + dataWidth + divisorWidth - 1
  val txStackSize: Int = 100
  val rxStackSize: Int = 2
  //val stackSize: Int = ceil(pow(2, frameIndexWidth)).toInt
  val stackSize: Int = ceil(pow(2, frameIndexWidth)).toInt
  val rxMemSize: Int = 100
  val txMemSize: Int = 100
  val memSize: Int = ceil(pow(2, frameIndexWidth)).toInt
  val resendFrame: UInt = 0.U((frameWidth-frameBitsWidth).W)
  //val nextFrame: UInt = Cat(1.U((frameIndexWidth+dataWidth).W), 1.U((divisorWidth-1).W))
  val nextFrame: UInt = 10.U((frameWidth-frameBitsWidth).W)

  require(frameBitsWidth > 3, s"Frame Bits Width must be at least 4, got $frameBitsWidth")
  //require(frameIndexWidth > 3, s"Frame Index Width must be at least 4, got $frameIndexWidth")
  require(dataWidth > 7, s"Data Width must be at least 8, got $dataWidth")
  require(divisorWidth > 3, s"Divisor Width must be at least 4, got $divisorWidth")

}
