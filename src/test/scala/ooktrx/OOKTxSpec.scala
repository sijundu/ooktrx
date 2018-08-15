// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class OOKTxRandomInputTester(val c: OOKTx[UInt]) extends DspTester(c) {

  val params = OokParams
  val preamble = "b1111".asUInt(params.preambleWidth.W)
  val divisor = "b101010101".asUInt(params.divisorWidth.W)
  var frameIndex = "b0001".asUInt(params.frameIndexWidth.W)
  var numberOfSteps = 0
  var randomPreamble = Random.nextInt(2)

  poke(c.io.preamble, preamble)
  poke(c.io.divisor, divisor)

  //poke(c.io.sendEn, true.B)

  while(numberOfSteps < 5000){
    if(numberOfSteps % (params.frameWidth+2) == 0){
      poke(c.io.in.bits, Random.nextInt(math.pow(2, params.dataWidth).toInt).asUInt)
      poke(c.io.frameIndex, frameIndex)
      poke(c.io.in.valid, true.B)
      //frameIndex = frameIndex + 1.U
    }else{
      poke(c.io.in.valid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

/*
class OOKTxFullFrameTester(val c: OOKTx[UInt]) extends DspTester(c) {

  val params = OokParams
  val preamble = "b1111".asUInt(params.preambleWidth.W)
  var numberOfSteps = 0
  var randomPreamble = Random.nextInt(2)

  poke(c.io.preamble, preamble)
  poke(c.io.divisor, "b1101".asUInt(params.divisorWidth.W))

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
*/

class OOKTxSpec extends FreeSpec with Matchers {

  val params = OokParams
  "OOK TX test with random input bits: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new OOKTx(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/OOK_Tx_test_Random_Input"
      )
    ) { c => 
      new OOKTxRandomInputTester(c)
    }
  }

  /*
  "OOK TX test with full valid input frame: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new OOKTx(frameWidth = 20,
                              preambleWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 9,
                              divisorWidth = 4,
                              stackSize =16 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/OOK_Tx_test_Full_Frame"
      )
    ) { c => 
      new OOKTxFullFrameTester(c)
    }
  }
  */
}

