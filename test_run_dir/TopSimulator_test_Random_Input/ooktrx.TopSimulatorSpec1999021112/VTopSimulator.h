// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTopSimulator_H_
#define _VTopSimulator_H_

#include "verilated.h"
class VTopSimulator__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VTopSimulator) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_txin_ready,0,0);
    VL_IN8(io_txin_valid,0,0);
    VL_IN8(io_txout_ready,0,0);
    VL_OUT8(io_txout_valid,0,0);
    VL_OUT8(io_rxin_ready,0,0);
    VL_IN8(io_rxin_valid,0,0);
    VL_IN8(io_rxout_ready,0,0);
    VL_OUT8(io_rxout_valid,0,0);
    VL_IN8(io_frameBits,3,0);
    VL_IN8(io_frameIndex,7,0);
    VL_IN8(io_error,0,0);
    //char	__VpadToAlign13[1];
    VL_IN16(io_txin_bits,15,0);
    VL_OUT16(io_txout_bits,15,0);
    VL_IN16(io_rxin_bits,15,0);
    VL_OUT16(io_rxout_bits,15,0);
    VL_IN16(io_divisor,8,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(TopSimulator__DOT__dataInAir,0,0);
    VL_SIG8(TopSimulator__DOT__dataInAirB,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__state,3,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_23,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__firstTx,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMode,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__crcPassAsTx,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__crcFailAsTx,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_97,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_105,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_109,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_110,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_111,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_114,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_115,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_116,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_117,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_118,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_119,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_120,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_121,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_122,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_123,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_124,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT___T_125,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter,4,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer,3,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer,7,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_60,4,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_40,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_43,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_47,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_58,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_61,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_65,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state,2,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter,5,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_45,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_50,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_51,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_53,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_56,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_58,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_71,5,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state,2,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter,5,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg,3,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_32,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40,5,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_43,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_45,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_57,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_58,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_61,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_64,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_67,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_30,4,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed,1,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_40,1,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_47,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_58,1,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_65,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter,4,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state,1,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_32,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_40,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_50,4,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_99,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_31,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_37,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_41,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_45,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_31,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_37,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_41,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_45,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57,6,0);
    VL_SIG8(TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__state,3,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_23,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__firstTx,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMode,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__crcPassAsTx,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__crcFailAsTx,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_97,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_105,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_109,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_110,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_111,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_114,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_115,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_116,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_117,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_118,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_119,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_120,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_121,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_122,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_123,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_124,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT___T_125,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter,4,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer,3,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer,7,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_60,4,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_40,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_43,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_47,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_58,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_61,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_65,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state,2,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter,5,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_45,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_50,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_51,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_53,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_56,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_58,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_71,5,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state,2,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter,5,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg,3,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_32,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40,5,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_43,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_45,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_52,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_57,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_58,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_61,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_64,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_67,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_30,4,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed,1,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_40,1,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_47,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_58,1,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_65,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter,4,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state,1,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_32,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_40,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_50,4,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_99,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_31,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_37,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_41,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_45,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_31,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_37,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_41,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_45,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48,0,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57,6,0);
    VL_SIG8(TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0,6,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__counter,9,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT___T_27,9,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__loadDataBuffer,15,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer,15,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48,11,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data,15,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__counter,9,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT___T_27,9,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__loadDataBuffer,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48,11,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data,15,0);
    VL_SIG(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended,23,0);
    VL_SIGW(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20,71,0,3);
    VL_SIG(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal,23,0);
    VL_SIGW(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28,71,0,3);
    VL_SIG(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended,23,0);
    VL_SIGW(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20,71,0,3);
    VL_SIG(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal,23,0);
    VL_SIGW(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28,71,0,3);
    //char	__VpadToAlign372[4];
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_49,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_55,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_67,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_32,36,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_49,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_55,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_67,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_32,36,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn,35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack[100],35,0);
    VL_SIG64(TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack[2],35,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__txMemory__DOT__mem[100],15,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem[100],15,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack[100],35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack[2],35,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__txMemory__DOT__mem[100],15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem[100],15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign3005[1];
    VL_SIG16(TopSimulator__DOT__tx__DOT__txMemory__DOT____Vlvbound1,15,0);
    VL_SIG16(TopSimulator__DOT__tx__DOT__rxMemory__DOT____Vlvbound1,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__txMemory__DOT____Vlvbound1,15,0);
    VL_SIG16(TopSimulator__DOT__rx__DOT__rxMemory__DOT____Vlvbound1,15,0);
    //char	__VpadToAlign3014[2];
    VL_SIG(__Vm_traceActivity,31,0);
    //char	__VpadToAlign3020[4];
    VL_SIG64(TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1,35,0);
    VL_SIG64(TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1,35,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign3044[4];
    VTopSimulator__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VTopSimulator& operator= (const VTopSimulator&);	///< Copying not allowed
    VTopSimulator(const VTopSimulator&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VTopSimulator(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VTopSimulator();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VTopSimulator__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VTopSimulator__Syms* symsp, bool first);
  private:
    static QData	_change_request(VTopSimulator__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__3(VTopSimulator__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VTopSimulator__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_eval_initial(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_eval_settle(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VTopSimulator__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(VTopSimulator__Syms* __restrict vlSymsp);
    static void	traceChgThis(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
