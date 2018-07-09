// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class FrameSendTester(val c: FrameSend) extends DspTester(c) {

  var numberOfSteps = 0

  while(numberOfSteps < 4000){
    if(numberOfSteps % 25 == 0){
      poke(c.io.frameIn, Random.nextInt(math.pow(2, c.frameWidth).toInt).asUInt)
      poke(c.io.frameInValid, true.B)
    }else{
      poke(c.io.frameInValid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

class FrameSendSpec extends FreeSpec with Matchers {
  "First test: with 4-bit frame bits" in{
    val frameWidthNb = 20 
    val gen = () => new FrameSend(frameWidthNb)
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Frame_Send_first_test"
      )
    ) { c => 
      new FrameSendTester(c)
    }
  }
}

