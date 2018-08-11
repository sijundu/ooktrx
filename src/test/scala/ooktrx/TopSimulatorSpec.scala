// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class TopSimulatorRandomInputTester(val c: TopSimulator[UInt]) extends DspTester(c) {

  val params = OokParams
  val frameBits = "b1111".asUInt(params.frameBitsWidth.W)
  val frameIndex = "b00001111".asUInt(params.frameIndexWidth.W)
  val divisor = "b101010101".asUInt(params.divisorWidth.W)
  var numberOfSteps = 0
  var startStepNb = 100
  var frameNb = 10

  poke(c.io.frameBits, frameBits)
  poke(c.io.frameIndex, frameIndex)
  poke(c.io.divisor, divisor)

  poke(c.io.rxout.ready, true.B)
  /*
  while(numberOfSteps < 5000){
    if((numberOfSteps > startStepNb) && (numberOfSteps <= (startStepNb+frameNb))){
      poke(c.io.in.bits, (((numberOfSteps-startStepNb) << params.dataWidth)+(Random.nextInt(math.pow(2, (params.dataWidth.toLong)).toInt))).asUInt)
      //poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toLong).asUInt)
      poke(c.io.in.valid, true.B)
    //}else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
    //  poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
    //  poke(c.io.dataInValid, true.B)
    //  poke(c.io.txStart, true.B)
    //  poke(c.io.frameCount, 18.U)
    }else{
      poke(c.io.in.bits, 0.U((params.frameIndexWidth + params.dataWidth).W))
      poke(c.io.in.valid, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
  */
  while(numberOfSteps < 8000){
    //poke(c.io.in.bits, (((numberOfSteps-startStepNb) << params.dataWidth)+(Random.nextInt(math.pow(2, (params.dataWidth.toLong)).toInt))).asUInt)
    if(numberOfSteps % 5 == 1 && frameNb >0){
      poke(c.io.txin.bits, Random.nextInt(math.pow(2, (params.dataWidth)).toInt).asUInt)
      poke(c.io.txin.valid, true.B)
      frameNb -= 1
    //}else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
    //  poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
    //  poke(c.io.dataInValid, true.B)
    //  poke(c.io.txStart, true.B)
    //  poke(c.io.frameCount, 18.U)
    }else{
      poke(c.io.txin.bits, 0.U(params.dataWidth.W))
      poke(c.io.txin.valid, false.B)
    }
    if(Random.nextInt(100).toInt == 1){
      poke(c.io.error, true.B)
    }else{
      poke(c.io.error, false.B)
    }
    step(1)
    numberOfSteps += 1
  }
}


class TopSimulatorSpec extends FreeSpec with Matchers {

  val params = OokParams
  "Top Simulator test with random input bits" in{
    val gen = () => new TopSimulator(
      params.dataType,
      params.ooktrxParams
    )
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
