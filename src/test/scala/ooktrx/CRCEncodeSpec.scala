
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class CRCEncodeTester(val c: CRCEncode[UInt]) extends DspTester(c) {
  
  val params = OokParams
  val divisor = "b1101".asUInt(params.divisorWidth.W)
  var numberOfSteps = 0
  var validIn = false.B

  poke(c.io.divisor, divisor)
  poke(c.io.frameBits, "b1111".asUInt(params.frameBitsWidth.W))

  while(numberOfSteps < 2000) {
    if(numberOfSteps%20 == 0){
      poke(c.io.in.bits, Random.nextInt(math.pow(2, params.dataWidth).toInt).asUInt)
      validIn = true.B
    } else{
      validIn = false.B
    }
    poke(c.io.in.valid, validIn)
    step(1)
    numberOfSteps += 1
  }
}

class CRCEncodeSpec extends FreeSpec with Matchers {
  val params = OokParams
  "CRC Encoding first test" in {
    val gen = () => new CRCEncode(
      params.dataType,
      params.ooktrxParams
    )
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/CRC_Encode_Auto_test"
      )
    ) { c =>
      new CRCEncodeTester(c)
    }
  }
}
