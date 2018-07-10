// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class TopSimulatorRandomInputTester(val c: TopSimulator) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  val divisor = "b10101".asUInt(c.divisorWidth.W)
  var numberOfSteps = 0
  var startStepNb = 100
  var frameNb = 100

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, divisor)

  while(numberOfSteps < 5000){
    if((numberOfSteps > startStepNb) && (numberOfSteps <= (startStepNb+frameNb))){
      poke(c.io.dataIn, (((numberOfSteps-startStepNb) << c.dataWidth)+(Random.nextInt(math.pow(2, (c.dataWidth.toLong)).toInt))).asUInt)
      //poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toLong).asUInt)
      poke(c.io.dataInValid, true.B)
    //}else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
    //  poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
    //  poke(c.io.dataInValid, true.B)
    //  poke(c.io.txStart, true.B)
    //  poke(c.io.frameCount, 18.U)
    }else{
      poke(c.io.dataIn, 0.U((c.frameIndexWidth + c.dataWidth).W))
      poke(c.io.dataInValid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}


class TopSimulatorSpec extends FreeSpec with Matchers {

  "RX Control test with random input bits" in{
    val gen = () => new TopSimulator(frameWidth = 32,
                              frameBitsWidth = 4,
                              frameIndexWidth = 8,
                              dataWidth = 16,
                              divisorWidth = 5,
                              txStackSize = 64,
                              txMemSize = 128, 
                              rxStackSize = 8,
                              rxMemSize = 128 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/TopSimulator_test_Random_Input"
      )
    ) { c => 
      new TopSimulatorRandomInputTester(c)
    }
  }

}
