// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class TxControlRandomInputTester(val c: TxControl[UInt]) extends DspTester(c) {

  val params = OokParams
  val frameBits = "b1111".asUInt(params.frameBitsWidth.W)
  val divisor = "b101010101".asUInt(params.divisorWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)
  
  poke(c.io.txEn, true.B)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, divisor)

  while(numberOfSteps < 3000){
    if((numberOfSteps >= 100) && (numberOfSteps < 110)){
      poke(c.io.in.bits, Random.nextInt(math.pow(2, (params.frameIndexWidth+params.dataWidth)).toInt).asUInt)
      poke(c.io.in.valid, true.B)
    }else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
      poke(c.io.in.bits, Random.nextInt(math.pow(2, (params.frameIndexWidth+params.dataWidth)).toInt).asUInt)
      poke(c.io.in.valid, true.B)
    }else{
      poke(c.io.in.bits, 0.U(params.dataWidth.W))
      poke(c.io.in.valid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

/*
class TxControlFullFrameTester(val c: TxControl) extends DspTester(c) {

}
*/

class TxControlSpec extends FreeSpec with Matchers {

  val params = OokParams
  "RX Control test with random input bits" in{
    val gen = () => new TxControl(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Tx_Control_test_Random_Input"
      )
    ) { c => 
      new TxControlRandomInputTester(c)
    }
  }

 /*
  "OOK RX test with full valid input frame: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new TxControl(frameWidth = 20,
                              frameBitsWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 9,
                              divisorWidth = 4,
                              stackSize =16 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Tx_Control_test_Full_Frame"
      )
    ) { c => 
      new TxControlFullFrameTester(c)
    }
  }
  */
}

