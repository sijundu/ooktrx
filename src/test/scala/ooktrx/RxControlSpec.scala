// See README.md for license details.
//
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.util._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class RxControlRandomInputTester(val c: RxControl) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  val divisor = "b1101".asUInt(c.divisorWidth.W)
  val frameCount = 10.U((log2Ceil(c.rxMemSize).toInt).W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.rxEn, true.B)
  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, divisor)

  while(numberOfSteps < 5000){
    /*
    if(numberOfSteps % 1000 == 100){
      poke(c.io.rxStart, true.B)
      poke(c.io.frameCount, frameCount)
    //}else if(numberOfSteps % 1000 == 900){
      //poke(c.io.readDataRequest, true.B)
    //  poke(c.io.frameCount, frameCount)
    }else{
      //poke(c.io.readDataRequest, false.B)
      poke(c.io.rxStart, false.B)
      poke(c.io.frameCount, 0.U)
    }
    */
    randomFrameBits = Random.nextInt(2)
    poke(c.io.in, randomFrameBits != 0)
    step(1)
    numberOfSteps += 1
  }
}

/*
class RxControlFullFrameTester(val c: RxControl) extends DspTester(c) {

  val frameBits = "b1111".asUInt(c.frameBitsWidth.W)
  var numberOfSteps = 0
  var randomFrameBits = Random.nextInt(2)

  poke(c.io.frameBits, frameBits)
  poke(c.io.divisor, "b1101".asUInt(c.divisorWidth.W))

  while(numberOfSteps < 5000){
    randomFrameBits = Random.nextInt(2)
    if(numberOfSteps > 10 && numberOfSteps % c.frameWidth < c.frameBitsWidth){
      poke(c.io.in, true.B)
    }else{
      poke(c.io.in, randomFrameBits != 0)
    }
    step(1)
    numberOfSteps += 1
  }
}
*/

class RxControlSpec extends FreeSpec with Matchers {

  "RX Control test with random input bits" in{
    val gen = () => new RxControl(frameWidth = 20,
                              frameBitsWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 9,
                              divisorWidth = 4,
                              rxStackSize =16,
                              rxMemSize = 16 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/Rx_Control_test_Random_Input"
      )
    ) { c => 
      new RxControlRandomInputTester(c)
    }
  }

 /*
  "OOK RX test with full valid input frame: with FrameSync, FrameStackRx and CRC Check" in{
    val gen = () => new RxControl(frameWidth = 20,
                              frameBitsWidth = 4,
                              frameIndexWidth = 4,
                              dataWidth = 9,
                              divisorWidth = 4,
                              stackSize =16 )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/OOK_Rx_test_Full_Frame"
      )
    ) { c => 
      new RxControlFullFrameTester(c)
    }
  }
  */
}

