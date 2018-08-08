package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random
import dsptools.numbers._
import chisel3.experimental._

object OokParams
{
  val frameBitsWidth: Int = 4
  val frameIndexWidth: Int = 8
  val dataWidth: Int = 16
  val divisorWidth: Int = 9
  val frameWidth: Int = frameBitsWidth+frameIndexWidth+dataWidth+divisorWidth-1
  val dataType = UInt(dataWidth.W)
  val ooktrxParams = new OOKTRXparams(
    frameBitsWidth = frameBitsWidth,
    frameIndexWidth = frameIndexWidth,
    dataWidth = dataWidth,
    divisorWidth = divisorWidth
  )
}
