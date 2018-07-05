package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

class CRCCheckTester(val c: CRCCheck) extends DspTester(c) {
  
  val divisor = "b1101".asUInt(c.divisorWidth.W)
  var numberOfSteps = 0
  var validIn = false.B

  poke(c.io.divisor, divisor)

  while(numberOfSteps < 4000) {
    if(numberOfSteps % 20 == 10) {
      poke(c.io.frameIn, Random.nextInt(math.pow(2, c.frameWidth).toInt).asUInt)
      validIn = true.B
    } else{
      validIn = false.B
    }
    poke(c.io.frameValid, validIn)
    step(1)
    numberOfSteps += 1
  }
}

class CRCCheckSpec extends FreeSpec with Matchers {
  "CRC Checking first test" in {
    val frameWidthNb = 20
    val frameIndexWidthNb = 4
    val dataWidthNb = 9  
    val divisorWidthNb = 4
    val gen = () => new CRCCheck(frameWidthNb, frameIndexWidthNb, dataWidthNb, divisorWidthNb)
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/CRC_Check_first_test"
      )
    ) { c =>
      new CRCCheckTester(c)
    }
  }
}

