// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFrameSync__Syms.h"


//======================

void VFrameSync::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VFrameSync::traceInit, &VFrameSync::traceFull, &VFrameSync::traceChg, this);
}
void VFrameSync::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VFrameSync* t=(VFrameSync*)userthis;
    VFrameSync__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VFrameSync::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFrameSync* t=(VFrameSync*)userthis;
    VFrameSync__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VFrameSync::traceInitThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VFrameSync::traceFullThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFrameSync::traceInitThis__1(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+2,"clock",-1);
	vcdp->declBit  (c+3,"reset",-1);
	vcdp->declBit  (c+4,"io_in",-1);
	vcdp->declBus  (c+5,"io_frameBits",-1,3,0);
	vcdp->declBit  (c+6,"io_syncOk",-1);
	vcdp->declBit  (c+2,"FrameSync clock",-1);
	vcdp->declBit  (c+3,"FrameSync reset",-1);
	vcdp->declBit  (c+4,"FrameSync io_in",-1);
	vcdp->declBus  (c+5,"FrameSync io_frameBits",-1,3,0);
	vcdp->declBit  (c+6,"FrameSync io_syncOk",-1);
	vcdp->declBus  (c+1,"FrameSync fifoReg",-1,3,0);
	// Tracing: FrameSync _RAND_0 // Ignored: Inlined leading underscore at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:9
	// Tracing: FrameSync _GEN_1 // Ignored: Inlined leading underscore at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:10
	// Tracing: FrameSync _T_13 // Ignored: Inlined leading underscore at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:11
	// Tracing: FrameSync _GEN_2 // Ignored: Inlined leading underscore at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:12
	// Tracing: FrameSync _T_14 // Ignored: Inlined leading underscore at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:13
    }
}

void VFrameSync::traceFullThis__1(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->FrameSync__DOT__fifoReg),4);
	vcdp->fullBit  (c+2,(vlTOPp->clock));
	vcdp->fullBit  (c+3,(vlTOPp->reset));
	vcdp->fullBit  (c+4,(vlTOPp->io_in));
	vcdp->fullBus  (c+5,(vlTOPp->io_frameBits),4);
	vcdp->fullBit  (c+6,(vlTOPp->io_syncOk));
    }
}
