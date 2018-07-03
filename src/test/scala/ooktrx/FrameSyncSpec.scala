// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class FrameSyncTester(val c: FrameSync) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.frameIndex, "b0011".asUInt(4.W))

  while(numberOfSteps < 1000){
    randomFrameBits = Random.nextInt(2)
    poke(c.io.in, randomFrameBits != 0)
    if(numberOfSteps % 100 < 100){
      poke(c.io.requestFrame, true.B)
    }else{
      poke(c.io.requestFrame, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}

class FrameSyncSpec extends FreeSpec with Matchers {
  "First test: with 4-bit frame bits" in{
    val frameBitsWidthNb = 4
    val frameWidthNb = 20 
    val frameIndexWidthNb = 4
    val gen = () => new FrameSync(frameBitsWidthNb, frameWidthNb, frameIndexWidthNb)
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/frame_sync_first_test"
      )
    ) { c => 
      new FrameSyncTester(c)
    }
  }
}

