;buildInfoPackage: chisel3, version: 3.1.1, scalaVersion: 2.11.12, sbtVersion: 1.1.1, builtAtString: 2018-06-21 18:49:36.391, builtAtMillis: 1529606976391
circuit FrameSync : 
  module FrameSync : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip in : UInt<1>, flip frameBits : UInt<4>, syncOk : UInt<1>}
    
    reg fifoReg : UInt<4>, clock with : (reset => (reset, UInt<4>("h00"))) @[FrameSync.scala 28:24]
    node _T_13 = shl(fifoReg, 1) @[FrameSync.scala 30:23]
    node _T_14 = or(_T_13, io.in) @[FrameSync.scala 30:29]
    fifoReg <= _T_14 @[FrameSync.scala 30:11]
    node _T_15 = eq(fifoReg, io.frameBits) @[FrameSync.scala 32:17]
    when _T_15 : @[FrameSync.scala 32:34]
      io.syncOk <= UInt<1>("h01") @[FrameSync.scala 33:15]
      skip @[FrameSync.scala 32:34]
    else : @[FrameSync.scala 34:15]
      io.syncOk <= UInt<1>("h00") @[FrameSync.scala 35:15]
      skip @[FrameSync.scala 34:15]
    
