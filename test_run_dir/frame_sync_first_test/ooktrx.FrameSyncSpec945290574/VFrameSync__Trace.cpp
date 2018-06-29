// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFrameSync__Syms.h"


//======================

void VFrameSync::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFrameSync* t=(VFrameSync*)userthis;
    VFrameSync__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VFrameSync::traceChgThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFrameSync::traceChgThis__2(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->FrameSync__DOT__fifoReg),4);
    }
}

void VFrameSync::traceChgThis__3(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+2,(vlTOPp->clock));
	vcdp->chgBit  (c+3,(vlTOPp->reset));
	vcdp->chgBit  (c+4,(vlTOPp->io_in));
	vcdp->chgBus  (c+5,(vlTOPp->io_frameBits),4);
	vcdp->chgBit  (c+6,(vlTOPp->io_syncOk));
    }
}
