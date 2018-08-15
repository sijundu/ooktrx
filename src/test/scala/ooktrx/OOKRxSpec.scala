// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class OOKRxRandomInputTester(val c: OOKRx[UInt]) extends DspTester(c) {

  val params = OokParams
  val preamble = "b1111".asUInt(params.preambleWidth.W)
  var numberOfSteps = 0
  var randomPreamble = Random.nextInt(2)

  poke(c.io.preamble, preamble)
  poke(c.io.divisor, "b11101".asUInt(params.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomPreamble = Random.nextInt(2)
    poke(c.io.in, randomPreamble != 0)
    step(1)
    numberOfSteps += 1
  }
}

class OOKRxFullFrameTester(val c: OOKRx[UInt]) extends DspTester(c) {

  val params = OokParams
  val preamble = "b1111".asUInt(params.preambleWidth.W)
  var numberOfSteps = 0
  var randomPreamble = Random.nextInt(2)

  poke(c.io.preamble, preamble)
  poke(c.io.divisor, "b11101".asUInt(params.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomPreamble = Random.nextInt(2)
    if(numberOfSteps > 10 && numberOfSteps % params.frameWidth < params.preambleWidth){
      poke(c.io.in, true.B)
    }else{
      poke(c.io.in, randomPreamble != 0)
    }
    step(1)
    numberOfSteps += 1
  }
}

class OOKRxSpec extends FreeSpec with Matchers {
  val params = OokParams

  /*
  "OOK RX test with random input bits: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new OOKRx(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/OOK_Rx_test_Random_Input"
      )
    ) { c => 
      new OOKRxRandomInputTester(c)
    }
  }
  */

  "OOK RX test with full valid input frame: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new OOKRx(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/OOK_Rx_test_Full_Frame"
      )
    ) { c => 
      new OOKRxFullFrameTester(c)
    }
  }
}

