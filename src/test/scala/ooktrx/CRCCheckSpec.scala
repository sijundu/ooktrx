package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

class CRCCheckTester(val c: CRCCheck[UInt]) extends DspTester(c) {
  
  val params = OokParams
  val divisor = "b11101".asUInt(params.divisorWidth.W)
  var numberOfSteps = 0
  var validIn = false.B

  poke(c.io.divisor, divisor)

  while(numberOfSteps < 4000) {
    if(numberOfSteps % 20 == 10) {
      poke(c.io.in.bits, Random.nextInt(math.pow(2, params.frameWidth).toInt).asUInt)
      validIn = true.B
    } else{
      validIn = false.B
    }
    poke(c.io.in.valid, validIn)
    step(1)
    numberOfSteps += 1
  }
}

class CRCCheckSpec extends FreeSpec with Matchers {
  val params = OokParams
  "CRC Checking first test" in {
    val gen = () => new CRCCheck(
      params.dataType,
      params.ooktrxParams
    )
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

