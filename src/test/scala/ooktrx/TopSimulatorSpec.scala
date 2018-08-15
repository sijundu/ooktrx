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
  var frameNb = 50
  var rxDataCount = 0
  val frameNumber = frameNb

  poke(c.io.frameBits, frameBits)
  poke(c.io.frameIndex, frameIndex)
  poke(c.io.divisor, divisor)

  poke(c.io.rxout.ready, true.B)

  while(numberOfSteps < 200000 && rxDataCount < frameNumber){
    //poke(c.io.in.bits, (((numberOfSteps-startStepNb) << params.dataWidth)+(Random.nextInt(math.pow(2, (params.dataWidth.toLong)).toInt))).asUInt)
    //if(numberOfSteps % 5 == 1 && frameNb >0){
    if(frameNb >0){
      poke(c.io.hostIn.bits, Random.nextInt(math.pow(2, (params.dataWidth)).toInt).asUInt)
      poke(c.io.hostIn.valid, true.B)
      frameNb -= 1
    //}else if((numberOfSteps >= 1100) && (numberOfSteps < 1118)){
    //  poke(c.io.dataIn, Random.nextInt(math.pow(2, (c.frameIndexWidth+c.dataWidth)).toInt).asUInt)
    //  poke(c.io.dataInValid, true.B)
    //  poke(c.io.txStart, true.B)
    //  poke(c.io.frameCount, 18.U)
    }else{
      poke(c.io.hostIn.bits, 0.U(params.dataWidth.W))
      poke(c.io.hostIn.valid, false.B)
    }
    if(Random.nextInt(30).toInt == 1){
      poke(c.io.error, true.B)
    }else{
      poke(c.io.error, false.B)
    }
    if(peek(c.io.rxout.valid) == true){
      rxDataCount += 1
    }
    print(rxDataCount)
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
