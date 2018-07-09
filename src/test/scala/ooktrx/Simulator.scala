// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class SimulatorRandomInputTester(val c: Simulator) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  val divisor = "b1101".asUInt(c.divisorWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)
  var frameNb = 20

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, divisor)

  while(numberOfSteps < 2000){
    if((numberOfSteps >= 100) && (numberOfSteps < (100+frameNb))){
      poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
      poke(c.io.dataInValid, true.B)
      poke(c.io.txStart, true.B)
      poke(c.io.frameCount, frameNb.U)
    //}else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
    //  poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
    //  poke(c.io.dataInValid, true.B)
    //  poke(c.io.txStart, true.B)
    //  poke(c.io.frameCount, 18.U)
    }else{
      poke(c.io.dataIn, 0.U(c.dataWidth.W))
      poke(c.io.dataInValid, false.B)
      poke(c.io.txStart, false.B)
      poke(c.io.frameCount, 0.U)
    }
    step(1)
    numberOfSteps += 1
  }
}


class SimulatorSpec extends FreeSpec with Matchers {

  "RX Control test with random input bits" in{
    val gen = () => new Simulator(frameWidth = 32,
                              frameBitsWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 16,
                              divisorWidth = 9,
                              txStackSize =16,
                              txMemSize = 32, 
                              rxStackSize =16,
                              rxMemSize = 32 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Simulator_test_Random_Input"
      )
    ) { c => 
      new SimulatorRandomInputTester(c)
    }
  }

}
