// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class FrameSendTester(val c: FrameSend[UInt]) extends DspTester(c) {

  val params = OokParams
  var numberOfSteps = 0

  while(numberOfSteps < 4000){
    if(numberOfSteps % 34 == 0){
      poke(c.io.in.bits, Random.nextInt(math.pow(2, params.frameWidth).toInt).asUInt)
      poke(c.io.in.valid, true.B)
    }else{
      poke(c.io.in.valid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

class FrameSendSpec extends FreeSpec with Matchers {
  val params = OokParams
  "First test: with 4-bit frame bits" in{
    val gen = () => new FrameSend(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Frame_Send_test"
      )
    ) { c => 
      new FrameSendTester(c)
    }
  }
}

