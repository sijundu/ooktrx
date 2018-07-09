// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class OOKTxRandomInputTester(val c: OOKTx) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  val divisor = "b1101".asUInt(c.divisorWidth.W)
  var frameIndex = "b0001".asUInt(c.frameIndexWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, divisor)

  //poke(c.io.sendEn, true.B)

  while(numberOfSteps < 5000){
    if(numberOfSteps % 20 == 0){
      poke(c.io.dataIn, Random.nextInt(math.pow(2, c.dataWidth).toInt).asUInt)
      poke(c.io.frameIndex, frameIndex)
      poke(c.io.dataInValid, true.B)
      //frameIndex = frameIndex + 1.U
    }else{
      poke(c.io.dataInValid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

/*
class OOKTxFullFrameTester(val c: OOKTx) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, "b1101".asUInt(c.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomFrameBits = Random.nextInt(2)
    if(numberOfSteps > 10 && numberOfSteps % c.frameWidth < c.frameBitsWidth){
      poke(c.io.in, true.B)
    }else{
      poke(c.io.in, randomFrameBits != 0)
    }
    step(1)
    numberOfSteps += 1
  }
}
*/

class OOKTxSpec extends FreeSpec with Matchers {

  "OOK TX test with random input bits: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new OOKTx(frameWidth = 20,
                              frameBitsWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 9,
                              divisorWidth = 4,
                              stackSize =16 )
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
                              frameBitsWidth = 4,
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

