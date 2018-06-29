module FrameSync(
  input        clock,
  input        reset,
  input        io_in,
  input  [3:0] io_frameBits,
  output       io_syncOk
);
  reg [3:0] fifoReg; // @[FrameSync.scala 28:24]
  reg [31:0] _RAND_0;
  wire [4:0] _GEN_1; // @[FrameSync.scala 30:23]
  wire [4:0] _T_13; // @[FrameSync.scala 30:23]
  wire [4:0] _GEN_2; // @[FrameSync.scala 30:29]
  wire [4:0] _T_14; // @[FrameSync.scala 30:29]
  assign _GEN_1 = {{1'd0}, fifoReg}; // @[FrameSync.scala 30:23]
  assign _T_13 = _GEN_1 << 1; // @[FrameSync.scala 30:23]
  assign _GEN_2 = {{4'd0}, io_in}; // @[FrameSync.scala 30:29]
  assign _T_14 = _T_13 | _GEN_2; // @[FrameSync.scala 30:29]
  assign io_syncOk = fifoReg == io_frameBits; // @[FrameSync.scala 33:15 FrameSync.scala 35:15]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{$random}};
  fifoReg = _RAND_0[3:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      fifoReg <= 4'h0;
    end else begin
      fifoReg <= _T_14[3:0];
    end
  end
endmodule
