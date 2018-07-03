
package ooktrx

import dsptools.DspTester
import org.scalatest.{FreeSpec, Matchers}
import chisel3._
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}
import scala.util.Random

class CRCEncodeTester(val c: CRCEncode) extends DspTester(c) {
  
  val divisor = "b1101".asUInt(c.divisorWidth.W)
  var numberOfSteps = 0
  var validIn = false.B

  poke(c.io.divisor, divisor)

  while(numberOfSteps < 2000) {
    if(numberOfSteps%20 == 0){
      poke(c.io.dataIn, Random.nextInt(math.pow(2, c.dataWidth - c.divisorWidth + 1).toInt).asUInt)
      validIn = true.B
    } else{
      validIn = false.B
    }
    poke(c.io.validIn, validIn)
    step(1)
    numberOfSteps += 1
  }
}

class CRCEncodeSpec extends FreeSpec with Matchers {
  "CRC Encoding first test" in {
    val dataWidthNb = 12
    val divisorWidthNb = 4
    val gen = () => new CRCEncode(dataWidthNb, divisorWidthNb)
    dsptools.Driver.execute(
      gen, Array(
        "--backend-name", "verilator",
        "--target-dir", s"test_run_dir/CRC_Encode_Auto_first_test"
      )
    ) { c =>
      new CRCEncodeTester(c)
    }
  }
}
