// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class FrameSyncTester(val c: FrameSync[UInt]) extends DspTester(c) {

  val params = OokParams
  val frameBits = "b1111".asUInt(params.ooktrxParams.frameWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  //poke(c.io.frameIndex, "b0011".asUInt(4.W))

  while(numberOfSteps < 1000){
    randomFrameBits = Random.nextInt(2)
    if(numberOfSteps % params.ooktrxParams.frameWidth < params.frameBitsWidth){
      poke(c.io.in, true.B)
    }else{
      poke(c.io.in, randomFrameBits != 0)
    }
    poke(c.io.out.ready, true.B)
    step(1)
    numberOfSteps += 1
  }
}

class FrameSyncSpec extends FreeSpec with Matchers {
  val params = OokParams
  "First test: with 4-bit frame bits" in{
    val gen = () => new FrameSync(
                              params.dataType, 
                              params.ooktrxParams 
                            )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/frame_sync_test"
      )
    ) { c => 
      new FrameSyncTester(c)
    }
  }
}

