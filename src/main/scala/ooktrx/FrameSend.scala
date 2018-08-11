// See README.md for licence details.

package ooktrx

import chisel3._
import chisel3.util._

// Frame example 32-bit in total
//   0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0  0 0 0 0
//  |       A        |    B   |                  C                 |    D  |
//
//  A+B+C+D @frameWidth = 32
//  A       @frameBitsWidth = 8
//  B       @frameIndexWidth = 4
//  C       @dataWidth = 16
//  D       is the CRC residue: @divisorWidth = 5, which is WidthOf(D) + 1
//  Note:   Width of specific sections may vary

class FrameSendIO[T <: Data](gen: T, p: OOKTRXparams) extends Bundle{
  val in = Flipped(Decoupled(UInt(p.frameWidth.W)))
  val frameBits = Input(UInt(p.frameBitsWidth.W))
  val crcPassAsRx = Input(Bool())
  val crcFailAsRx = Input(Bool())
  val sendAsTx = Input(Bool())
  val resendAsTx = Input(Bool())
  val out = Output(Bool())
}

class FrameSend[T <: Data](gen: T, p: OOKTRXparams) extends Module{

  val io = IO(new FrameSendIO(gen, p))

  val sIdle :: sRequest :: sCrcFailAsRx :: sCrcPassAsRx :: sResendAsTx :: sSendAsTx :: sSend :: Nil = Enum(7)
  val state = Reg(init = sIdle)

  val out = RegInit(Bool(), false.B)
  io.out := out

  val resendFrame = Cat(io.frameBits, p.resendFrame)
  val nextFrame = Cat(io.frameBits, p.nextFrame)

  // Hazzard flags
  val crcPassAsRx = RegInit(Bool(), false.B)
  val crcFail = RegInit(Bool(), false.B)
  val resend = RegInit(Bool(), false.B)
  val send = RegInit(Bool(), false.B)
  when(io.crcPassAsRx){
    crcPassAsRx := true.B
  }.elsewhen(state === sCrcPassAsRx){
    crcPassAsRx := false.B
  }
  when(io.crcFailAsRx){
    crcFail := true.B
  }.elsewhen(state === sCrcFailAsRx){
    crcFail := false.B
  }
  when(io.resendAsTx){
    resend := true.B
  }.elsewhen(state === sResendAsTx){
    resend := false.B
  }
  when(io.sendAsTx){
    send := true.B
  }.elsewhen(state === sSendAsTx){
    send := false.B
  }

  val requestFrame = RegInit(Bool(), false.B)
  io.in.ready := requestFrame

  val frameBuffer = RegInit(0.U(p.frameWidth.W))

  val counter = RegInit(0.U(log2Ceil(p.frameWidth+1).toInt.W))

  /////////////////// FSM implementation /////////////////
  switch(state){
    is(sIdle){
      out := false.B
      counter := 0.U
      when(crcFail){
        state := sCrcFailAsRx
      }.elsewhen(crcPassAsRx){
        state := sCrcPassAsRx
      }.elsewhen(resend){
        state := sResendAsTx
      }.elsewhen(send){
        state := sRequest
      //}.otherwise{
      }
    }
    is(sRequest){
      requestFrame := true.B
      state := sSendAsTx
    }
    is(sCrcFailAsRx){
      frameBuffer := resendFrame
      state := sSend
    }
    is(sCrcPassAsRx){
      frameBuffer := nextFrame
      state := sSend
    }
    is(sResendAsTx){
      state := sSend
    }
    is(sSendAsTx){
      when(requestFrame && io.in.valid){
        frameBuffer := io.in.bits
        requestFrame := false.B
        state := sSend
      }
    }
    is(sSend){
      when(counter < p.frameWidth.asUInt){
        out := frameBuffer(p.frameWidth.asUInt - counter - 1.U)
        counter := counter + 1.U
        when(counter === (p.frameWidth-1).asUInt){
          state := sIdle
        }
      }
    }
  }

}
