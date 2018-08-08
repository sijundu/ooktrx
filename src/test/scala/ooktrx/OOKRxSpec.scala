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
  val frameBits = "b1111".asUInt(params.frameBitsWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, "b11101".asUInt(params.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomFrameBits = Random.nextInt(2)
    poke(c.io.in, randomFrameBits != 0)
    step(1)
    numberOfSteps += 1
  }
}

class OOKRxFullFrameTester(val c: OOKRx[UInt]) extends DspTester(c) {

  val params = OokParams
  val frameBits = "b1111".asUInt(params.frameBitsWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, "b11101".asUInt(params.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomFrameBits = Random.nextInt(2)
    if(numberOfSteps > 10 && numberOfSteps % params.frameWidth < params.frameBitsWidth){
      poke(c.io.in, true.B)
    }else{
      poke(c.io.in, randomFrameBits != 0)
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

