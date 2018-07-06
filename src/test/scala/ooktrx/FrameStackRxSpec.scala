package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random
import dsptools.numbers._
import chisel3.experimental._

class FrameStackRxTester(val c: FrameStack) extends DspTester(c) {
  
  var numberOfSteps = 0
  var frameValid = false.B
  var request = false.B
  
  while(numberOfSteps < 2000) {
    if(numberOfSteps % 10 == 3) {
      poke(c.io.in, Random.nextInt(math.pow(2, c.frameWidth).toInt).asUInt)
      frameValid = true.B
    } else {
      frameValid = false.B
    }
    if(numberOfSteps % 13 == 4) {
      request = true.B
    }else{
      request = false.B
    }
    poke(c.io.frameValidIn, frameValid)
    poke(c.io.requestIn, request)
    step(1)
    numberOfSteps += 1
  }
}

class FrameStackRxSpec extends FreeSpec with Matchers {
  val frameWidthNb = 20
  val StackSizeNb = 16
  "Frame Stack for Rx first test" in {
    val gen = () => new FrameStack(frameWidth = frameWidthNb, StackSize = StackSizeNb)
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Frame_Stack_Rx_first_test"
      )
    ) { c =>
      new FrameStackRxTester(c)
    }
  }
}


