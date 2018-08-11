// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTopSimulator__Syms.h"


//======================

void VTopSimulator::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTopSimulator* t=(VTopSimulator*)userthis;
    VTopSimulator__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VTopSimulator::traceChgThis(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTopSimulator::traceChgThis__2(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data),16);
	vcdp->chgBus  (c+2,(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data),16);
	vcdp->chgBus  (c+3,(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data),16);
	vcdp->chgQuad (c+4,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data),36);
	vcdp->chgQuad (c+6,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data),36);
	vcdp->chgBus  (c+8,(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data),16);
	vcdp->chgQuad (c+9,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data),36);
	vcdp->chgQuad (c+11,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data),36);
    }
}

void VTopSimulator::traceChgThis__3(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+13,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk));
	vcdp->chgBit  (c+14,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk));
    }
}

void VTopSimulator::traceChgThis__4(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+15,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out));
	vcdp->chgBit  (c+16,(vlTOPp->TopSimulator__DOT__dataInAirB));
	vcdp->chgBit  (c+17,((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+18,((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+19,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out));
	vcdp->chgBit  (c+20,(vlTOPp->TopSimulator__DOT__dataInAir));
	vcdp->chgBit  (c+21,((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+22,((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+23,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData));
	vcdp->chgBit  (c+24,((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+25,((5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+26,((6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+27,((8U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+28,((7U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+29,((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+30,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid));
	vcdp->chgBus  (c+31,((0xffffU & (IData)((vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
						 >> 8U)))),16);
	vcdp->chgBit  (c+32,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass));
	vcdp->chgBit  (c+33,((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgBit  (c+34,((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgBit  (c+35,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))));
	vcdp->chgBus  (c+36,(vlTOPp->TopSimulator__DOT__tx__DOT__loadDataBuffer),16);
	vcdp->chgBit  (c+37,((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))));
	vcdp->chgBit  (c+38,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage))));
	vcdp->chgBit  (c+39,((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))));
	vcdp->chgBit  (c+40,((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage))));
	vcdp->chgBus  (c+41,(vlTOPp->TopSimulator__DOT__tx__DOT__state),4);
	vcdp->chgBus  (c+42,(vlTOPp->TopSimulator__DOT__tx__DOT__counter),10);
	vcdp->chgBit  (c+43,(vlTOPp->TopSimulator__DOT__tx__DOT__firstTx));
	vcdp->chgBit  (c+44,(vlTOPp->TopSimulator__DOT__tx__DOT__txMode));
	vcdp->chgBit  (c+45,(vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx));
	vcdp->chgBit  (c+46,(vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx));
	vcdp->chgBit  (c+47,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed))));
	vcdp->chgBit  (c+48,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
	vcdp->chgQuad (c+49,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut),36);
	vcdp->chgBit  (c+51,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame));
	vcdp->chgBit  (c+52,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
	vcdp->chgQuad (c+53,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut),36);
	vcdp->chgBus  (c+55,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter),5);
	vcdp->chgBus  (c+56,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended),24);
	vcdp->chgBus  (c+57,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer),4);
	vcdp->chgBus  (c+58,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer),8);
	vcdp->chgBus  (c+59,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer),16);
	vcdp->chgBus  (c+60,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+61,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr),7);
	vcdp->chgBit  (c+62,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
			      & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut))));
	vcdp->chgBus  (c+63,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr),7);
	vcdp->chgBus  (c+64,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed),7);
	vcdp->chgBus  (c+65,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state),3);
	vcdp->chgBit  (c+66,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx));
	vcdp->chgBit  (c+67,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail));
	vcdp->chgBit  (c+68,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend));
	vcdp->chgBit  (c+69,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send));
	vcdp->chgQuad (c+70,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer),36);
	vcdp->chgBus  (c+72,(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter),6);
	vcdp->chgBit  (c+73,((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))));
	vcdp->chgBit  (c+74,((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgQuad (c+75,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame),36);
	vcdp->chgBit  (c+77,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame));
	vcdp->chgBit  (c+78,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut));
	vcdp->chgQuad (c+79,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut),36);
	vcdp->chgBus  (c+81,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state),3);
	vcdp->chgBus  (c+82,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter),6);
	vcdp->chgBus  (c+83,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg),4);
	vcdp->chgQuad (c+84,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack[0]),36);
	vcdp->chgQuad (c+86,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack[1]),36);
	vcdp->chgBit  (c+88,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0));
	vcdp->chgBit  (c+89,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr));
	vcdp->chgBit  (c+90,(((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
			      & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)))));
	vcdp->chgBit  (c+91,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr));
	vcdp->chgBus  (c+92,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed),2);
	vcdp->chgQuad (c+93,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn),36);
	vcdp->chgBus  (c+95,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal),24);
	vcdp->chgBus  (c+96,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter),5);
	vcdp->chgBus  (c+97,(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state),2);
	vcdp->chgBus  (c+98,(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+99,(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr),7);
	vcdp->chgBit  (c+100,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)) 
			       & (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)))));
	vcdp->chgBus  (c+101,(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage),7);
	vcdp->chgBus  (c+102,(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr),7);
	vcdp->chgBus  (c+103,(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+104,(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr),7);
	vcdp->chgBit  (c+105,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)) 
			       & (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)))));
	vcdp->chgBus  (c+106,(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage),7);
	vcdp->chgBus  (c+107,(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr),7);
	vcdp->chgBit  (c+108,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData));
	vcdp->chgBit  (c+109,((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+110,((5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+111,((6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+112,((8U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+113,((7U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+114,((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+115,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid));
	vcdp->chgBus  (c+116,((0xffffU & (IData)((vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
						  >> 8U)))),16);
	vcdp->chgBit  (c+117,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass));
	vcdp->chgBit  (c+118,((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgBit  (c+119,((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgBit  (c+120,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))));
	vcdp->chgBus  (c+121,(vlTOPp->TopSimulator__DOT__rx__DOT__loadDataBuffer),16);
	vcdp->chgBit  (c+122,((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))));
	vcdp->chgBit  (c+123,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage))));
	vcdp->chgBit  (c+124,((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))));
	vcdp->chgBit  (c+125,((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage))));
	vcdp->chgBus  (c+126,(vlTOPp->TopSimulator__DOT__rx__DOT__state),4);
	vcdp->chgBus  (c+127,(vlTOPp->TopSimulator__DOT__rx__DOT__counter),10);
	vcdp->chgBit  (c+128,(vlTOPp->TopSimulator__DOT__rx__DOT__firstTx));
	vcdp->chgBit  (c+129,(vlTOPp->TopSimulator__DOT__rx__DOT__txMode));
	vcdp->chgBit  (c+130,(vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx));
	vcdp->chgBit  (c+131,(vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx));
	vcdp->chgBit  (c+132,((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed))));
	vcdp->chgBit  (c+133,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
	vcdp->chgQuad (c+134,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut),36);
	vcdp->chgBit  (c+136,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame));
	vcdp->chgBit  (c+137,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
	vcdp->chgQuad (c+138,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut),36);
	vcdp->chgBus  (c+140,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter),5);
	vcdp->chgBus  (c+141,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended),24);
	vcdp->chgBus  (c+142,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer),4);
	vcdp->chgBus  (c+143,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer),8);
	vcdp->chgBus  (c+144,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer),16);
	vcdp->chgBus  (c+145,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+146,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr),7);
	vcdp->chgBit  (c+147,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
			       & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut))));
	vcdp->chgBus  (c+148,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr),7);
	vcdp->chgBus  (c+149,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed),7);
	vcdp->chgBus  (c+150,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state),3);
	vcdp->chgBit  (c+151,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx));
	vcdp->chgBit  (c+152,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail));
	vcdp->chgBit  (c+153,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend));
	vcdp->chgBit  (c+154,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send));
	vcdp->chgQuad (c+155,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer),36);
	vcdp->chgBus  (c+157,(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter),6);
	vcdp->chgBit  (c+158,((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))));
	vcdp->chgBit  (c+159,((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))));
	vcdp->chgQuad (c+160,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame),36);
	vcdp->chgBit  (c+162,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame));
	vcdp->chgBit  (c+163,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut));
	vcdp->chgQuad (c+164,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut),36);
	vcdp->chgBus  (c+166,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state),3);
	vcdp->chgBus  (c+167,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter),6);
	vcdp->chgBus  (c+168,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg),4);
	vcdp->chgQuad (c+169,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack[0]),36);
	vcdp->chgQuad (c+171,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack[1]),36);
	vcdp->chgBit  (c+173,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0));
	vcdp->chgBit  (c+174,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr));
	vcdp->chgBit  (c+175,(((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
			       & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)))));
	vcdp->chgBit  (c+176,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr));
	vcdp->chgBus  (c+177,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed),2);
	vcdp->chgQuad (c+178,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn),36);
	vcdp->chgBus  (c+180,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal),24);
	vcdp->chgBus  (c+181,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter),5);
	vcdp->chgBus  (c+182,(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state),2);
	vcdp->chgBus  (c+183,(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+184,(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr),7);
	vcdp->chgBit  (c+185,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)) 
			       & (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)))));
	vcdp->chgBus  (c+186,(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage),7);
	vcdp->chgBus  (c+187,(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr),7);
	vcdp->chgBus  (c+188,(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0),7);
	vcdp->chgBus  (c+189,(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr),7);
	vcdp->chgBit  (c+190,(((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)) 
			       & (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)))));
	vcdp->chgBus  (c+191,(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage),7);
	vcdp->chgBus  (c+192,(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr),7);
    }
}

