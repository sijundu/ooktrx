module CRCEncode(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [15:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [35:0] io_out_bits,
  input  [3:0]  io_frameBits,
  input  [7:0]  io_frameIndex,
  input  [8:0]  io_divisor
);
  reg [4:0] counter; // @[CRCEncode.scala 31:24]
  reg [31:0] _RAND_0;
  reg [23:0] dataExtended; // @[CRCEncode.scala 33:29]
  reg [31:0] _RAND_1;
  reg  requestData; // @[CRCEncode.scala 35:28]
  reg [31:0] _RAND_2;
  reg  validOut; // @[CRCEncode.scala 38:25]
  reg [31:0] _RAND_3;
  reg [3:0] frameBitsBuffer; // @[CRCEncode.scala 41:32]
  reg [31:0] _RAND_4;
  reg [7:0] frameIndexBuffer; // @[CRCEncode.scala 42:33]
  reg [31:0] _RAND_5;
  reg [15:0] dataInBuffer; // @[CRCEncode.scala 43:29]
  reg [31:0] _RAND_6;
  reg [35:0] frameOut; // @[CRCEncode.scala 45:25]
  reg [63:0] _RAND_7;
  wire  _T_32; // @[CRCEncode.scala 65:21]
  wire  _T_33; // @[CRCEncode.scala 65:36]
  wire [23:0] _GEN_25; // @[CRCEncode.scala 69:32]
  wire [23:0] _T_34; // @[CRCEncode.scala 69:32]
  wire  _T_39; // @[CRCEncode.scala 73:14]
  wire  _T_41; // @[CRCEncode.scala 73:27]
  wire  _T_42; // @[CRCEncode.scala 73:24]
  wire  _T_45; // @[CRCEncode.scala 74:23]
  wire [7:0] _T_46; // @[CRCEncode.scala 75:84]
  wire [23:0] _T_47; // @[Cat.scala 30:58]
  wire [11:0] _T_48; // @[Cat.scala 30:58]
  wire [35:0] _T_49; // @[Cat.scala 30:58]
  wire [23:0] _GEN_26; // @[CRCEncode.scala 78:29]
  wire  _T_52; // @[CRCEncode.scala 78:29]
  wire [23:0] _GEN_27; // @[CRCEncode.scala 79:72]
  wire [23:0] _T_53; // @[CRCEncode.scala 79:72]
  wire [35:0] _T_55; // @[Cat.scala 30:58]
  wire [5:0] _T_59; // @[CRCEncode.scala 83:26]
  wire [4:0] _T_60; // @[CRCEncode.scala 83:26]
  wire [5:0] _T_64; // @[CRCEncode.scala 85:62]
  wire [5:0] _T_65; // @[CRCEncode.scala 85:62]
  wire [4:0] _T_66; // @[CRCEncode.scala 85:62]
  wire [5:0] _T_67; // @[CRCEncode.scala 85:66]
  wire [5:0] _T_68; // @[CRCEncode.scala 85:66]
  wire [4:0] _T_69; // @[CRCEncode.scala 85:66]
  wire [23:0] _T_70; // @[CRCEncode.scala 85:24]
  wire  _T_71; // @[CRCEncode.scala 85:24]
  wire  _T_75; // @[CRCEncode.scala 86:22]
  wire [8:0] _T_76; // @[CRCEncode.scala 87:44]
  wire [8:0] _T_77; // @[CRCEncode.scala 87:91]
  wire [14:0] _T_78; // @[CRCEncode.scala 87:117]
  wire [23:0] _T_79; // @[Cat.scala 30:58]
  wire [5:0] _T_82; // @[CRCEncode.scala 89:54]
  wire [5:0] _T_83; // @[CRCEncode.scala 89:54]
  wire [4:0] _T_84; // @[CRCEncode.scala 89:54]
  wire [31:0] _T_85; // @[CRCEncode.scala 89:43]
  wire [54:0] _GEN_28; // @[CRCEncode.scala 90:37]
  wire [54:0] _T_86; // @[CRCEncode.scala 90:37]
  wire [23:0] _T_87; // @[CRCEncode.scala 90:47]
  wire [8:0] _T_88; // @[CRCEncode.scala 90:79]
  wire [8:0] _T_89; // @[CRCEncode.scala 90:98]
  wire [5:0] _T_91; // @[CRCEncode.scala 91:61]
  wire [4:0] _T_92; // @[CRCEncode.scala 91:61]
  wire [54:0] _T_93; // @[CRCEncode.scala 91:41]
  wire [23:0] _T_94; // @[CRCEncode.scala 91:71]
  wire [23:0] _T_98; // @[CRCEncode.scala 91:105]
  wire [40:0] _T_99; // @[Cat.scala 30:58]
  wire [5:0] _T_102; // @[CRCEncode.scala 92:87]
  wire [5:0] _T_103; // @[CRCEncode.scala 92:87]
  wire [4:0] _T_104; // @[CRCEncode.scala 92:87]
  wire [5:0] _T_105; // @[CRCEncode.scala 92:109]
  wire [5:0] _T_106; // @[CRCEncode.scala 92:109]
  wire [4:0] _T_107; // @[CRCEncode.scala 92:109]
  wire [71:0] _GEN_30; // @[CRCEncode.scala 92:47]
  wire [71:0] _T_108; // @[CRCEncode.scala 92:47]
  wire [71:0] _GEN_31; // @[CRCEncode.scala 92:119]
  wire [71:0] _T_109; // @[CRCEncode.scala 92:119]
  wire [71:0] _GEN_0; // @[CRCEncode.scala 86:30]
  wire [71:0] _GEN_1; // @[CRCEncode.scala 85:84]
  wire [35:0] _GEN_2; // @[CRCEncode.scala 78:44]
  wire  _GEN_4; // @[CRCEncode.scala 78:44]
  wire [4:0] _GEN_5; // @[CRCEncode.scala 78:44]
  wire [71:0] _GEN_6; // @[CRCEncode.scala 78:44]
  wire [35:0] _GEN_7; // @[CRCEncode.scala 74:53]
  wire  _GEN_8; // @[CRCEncode.scala 74:53]
  wire  _GEN_9; // @[CRCEncode.scala 74:53]
  wire [4:0] _GEN_10; // @[CRCEncode.scala 74:53]
  wire [71:0] _GEN_11; // @[CRCEncode.scala 74:53]
  wire [35:0] _GEN_12; // @[CRCEncode.scala 73:40]
  wire  _GEN_13; // @[CRCEncode.scala 73:40]
  wire  _GEN_14; // @[CRCEncode.scala 73:40]
  wire [4:0] _GEN_15; // @[CRCEncode.scala 73:40]
  wire [71:0] _GEN_16; // @[CRCEncode.scala 73:40]
  wire [3:0] _GEN_17; // @[CRCEncode.scala 65:51]
  wire [7:0] _GEN_18; // @[CRCEncode.scala 65:51]
  wire [15:0] _GEN_19; // @[CRCEncode.scala 65:51]
  wire [71:0] _GEN_20; // @[CRCEncode.scala 65:51]
  wire  _GEN_21; // @[CRCEncode.scala 65:51]
  wire [4:0] _GEN_22; // @[CRCEncode.scala 65:51]
  wire  _GEN_23; // @[CRCEncode.scala 65:51]
  wire [35:0] _GEN_24; // @[CRCEncode.scala 65:51]
  assign _T_32 = io_out_ready & requestData; // @[CRCEncode.scala 65:21]
  assign _T_33 = _T_32 & io_in_valid; // @[CRCEncode.scala 65:36]
  assign _GEN_25 = {{8'd0}, io_in_bits}; // @[CRCEncode.scala 69:32]
  assign _T_34 = _GEN_25 << 8; // @[CRCEncode.scala 69:32]
  assign _T_39 = validOut == 1'h0; // @[CRCEncode.scala 73:14]
  assign _T_41 = requestData == 1'h0; // @[CRCEncode.scala 73:27]
  assign _T_42 = _T_39 & _T_41; // @[CRCEncode.scala 73:24]
  assign _T_45 = dataExtended < 24'h100; // @[CRCEncode.scala 74:23]
  assign _T_46 = dataExtended[7:0]; // @[CRCEncode.scala 75:84]
  assign _T_47 = {dataInBuffer,_T_46}; // @[Cat.scala 30:58]
  assign _T_48 = {frameBitsBuffer,frameIndexBuffer}; // @[Cat.scala 30:58]
  assign _T_49 = {_T_48,_T_47}; // @[Cat.scala 30:58]
  assign _GEN_26 = {{15'd0}, io_divisor}; // @[CRCEncode.scala 78:29]
  assign _T_52 = dataExtended == _GEN_26; // @[CRCEncode.scala 78:29]
  assign _GEN_27 = {{8'd0}, dataInBuffer}; // @[CRCEncode.scala 79:72]
  assign _T_53 = _GEN_27 << 8; // @[CRCEncode.scala 79:72]
  assign _T_55 = {_T_48,_T_53}; // @[Cat.scala 30:58]
  assign _T_59 = counter + 5'h1; // @[CRCEncode.scala 83:26]
  assign _T_60 = _T_59[4:0]; // @[CRCEncode.scala 83:26]
  assign _T_64 = 5'h18 - 5'h1; // @[CRCEncode.scala 85:62]
  assign _T_65 = $unsigned(_T_64); // @[CRCEncode.scala 85:62]
  assign _T_66 = _T_65[4:0]; // @[CRCEncode.scala 85:62]
  assign _T_67 = _T_66 - counter; // @[CRCEncode.scala 85:66]
  assign _T_68 = $unsigned(_T_67); // @[CRCEncode.scala 85:66]
  assign _T_69 = _T_68[4:0]; // @[CRCEncode.scala 85:66]
  assign _T_70 = dataExtended >> _T_69; // @[CRCEncode.scala 85:24]
  assign _T_71 = _T_70[0]; // @[CRCEncode.scala 85:24]
  assign _T_75 = counter == 5'h0; // @[CRCEncode.scala 86:22]
  assign _T_76 = dataExtended[23:15]; // @[CRCEncode.scala 87:44]
  assign _T_77 = _T_76 ^ io_divisor; // @[CRCEncode.scala 87:91]
  assign _T_78 = dataExtended[14:0]; // @[CRCEncode.scala 87:117]
  assign _T_79 = {_T_77,_T_78}; // @[Cat.scala 30:58]
  assign _T_82 = counter - 5'h1; // @[CRCEncode.scala 89:54]
  assign _T_83 = $unsigned(_T_82); // @[CRCEncode.scala 89:54]
  assign _T_84 = _T_83[4:0]; // @[CRCEncode.scala 89:54]
  assign _T_85 = 32'h0 << _T_84; // @[CRCEncode.scala 89:43]
  assign _GEN_28 = {{31'd0}, dataExtended}; // @[CRCEncode.scala 90:37]
  assign _T_86 = _GEN_28 << counter; // @[CRCEncode.scala 90:37]
  assign _T_87 = _T_86[23:0]; // @[CRCEncode.scala 90:47]
  assign _T_88 = _T_87[23:15]; // @[CRCEncode.scala 90:79]
  assign _T_89 = _T_88 ^ io_divisor; // @[CRCEncode.scala 90:98]
  assign _T_91 = 5'h9 + counter; // @[CRCEncode.scala 91:61]
  assign _T_92 = _T_91[4:0]; // @[CRCEncode.scala 91:61]
  assign _T_93 = _GEN_28 << _T_92; // @[CRCEncode.scala 91:41]
  assign _T_94 = _T_93[23:0]; // @[CRCEncode.scala 91:71]
  assign _T_98 = _T_94 >> _T_92; // @[CRCEncode.scala 91:105]
  assign _T_99 = {_T_85,_T_89}; // @[Cat.scala 30:58]
  assign _T_102 = 5'h18 - 5'h9; // @[CRCEncode.scala 92:87]
  assign _T_103 = $unsigned(_T_102); // @[CRCEncode.scala 92:87]
  assign _T_104 = _T_103[4:0]; // @[CRCEncode.scala 92:87]
  assign _T_105 = _T_104 - counter; // @[CRCEncode.scala 92:109]
  assign _T_106 = $unsigned(_T_105); // @[CRCEncode.scala 92:109]
  assign _T_107 = _T_106[4:0]; // @[CRCEncode.scala 92:109]
  assign _GEN_30 = {{31'd0}, _T_99}; // @[CRCEncode.scala 92:47]
  assign _T_108 = _GEN_30 << _T_107; // @[CRCEncode.scala 92:47]
  assign _GEN_31 = {{48'd0}, _T_98}; // @[CRCEncode.scala 92:119]
  assign _T_109 = _T_108 | _GEN_31; // @[CRCEncode.scala 92:119]
  assign _GEN_0 = _T_75 ? {{48'd0}, _T_79} : _T_109; // @[CRCEncode.scala 86:30]
  assign _GEN_1 = _T_71 ? _GEN_0 : {{48'd0}, dataExtended}; // @[CRCEncode.scala 85:84]
  assign _GEN_2 = _T_52 ? _T_55 : frameOut; // @[CRCEncode.scala 78:44]
  assign _GEN_4 = _T_52 ? 1'h1 : requestData; // @[CRCEncode.scala 78:44]
  assign _GEN_5 = _T_52 ? counter : _T_60; // @[CRCEncode.scala 78:44]
  assign _GEN_6 = _T_52 ? {{48'd0}, dataExtended} : _GEN_1; // @[CRCEncode.scala 78:44]
  assign _GEN_7 = _T_45 ? _T_49 : _GEN_2; // @[CRCEncode.scala 74:53]
  assign _GEN_8 = _T_45 ? 1'h1 : _T_52; // @[CRCEncode.scala 74:53]
  assign _GEN_9 = _T_45 ? 1'h1 : _GEN_4; // @[CRCEncode.scala 74:53]
  assign _GEN_10 = _T_45 ? counter : _GEN_5; // @[CRCEncode.scala 74:53]
  assign _GEN_11 = _T_45 ? {{48'd0}, dataExtended} : _GEN_6; // @[CRCEncode.scala 74:53]
  assign _GEN_12 = _T_42 ? _GEN_7 : frameOut; // @[CRCEncode.scala 73:40]
  assign _GEN_13 = _T_42 ? _GEN_8 : 1'h0; // @[CRCEncode.scala 73:40]
  assign _GEN_14 = _T_42 ? _GEN_9 : requestData; // @[CRCEncode.scala 73:40]
  assign _GEN_15 = _T_42 ? _GEN_10 : counter; // @[CRCEncode.scala 73:40]
  assign _GEN_16 = _T_42 ? _GEN_11 : {{48'd0}, dataExtended}; // @[CRCEncode.scala 73:40]
  assign _GEN_17 = _T_33 ? io_frameBits : frameBitsBuffer; // @[CRCEncode.scala 65:51]
  assign _GEN_18 = _T_33 ? io_frameIndex : frameIndexBuffer; // @[CRCEncode.scala 65:51]
  assign _GEN_19 = _T_33 ? io_in_bits : dataInBuffer; // @[CRCEncode.scala 65:51]
  assign _GEN_20 = _T_33 ? {{48'd0}, _T_34} : _GEN_16; // @[CRCEncode.scala 65:51]
  assign _GEN_21 = _T_33 ? 1'h0 : _GEN_14; // @[CRCEncode.scala 65:51]
  assign _GEN_22 = _T_33 ? 5'h0 : _GEN_15; // @[CRCEncode.scala 65:51]
  assign _GEN_23 = _T_33 ? 1'h0 : _GEN_13; // @[CRCEncode.scala 65:51]
  assign _GEN_24 = _T_33 ? frameOut : _GEN_12; // @[CRCEncode.scala 65:51]
  assign io_in_ready = requestData; // @[CRCEncode.scala 36:15]
  assign io_out_valid = validOut; // @[CRCEncode.scala 39:16]
  assign io_out_bits = frameOut; // @[CRCEncode.scala 46:15]
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
  counter = _RAND_0[4:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  dataExtended = _RAND_1[23:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  requestData = _RAND_2[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  validOut = _RAND_3[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  frameBitsBuffer = _RAND_4[3:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  frameIndexBuffer = _RAND_5[7:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  dataInBuffer = _RAND_6[15:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_7 = {2{$random}};
  frameOut = _RAND_7[35:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      counter <= 5'h0;
    end else begin
      if (_T_33) begin
        counter <= 5'h0;
      end else begin
        if (_T_42) begin
          if (!(_T_45)) begin
            if (!(_T_52)) begin
              counter <= _T_60;
            end
          end
        end
      end
    end
    if (reset) begin
      dataExtended <= 24'h0;
    end else begin
      dataExtended <= _GEN_20[23:0];
    end
    if (reset) begin
      requestData <= 1'h1;
    end else begin
      if (_T_33) begin
        requestData <= 1'h0;
      end else begin
        if (_T_42) begin
          if (_T_45) begin
            requestData <= 1'h1;
          end else begin
            if (_T_52) begin
              requestData <= 1'h1;
            end
          end
        end
      end
    end
    if (reset) begin
      validOut <= 1'h0;
    end else begin
      if (_T_33) begin
        validOut <= 1'h0;
      end else begin
        if (_T_42) begin
          if (_T_45) begin
            validOut <= 1'h1;
          end else begin
            validOut <= _T_52;
          end
        end else begin
          validOut <= 1'h0;
        end
      end
    end
    if (reset) begin
      frameBitsBuffer <= 4'h0;
    end else begin
      if (_T_33) begin
        frameBitsBuffer <= io_frameBits;
      end
    end
    if (reset) begin
      frameIndexBuffer <= 8'h0;
    end else begin
      if (_T_33) begin
        frameIndexBuffer <= io_frameIndex;
      end
    end
    if (reset) begin
      dataInBuffer <= 16'h0;
    end else begin
      if (_T_33) begin
        dataInBuffer <= io_in_bits;
      end
    end
    if (reset) begin
      frameOut <= 36'h0;
    end else begin
      if (!(_T_33)) begin
        if (_T_42) begin
          if (_T_45) begin
            frameOut <= _T_49;
          end else begin
            if (_T_52) begin
              frameOut <= _T_55;
            end
          end
        end
      end
    end
  end
endmodule
module FrameStack(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [35:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [35:0] io_out_bits
);
  reg [35:0] stack [0:99]; // @[FrameStack.scala 29:26]
  reg [63:0] _RAND_0;
  wire [35:0] stack__T_29_data; // @[FrameStack.scala 29:26]
  wire [6:0] stack__T_29_addr; // @[FrameStack.scala 29:26]
  reg [63:0] _RAND_1;
  wire [35:0] stack__T_37_data; // @[FrameStack.scala 29:26]
  wire [6:0] stack__T_37_addr; // @[FrameStack.scala 29:26]
  wire  stack__T_37_mask; // @[FrameStack.scala 29:26]
  wire  stack__T_37_en; // @[FrameStack.scala 29:26]
  reg [6:0] readAddr; // @[FrameStack.scala 30:25]
  reg [31:0] _RAND_2;
  reg [6:0] writeAddr; // @[FrameStack.scala 31:26]
  reg [31:0] _RAND_3;
  reg [6:0] stackUsed; // @[FrameStack.scala 32:26]
  reg [31:0] _RAND_4;
  reg [35:0] frameOut; // @[FrameStack.scala 34:25]
  reg [63:0] _RAND_5;
  wire  _GEN_1; // @[FrameStack.scala 35:25]
  reg  frameValidOut; // @[FrameStack.scala 37:30]
  reg [31:0] _RAND_6;
  wire  _T_33; // @[FrameStack.scala 40:30]
  wire  _T_36; // @[FrameStack.scala 42:20]
  wire [7:0] _T_39; // @[FrameStack.scala 44:28]
  wire [6:0] _T_40; // @[FrameStack.scala 44:28]
  wire  _T_43; // @[FrameStack.scala 46:32]
  wire [7:0] _T_46; // @[FrameStack.scala 46:73]
  wire [6:0] _T_47; // @[FrameStack.scala 46:73]
  wire [6:0] _T_48; // @[FrameStack.scala 46:21]
  wire  _T_50; // @[FrameStack.scala 47:30]
  wire  _T_51; // @[FrameStack.scala 47:27]
  wire  _T_53; // @[FrameStack.scala 47:58]
  wire  _T_54; // @[FrameStack.scala 47:45]
  wire [7:0] _T_56; // @[FrameStack.scala 49:28]
  wire [7:0] _T_57; // @[FrameStack.scala 49:28]
  wire [6:0] _T_58; // @[FrameStack.scala 49:28]
  wire  _T_61; // @[FrameStack.scala 51:30]
  wire [7:0] _T_64; // @[FrameStack.scala 51:70]
  wire [6:0] _T_65; // @[FrameStack.scala 51:70]
  wire [6:0] _T_66; // @[FrameStack.scala 51:20]
  wire [6:0] _GEN_4; // @[FrameStack.scala 47:64]
  wire [6:0] _GEN_6; // @[FrameStack.scala 47:64]
  wire [6:0] _GEN_12; // @[FrameStack.scala 42:35]
  wire  _GEN_13; // @[FrameStack.scala 42:35]
  wire [6:0] _GEN_14; // @[FrameStack.scala 42:35]
  wire [6:0] _GEN_15; // @[FrameStack.scala 42:35]
  reg [6:0] stack__T_29_addr_pipe_0;
  reg [31:0] _RAND_7;
  assign stack__T_29_addr = stack__T_29_addr_pipe_0;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign stack__T_29_data = stack[stack__T_29_addr]; // @[FrameStack.scala 29:26]
  `else
  assign stack__T_29_data = stack__T_29_addr >= 7'h64 ? _RAND_1[35:0] : stack[stack__T_29_addr]; // @[FrameStack.scala 29:26]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign stack__T_37_data = io_in_bits;
  assign stack__T_37_addr = writeAddr;
  assign stack__T_37_mask = 1'h1;
  assign stack__T_37_en = io_in_ready & io_in_valid;
  assign _GEN_1 = 1'h1; // @[FrameStack.scala 35:25]
  assign _T_33 = stackUsed == 7'h64; // @[FrameStack.scala 40:30]
  assign _T_36 = io_in_ready & io_in_valid; // @[FrameStack.scala 42:20]
  assign _T_39 = stackUsed + 7'h1; // @[FrameStack.scala 44:28]
  assign _T_40 = _T_39[6:0]; // @[FrameStack.scala 44:28]
  assign _T_43 = writeAddr == 7'h63; // @[FrameStack.scala 46:32]
  assign _T_46 = writeAddr + 7'h1; // @[FrameStack.scala 46:73]
  assign _T_47 = _T_46[6:0]; // @[FrameStack.scala 46:73]
  assign _T_48 = _T_43 ? 7'h0 : _T_47; // @[FrameStack.scala 46:21]
  assign _T_50 = frameValidOut == 1'h0; // @[FrameStack.scala 47:30]
  assign _T_51 = io_out_ready & _T_50; // @[FrameStack.scala 47:27]
  assign _T_53 = stackUsed > 7'h0; // @[FrameStack.scala 47:58]
  assign _T_54 = _T_51 & _T_53; // @[FrameStack.scala 47:45]
  assign _T_56 = stackUsed - 7'h1; // @[FrameStack.scala 49:28]
  assign _T_57 = $unsigned(_T_56); // @[FrameStack.scala 49:28]
  assign _T_58 = _T_57[6:0]; // @[FrameStack.scala 49:28]
  assign _T_61 = readAddr == 7'h63; // @[FrameStack.scala 51:30]
  assign _T_64 = readAddr + 7'h1; // @[FrameStack.scala 51:70]
  assign _T_65 = _T_64[6:0]; // @[FrameStack.scala 51:70]
  assign _T_66 = _T_61 ? 7'h0 : _T_65; // @[FrameStack.scala 51:20]
  assign _GEN_4 = _T_54 ? _T_58 : stackUsed; // @[FrameStack.scala 47:64]
  assign _GEN_6 = _T_54 ? _T_66 : readAddr; // @[FrameStack.scala 47:64]
  assign _GEN_12 = _T_36 ? _T_40 : _GEN_4; // @[FrameStack.scala 42:35]
  assign _GEN_13 = _T_36 ? 1'h0 : _T_54; // @[FrameStack.scala 42:35]
  assign _GEN_14 = _T_36 ? _T_48 : writeAddr; // @[FrameStack.scala 42:35]
  assign _GEN_15 = _T_36 ? readAddr : _GEN_6; // @[FrameStack.scala 42:35]
  assign io_in_ready = _T_33 == 1'h0; // @[FrameStack.scala 40:15]
  assign io_out_valid = frameValidOut; // @[FrameStack.scala 38:16]
  assign io_out_bits = frameOut; // @[FrameStack.scala 36:15]
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
  _RAND_0 = {2{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 100; initvar = initvar+1)
    stack[initvar] = _RAND_0[35:0];
  `endif // RANDOMIZE_MEM_INIT
  _RAND_1 = {2{$random}};
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  readAddr = _RAND_2[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  writeAddr = _RAND_3[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  stackUsed = _RAND_4[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {2{$random}};
  frameOut = _RAND_5[35:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  frameValidOut = _RAND_6[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_7 = {1{$random}};
  stack__T_29_addr_pipe_0 = _RAND_7[6:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(stack__T_37_en & stack__T_37_mask) begin
      stack[stack__T_37_addr] <= stack__T_37_data; // @[FrameStack.scala 29:26]
    end
    if (reset) begin
      readAddr <= 7'h0;
    end else begin
      if (!(_T_36)) begin
        if (_T_54) begin
          if (_T_61) begin
            readAddr <= 7'h0;
          end else begin
            readAddr <= _T_65;
          end
        end
      end
    end
    if (reset) begin
      writeAddr <= 7'h0;
    end else begin
      if (_T_36) begin
        if (_T_43) begin
          writeAddr <= 7'h0;
        end else begin
          writeAddr <= _T_47;
        end
      end
    end
    if (reset) begin
      stackUsed <= 7'h0;
    end else begin
      if (_T_36) begin
        stackUsed <= _T_40;
      end else begin
        if (_T_54) begin
          stackUsed <= _T_58;
        end
      end
    end
    if (reset) begin
      frameOut <= 36'h0;
    end else begin
      frameOut <= stack__T_29_data;
    end
    if (reset) begin
      frameValidOut <= 1'h0;
    end else begin
      if (_T_36) begin
        frameValidOut <= 1'h0;
      end else begin
        frameValidOut <= _T_54;
      end
    end
    if (_GEN_1) begin
      stack__T_29_addr_pipe_0 <= readAddr;
    end
  end
endmodule
module FrameSend(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [35:0] io_in_bits,
  input  [3:0]  io_frameBits,
  input         io_crcPassAsRx,
  input         io_crcFailAsRx,
  input         io_sendAsTx,
  input         io_resendAsTx,
  output        io_out
);
  reg [2:0] state; // @[FrameSend.scala 34:18]
  reg [31:0] _RAND_0;
  reg  out; // @[FrameSend.scala 36:20]
  reg [31:0] _RAND_1;
  wire [35:0] resendFrame; // @[Cat.scala 30:58]
  wire [35:0] nextFrame; // @[Cat.scala 30:58]
  reg  crcPassAsRx; // @[FrameSend.scala 43:28]
  reg [31:0] _RAND_2;
  reg  crcFail; // @[FrameSend.scala 44:24]
  reg [31:0] _RAND_3;
  reg  resend; // @[FrameSend.scala 45:23]
  reg [31:0] _RAND_4;
  reg  send; // @[FrameSend.scala 46:21]
  reg [31:0] _RAND_5;
  wire  _T_28; // @[FrameSend.scala 49:20]
  wire  _GEN_0; // @[FrameSend.scala 49:37]
  wire  _GEN_1; // @[FrameSend.scala 47:23]
  wire  _T_31; // @[FrameSend.scala 54:20]
  wire  _GEN_2; // @[FrameSend.scala 54:37]
  wire  _GEN_3; // @[FrameSend.scala 52:23]
  wire  _T_34; // @[FrameSend.scala 59:20]
  wire  _GEN_4; // @[FrameSend.scala 59:36]
  wire  _GEN_5; // @[FrameSend.scala 57:22]
  wire  _T_37; // @[FrameSend.scala 64:20]
  wire  _GEN_6; // @[FrameSend.scala 64:34]
  wire  _GEN_7; // @[FrameSend.scala 62:20]
  reg  requestFrame; // @[FrameSend.scala 68:29]
  reg [31:0] _RAND_6;
  reg [35:0] frameBuffer; // @[FrameSend.scala 71:28]
  reg [63:0] _RAND_7;
  reg [5:0] counter; // @[FrameSend.scala 73:24]
  reg [31:0] _RAND_8;
  wire  _T_45; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_8; // @[FrameSend.scala 86:23]
  wire [2:0] _GEN_9; // @[FrameSend.scala 84:25]
  wire [2:0] _GEN_10; // @[FrameSend.scala 82:30]
  wire [2:0] _GEN_11; // @[FrameSend.scala 80:20]
  wire  _T_48; // @[Conditional.scala 37:30]
  wire  _T_50; // @[Conditional.scala 37:30]
  wire  _T_51; // @[Conditional.scala 37:30]
  wire  _T_52; // @[Conditional.scala 37:30]
  wire  _T_53; // @[Conditional.scala 37:30]
  wire  _T_54; // @[FrameSend.scala 107:25]
  wire [35:0] _GEN_12; // @[FrameSend.scala 107:40]
  wire  _GEN_13; // @[FrameSend.scala 107:40]
  wire [2:0] _GEN_14; // @[FrameSend.scala 107:40]
  wire  _T_56; // @[Conditional.scala 37:30]
  wire  _T_58; // @[FrameSend.scala 114:20]
  wire [6:0] _T_60; // @[FrameSend.scala 115:48]
  wire [6:0] _T_61; // @[FrameSend.scala 115:48]
  wire [5:0] _T_62; // @[FrameSend.scala 115:48]
  wire [6:0] _T_64; // @[FrameSend.scala 115:58]
  wire [6:0] _T_65; // @[FrameSend.scala 115:58]
  wire [5:0] _T_66; // @[FrameSend.scala 115:58]
  wire [35:0] _T_67; // @[FrameSend.scala 115:27]
  wire  _T_68; // @[FrameSend.scala 115:27]
  wire [6:0] _T_70; // @[FrameSend.scala 116:28]
  wire [5:0] _T_71; // @[FrameSend.scala 116:28]
  wire  _T_73; // @[FrameSend.scala 117:22]
  wire [2:0] _GEN_15; // @[FrameSend.scala 117:50]
  wire  _GEN_16; // @[FrameSend.scala 114:42]
  wire [5:0] _GEN_17; // @[FrameSend.scala 114:42]
  wire [2:0] _GEN_18; // @[FrameSend.scala 114:42]
  wire  _GEN_19; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_20; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_21; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_22; // @[Conditional.scala 39:67]
  wire  _GEN_23; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_24; // @[Conditional.scala 39:67]
  wire  _GEN_25; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_26; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_27; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_28; // @[Conditional.scala 39:67]
  wire  _GEN_29; // @[Conditional.scala 39:67]
  wire  _GEN_30; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_31; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_32; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_33; // @[Conditional.scala 39:67]
  wire  _GEN_34; // @[Conditional.scala 39:67]
  wire  _GEN_35; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_36; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_37; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_38; // @[Conditional.scala 39:67]
  wire  _GEN_39; // @[Conditional.scala 39:67]
  wire  _GEN_40; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_41; // @[Conditional.scala 39:67]
  wire  _GEN_42; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_43; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_44; // @[Conditional.scala 39:67]
  wire  _GEN_45; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_46; // @[Conditional.scala 39:67]
  wire  _GEN_47; // @[Conditional.scala 40:58]
  wire [5:0] _GEN_48; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_49; // @[Conditional.scala 40:58]
  wire  _GEN_50; // @[Conditional.scala 40:58]
  wire [35:0] _GEN_51; // @[Conditional.scala 40:58]
  assign resendFrame = {io_frameBits,32'h0}; // @[Cat.scala 30:58]
  assign nextFrame = {io_frameBits,32'ha}; // @[Cat.scala 30:58]
  assign _T_28 = state == 3'h3; // @[FrameSend.scala 49:20]
  assign _GEN_0 = _T_28 ? 1'h0 : crcPassAsRx; // @[FrameSend.scala 49:37]
  assign _GEN_1 = io_crcPassAsRx ? 1'h1 : _GEN_0; // @[FrameSend.scala 47:23]
  assign _T_31 = state == 3'h2; // @[FrameSend.scala 54:20]
  assign _GEN_2 = _T_31 ? 1'h0 : crcFail; // @[FrameSend.scala 54:37]
  assign _GEN_3 = io_crcFailAsRx ? 1'h1 : _GEN_2; // @[FrameSend.scala 52:23]
  assign _T_34 = state == 3'h4; // @[FrameSend.scala 59:20]
  assign _GEN_4 = _T_34 ? 1'h0 : resend; // @[FrameSend.scala 59:36]
  assign _GEN_5 = io_resendAsTx ? 1'h1 : _GEN_4; // @[FrameSend.scala 57:22]
  assign _T_37 = state == 3'h5; // @[FrameSend.scala 64:20]
  assign _GEN_6 = _T_37 ? 1'h0 : send; // @[FrameSend.scala 64:34]
  assign _GEN_7 = io_sendAsTx ? 1'h1 : _GEN_6; // @[FrameSend.scala 62:20]
  assign _T_45 = 3'h0 == state; // @[Conditional.scala 37:30]
  assign _GEN_8 = send ? 3'h1 : state; // @[FrameSend.scala 86:23]
  assign _GEN_9 = resend ? 3'h4 : _GEN_8; // @[FrameSend.scala 84:25]
  assign _GEN_10 = crcPassAsRx ? 3'h3 : _GEN_9; // @[FrameSend.scala 82:30]
  assign _GEN_11 = crcFail ? 3'h2 : _GEN_10; // @[FrameSend.scala 80:20]
  assign _T_48 = 3'h1 == state; // @[Conditional.scala 37:30]
  assign _T_50 = 3'h2 == state; // @[Conditional.scala 37:30]
  assign _T_51 = 3'h3 == state; // @[Conditional.scala 37:30]
  assign _T_52 = 3'h4 == state; // @[Conditional.scala 37:30]
  assign _T_53 = 3'h5 == state; // @[Conditional.scala 37:30]
  assign _T_54 = requestFrame & io_in_valid; // @[FrameSend.scala 107:25]
  assign _GEN_12 = _T_54 ? io_in_bits : frameBuffer; // @[FrameSend.scala 107:40]
  assign _GEN_13 = _T_54 ? 1'h0 : requestFrame; // @[FrameSend.scala 107:40]
  assign _GEN_14 = _T_54 ? 3'h6 : state; // @[FrameSend.scala 107:40]
  assign _T_56 = 3'h6 == state; // @[Conditional.scala 37:30]
  assign _T_58 = counter < 6'h24; // @[FrameSend.scala 114:20]
  assign _T_60 = 6'h24 - counter; // @[FrameSend.scala 115:48]
  assign _T_61 = $unsigned(_T_60); // @[FrameSend.scala 115:48]
  assign _T_62 = _T_61[5:0]; // @[FrameSend.scala 115:48]
  assign _T_64 = _T_62 - 6'h1; // @[FrameSend.scala 115:58]
  assign _T_65 = $unsigned(_T_64); // @[FrameSend.scala 115:58]
  assign _T_66 = _T_65[5:0]; // @[FrameSend.scala 115:58]
  assign _T_67 = frameBuffer >> _T_66; // @[FrameSend.scala 115:27]
  assign _T_68 = _T_67[0]; // @[FrameSend.scala 115:27]
  assign _T_70 = counter + 6'h1; // @[FrameSend.scala 116:28]
  assign _T_71 = _T_70[5:0]; // @[FrameSend.scala 116:28]
  assign _T_73 = counter == 6'h23; // @[FrameSend.scala 117:22]
  assign _GEN_15 = _T_73 ? 3'h0 : state; // @[FrameSend.scala 117:50]
  assign _GEN_16 = _T_58 ? _T_68 : out; // @[FrameSend.scala 114:42]
  assign _GEN_17 = _T_58 ? _T_71 : counter; // @[FrameSend.scala 114:42]
  assign _GEN_18 = _T_58 ? _GEN_15 : state; // @[FrameSend.scala 114:42]
  assign _GEN_19 = _T_56 ? _GEN_16 : out; // @[Conditional.scala 39:67]
  assign _GEN_20 = _T_56 ? _GEN_17 : counter; // @[Conditional.scala 39:67]
  assign _GEN_21 = _T_56 ? _GEN_18 : state; // @[Conditional.scala 39:67]
  assign _GEN_22 = _T_53 ? _GEN_12 : frameBuffer; // @[Conditional.scala 39:67]
  assign _GEN_23 = _T_53 ? _GEN_13 : requestFrame; // @[Conditional.scala 39:67]
  assign _GEN_24 = _T_53 ? _GEN_14 : _GEN_21; // @[Conditional.scala 39:67]
  assign _GEN_25 = _T_53 ? out : _GEN_19; // @[Conditional.scala 39:67]
  assign _GEN_26 = _T_53 ? counter : _GEN_20; // @[Conditional.scala 39:67]
  assign _GEN_27 = _T_52 ? 3'h6 : _GEN_24; // @[Conditional.scala 39:67]
  assign _GEN_28 = _T_52 ? frameBuffer : _GEN_22; // @[Conditional.scala 39:67]
  assign _GEN_29 = _T_52 ? requestFrame : _GEN_23; // @[Conditional.scala 39:67]
  assign _GEN_30 = _T_52 ? out : _GEN_25; // @[Conditional.scala 39:67]
  assign _GEN_31 = _T_52 ? counter : _GEN_26; // @[Conditional.scala 39:67]
  assign _GEN_32 = _T_51 ? nextFrame : _GEN_28; // @[Conditional.scala 39:67]
  assign _GEN_33 = _T_51 ? 3'h6 : _GEN_27; // @[Conditional.scala 39:67]
  assign _GEN_34 = _T_51 ? requestFrame : _GEN_29; // @[Conditional.scala 39:67]
  assign _GEN_35 = _T_51 ? out : _GEN_30; // @[Conditional.scala 39:67]
  assign _GEN_36 = _T_51 ? counter : _GEN_31; // @[Conditional.scala 39:67]
  assign _GEN_37 = _T_50 ? resendFrame : _GEN_32; // @[Conditional.scala 39:67]
  assign _GEN_38 = _T_50 ? 3'h6 : _GEN_33; // @[Conditional.scala 39:67]
  assign _GEN_39 = _T_50 ? requestFrame : _GEN_34; // @[Conditional.scala 39:67]
  assign _GEN_40 = _T_50 ? out : _GEN_35; // @[Conditional.scala 39:67]
  assign _GEN_41 = _T_50 ? counter : _GEN_36; // @[Conditional.scala 39:67]
  assign _GEN_42 = _T_48 ? 1'h1 : _GEN_39; // @[Conditional.scala 39:67]
  assign _GEN_43 = _T_48 ? 3'h5 : _GEN_38; // @[Conditional.scala 39:67]
  assign _GEN_44 = _T_48 ? frameBuffer : _GEN_37; // @[Conditional.scala 39:67]
  assign _GEN_45 = _T_48 ? out : _GEN_40; // @[Conditional.scala 39:67]
  assign _GEN_46 = _T_48 ? counter : _GEN_41; // @[Conditional.scala 39:67]
  assign _GEN_47 = _T_45 ? 1'h0 : _GEN_45; // @[Conditional.scala 40:58]
  assign _GEN_48 = _T_45 ? 6'h0 : _GEN_46; // @[Conditional.scala 40:58]
  assign _GEN_49 = _T_45 ? _GEN_11 : _GEN_43; // @[Conditional.scala 40:58]
  assign _GEN_50 = _T_45 ? requestFrame : _GEN_42; // @[Conditional.scala 40:58]
  assign _GEN_51 = _T_45 ? frameBuffer : _GEN_44; // @[Conditional.scala 40:58]
  assign io_in_ready = requestFrame; // @[FrameSend.scala 69:15]
  assign io_out = out; // @[FrameSend.scala 37:10]
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
  state = _RAND_0[2:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  out = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  crcPassAsRx = _RAND_2[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  crcFail = _RAND_3[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  resend = _RAND_4[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  send = _RAND_5[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  requestFrame = _RAND_6[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_7 = {2{$random}};
  frameBuffer = _RAND_7[35:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_8 = {1{$random}};
  counter = _RAND_8[5:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      state <= 3'h0;
    end else begin
      if (_T_45) begin
        if (crcFail) begin
          state <= 3'h2;
        end else begin
          if (crcPassAsRx) begin
            state <= 3'h3;
          end else begin
            if (resend) begin
              state <= 3'h4;
            end else begin
              if (send) begin
                state <= 3'h1;
              end
            end
          end
        end
      end else begin
        if (_T_48) begin
          state <= 3'h5;
        end else begin
          if (_T_50) begin
            state <= 3'h6;
          end else begin
            if (_T_51) begin
              state <= 3'h6;
            end else begin
              if (_T_52) begin
                state <= 3'h6;
              end else begin
                if (_T_53) begin
                  if (_T_54) begin
                    state <= 3'h6;
                  end
                end else begin
                  if (_T_56) begin
                    if (_T_58) begin
                      if (_T_73) begin
                        state <= 3'h0;
                      end
                    end
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      out <= 1'h0;
    end else begin
      if (_T_45) begin
        out <= 1'h0;
      end else begin
        if (!(_T_48)) begin
          if (!(_T_50)) begin
            if (!(_T_51)) begin
              if (!(_T_52)) begin
                if (!(_T_53)) begin
                  if (_T_56) begin
                    if (_T_58) begin
                      out <= _T_68;
                    end
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      crcPassAsRx <= 1'h0;
    end else begin
      if (io_crcPassAsRx) begin
        crcPassAsRx <= 1'h1;
      end else begin
        if (_T_28) begin
          crcPassAsRx <= 1'h0;
        end
      end
    end
    if (reset) begin
      crcFail <= 1'h0;
    end else begin
      if (io_crcFailAsRx) begin
        crcFail <= 1'h1;
      end else begin
        if (_T_31) begin
          crcFail <= 1'h0;
        end
      end
    end
    if (reset) begin
      resend <= 1'h0;
    end else begin
      if (io_resendAsTx) begin
        resend <= 1'h1;
      end else begin
        if (_T_34) begin
          resend <= 1'h0;
        end
      end
    end
    if (reset) begin
      send <= 1'h0;
    end else begin
      if (io_sendAsTx) begin
        send <= 1'h1;
      end else begin
        if (_T_37) begin
          send <= 1'h0;
        end
      end
    end
    if (reset) begin
      requestFrame <= 1'h0;
    end else begin
      if (!(_T_45)) begin
        if (_T_48) begin
          requestFrame <= 1'h1;
        end else begin
          if (!(_T_50)) begin
            if (!(_T_51)) begin
              if (!(_T_52)) begin
                if (_T_53) begin
                  if (_T_54) begin
                    requestFrame <= 1'h0;
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      frameBuffer <= 36'h0;
    end else begin
      if (!(_T_45)) begin
        if (!(_T_48)) begin
          if (_T_50) begin
            frameBuffer <= resendFrame;
          end else begin
            if (_T_51) begin
              frameBuffer <= nextFrame;
            end else begin
              if (!(_T_52)) begin
                if (_T_53) begin
                  if (_T_54) begin
                    frameBuffer <= io_in_bits;
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      counter <= 6'h0;
    end else begin
      if (_T_45) begin
        counter <= 6'h0;
      end else begin
        if (!(_T_48)) begin
          if (!(_T_50)) begin
            if (!(_T_51)) begin
              if (!(_T_52)) begin
                if (!(_T_53)) begin
                  if (_T_56) begin
                    if (_T_58) begin
                      counter <= _T_71;
                    end
                  end
                end
              end
            end
          end
        end
      end
    end
  end
endmodule
module OOKTx(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [15:0] io_in_bits,
  output        io_out,
  input  [3:0]  io_frameBits,
  input  [7:0]  io_frameIndex,
  input  [8:0]  io_divisor,
  input         io_crcPassAsRx,
  input         io_crcFailAsRx,
  input         io_resendAsTx,
  input         io_sendAsTx
);
  wire  crcEncode_clock; // @[OOKTx.scala 35:25]
  wire  crcEncode_reset; // @[OOKTx.scala 35:25]
  wire  crcEncode_io_in_ready; // @[OOKTx.scala 35:25]
  wire  crcEncode_io_in_valid; // @[OOKTx.scala 35:25]
  wire [15:0] crcEncode_io_in_bits; // @[OOKTx.scala 35:25]
  wire  crcEncode_io_out_ready; // @[OOKTx.scala 35:25]
  wire  crcEncode_io_out_valid; // @[OOKTx.scala 35:25]
  wire [35:0] crcEncode_io_out_bits; // @[OOKTx.scala 35:25]
  wire [3:0] crcEncode_io_frameBits; // @[OOKTx.scala 35:25]
  wire [7:0] crcEncode_io_frameIndex; // @[OOKTx.scala 35:25]
  wire [8:0] crcEncode_io_divisor; // @[OOKTx.scala 35:25]
  wire  frameStackTx_clock; // @[OOKTx.scala 36:28]
  wire  frameStackTx_reset; // @[OOKTx.scala 36:28]
  wire  frameStackTx_io_in_ready; // @[OOKTx.scala 36:28]
  wire  frameStackTx_io_in_valid; // @[OOKTx.scala 36:28]
  wire [35:0] frameStackTx_io_in_bits; // @[OOKTx.scala 36:28]
  wire  frameStackTx_io_out_ready; // @[OOKTx.scala 36:28]
  wire  frameStackTx_io_out_valid; // @[OOKTx.scala 36:28]
  wire [35:0] frameStackTx_io_out_bits; // @[OOKTx.scala 36:28]
  wire  frameSend_clock; // @[OOKTx.scala 37:25]
  wire  frameSend_reset; // @[OOKTx.scala 37:25]
  wire  frameSend_io_in_ready; // @[OOKTx.scala 37:25]
  wire  frameSend_io_in_valid; // @[OOKTx.scala 37:25]
  wire [35:0] frameSend_io_in_bits; // @[OOKTx.scala 37:25]
  wire [3:0] frameSend_io_frameBits; // @[OOKTx.scala 37:25]
  wire  frameSend_io_crcPassAsRx; // @[OOKTx.scala 37:25]
  wire  frameSend_io_crcFailAsRx; // @[OOKTx.scala 37:25]
  wire  frameSend_io_sendAsTx; // @[OOKTx.scala 37:25]
  wire  frameSend_io_resendAsTx; // @[OOKTx.scala 37:25]
  wire  frameSend_io_out; // @[OOKTx.scala 37:25]
  CRCEncode crcEncode ( // @[OOKTx.scala 35:25]
    .clock(crcEncode_clock),
    .reset(crcEncode_reset),
    .io_in_ready(crcEncode_io_in_ready),
    .io_in_valid(crcEncode_io_in_valid),
    .io_in_bits(crcEncode_io_in_bits),
    .io_out_ready(crcEncode_io_out_ready),
    .io_out_valid(crcEncode_io_out_valid),
    .io_out_bits(crcEncode_io_out_bits),
    .io_frameBits(crcEncode_io_frameBits),
    .io_frameIndex(crcEncode_io_frameIndex),
    .io_divisor(crcEncode_io_divisor)
  );
  FrameStack frameStackTx ( // @[OOKTx.scala 36:28]
    .clock(frameStackTx_clock),
    .reset(frameStackTx_reset),
    .io_in_ready(frameStackTx_io_in_ready),
    .io_in_valid(frameStackTx_io_in_valid),
    .io_in_bits(frameStackTx_io_in_bits),
    .io_out_ready(frameStackTx_io_out_ready),
    .io_out_valid(frameStackTx_io_out_valid),
    .io_out_bits(frameStackTx_io_out_bits)
  );
  FrameSend frameSend ( // @[OOKTx.scala 37:25]
    .clock(frameSend_clock),
    .reset(frameSend_reset),
    .io_in_ready(frameSend_io_in_ready),
    .io_in_valid(frameSend_io_in_valid),
    .io_in_bits(frameSend_io_in_bits),
    .io_frameBits(frameSend_io_frameBits),
    .io_crcPassAsRx(frameSend_io_crcPassAsRx),
    .io_crcFailAsRx(frameSend_io_crcFailAsRx),
    .io_sendAsTx(frameSend_io_sendAsTx),
    .io_resendAsTx(frameSend_io_resendAsTx),
    .io_out(frameSend_io_out)
  );
  assign io_in_ready = crcEncode_io_in_ready; // @[OOKTx.scala 41:19]
  assign io_out = frameSend_io_out; // @[OOKTx.scala 40:10]
  assign crcEncode_clock = clock;
  assign crcEncode_reset = reset;
  assign crcEncode_io_in_valid = io_in_valid; // @[OOKTx.scala 41:19]
  assign crcEncode_io_in_bits = io_in_bits; // @[OOKTx.scala 41:19]
  assign crcEncode_io_out_ready = frameStackTx_io_in_ready; // @[OOKTx.scala 52:20]
  assign crcEncode_io_frameBits = io_frameBits; // @[OOKTx.scala 43:26]
  assign crcEncode_io_frameIndex = io_frameIndex; // @[OOKTx.scala 44:27]
  assign crcEncode_io_divisor = io_divisor; // @[OOKTx.scala 42:24]
  assign frameStackTx_clock = clock;
  assign frameStackTx_reset = reset;
  assign frameStackTx_io_in_valid = crcEncode_io_out_valid; // @[OOKTx.scala 52:20]
  assign frameStackTx_io_in_bits = crcEncode_io_out_bits; // @[OOKTx.scala 52:20]
  assign frameStackTx_io_out_ready = frameSend_io_in_ready; // @[OOKTx.scala 55:23]
  assign frameSend_clock = clock;
  assign frameSend_reset = reset;
  assign frameSend_io_in_valid = frameStackTx_io_out_valid; // @[OOKTx.scala 55:23]
  assign frameSend_io_in_bits = frameStackTx_io_out_bits; // @[OOKTx.scala 55:23]
  assign frameSend_io_frameBits = io_frameBits; // @[OOKTx.scala 45:26]
  assign frameSend_io_crcPassAsRx = io_crcPassAsRx; // @[OOKTx.scala 46:28]
  assign frameSend_io_crcFailAsRx = io_crcFailAsRx; // @[OOKTx.scala 47:28]
  assign frameSend_io_sendAsTx = io_sendAsTx; // @[OOKTx.scala 49:25]
  assign frameSend_io_resendAsTx = io_resendAsTx; // @[OOKTx.scala 48:27]
endmodule
module FrameSync(
  input         clock,
  input         reset,
  input         io_in,
  input  [3:0]  io_frameBits,
  input         io_out_ready,
  output        io_out_valid,
  output [35:0] io_out_bits,
  output        io_crcPass,
  output        io_crcFail
);
  reg [2:0] state; // @[FrameSync.scala 34:18]
  reg [31:0] _RAND_0;
  reg [35:0] wholeFrame; // @[FrameSync.scala 38:27]
  reg [63:0] _RAND_1;
  reg [5:0] bitCounter; // @[FrameSync.scala 41:27]
  reg [31:0] _RAND_2;
  reg [3:0] frameBitsReg; // @[FrameSync.scala 43:29]
  reg [31:0] _RAND_3;
  wire  syncOk; // @[FrameSync.scala 46:27]
  wire [35:0] resendFrame; // @[Cat.scala 30:58]
  wire [35:0] nextFrame; // @[Cat.scala 30:58]
  wire  _T_32; // @[Conditional.scala 37:30]
  wire  _T_34; // @[FrameSync.scala 57:12]
  wire [4:0] _GEN_34; // @[FrameSync.scala 58:40]
  wire [4:0] _T_35; // @[FrameSync.scala 58:40]
  wire [4:0] _GEN_35; // @[FrameSync.scala 58:46]
  wire [4:0] _T_36; // @[FrameSync.scala 58:46]
  wire [6:0] _T_39; // @[FrameSync.scala 61:34]
  wire [5:0] _T_40; // @[FrameSync.scala 61:34]
  wire [4:0] _GEN_36; // @[FrameSync.scala 62:37]
  wire [4:0] _T_41; // @[FrameSync.scala 62:37]
  wire [4:0] _T_42; // @[FrameSync.scala 62:43]
  wire [4:0] _GEN_0; // @[FrameSync.scala 57:20]
  wire [5:0] _GEN_1; // @[FrameSync.scala 57:20]
  wire [35:0] _GEN_2; // @[FrameSync.scala 57:20]
  wire [2:0] _GEN_3; // @[FrameSync.scala 57:20]
  wire  _T_43; // @[Conditional.scala 37:30]
  wire  _T_45; // @[FrameSync.scala 67:23]
  wire [36:0] _GEN_38; // @[FrameSync.scala 69:35]
  wire [36:0] _T_49; // @[FrameSync.scala 69:35]
  wire [36:0] _GEN_39; // @[FrameSync.scala 69:41]
  wire [36:0] _T_50; // @[FrameSync.scala 69:41]
  wire  _T_52; // @[FrameSync.scala 70:29]
  wire  _T_57; // @[FrameSync.scala 73:25]
  wire  _T_58; // @[FrameSync.scala 75:31]
  wire  _T_60; // @[FrameSync.scala 77:31]
  wire [2:0] _GEN_4; // @[FrameSync.scala 77:72]
  wire [2:0] _GEN_5; // @[FrameSync.scala 75:47]
  wire [2:0] _GEN_6; // @[FrameSync.scala 73:39]
  wire [5:0] _GEN_7; // @[FrameSync.scala 70:73]
  wire [3:0] _GEN_8; // @[FrameSync.scala 70:73]
  wire [2:0] _GEN_9; // @[FrameSync.scala 70:73]
  wire [5:0] _GEN_10; // @[FrameSync.scala 67:64]
  wire [36:0] _GEN_11; // @[FrameSync.scala 67:64]
  wire [3:0] _GEN_12; // @[FrameSync.scala 67:64]
  wire [2:0] _GEN_13; // @[FrameSync.scala 67:64]
  wire  _T_61; // @[Conditional.scala 37:30]
  wire [5:0] _GEN_14; // @[FrameSync.scala 83:25]
  wire [35:0] _GEN_15; // @[FrameSync.scala 83:25]
  wire [2:0] _GEN_16; // @[FrameSync.scala 83:25]
  wire  _T_64; // @[Conditional.scala 37:30]
  wire  _T_67; // @[Conditional.scala 37:30]
  wire [5:0] _GEN_17; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_18; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_19; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_20; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_21; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_22; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_23; // @[Conditional.scala 39:67]
  wire [35:0] _GEN_24; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_25; // @[Conditional.scala 39:67]
  wire [5:0] _GEN_26; // @[Conditional.scala 39:67]
  wire [36:0] _GEN_27; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_28; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_29; // @[Conditional.scala 39:67]
  wire [4:0] _GEN_30; // @[Conditional.scala 40:58]
  wire [5:0] _GEN_31; // @[Conditional.scala 40:58]
  wire [36:0] _GEN_32; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_33; // @[Conditional.scala 40:58]
  assign syncOk = frameBitsReg == io_frameBits; // @[FrameSync.scala 46:27]
  assign resendFrame = {io_frameBits,32'h0}; // @[Cat.scala 30:58]
  assign nextFrame = {io_frameBits,32'ha}; // @[Cat.scala 30:58]
  assign _T_32 = 3'h0 == state; // @[Conditional.scala 37:30]
  assign _T_34 = syncOk == 1'h0; // @[FrameSync.scala 57:12]
  assign _GEN_34 = {{1'd0}, frameBitsReg}; // @[FrameSync.scala 58:40]
  assign _T_35 = _GEN_34 << 1; // @[FrameSync.scala 58:40]
  assign _GEN_35 = {{4'd0}, io_in}; // @[FrameSync.scala 58:46]
  assign _T_36 = _T_35 | _GEN_35; // @[FrameSync.scala 58:46]
  assign _T_39 = bitCounter + 6'h1; // @[FrameSync.scala 61:34]
  assign _T_40 = _T_39[5:0]; // @[FrameSync.scala 61:34]
  assign _GEN_36 = {{1'd0}, io_frameBits}; // @[FrameSync.scala 62:37]
  assign _T_41 = _GEN_36 << 1; // @[FrameSync.scala 62:37]
  assign _T_42 = _T_41 | _GEN_35; // @[FrameSync.scala 62:43]
  assign _GEN_0 = _T_34 ? _T_36 : {{1'd0}, frameBitsReg}; // @[FrameSync.scala 57:20]
  assign _GEN_1 = _T_34 ? 6'h0 : _T_40; // @[FrameSync.scala 57:20]
  assign _GEN_2 = _T_34 ? wholeFrame : {{31'd0}, _T_42}; // @[FrameSync.scala 57:20]
  assign _GEN_3 = _T_34 ? state : 3'h1; // @[FrameSync.scala 57:20]
  assign _T_43 = 3'h1 == state; // @[Conditional.scala 37:30]
  assign _T_45 = bitCounter < 6'h20; // @[FrameSync.scala 67:23]
  assign _GEN_38 = {{1'd0}, wholeFrame}; // @[FrameSync.scala 69:35]
  assign _T_49 = _GEN_38 << 1; // @[FrameSync.scala 69:35]
  assign _GEN_39 = {{36'd0}, io_in}; // @[FrameSync.scala 69:41]
  assign _T_50 = _T_49 | _GEN_39; // @[FrameSync.scala 69:41]
  assign _T_52 = bitCounter >= 6'h1f; // @[FrameSync.scala 70:29]
  assign _T_57 = wholeFrame == nextFrame; // @[FrameSync.scala 73:25]
  assign _T_58 = wholeFrame == resendFrame; // @[FrameSync.scala 75:31]
  assign _T_60 = bitCounter > 6'h20; // @[FrameSync.scala 77:31]
  assign _GEN_4 = _T_60 ? 3'h2 : state; // @[FrameSync.scala 77:72]
  assign _GEN_5 = _T_58 ? 3'h3 : _GEN_4; // @[FrameSync.scala 75:47]
  assign _GEN_6 = _T_57 ? 3'h4 : _GEN_5; // @[FrameSync.scala 73:39]
  assign _GEN_7 = _T_52 ? _T_40 : bitCounter; // @[FrameSync.scala 70:73]
  assign _GEN_8 = _T_52 ? 4'h0 : frameBitsReg; // @[FrameSync.scala 70:73]
  assign _GEN_9 = _T_52 ? _GEN_6 : state; // @[FrameSync.scala 70:73]
  assign _GEN_10 = _T_45 ? _T_40 : _GEN_7; // @[FrameSync.scala 67:64]
  assign _GEN_11 = _T_45 ? _T_50 : {{1'd0}, wholeFrame}; // @[FrameSync.scala 67:64]
  assign _GEN_12 = _T_45 ? frameBitsReg : _GEN_8; // @[FrameSync.scala 67:64]
  assign _GEN_13 = _T_45 ? state : _GEN_9; // @[FrameSync.scala 67:64]
  assign _T_61 = 3'h2 == state; // @[Conditional.scala 37:30]
  assign _GEN_14 = io_out_ready ? 6'h0 : bitCounter; // @[FrameSync.scala 83:25]
  assign _GEN_15 = io_out_ready ? 36'h0 : wholeFrame; // @[FrameSync.scala 83:25]
  assign _GEN_16 = io_out_ready ? 3'h0 : state; // @[FrameSync.scala 83:25]
  assign _T_64 = 3'h3 == state; // @[Conditional.scala 37:30]
  assign _T_67 = 3'h4 == state; // @[Conditional.scala 37:30]
  assign _GEN_17 = _T_67 ? 6'h0 : bitCounter; // @[Conditional.scala 39:67]
  assign _GEN_18 = _T_67 ? 36'h0 : wholeFrame; // @[Conditional.scala 39:67]
  assign _GEN_19 = _T_67 ? 3'h0 : state; // @[Conditional.scala 39:67]
  assign _GEN_20 = _T_64 ? 6'h0 : _GEN_17; // @[Conditional.scala 39:67]
  assign _GEN_21 = _T_64 ? 36'h0 : _GEN_18; // @[Conditional.scala 39:67]
  assign _GEN_22 = _T_64 ? 3'h0 : _GEN_19; // @[Conditional.scala 39:67]
  assign _GEN_23 = _T_61 ? _GEN_14 : _GEN_20; // @[Conditional.scala 39:67]
  assign _GEN_24 = _T_61 ? _GEN_15 : _GEN_21; // @[Conditional.scala 39:67]
  assign _GEN_25 = _T_61 ? _GEN_16 : _GEN_22; // @[Conditional.scala 39:67]
  assign _GEN_26 = _T_43 ? _GEN_10 : _GEN_23; // @[Conditional.scala 39:67]
  assign _GEN_27 = _T_43 ? _GEN_11 : {{1'd0}, _GEN_24}; // @[Conditional.scala 39:67]
  assign _GEN_28 = _T_43 ? _GEN_12 : frameBitsReg; // @[Conditional.scala 39:67]
  assign _GEN_29 = _T_43 ? _GEN_13 : _GEN_25; // @[Conditional.scala 39:67]
  assign _GEN_30 = _T_32 ? _GEN_0 : {{1'd0}, _GEN_28}; // @[Conditional.scala 40:58]
  assign _GEN_31 = _T_32 ? _GEN_1 : _GEN_26; // @[Conditional.scala 40:58]
  assign _GEN_32 = _T_32 ? {{1'd0}, _GEN_2} : _GEN_27; // @[Conditional.scala 40:58]
  assign _GEN_33 = _T_32 ? _GEN_3 : _GEN_29; // @[Conditional.scala 40:58]
  assign io_out_valid = state == 3'h2; // @[FrameSync.scala 36:16]
  assign io_out_bits = wholeFrame; // @[FrameSync.scala 39:15]
  assign io_crcPass = state == 3'h4; // @[FrameSync.scala 48:14]
  assign io_crcFail = state == 3'h3; // @[FrameSync.scala 49:14]
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
  state = _RAND_0[2:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {2{$random}};
  wholeFrame = _RAND_1[35:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  bitCounter = _RAND_2[5:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  frameBitsReg = _RAND_3[3:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      state <= 3'h0;
    end else begin
      if (_T_32) begin
        if (!(_T_34)) begin
          state <= 3'h1;
        end
      end else begin
        if (_T_43) begin
          if (!(_T_45)) begin
            if (_T_52) begin
              if (_T_57) begin
                state <= 3'h4;
              end else begin
                if (_T_58) begin
                  state <= 3'h3;
                end else begin
                  if (_T_60) begin
                    state <= 3'h2;
                  end
                end
              end
            end
          end
        end else begin
          if (_T_61) begin
            if (io_out_ready) begin
              state <= 3'h0;
            end
          end else begin
            if (_T_64) begin
              state <= 3'h0;
            end else begin
              if (_T_67) begin
                state <= 3'h0;
              end
            end
          end
        end
      end
    end
    if (reset) begin
      wholeFrame <= 36'h0;
    end else begin
      wholeFrame <= _GEN_32[35:0];
    end
    if (reset) begin
      bitCounter <= 6'h0;
    end else begin
      if (_T_32) begin
        if (_T_34) begin
          bitCounter <= 6'h0;
        end else begin
          bitCounter <= _T_40;
        end
      end else begin
        if (_T_43) begin
          if (_T_45) begin
            bitCounter <= _T_40;
          end else begin
            if (_T_52) begin
              bitCounter <= _T_40;
            end
          end
        end else begin
          if (_T_61) begin
            if (io_out_ready) begin
              bitCounter <= 6'h0;
            end
          end else begin
            if (_T_64) begin
              bitCounter <= 6'h0;
            end else begin
              if (_T_67) begin
                bitCounter <= 6'h0;
              end
            end
          end
        end
      end
    end
    if (reset) begin
      frameBitsReg <= 4'h0;
    end else begin
      frameBitsReg <= _GEN_30[3:0];
    end
  end
endmodule
module FrameStack_1(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [35:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [35:0] io_out_bits
);
  reg [35:0] stack [0:1]; // @[FrameStack.scala 29:26]
  reg [63:0] _RAND_0;
  wire [35:0] stack__T_29_data; // @[FrameStack.scala 29:26]
  wire  stack__T_29_addr; // @[FrameStack.scala 29:26]
  wire [35:0] stack__T_37_data; // @[FrameStack.scala 29:26]
  wire  stack__T_37_addr; // @[FrameStack.scala 29:26]
  wire  stack__T_37_mask; // @[FrameStack.scala 29:26]
  wire  stack__T_37_en; // @[FrameStack.scala 29:26]
  reg  readAddr; // @[FrameStack.scala 30:25]
  reg [31:0] _RAND_1;
  reg  writeAddr; // @[FrameStack.scala 31:26]
  reg [31:0] _RAND_2;
  reg [1:0] stackUsed; // @[FrameStack.scala 32:26]
  reg [31:0] _RAND_3;
  reg [35:0] frameOut; // @[FrameStack.scala 34:25]
  reg [63:0] _RAND_4;
  wire  _GEN_1; // @[FrameStack.scala 35:25]
  reg  frameValidOut; // @[FrameStack.scala 37:30]
  reg [31:0] _RAND_5;
  wire  _T_33; // @[FrameStack.scala 40:30]
  wire  _T_36; // @[FrameStack.scala 42:20]
  wire [2:0] _T_39; // @[FrameStack.scala 44:28]
  wire [1:0] _T_40; // @[FrameStack.scala 44:28]
  wire [1:0] _T_46; // @[FrameStack.scala 46:73]
  wire  _T_47; // @[FrameStack.scala 46:73]
  wire  _T_48; // @[FrameStack.scala 46:21]
  wire  _T_50; // @[FrameStack.scala 47:30]
  wire  _T_51; // @[FrameStack.scala 47:27]
  wire  _T_53; // @[FrameStack.scala 47:58]
  wire  _T_54; // @[FrameStack.scala 47:45]
  wire [2:0] _T_56; // @[FrameStack.scala 49:28]
  wire [2:0] _T_57; // @[FrameStack.scala 49:28]
  wire [1:0] _T_58; // @[FrameStack.scala 49:28]
  wire [1:0] _T_64; // @[FrameStack.scala 51:70]
  wire  _T_65; // @[FrameStack.scala 51:70]
  wire  _T_66; // @[FrameStack.scala 51:20]
  wire [1:0] _GEN_4; // @[FrameStack.scala 47:64]
  wire  _GEN_6; // @[FrameStack.scala 47:64]
  wire [1:0] _GEN_12; // @[FrameStack.scala 42:35]
  wire  _GEN_13; // @[FrameStack.scala 42:35]
  wire  _GEN_14; // @[FrameStack.scala 42:35]
  wire  _GEN_15; // @[FrameStack.scala 42:35]
  reg  stack__T_29_addr_pipe_0;
  reg [31:0] _RAND_6;
  assign stack__T_29_addr = stack__T_29_addr_pipe_0;
  assign stack__T_29_data = stack[stack__T_29_addr]; // @[FrameStack.scala 29:26]
  assign stack__T_37_data = io_in_bits;
  assign stack__T_37_addr = writeAddr;
  assign stack__T_37_mask = 1'h1;
  assign stack__T_37_en = io_in_ready & io_in_valid;
  assign _GEN_1 = 1'h1; // @[FrameStack.scala 35:25]
  assign _T_33 = stackUsed == 2'h2; // @[FrameStack.scala 40:30]
  assign _T_36 = io_in_ready & io_in_valid; // @[FrameStack.scala 42:20]
  assign _T_39 = stackUsed + 2'h1; // @[FrameStack.scala 44:28]
  assign _T_40 = _T_39[1:0]; // @[FrameStack.scala 44:28]
  assign _T_46 = writeAddr + 1'h1; // @[FrameStack.scala 46:73]
  assign _T_47 = _T_46[0:0]; // @[FrameStack.scala 46:73]
  assign _T_48 = writeAddr ? 1'h0 : _T_47; // @[FrameStack.scala 46:21]
  assign _T_50 = frameValidOut == 1'h0; // @[FrameStack.scala 47:30]
  assign _T_51 = io_out_ready & _T_50; // @[FrameStack.scala 47:27]
  assign _T_53 = stackUsed > 2'h0; // @[FrameStack.scala 47:58]
  assign _T_54 = _T_51 & _T_53; // @[FrameStack.scala 47:45]
  assign _T_56 = stackUsed - 2'h1; // @[FrameStack.scala 49:28]
  assign _T_57 = $unsigned(_T_56); // @[FrameStack.scala 49:28]
  assign _T_58 = _T_57[1:0]; // @[FrameStack.scala 49:28]
  assign _T_64 = readAddr + 1'h1; // @[FrameStack.scala 51:70]
  assign _T_65 = _T_64[0:0]; // @[FrameStack.scala 51:70]
  assign _T_66 = readAddr ? 1'h0 : _T_65; // @[FrameStack.scala 51:20]
  assign _GEN_4 = _T_54 ? _T_58 : stackUsed; // @[FrameStack.scala 47:64]
  assign _GEN_6 = _T_54 ? _T_66 : readAddr; // @[FrameStack.scala 47:64]
  assign _GEN_12 = _T_36 ? _T_40 : _GEN_4; // @[FrameStack.scala 42:35]
  assign _GEN_13 = _T_36 ? 1'h0 : _T_54; // @[FrameStack.scala 42:35]
  assign _GEN_14 = _T_36 ? _T_48 : writeAddr; // @[FrameStack.scala 42:35]
  assign _GEN_15 = _T_36 ? readAddr : _GEN_6; // @[FrameStack.scala 42:35]
  assign io_in_ready = _T_33 == 1'h0; // @[FrameStack.scala 40:15]
  assign io_out_valid = frameValidOut; // @[FrameStack.scala 38:16]
  assign io_out_bits = frameOut; // @[FrameStack.scala 36:15]
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
  _RAND_0 = {2{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 2; initvar = initvar+1)
    stack[initvar] = _RAND_0[35:0];
  `endif // RANDOMIZE_MEM_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  readAddr = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  writeAddr = _RAND_2[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  stackUsed = _RAND_3[1:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {2{$random}};
  frameOut = _RAND_4[35:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  frameValidOut = _RAND_5[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  stack__T_29_addr_pipe_0 = _RAND_6[0:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(stack__T_37_en & stack__T_37_mask) begin
      stack[stack__T_37_addr] <= stack__T_37_data; // @[FrameStack.scala 29:26]
    end
    if (reset) begin
      readAddr <= 1'h0;
    end else begin
      if (!(_T_36)) begin
        if (_T_54) begin
          if (readAddr) begin
            readAddr <= 1'h0;
          end else begin
            readAddr <= _T_65;
          end
        end
      end
    end
    if (reset) begin
      writeAddr <= 1'h0;
    end else begin
      if (_T_36) begin
        if (writeAddr) begin
          writeAddr <= 1'h0;
        end else begin
          writeAddr <= _T_47;
        end
      end
    end
    if (reset) begin
      stackUsed <= 2'h0;
    end else begin
      if (_T_36) begin
        stackUsed <= _T_40;
      end else begin
        if (_T_54) begin
          stackUsed <= _T_58;
        end
      end
    end
    if (reset) begin
      frameOut <= 36'h0;
    end else begin
      frameOut <= stack__T_29_data;
    end
    if (reset) begin
      frameValidOut <= 1'h0;
    end else begin
      if (_T_36) begin
        frameValidOut <= 1'h0;
      end else begin
        frameValidOut <= _T_54;
      end
    end
    if (_GEN_1) begin
      stack__T_29_addr_pipe_0 <= readAddr;
    end
  end
endmodule
module CRCCheck(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [35:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [15:0] io_out_bits,
  input  [8:0]  io_divisor,
  output        io_crcPass
);
  reg  dataOutValid; // @[CRCCheck.scala 31:29]
  reg [31:0] _RAND_0;
  reg  crcPass; // @[CRCCheck.scala 34:24]
  reg [31:0] _RAND_1;
  reg  requestFrame; // @[CRCCheck.scala 37:29]
  reg [31:0] _RAND_2;
  reg [35:0] frameIn; // @[CRCCheck.scala 42:24]
  reg [63:0] _RAND_3;
  reg [23:0] dataCal; // @[CRCCheck.scala 46:24]
  reg [31:0] _RAND_4;
  reg [4:0] counter; // @[CRCCheck.scala 48:24]
  reg [31:0] _RAND_5;
  reg [1:0] state; // @[CRCCheck.scala 52:18]
  reg [31:0] _RAND_6;
  wire  _T_32; // @[Conditional.scala 37:30]
  wire [23:0] _T_36; // @[CRCCheck.scala 63:30]
  wire  _GEN_0; // @[CRCCheck.scala 60:24]
  wire [35:0] _GEN_1; // @[CRCCheck.scala 60:24]
  wire [23:0] _GEN_2; // @[CRCCheck.scala 60:24]
  wire [4:0] _GEN_4; // @[CRCCheck.scala 60:24]
  wire [1:0] _GEN_5; // @[CRCCheck.scala 60:24]
  wire  _T_40; // @[Conditional.scala 37:30]
  wire  _T_42; // @[CRCCheck.scala 73:21]
  wire [23:0] _GEN_33; // @[CRCCheck.scala 73:39]
  wire  _T_43; // @[CRCCheck.scala 73:39]
  wire  _T_44; // @[CRCCheck.scala 73:29]
  wire  _T_46; // @[CRCCheck.scala 76:26]
  wire [5:0] _T_49; // @[CRCCheck.scala 80:28]
  wire [4:0] _T_50; // @[CRCCheck.scala 80:28]
  wire [5:0] _T_53; // @[CRCCheck.scala 81:59]
  wire [5:0] _T_54; // @[CRCCheck.scala 81:59]
  wire [4:0] _T_55; // @[CRCCheck.scala 81:59]
  wire [5:0] _T_56; // @[CRCCheck.scala 81:63]
  wire [5:0] _T_57; // @[CRCCheck.scala 81:63]
  wire [4:0] _T_58; // @[CRCCheck.scala 81:63]
  wire [23:0] _T_59; // @[CRCCheck.scala 81:21]
  wire  _T_60; // @[CRCCheck.scala 81:21]
  wire  _T_64; // @[CRCCheck.scala 82:24]
  wire [8:0] _T_65; // @[CRCCheck.scala 83:36]
  wire [8:0] _T_66; // @[CRCCheck.scala 83:83]
  wire [14:0] _T_67; // @[CRCCheck.scala 83:104]
  wire [23:0] _T_68; // @[Cat.scala 30:58]
  wire [5:0] _T_71; // @[CRCCheck.scala 85:56]
  wire [5:0] _T_72; // @[CRCCheck.scala 85:56]
  wire [4:0] _T_73; // @[CRCCheck.scala 85:56]
  wire [31:0] _T_74; // @[CRCCheck.scala 85:45]
  wire [54:0] _GEN_35; // @[CRCCheck.scala 86:34]
  wire [54:0] _T_75; // @[CRCCheck.scala 86:34]
  wire [23:0] _T_76; // @[CRCCheck.scala 86:44]
  wire [8:0] _T_77; // @[CRCCheck.scala 86:76]
  wire [8:0] _T_78; // @[CRCCheck.scala 86:95]
  wire [5:0] _T_80; // @[CRCCheck.scala 87:58]
  wire [4:0] _T_81; // @[CRCCheck.scala 87:58]
  wire [54:0] _T_82; // @[CRCCheck.scala 87:38]
  wire [23:0] _T_83; // @[CRCCheck.scala 87:68]
  wire [23:0] _T_87; // @[CRCCheck.scala 87:102]
  wire [40:0] _T_88; // @[Cat.scala 30:58]
  wire [5:0] _T_91; // @[CRCCheck.scala 88:84]
  wire [5:0] _T_92; // @[CRCCheck.scala 88:84]
  wire [4:0] _T_93; // @[CRCCheck.scala 88:84]
  wire [5:0] _T_94; // @[CRCCheck.scala 88:106]
  wire [5:0] _T_95; // @[CRCCheck.scala 88:106]
  wire [4:0] _T_96; // @[CRCCheck.scala 88:106]
  wire [71:0] _GEN_37; // @[CRCCheck.scala 88:44]
  wire [71:0] _T_97; // @[CRCCheck.scala 88:44]
  wire [71:0] _GEN_38; // @[CRCCheck.scala 88:116]
  wire [71:0] _T_98; // @[CRCCheck.scala 88:116]
  wire [71:0] _GEN_6; // @[CRCCheck.scala 82:32]
  wire [71:0] _GEN_7; // @[CRCCheck.scala 81:81]
  wire  _GEN_8; // @[CRCCheck.scala 76:39]
  wire [1:0] _GEN_9; // @[CRCCheck.scala 76:39]
  wire [4:0] _GEN_10; // @[CRCCheck.scala 76:39]
  wire [71:0] _GEN_11; // @[CRCCheck.scala 76:39]
  wire  _GEN_12; // @[CRCCheck.scala 73:55]
  wire [1:0] _GEN_13; // @[CRCCheck.scala 73:55]
  wire [4:0] _GEN_14; // @[CRCCheck.scala 73:55]
  wire [71:0] _GEN_15; // @[CRCCheck.scala 73:55]
  wire  _T_99; // @[Conditional.scala 37:30]
  wire  _T_101; // @[CRCCheck.scala 95:28]
  wire  _T_102; // @[CRCCheck.scala 95:25]
  wire  _GEN_16; // @[CRCCheck.scala 95:42]
  wire [1:0] _GEN_17; // @[CRCCheck.scala 95:42]
  wire  _GEN_18; // @[Conditional.scala 39:67]
  wire [1:0] _GEN_19; // @[Conditional.scala 39:67]
  wire  _GEN_20; // @[Conditional.scala 39:67]
  wire [1:0] _GEN_21; // @[Conditional.scala 39:67]
  wire [4:0] _GEN_22; // @[Conditional.scala 39:67]
  wire [71:0] _GEN_23; // @[Conditional.scala 39:67]
  wire  _GEN_24; // @[Conditional.scala 39:67]
  wire  _GEN_25; // @[Conditional.scala 40:58]
  wire  _GEN_26; // @[Conditional.scala 40:58]
  wire [35:0] _GEN_27; // @[Conditional.scala 40:58]
  wire [71:0] _GEN_28; // @[Conditional.scala 40:58]
  wire [4:0] _GEN_30; // @[Conditional.scala 40:58]
  wire [1:0] _GEN_31; // @[Conditional.scala 40:58]
  wire  _GEN_32; // @[Conditional.scala 40:58]
  assign _T_32 = 2'h0 == state; // @[Conditional.scala 37:30]
  assign _T_36 = io_in_bits[23:0]; // @[CRCCheck.scala 63:30]
  assign _GEN_0 = io_in_valid ? 1'h0 : 1'h1; // @[CRCCheck.scala 60:24]
  assign _GEN_1 = io_in_valid ? io_in_bits : frameIn; // @[CRCCheck.scala 60:24]
  assign _GEN_2 = io_in_valid ? _T_36 : dataCal; // @[CRCCheck.scala 60:24]
  assign _GEN_4 = io_in_valid ? 5'h0 : counter; // @[CRCCheck.scala 60:24]
  assign _GEN_5 = io_in_valid ? 2'h1 : state; // @[CRCCheck.scala 60:24]
  assign _T_40 = 2'h1 == state; // @[Conditional.scala 37:30]
  assign _T_42 = dataCal == 24'h0; // @[CRCCheck.scala 73:21]
  assign _GEN_33 = {{15'd0}, io_divisor}; // @[CRCCheck.scala 73:39]
  assign _T_43 = dataCal == _GEN_33; // @[CRCCheck.scala 73:39]
  assign _T_44 = _T_42 | _T_43; // @[CRCCheck.scala 73:29]
  assign _T_46 = dataCal < _GEN_33; // @[CRCCheck.scala 76:26]
  assign _T_49 = counter + 5'h1; // @[CRCCheck.scala 80:28]
  assign _T_50 = _T_49[4:0]; // @[CRCCheck.scala 80:28]
  assign _T_53 = 5'h18 - 5'h1; // @[CRCCheck.scala 81:59]
  assign _T_54 = $unsigned(_T_53); // @[CRCCheck.scala 81:59]
  assign _T_55 = _T_54[4:0]; // @[CRCCheck.scala 81:59]
  assign _T_56 = _T_55 - counter; // @[CRCCheck.scala 81:63]
  assign _T_57 = $unsigned(_T_56); // @[CRCCheck.scala 81:63]
  assign _T_58 = _T_57[4:0]; // @[CRCCheck.scala 81:63]
  assign _T_59 = dataCal >> _T_58; // @[CRCCheck.scala 81:21]
  assign _T_60 = _T_59[0]; // @[CRCCheck.scala 81:21]
  assign _T_64 = counter == 5'h0; // @[CRCCheck.scala 82:24]
  assign _T_65 = dataCal[23:15]; // @[CRCCheck.scala 83:36]
  assign _T_66 = _T_65 ^ io_divisor; // @[CRCCheck.scala 83:83]
  assign _T_67 = dataCal[14:0]; // @[CRCCheck.scala 83:104]
  assign _T_68 = {_T_66,_T_67}; // @[Cat.scala 30:58]
  assign _T_71 = counter - 5'h1; // @[CRCCheck.scala 85:56]
  assign _T_72 = $unsigned(_T_71); // @[CRCCheck.scala 85:56]
  assign _T_73 = _T_72[4:0]; // @[CRCCheck.scala 85:56]
  assign _T_74 = 32'h0 << _T_73; // @[CRCCheck.scala 85:45]
  assign _GEN_35 = {{31'd0}, dataCal}; // @[CRCCheck.scala 86:34]
  assign _T_75 = _GEN_35 << counter; // @[CRCCheck.scala 86:34]
  assign _T_76 = _T_75[23:0]; // @[CRCCheck.scala 86:44]
  assign _T_77 = _T_76[23:15]; // @[CRCCheck.scala 86:76]
  assign _T_78 = _T_77 ^ io_divisor; // @[CRCCheck.scala 86:95]
  assign _T_80 = 5'h9 + counter; // @[CRCCheck.scala 87:58]
  assign _T_81 = _T_80[4:0]; // @[CRCCheck.scala 87:58]
  assign _T_82 = _GEN_35 << _T_81; // @[CRCCheck.scala 87:38]
  assign _T_83 = _T_82[23:0]; // @[CRCCheck.scala 87:68]
  assign _T_87 = _T_83 >> _T_81; // @[CRCCheck.scala 87:102]
  assign _T_88 = {_T_74,_T_78}; // @[Cat.scala 30:58]
  assign _T_91 = 5'h18 - 5'h9; // @[CRCCheck.scala 88:84]
  assign _T_92 = $unsigned(_T_91); // @[CRCCheck.scala 88:84]
  assign _T_93 = _T_92[4:0]; // @[CRCCheck.scala 88:84]
  assign _T_94 = _T_93 - counter; // @[CRCCheck.scala 88:106]
  assign _T_95 = $unsigned(_T_94); // @[CRCCheck.scala 88:106]
  assign _T_96 = _T_95[4:0]; // @[CRCCheck.scala 88:106]
  assign _GEN_37 = {{31'd0}, _T_88}; // @[CRCCheck.scala 88:44]
  assign _T_97 = _GEN_37 << _T_96; // @[CRCCheck.scala 88:44]
  assign _GEN_38 = {{48'd0}, _T_87}; // @[CRCCheck.scala 88:116]
  assign _T_98 = _T_97 | _GEN_38; // @[CRCCheck.scala 88:116]
  assign _GEN_6 = _T_64 ? {{48'd0}, _T_68} : _T_98; // @[CRCCheck.scala 82:32]
  assign _GEN_7 = _T_60 ? _GEN_6 : {{48'd0}, dataCal}; // @[CRCCheck.scala 81:81]
  assign _GEN_8 = _T_46 ? 1'h0 : crcPass; // @[CRCCheck.scala 76:39]
  assign _GEN_9 = _T_46 ? 2'h2 : state; // @[CRCCheck.scala 76:39]
  assign _GEN_10 = _T_46 ? counter : _T_50; // @[CRCCheck.scala 76:39]
  assign _GEN_11 = _T_46 ? {{48'd0}, dataCal} : _GEN_7; // @[CRCCheck.scala 76:39]
  assign _GEN_12 = _T_44 ? 1'h1 : _GEN_8; // @[CRCCheck.scala 73:55]
  assign _GEN_13 = _T_44 ? 2'h2 : _GEN_9; // @[CRCCheck.scala 73:55]
  assign _GEN_14 = _T_44 ? counter : _GEN_10; // @[CRCCheck.scala 73:55]
  assign _GEN_15 = _T_44 ? {{48'd0}, dataCal} : _GEN_11; // @[CRCCheck.scala 73:55]
  assign _T_99 = 2'h2 == state; // @[Conditional.scala 37:30]
  assign _T_101 = dataOutValid == 1'h0; // @[CRCCheck.scala 95:28]
  assign _T_102 = io_out_ready & _T_101; // @[CRCCheck.scala 95:25]
  assign _GEN_16 = _T_102 ? 1'h1 : dataOutValid; // @[CRCCheck.scala 95:42]
  assign _GEN_17 = _T_102 ? 2'h0 : state; // @[CRCCheck.scala 95:42]
  assign _GEN_18 = _T_99 ? _GEN_16 : dataOutValid; // @[Conditional.scala 39:67]
  assign _GEN_19 = _T_99 ? _GEN_17 : state; // @[Conditional.scala 39:67]
  assign _GEN_20 = _T_40 ? _GEN_12 : crcPass; // @[Conditional.scala 39:67]
  assign _GEN_21 = _T_40 ? _GEN_13 : _GEN_19; // @[Conditional.scala 39:67]
  assign _GEN_22 = _T_40 ? _GEN_14 : counter; // @[Conditional.scala 39:67]
  assign _GEN_23 = _T_40 ? _GEN_15 : {{48'd0}, dataCal}; // @[Conditional.scala 39:67]
  assign _GEN_24 = _T_40 ? dataOutValid : _GEN_18; // @[Conditional.scala 39:67]
  assign _GEN_25 = _T_32 ? 1'h0 : _GEN_24; // @[Conditional.scala 40:58]
  assign _GEN_26 = _T_32 ? _GEN_0 : requestFrame; // @[Conditional.scala 40:58]
  assign _GEN_27 = _T_32 ? _GEN_1 : frameIn; // @[Conditional.scala 40:58]
  assign _GEN_28 = _T_32 ? {{48'd0}, _GEN_2} : _GEN_23; // @[Conditional.scala 40:58]
  assign _GEN_30 = _T_32 ? _GEN_4 : _GEN_22; // @[Conditional.scala 40:58]
  assign _GEN_31 = _T_32 ? _GEN_5 : _GEN_21; // @[Conditional.scala 40:58]
  assign _GEN_32 = _T_32 ? crcPass : _GEN_20; // @[Conditional.scala 40:58]
  assign io_in_ready = requestFrame; // @[CRCCheck.scala 38:15]
  assign io_out_valid = dataOutValid; // @[CRCCheck.scala 32:16]
  assign io_out_bits = frameIn[23:8]; // @[CRCCheck.scala 43:15]
  assign io_crcPass = crcPass; // @[CRCCheck.scala 35:14]
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
  dataOutValid = _RAND_0[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  crcPass = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  requestFrame = _RAND_2[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {2{$random}};
  frameIn = _RAND_3[35:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  dataCal = _RAND_4[23:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  counter = _RAND_5[4:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  state = _RAND_6[1:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      dataOutValid <= 1'h0;
    end else begin
      if (_T_32) begin
        dataOutValid <= 1'h0;
      end else begin
        if (!(_T_40)) begin
          if (_T_99) begin
            if (_T_102) begin
              dataOutValid <= 1'h1;
            end
          end
        end
      end
    end
    if (reset) begin
      crcPass <= 1'h0;
    end else begin
      if (!(_T_32)) begin
        if (_T_40) begin
          if (_T_44) begin
            crcPass <= 1'h1;
          end else begin
            if (_T_46) begin
              crcPass <= 1'h0;
            end
          end
        end
      end
    end
    if (reset) begin
      requestFrame <= 1'h0;
    end else begin
      if (_T_32) begin
        if (io_in_valid) begin
          requestFrame <= 1'h0;
        end else begin
          requestFrame <= 1'h1;
        end
      end
    end
    if (reset) begin
      frameIn <= 36'h0;
    end else begin
      if (_T_32) begin
        if (io_in_valid) begin
          frameIn <= io_in_bits;
        end
      end
    end
    if (reset) begin
      dataCal <= 24'h0;
    end else begin
      dataCal <= _GEN_28[23:0];
    end
    if (reset) begin
      counter <= 5'h0;
    end else begin
      if (_T_32) begin
        if (io_in_valid) begin
          counter <= 5'h0;
        end
      end else begin
        if (_T_40) begin
          if (!(_T_44)) begin
            if (!(_T_46)) begin
              counter <= _T_50;
            end
          end
        end
      end
    end
    if (reset) begin
      state <= 2'h0;
    end else begin
      if (_T_32) begin
        if (io_in_valid) begin
          state <= 2'h1;
        end
      end else begin
        if (_T_40) begin
          if (_T_44) begin
            state <= 2'h2;
          end else begin
            if (_T_46) begin
              state <= 2'h2;
            end
          end
        end else begin
          if (_T_99) begin
            if (_T_102) begin
              state <= 2'h0;
            end
          end
        end
      end
    end
  end
endmodule
module OOKRx(
  input         clock,
  input         reset,
  input         io_in,
  input  [3:0]  io_frameBits,
  input  [8:0]  io_divisor,
  input         io_out_ready,
  output        io_out_valid,
  output [15:0] io_out_bits,
  output        io_crcPass,
  output        io_crcPassAsTx,
  output        io_crcFailAsTx
);
  wire  frameSync_clock; // @[OOKRx.scala 34:25]
  wire  frameSync_reset; // @[OOKRx.scala 34:25]
  wire  frameSync_io_in; // @[OOKRx.scala 34:25]
  wire [3:0] frameSync_io_frameBits; // @[OOKRx.scala 34:25]
  wire  frameSync_io_out_ready; // @[OOKRx.scala 34:25]
  wire  frameSync_io_out_valid; // @[OOKRx.scala 34:25]
  wire [35:0] frameSync_io_out_bits; // @[OOKRx.scala 34:25]
  wire  frameSync_io_crcPass; // @[OOKRx.scala 34:25]
  wire  frameSync_io_crcFail; // @[OOKRx.scala 34:25]
  wire  frameStackRx_clock; // @[OOKRx.scala 35:28]
  wire  frameStackRx_reset; // @[OOKRx.scala 35:28]
  wire  frameStackRx_io_in_ready; // @[OOKRx.scala 35:28]
  wire  frameStackRx_io_in_valid; // @[OOKRx.scala 35:28]
  wire [35:0] frameStackRx_io_in_bits; // @[OOKRx.scala 35:28]
  wire  frameStackRx_io_out_ready; // @[OOKRx.scala 35:28]
  wire  frameStackRx_io_out_valid; // @[OOKRx.scala 35:28]
  wire [35:0] frameStackRx_io_out_bits; // @[OOKRx.scala 35:28]
  wire  crcCheck_clock; // @[OOKRx.scala 36:24]
  wire  crcCheck_reset; // @[OOKRx.scala 36:24]
  wire  crcCheck_io_in_ready; // @[OOKRx.scala 36:24]
  wire  crcCheck_io_in_valid; // @[OOKRx.scala 36:24]
  wire [35:0] crcCheck_io_in_bits; // @[OOKRx.scala 36:24]
  wire  crcCheck_io_out_ready; // @[OOKRx.scala 36:24]
  wire  crcCheck_io_out_valid; // @[OOKRx.scala 36:24]
  wire [15:0] crcCheck_io_out_bits; // @[OOKRx.scala 36:24]
  wire [8:0] crcCheck_io_divisor; // @[OOKRx.scala 36:24]
  wire  crcCheck_io_crcPass; // @[OOKRx.scala 36:24]
  FrameSync frameSync ( // @[OOKRx.scala 34:25]
    .clock(frameSync_clock),
    .reset(frameSync_reset),
    .io_in(frameSync_io_in),
    .io_frameBits(frameSync_io_frameBits),
    .io_out_ready(frameSync_io_out_ready),
    .io_out_valid(frameSync_io_out_valid),
    .io_out_bits(frameSync_io_out_bits),
    .io_crcPass(frameSync_io_crcPass),
    .io_crcFail(frameSync_io_crcFail)
  );
  FrameStack_1 frameStackRx ( // @[OOKRx.scala 35:28]
    .clock(frameStackRx_clock),
    .reset(frameStackRx_reset),
    .io_in_ready(frameStackRx_io_in_ready),
    .io_in_valid(frameStackRx_io_in_valid),
    .io_in_bits(frameStackRx_io_in_bits),
    .io_out_ready(frameStackRx_io_out_ready),
    .io_out_valid(frameStackRx_io_out_valid),
    .io_out_bits(frameStackRx_io_out_bits)
  );
  CRCCheck crcCheck ( // @[OOKRx.scala 36:24]
    .clock(crcCheck_clock),
    .reset(crcCheck_reset),
    .io_in_ready(crcCheck_io_in_ready),
    .io_in_valid(crcCheck_io_in_valid),
    .io_in_bits(crcCheck_io_in_bits),
    .io_out_ready(crcCheck_io_out_ready),
    .io_out_valid(crcCheck_io_out_valid),
    .io_out_bits(crcCheck_io_out_bits),
    .io_divisor(crcCheck_io_divisor),
    .io_crcPass(crcCheck_io_crcPass)
  );
  assign io_out_valid = crcCheck_io_out_valid; // @[OOKRx.scala 42:10]
  assign io_out_bits = crcCheck_io_out_bits; // @[OOKRx.scala 42:10]
  assign io_crcPass = crcCheck_io_crcPass; // @[OOKRx.scala 44:14]
  assign io_crcPassAsTx = frameSync_io_crcPass; // @[OOKRx.scala 45:18]
  assign io_crcFailAsTx = frameSync_io_crcFail; // @[OOKRx.scala 46:18]
  assign frameSync_clock = clock;
  assign frameSync_reset = reset;
  assign frameSync_io_in = io_in; // @[OOKRx.scala 39:19]
  assign frameSync_io_frameBits = io_frameBits; // @[OOKRx.scala 40:26]
  assign frameSync_io_out_ready = frameStackRx_io_in_ready; // @[OOKRx.scala 49:20]
  assign frameStackRx_clock = clock;
  assign frameStackRx_reset = reset;
  assign frameStackRx_io_in_valid = frameSync_io_out_valid; // @[OOKRx.scala 49:20]
  assign frameStackRx_io_in_bits = frameSync_io_out_bits; // @[OOKRx.scala 49:20]
  assign frameStackRx_io_out_ready = crcCheck_io_in_ready; // @[OOKRx.scala 52:23]
  assign crcCheck_clock = clock;
  assign crcCheck_reset = reset;
  assign crcCheck_io_in_valid = frameStackRx_io_out_valid; // @[OOKRx.scala 52:23]
  assign crcCheck_io_in_bits = frameStackRx_io_out_bits; // @[OOKRx.scala 52:23]
  assign crcCheck_io_out_ready = io_out_ready; // @[OOKRx.scala 42:10]
  assign crcCheck_io_divisor = io_divisor; // @[OOKRx.scala 41:23]
endmodule
module DataMemory(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [15:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [15:0] io_out_bits
);
  reg [15:0] mem [0:99]; // @[DataMemory.scala 37:24]
  reg [31:0] _RAND_0;
  wire [15:0] mem__T_29_data; // @[DataMemory.scala 37:24]
  wire [6:0] mem__T_29_addr; // @[DataMemory.scala 37:24]
  reg [31:0] _RAND_1;
  wire [15:0] mem__T_35_data; // @[DataMemory.scala 37:24]
  wire [6:0] mem__T_35_addr; // @[DataMemory.scala 37:24]
  wire  mem__T_35_mask; // @[DataMemory.scala 37:24]
  wire  mem__T_35_en; // @[DataMemory.scala 37:24]
  reg [6:0] memUsage; // @[DataMemory.scala 42:25]
  reg [31:0] _RAND_2;
  reg [6:0] writeAddr; // @[DataMemory.scala 43:26]
  reg [31:0] _RAND_3;
  reg [6:0] readAddr; // @[DataMemory.scala 44:25]
  reg [31:0] _RAND_4;
  wire  _T_19; // @[DataMemory.scala 46:32]
  wire  _GEN_1; // @[DataMemory.scala 47:26]
  wire  _T_31; // @[DataMemory.scala 48:31]
  wire  _T_37; // @[DataMemory.scala 53:34]
  wire [7:0] _T_40; // @[DataMemory.scala 53:71]
  wire [6:0] _T_41; // @[DataMemory.scala 53:71]
  wire [6:0] _T_42; // @[DataMemory.scala 53:23]
  wire [7:0] _T_44; // @[DataMemory.scala 54:28]
  wire [6:0] _T_45; // @[DataMemory.scala 54:28]
  wire  _T_46; // @[DataMemory.scala 55:29]
  wire  _T_48; // @[DataMemory.scala 56:32]
  wire [7:0] _T_51; // @[DataMemory.scala 56:68]
  wire [6:0] _T_52; // @[DataMemory.scala 56:68]
  wire [6:0] _T_53; // @[DataMemory.scala 56:22]
  wire [7:0] _T_55; // @[DataMemory.scala 57:28]
  wire [7:0] _T_56; // @[DataMemory.scala 57:28]
  wire [6:0] _T_57; // @[DataMemory.scala 57:28]
  wire [6:0] _GEN_4; // @[DataMemory.scala 55:45]
  wire [6:0] _GEN_5; // @[DataMemory.scala 55:45]
  wire [6:0] _GEN_11; // @[DataMemory.scala 51:22]
  wire [6:0] _GEN_12; // @[DataMemory.scala 51:22]
  wire [6:0] _GEN_13; // @[DataMemory.scala 51:22]
  wire [6:0] _GEN_14; // @[DataMemory.scala 60:23]
  wire [6:0] _GEN_15; // @[DataMemory.scala 60:23]
  wire [6:0] _GEN_21; // @[DataMemory.scala 50:20]
  wire [6:0] _GEN_22; // @[DataMemory.scala 50:20]
  wire [6:0] _GEN_23; // @[DataMemory.scala 50:20]
  reg [6:0] mem__T_29_addr_pipe_0;
  reg [31:0] _RAND_5;
  assign mem__T_29_addr = mem__T_29_addr_pipe_0;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign mem__T_29_data = mem[mem__T_29_addr]; // @[DataMemory.scala 37:24]
  `else
  assign mem__T_29_data = mem__T_29_addr >= 7'h64 ? _RAND_1[15:0] : mem[mem__T_29_addr]; // @[DataMemory.scala 37:24]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign mem__T_35_data = io_in_bits;
  assign mem__T_35_addr = writeAddr;
  assign mem__T_35_mask = 1'h1;
  assign mem__T_35_en = io_in_ready ? io_in_valid : 1'h0;
  assign _T_19 = memUsage == 7'h0; // @[DataMemory.scala 46:32]
  assign _GEN_1 = 1'h1; // @[DataMemory.scala 47:26]
  assign _T_31 = memUsage == 7'h64; // @[DataMemory.scala 48:31]
  assign _T_37 = writeAddr == 7'h63; // @[DataMemory.scala 53:34]
  assign _T_40 = writeAddr + 7'h1; // @[DataMemory.scala 53:71]
  assign _T_41 = _T_40[6:0]; // @[DataMemory.scala 53:71]
  assign _T_42 = _T_37 ? 7'h0 : _T_41; // @[DataMemory.scala 53:23]
  assign _T_44 = memUsage + 7'h1; // @[DataMemory.scala 54:28]
  assign _T_45 = _T_44[6:0]; // @[DataMemory.scala 54:28]
  assign _T_46 = io_out_valid & io_out_ready; // @[DataMemory.scala 55:29]
  assign _T_48 = readAddr == 7'h63; // @[DataMemory.scala 56:32]
  assign _T_51 = readAddr + 7'h1; // @[DataMemory.scala 56:68]
  assign _T_52 = _T_51[6:0]; // @[DataMemory.scala 56:68]
  assign _T_53 = _T_48 ? 7'h0 : _T_52; // @[DataMemory.scala 56:22]
  assign _T_55 = memUsage - 7'h1; // @[DataMemory.scala 57:28]
  assign _T_56 = $unsigned(_T_55); // @[DataMemory.scala 57:28]
  assign _T_57 = _T_56[6:0]; // @[DataMemory.scala 57:28]
  assign _GEN_4 = _T_46 ? _T_53 : readAddr; // @[DataMemory.scala 55:45]
  assign _GEN_5 = _T_46 ? _T_57 : memUsage; // @[DataMemory.scala 55:45]
  assign _GEN_11 = io_in_valid ? _T_42 : writeAddr; // @[DataMemory.scala 51:22]
  assign _GEN_12 = io_in_valid ? _T_45 : _GEN_5; // @[DataMemory.scala 51:22]
  assign _GEN_13 = io_in_valid ? readAddr : _GEN_4; // @[DataMemory.scala 51:22]
  assign _GEN_14 = io_out_ready ? _T_53 : readAddr; // @[DataMemory.scala 60:23]
  assign _GEN_15 = io_out_ready ? _T_57 : memUsage; // @[DataMemory.scala 60:23]
  assign _GEN_21 = io_in_ready ? _GEN_11 : writeAddr; // @[DataMemory.scala 50:20]
  assign _GEN_22 = io_in_ready ? _GEN_12 : _GEN_15; // @[DataMemory.scala 50:20]
  assign _GEN_23 = io_in_ready ? _GEN_13 : _GEN_14; // @[DataMemory.scala 50:20]
  assign io_in_ready = _T_31 ? 1'h0 : 1'h1; // @[DataMemory.scala 48:15]
  assign io_out_valid = _T_19 ? 1'h0 : 1'h1; // @[DataMemory.scala 46:16]
  assign io_out_bits = mem__T_29_data; // @[DataMemory.scala 47:15]
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
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 100; initvar = initvar+1)
    mem[initvar] = _RAND_0[15:0];
  `endif // RANDOMIZE_MEM_INIT
  _RAND_1 = {1{$random}};
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  memUsage = _RAND_2[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  writeAddr = _RAND_3[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  readAddr = _RAND_4[6:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  mem__T_29_addr_pipe_0 = _RAND_5[6:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(mem__T_35_en & mem__T_35_mask) begin
      mem[mem__T_35_addr] <= mem__T_35_data; // @[DataMemory.scala 37:24]
    end
    if (reset) begin
      memUsage <= 7'h0;
    end else begin
      if (io_in_ready) begin
        if (io_in_valid) begin
          memUsage <= _T_45;
        end else begin
          if (_T_46) begin
            memUsage <= _T_57;
          end
        end
      end else begin
        if (io_out_ready) begin
          memUsage <= _T_57;
        end
      end
    end
    if (reset) begin
      writeAddr <= 7'h0;
    end else begin
      if (io_in_ready) begin
        if (io_in_valid) begin
          if (_T_37) begin
            writeAddr <= 7'h0;
          end else begin
            writeAddr <= _T_41;
          end
        end
      end
    end
    if (reset) begin
      readAddr <= 7'h0;
    end else begin
      if (io_in_ready) begin
        if (!(io_in_valid)) begin
          if (_T_46) begin
            if (_T_48) begin
              readAddr <= 7'h0;
            end else begin
              readAddr <= _T_52;
            end
          end
        end
      end else begin
        if (io_out_ready) begin
          if (_T_48) begin
            readAddr <= 7'h0;
          end else begin
            readAddr <= _T_52;
          end
        end
      end
    end
    if (_GEN_1) begin
      mem__T_29_addr_pipe_0 <= readAddr;
    end
  end
endmodule
module TopControl(
  input         clock,
  input         reset,
  input  [3:0]  io_frameBits,
  input  [7:0]  io_frameIndex,
  input  [8:0]  io_divisor,
  output        io_bitTx,
  input         io_bitRx,
  output        io_in_ready,
  input         io_in_valid,
  input  [15:0] io_in_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [15:0] io_out_bits
);
  wire  ooktx_clock; // @[TopControl.scala 43:21]
  wire  ooktx_reset; // @[TopControl.scala 43:21]
  wire  ooktx_io_in_ready; // @[TopControl.scala 43:21]
  wire  ooktx_io_in_valid; // @[TopControl.scala 43:21]
  wire [15:0] ooktx_io_in_bits; // @[TopControl.scala 43:21]
  wire  ooktx_io_out; // @[TopControl.scala 43:21]
  wire [3:0] ooktx_io_frameBits; // @[TopControl.scala 43:21]
  wire [7:0] ooktx_io_frameIndex; // @[TopControl.scala 43:21]
  wire [8:0] ooktx_io_divisor; // @[TopControl.scala 43:21]
  wire  ooktx_io_crcPassAsRx; // @[TopControl.scala 43:21]
  wire  ooktx_io_crcFailAsRx; // @[TopControl.scala 43:21]
  wire  ooktx_io_resendAsTx; // @[TopControl.scala 43:21]
  wire  ooktx_io_sendAsTx; // @[TopControl.scala 43:21]
  wire  ookrx_clock; // @[TopControl.scala 44:21]
  wire  ookrx_reset; // @[TopControl.scala 44:21]
  wire  ookrx_io_in; // @[TopControl.scala 44:21]
  wire [3:0] ookrx_io_frameBits; // @[TopControl.scala 44:21]
  wire [8:0] ookrx_io_divisor; // @[TopControl.scala 44:21]
  wire  ookrx_io_out_ready; // @[TopControl.scala 44:21]
  wire  ookrx_io_out_valid; // @[TopControl.scala 44:21]
  wire [15:0] ookrx_io_out_bits; // @[TopControl.scala 44:21]
  wire  ookrx_io_crcPass; // @[TopControl.scala 44:21]
  wire  ookrx_io_crcPassAsTx; // @[TopControl.scala 44:21]
  wire  ookrx_io_crcFailAsTx; // @[TopControl.scala 44:21]
  wire  txMemory_clock; // @[TopControl.scala 47:24]
  wire  txMemory_reset; // @[TopControl.scala 47:24]
  wire  txMemory_io_in_ready; // @[TopControl.scala 47:24]
  wire  txMemory_io_in_valid; // @[TopControl.scala 47:24]
  wire [15:0] txMemory_io_in_bits; // @[TopControl.scala 47:24]
  wire  txMemory_io_out_ready; // @[TopControl.scala 47:24]
  wire  txMemory_io_out_valid; // @[TopControl.scala 47:24]
  wire [15:0] txMemory_io_out_bits; // @[TopControl.scala 47:24]
  wire  rxMemory_clock; // @[TopControl.scala 48:24]
  wire  rxMemory_reset; // @[TopControl.scala 48:24]
  wire  rxMemory_io_in_ready; // @[TopControl.scala 48:24]
  wire  rxMemory_io_in_valid; // @[TopControl.scala 48:24]
  wire [15:0] rxMemory_io_in_bits; // @[TopControl.scala 48:24]
  wire  rxMemory_io_out_ready; // @[TopControl.scala 48:24]
  wire  rxMemory_io_out_valid; // @[TopControl.scala 48:24]
  wire [15:0] rxMemory_io_out_bits; // @[TopControl.scala 48:24]
  reg [3:0] state; // @[TopControl.scala 40:18]
  reg [31:0] _RAND_0;
  reg [9:0] counter; // @[TopControl.scala 51:24]
  reg [31:0] _RAND_1;
  wire  _T_21; // @[TopControl.scala 53:14]
  wire  _T_22; // @[TopControl.scala 53:40]
  wire  _T_23; // @[TopControl.scala 53:31]
  wire [10:0] _T_26; // @[TopControl.scala 56:24]
  wire [9:0] _T_27; // @[TopControl.scala 56:24]
  wire [9:0] _GEN_0; // @[TopControl.scala 53:57]
  reg  firstTx; // @[TopControl.scala 59:24]
  reg [31:0] _RAND_2;
  wire  _T_35; // @[TopControl.scala 62:14]
  wire  _GEN_1; // @[TopControl.scala 62:37]
  wire  _GEN_2; // @[TopControl.scala 60:57]
  reg  txMode; // @[TopControl.scala 66:23]
  reg [31:0] _RAND_3;
  wire  _GEN_3; // @[TopControl.scala 69:33]
  wire  _GEN_4; // @[TopControl.scala 67:30]
  reg [15:0] loadDataBuffer; // @[TopControl.scala 85:31]
  reg [31:0] _RAND_4;
  reg  crcPassAsTx; // @[TopControl.scala 118:28]
  reg [31:0] _RAND_5;
  reg  crcFailAsTx; // @[TopControl.scala 119:28]
  reg [31:0] _RAND_6;
  wire  _T_95; // @[TopControl.scala 121:41]
  wire  _T_96; // @[TopControl.scala 121:56]
  wire  _T_97; // @[TopControl.scala 121:29]
  wire  _GEN_5; // @[TopControl.scala 123:37]
  wire  _GEN_6; // @[TopControl.scala 121:68]
  wire  _T_103; // @[TopControl.scala 126:59]
  wire  _T_104; // @[TopControl.scala 126:56]
  wire  _T_105; // @[TopControl.scala 126:29]
  wire  _GEN_7; // @[TopControl.scala 128:37]
  wire  _GEN_8; // @[TopControl.scala 126:69]
  wire  _T_109; // @[Conditional.scala 37:30]
  wire  _T_110; // @[TopControl.scala 141:24]
  wire  _T_111; // @[TopControl.scala 143:30]
  wire  _T_113; // @[TopControl.scala 145:40]
  wire  _T_114; // @[TopControl.scala 145:37]
  wire [3:0] _GEN_9; // @[TopControl.scala 146:31]
  wire  _T_115; // @[TopControl.scala 151:31]
  wire  _T_116; // @[TopControl.scala 153:36]
  wire  _T_117; // @[TopControl.scala 155:30]
  wire [15:0] _GEN_10; // @[TopControl.scala 155:54]
  wire [3:0] _GEN_11; // @[TopControl.scala 155:54]
  wire [3:0] _GEN_12; // @[TopControl.scala 153:61]
  wire [15:0] _GEN_13; // @[TopControl.scala 153:61]
  wire [3:0] _GEN_14; // @[TopControl.scala 151:56]
  wire [15:0] _GEN_15; // @[TopControl.scala 151:56]
  wire [3:0] _GEN_16; // @[TopControl.scala 145:48]
  wire [15:0] _GEN_17; // @[TopControl.scala 145:48]
  wire [3:0] _GEN_18; // @[TopControl.scala 143:40]
  wire [15:0] _GEN_19; // @[TopControl.scala 143:40]
  wire [3:0] _GEN_20; // @[TopControl.scala 141:34]
  wire [15:0] _GEN_21; // @[TopControl.scala 141:34]
  wire  _T_118; // @[Conditional.scala 37:30]
  wire  _T_119; // @[Conditional.scala 37:30]
  wire  _T_120; // @[Conditional.scala 37:30]
  wire  _T_121; // @[Conditional.scala 37:30]
  wire  _T_122; // @[Conditional.scala 37:30]
  wire  _T_123; // @[Conditional.scala 37:30]
  wire  _T_124; // @[Conditional.scala 37:30]
  wire  _T_125; // @[Conditional.scala 37:30]
  wire [3:0] _GEN_22; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_23; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_24; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_25; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_26; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_27; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_28; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_29; // @[Conditional.scala 39:67]
  wire [3:0] _GEN_30; // @[Conditional.scala 40:58]
  wire [15:0] _GEN_31; // @[Conditional.scala 40:58]
  OOKTx ooktx ( // @[TopControl.scala 43:21]
    .clock(ooktx_clock),
    .reset(ooktx_reset),
    .io_in_ready(ooktx_io_in_ready),
    .io_in_valid(ooktx_io_in_valid),
    .io_in_bits(ooktx_io_in_bits),
    .io_out(ooktx_io_out),
    .io_frameBits(ooktx_io_frameBits),
    .io_frameIndex(ooktx_io_frameIndex),
    .io_divisor(ooktx_io_divisor),
    .io_crcPassAsRx(ooktx_io_crcPassAsRx),
    .io_crcFailAsRx(ooktx_io_crcFailAsRx),
    .io_resendAsTx(ooktx_io_resendAsTx),
    .io_sendAsTx(ooktx_io_sendAsTx)
  );
  OOKRx ookrx ( // @[TopControl.scala 44:21]
    .clock(ookrx_clock),
    .reset(ookrx_reset),
    .io_in(ookrx_io_in),
    .io_frameBits(ookrx_io_frameBits),
    .io_divisor(ookrx_io_divisor),
    .io_out_ready(ookrx_io_out_ready),
    .io_out_valid(ookrx_io_out_valid),
    .io_out_bits(ookrx_io_out_bits),
    .io_crcPass(ookrx_io_crcPass),
    .io_crcPassAsTx(ookrx_io_crcPassAsTx),
    .io_crcFailAsTx(ookrx_io_crcFailAsTx)
  );
  DataMemory txMemory ( // @[TopControl.scala 47:24]
    .clock(txMemory_clock),
    .reset(txMemory_reset),
    .io_in_ready(txMemory_io_in_ready),
    .io_in_valid(txMemory_io_in_valid),
    .io_in_bits(txMemory_io_in_bits),
    .io_out_ready(txMemory_io_out_ready),
    .io_out_valid(txMemory_io_out_valid),
    .io_out_bits(txMemory_io_out_bits)
  );
  DataMemory rxMemory ( // @[TopControl.scala 48:24]
    .clock(rxMemory_clock),
    .reset(rxMemory_reset),
    .io_in_ready(rxMemory_io_in_ready),
    .io_in_valid(rxMemory_io_in_valid),
    .io_in_bits(rxMemory_io_in_bits),
    .io_out_ready(rxMemory_io_out_ready),
    .io_out_valid(rxMemory_io_out_valid),
    .io_out_bits(rxMemory_io_out_bits)
  );
  assign _T_21 = state == 4'h7; // @[TopControl.scala 53:14]
  assign _T_22 = state == 4'h8; // @[TopControl.scala 53:40]
  assign _T_23 = _T_21 | _T_22; // @[TopControl.scala 53:31]
  assign _T_26 = counter + 10'h1; // @[TopControl.scala 56:24]
  assign _T_27 = _T_26[9:0]; // @[TopControl.scala 56:24]
  assign _GEN_0 = _T_23 ? 10'h0 : _T_27; // @[TopControl.scala 53:57]
  assign _T_35 = txMemory_io_out_valid == 1'h0; // @[TopControl.scala 62:14]
  assign _GEN_1 = _T_35 ? 1'h1 : firstTx; // @[TopControl.scala 62:37]
  assign _GEN_2 = _T_23 ? 1'h0 : _GEN_1; // @[TopControl.scala 60:57]
  assign _GEN_3 = ookrx_io_out_valid ? 1'h0 : txMode; // @[TopControl.scala 69:33]
  assign _GEN_4 = txMemory_io_out_valid ? 1'h1 : _GEN_3; // @[TopControl.scala 67:30]
  assign _T_95 = counter == 10'h3e8; // @[TopControl.scala 121:41]
  assign _T_96 = _T_95 & firstTx; // @[TopControl.scala 121:56]
  assign _T_97 = ookrx_io_crcPassAsTx | _T_96; // @[TopControl.scala 121:29]
  assign _GEN_5 = _T_21 ? 1'h0 : crcPassAsTx; // @[TopControl.scala 123:37]
  assign _GEN_6 = _T_97 ? 1'h1 : _GEN_5; // @[TopControl.scala 121:68]
  assign _T_103 = firstTx == 1'h0; // @[TopControl.scala 126:59]
  assign _T_104 = _T_95 & _T_103; // @[TopControl.scala 126:56]
  assign _T_105 = ookrx_io_crcFailAsTx | _T_104; // @[TopControl.scala 126:29]
  assign _GEN_7 = _T_22 ? 1'h0 : crcFailAsTx; // @[TopControl.scala 128:37]
  assign _GEN_8 = _T_105 ? 1'h1 : _GEN_7; // @[TopControl.scala 126:69]
  assign _T_109 = 4'h0 == state; // @[Conditional.scala 37:30]
  assign _T_110 = crcPassAsTx & txMode; // @[TopControl.scala 141:24]
  assign _T_111 = crcFailAsTx & txMode; // @[TopControl.scala 143:30]
  assign _T_113 = txMode == 1'h0; // @[TopControl.scala 145:40]
  assign _T_114 = ookrx_io_out_valid & _T_113; // @[TopControl.scala 145:37]
  assign _GEN_9 = ookrx_io_crcPass ? 4'h5 : 4'h6; // @[TopControl.scala 146:31]
  assign _T_115 = io_out_ready & rxMemory_io_out_valid; // @[TopControl.scala 151:31]
  assign _T_116 = ooktx_io_in_ready & txMemory_io_out_valid; // @[TopControl.scala 153:36]
  assign _T_117 = io_in_valid & txMemory_io_in_ready; // @[TopControl.scala 155:30]
  assign _GEN_10 = _T_117 ? io_in_bits : loadDataBuffer; // @[TopControl.scala 155:54]
  assign _GEN_11 = _T_117 ? 4'h4 : state; // @[TopControl.scala 155:54]
  assign _GEN_12 = _T_116 ? 4'h3 : _GEN_11; // @[TopControl.scala 153:61]
  assign _GEN_13 = _T_116 ? loadDataBuffer : _GEN_10; // @[TopControl.scala 153:61]
  assign _GEN_14 = _T_115 ? 4'h2 : _GEN_12; // @[TopControl.scala 151:56]
  assign _GEN_15 = _T_115 ? loadDataBuffer : _GEN_13; // @[TopControl.scala 151:56]
  assign _GEN_16 = _T_114 ? _GEN_9 : _GEN_14; // @[TopControl.scala 145:48]
  assign _GEN_17 = _T_114 ? loadDataBuffer : _GEN_15; // @[TopControl.scala 145:48]
  assign _GEN_18 = _T_111 ? 4'h8 : _GEN_16; // @[TopControl.scala 143:40]
  assign _GEN_19 = _T_111 ? loadDataBuffer : _GEN_17; // @[TopControl.scala 143:40]
  assign _GEN_20 = _T_110 ? 4'h7 : _GEN_18; // @[TopControl.scala 141:34]
  assign _GEN_21 = _T_110 ? loadDataBuffer : _GEN_19; // @[TopControl.scala 141:34]
  assign _T_118 = 4'h1 == state; // @[Conditional.scala 37:30]
  assign _T_119 = 4'h2 == state; // @[Conditional.scala 37:30]
  assign _T_120 = 4'h3 == state; // @[Conditional.scala 37:30]
  assign _T_121 = 4'h4 == state; // @[Conditional.scala 37:30]
  assign _T_122 = 4'h5 == state; // @[Conditional.scala 37:30]
  assign _T_123 = 4'h6 == state; // @[Conditional.scala 37:30]
  assign _T_124 = 4'h7 == state; // @[Conditional.scala 37:30]
  assign _T_125 = 4'h8 == state; // @[Conditional.scala 37:30]
  assign _GEN_22 = _T_125 ? 4'h0 : state; // @[Conditional.scala 39:67]
  assign _GEN_23 = _T_124 ? 4'h0 : _GEN_22; // @[Conditional.scala 39:67]
  assign _GEN_24 = _T_123 ? 4'h0 : _GEN_23; // @[Conditional.scala 39:67]
  assign _GEN_25 = _T_122 ? 4'h1 : _GEN_24; // @[Conditional.scala 39:67]
  assign _GEN_26 = _T_121 ? 4'h0 : _GEN_25; // @[Conditional.scala 39:67]
  assign _GEN_27 = _T_120 ? 4'h0 : _GEN_26; // @[Conditional.scala 39:67]
  assign _GEN_28 = _T_119 ? 4'h0 : _GEN_27; // @[Conditional.scala 39:67]
  assign _GEN_29 = _T_118 ? 4'h0 : _GEN_28; // @[Conditional.scala 39:67]
  assign _GEN_30 = _T_109 ? _GEN_20 : _GEN_29; // @[Conditional.scala 40:58]
  assign _GEN_31 = _T_109 ? _GEN_21 : loadDataBuffer; // @[Conditional.scala 40:58]
  assign io_bitTx = ooktx_io_out; // @[TopControl.scala 77:12]
  assign io_in_ready = state == 4'h4; // @[TopControl.scala 107:15]
  assign io_out_valid = state == 4'h2; // @[TopControl.scala 96:16]
  assign io_out_bits = rxMemory_io_out_bits; // @[TopControl.scala 95:15]
  assign ooktx_clock = clock;
  assign ooktx_reset = reset;
  assign ooktx_io_in_valid = state == 4'h3; // @[TopControl.scala 101:21]
  assign ooktx_io_in_bits = txMemory_io_out_bits; // @[TopControl.scala 100:20]
  assign ooktx_io_frameBits = io_frameBits; // @[TopControl.scala 74:22]
  assign ooktx_io_frameIndex = io_frameIndex; // @[TopControl.scala 75:23]
  assign ooktx_io_divisor = io_divisor; // @[TopControl.scala 76:20]
  assign ooktx_io_crcPassAsRx = state == 4'h5; // @[TopControl.scala 110:24]
  assign ooktx_io_crcFailAsRx = state == 4'h6; // @[TopControl.scala 111:24]
  assign ooktx_io_resendAsTx = state == 4'h8; // @[TopControl.scala 114:23]
  assign ooktx_io_sendAsTx = state == 4'h7; // @[TopControl.scala 115:21]
  assign ookrx_clock = clock;
  assign ookrx_reset = reset;
  assign ookrx_io_in = io_bitRx; // @[TopControl.scala 82:15]
  assign ookrx_io_frameBits = io_frameBits; // @[TopControl.scala 80:22]
  assign ookrx_io_divisor = io_divisor; // @[TopControl.scala 81:20]
  assign ookrx_io_out_ready = state == 4'h0; // @[TopControl.scala 88:22]
  assign txMemory_clock = clock;
  assign txMemory_reset = reset;
  assign txMemory_io_in_valid = state == 4'h4; // @[TopControl.scala 106:24]
  assign txMemory_io_in_bits = loadDataBuffer; // @[TopControl.scala 105:23]
  assign txMemory_io_out_ready = state == 4'h3; // @[TopControl.scala 102:25]
  assign rxMemory_clock = clock;
  assign rxMemory_reset = reset;
  assign rxMemory_io_in_valid = state == 4'h1; // @[TopControl.scala 92:24]
  assign rxMemory_io_in_bits = ookrx_io_out_bits; // @[TopControl.scala 91:23]
  assign rxMemory_io_out_ready = state == 4'h2; // @[TopControl.scala 97:25]
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
  state = _RAND_0[3:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  counter = _RAND_1[9:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  firstTx = _RAND_2[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  txMode = _RAND_3[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_4 = {1{$random}};
  loadDataBuffer = _RAND_4[15:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{$random}};
  crcPassAsTx = _RAND_5[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_6 = {1{$random}};
  crcFailAsTx = _RAND_6[0:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (reset) begin
      state <= 4'h0;
    end else begin
      if (_T_109) begin
        if (_T_110) begin
          state <= 4'h7;
        end else begin
          if (_T_111) begin
            state <= 4'h8;
          end else begin
            if (_T_114) begin
              if (ookrx_io_crcPass) begin
                state <= 4'h5;
              end else begin
                state <= 4'h6;
              end
            end else begin
              if (_T_115) begin
                state <= 4'h2;
              end else begin
                if (_T_116) begin
                  state <= 4'h3;
                end else begin
                  if (_T_117) begin
                    state <= 4'h4;
                  end
                end
              end
            end
          end
        end
      end else begin
        if (_T_118) begin
          state <= 4'h0;
        end else begin
          if (_T_119) begin
            state <= 4'h0;
          end else begin
            if (_T_120) begin
              state <= 4'h0;
            end else begin
              if (_T_121) begin
                state <= 4'h0;
              end else begin
                if (_T_122) begin
                  state <= 4'h1;
                end else begin
                  if (_T_123) begin
                    state <= 4'h0;
                  end else begin
                    if (_T_124) begin
                      state <= 4'h0;
                    end else begin
                      if (_T_125) begin
                        state <= 4'h0;
                      end
                    end
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      counter <= 10'h0;
    end else begin
      if (_T_23) begin
        counter <= 10'h0;
      end else begin
        counter <= _T_27;
      end
    end
    if (reset) begin
      firstTx <= 1'h1;
    end else begin
      if (_T_23) begin
        firstTx <= 1'h0;
      end else begin
        if (_T_35) begin
          firstTx <= 1'h1;
        end
      end
    end
    if (reset) begin
      txMode <= 1'h0;
    end else begin
      if (txMemory_io_out_valid) begin
        txMode <= 1'h1;
      end else begin
        if (ookrx_io_out_valid) begin
          txMode <= 1'h0;
        end
      end
    end
    if (reset) begin
      loadDataBuffer <= 16'h0;
    end else begin
      if (_T_109) begin
        if (!(_T_110)) begin
          if (!(_T_111)) begin
            if (!(_T_114)) begin
              if (!(_T_115)) begin
                if (!(_T_116)) begin
                  if (_T_117) begin
                    loadDataBuffer <= io_in_bits;
                  end
                end
              end
            end
          end
        end
      end
    end
    if (reset) begin
      crcPassAsTx <= 1'h0;
    end else begin
      if (_T_97) begin
        crcPassAsTx <= 1'h1;
      end else begin
        if (_T_21) begin
          crcPassAsTx <= 1'h0;
        end
      end
    end
    if (reset) begin
      crcFailAsTx <= 1'h0;
    end else begin
      if (_T_105) begin
        crcFailAsTx <= 1'h1;
      end else begin
        if (_T_22) begin
          crcFailAsTx <= 1'h0;
        end
      end
    end
  end
endmodule
module TopSimulator(
  input         clock,
  input         reset,
  output        io_txin_ready,
  input         io_txin_valid,
  input  [15:0] io_txin_bits,
  input         io_txout_ready,
  output        io_txout_valid,
  output [15:0] io_txout_bits,
  output        io_rxin_ready,
  input         io_rxin_valid,
  input  [15:0] io_rxin_bits,
  input         io_rxout_ready,
  output        io_rxout_valid,
  output [15:0] io_rxout_bits,
  input  [3:0]  io_frameBits,
  input  [7:0]  io_frameIndex,
  input  [8:0]  io_divisor,
  input         io_error
);
  wire  tx_clock; // @[TopSimulator.scala 36:18]
  wire  tx_reset; // @[TopSimulator.scala 36:18]
  wire [3:0] tx_io_frameBits; // @[TopSimulator.scala 36:18]
  wire [7:0] tx_io_frameIndex; // @[TopSimulator.scala 36:18]
  wire [8:0] tx_io_divisor; // @[TopSimulator.scala 36:18]
  wire  tx_io_bitTx; // @[TopSimulator.scala 36:18]
  wire  tx_io_bitRx; // @[TopSimulator.scala 36:18]
  wire  tx_io_in_ready; // @[TopSimulator.scala 36:18]
  wire  tx_io_in_valid; // @[TopSimulator.scala 36:18]
  wire [15:0] tx_io_in_bits; // @[TopSimulator.scala 36:18]
  wire  tx_io_out_ready; // @[TopSimulator.scala 36:18]
  wire  tx_io_out_valid; // @[TopSimulator.scala 36:18]
  wire [15:0] tx_io_out_bits; // @[TopSimulator.scala 36:18]
  wire  rx_clock; // @[TopSimulator.scala 37:18]
  wire  rx_reset; // @[TopSimulator.scala 37:18]
  wire [3:0] rx_io_frameBits; // @[TopSimulator.scala 37:18]
  wire [7:0] rx_io_frameIndex; // @[TopSimulator.scala 37:18]
  wire [8:0] rx_io_divisor; // @[TopSimulator.scala 37:18]
  wire  rx_io_bitTx; // @[TopSimulator.scala 37:18]
  wire  rx_io_bitRx; // @[TopSimulator.scala 37:18]
  wire  rx_io_in_ready; // @[TopSimulator.scala 37:18]
  wire  rx_io_in_valid; // @[TopSimulator.scala 37:18]
  wire [15:0] rx_io_in_bits; // @[TopSimulator.scala 37:18]
  wire  rx_io_out_ready; // @[TopSimulator.scala 37:18]
  wire  rx_io_out_valid; // @[TopSimulator.scala 37:18]
  wire [15:0] rx_io_out_bits; // @[TopSimulator.scala 37:18]
  wire  _T_27; // @[TopSimulator.scala 40:41]
  reg  dataInAir; // @[TopSimulator.scala 40:26]
  reg [31:0] _RAND_0;
  reg  dataInAirB; // @[TopSimulator.scala 41:27]
  reg [31:0] _RAND_1;
  TopControl tx ( // @[TopSimulator.scala 36:18]
    .clock(tx_clock),
    .reset(tx_reset),
    .io_frameBits(tx_io_frameBits),
    .io_frameIndex(tx_io_frameIndex),
    .io_divisor(tx_io_divisor),
    .io_bitTx(tx_io_bitTx),
    .io_bitRx(tx_io_bitRx),
    .io_in_ready(tx_io_in_ready),
    .io_in_valid(tx_io_in_valid),
    .io_in_bits(tx_io_in_bits),
    .io_out_ready(tx_io_out_ready),
    .io_out_valid(tx_io_out_valid),
    .io_out_bits(tx_io_out_bits)
  );
  TopControl rx ( // @[TopSimulator.scala 37:18]
    .clock(rx_clock),
    .reset(rx_reset),
    .io_frameBits(rx_io_frameBits),
    .io_frameIndex(rx_io_frameIndex),
    .io_divisor(rx_io_divisor),
    .io_bitTx(rx_io_bitTx),
    .io_bitRx(rx_io_bitRx),
    .io_in_ready(rx_io_in_ready),
    .io_in_valid(rx_io_in_valid),
    .io_in_bits(rx_io_in_bits),
    .io_out_ready(rx_io_out_ready),
    .io_out_valid(rx_io_out_valid),
    .io_out_bits(rx_io_out_bits)
  );
  assign _T_27 = tx_io_bitTx == 1'h0; // @[TopSimulator.scala 40:41]
  assign io_txin_ready = tx_io_in_ready; // @[TopSimulator.scala 47:12]
  assign io_txout_valid = tx_io_out_valid; // @[TopSimulator.scala 48:13]
  assign io_txout_bits = tx_io_out_bits; // @[TopSimulator.scala 48:13]
  assign io_rxin_ready = rx_io_in_ready; // @[TopSimulator.scala 56:12]
  assign io_rxout_valid = rx_io_out_valid; // @[TopSimulator.scala 57:13]
  assign io_rxout_bits = rx_io_out_bits; // @[TopSimulator.scala 57:13]
  assign tx_clock = clock;
  assign tx_reset = reset;
  assign tx_io_frameBits = io_frameBits; // @[TopSimulator.scala 44:19]
  assign tx_io_frameIndex = io_frameIndex; // @[TopSimulator.scala 46:20]
  assign tx_io_divisor = io_divisor; // @[TopSimulator.scala 45:17]
  assign tx_io_bitRx = dataInAirB; // @[TopSimulator.scala 49:15]
  assign tx_io_in_valid = io_txin_valid; // @[TopSimulator.scala 47:12]
  assign tx_io_in_bits = io_txin_bits; // @[TopSimulator.scala 47:12]
  assign tx_io_out_ready = io_txout_ready; // @[TopSimulator.scala 48:13]
  assign rx_clock = clock;
  assign rx_reset = reset;
  assign rx_io_frameBits = io_frameBits; // @[TopSimulator.scala 53:19]
  assign rx_io_frameIndex = io_frameIndex; // @[TopSimulator.scala 55:20]
  assign rx_io_divisor = io_divisor; // @[TopSimulator.scala 54:16]
  assign rx_io_bitRx = dataInAir; // @[TopSimulator.scala 58:15]
  assign rx_io_in_valid = io_rxin_valid; // @[TopSimulator.scala 56:12]
  assign rx_io_in_bits = io_rxin_bits; // @[TopSimulator.scala 56:12]
  assign rx_io_out_ready = io_rxout_ready; // @[TopSimulator.scala 57:13]
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
  dataInAir = _RAND_0[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  dataInAirB = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (io_error) begin
      dataInAir <= _T_27;
    end else begin
      dataInAir <= tx_io_bitTx;
    end
    dataInAirB <= rx_io_bitTx;
  end
endmodule