void VTopSimulator::traceChgThis__5(VTopSimulator__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+193,(vlTOPp->clock));
	vcdp->chgBit  (c+194,(vlTOPp->reset));
	vcdp->chgBit  (c+195,(vlTOPp->io_txin_ready));
	vcdp->chgBit  (c+196,(vlTOPp->io_txin_valid));
	vcdp->chgBus  (c+197,(vlTOPp->io_txin_bits),16);
	vcdp->chgBit  (c+198,(vlTOPp->io_txout_ready));
	vcdp->chgBit  (c+199,(vlTOPp->io_txout_valid));
	vcdp->chgBus  (c+200,(vlTOPp->io_txout_bits),16);
	vcdp->chgBit  (c+201,(vlTOPp->io_rxin_ready));
	vcdp->chgBit  (c+202,(vlTOPp->io_rxin_valid));
	vcdp->chgBus  (c+203,(vlTOPp->io_rxin_bits),16);
	vcdp->chgBit  (c+204,(vlTOPp->io_rxout_ready));
	vcdp->chgBit  (c+205,(vlTOPp->io_rxout_valid));
	vcdp->chgBus  (c+206,(vlTOPp->io_rxout_bits),16);
	vcdp->chgBus  (c+207,(vlTOPp->io_frameBits),4);
	vcdp->chgBus  (c+208,(vlTOPp->io_frameIndex),8);
	vcdp->chgBus  (c+209,(vlTOPp->io_divisor),9);
	vcdp->chgBit  (c+210,(vlTOPp->io_error));
	vcdp->chgQuad (c+211,(((QData)((IData)(vlTOPp->io_frameBits)) 
			       << 0x20U)),36);
	vcdp->chgQuad (c+213,((VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
					      << 0x20U))),36);
    }
}
