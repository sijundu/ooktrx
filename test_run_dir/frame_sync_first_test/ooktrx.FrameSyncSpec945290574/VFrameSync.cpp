// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFrameSync.h for the primary calling header

#include "VFrameSync.h"        // For This
#include "VFrameSync__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VFrameSync) {
    VFrameSync__Syms* __restrict vlSymsp = __VlSymsp = new VFrameSync__Syms(this, name());
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFrameSync::__Vconfigure(VFrameSync__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFrameSync::~VFrameSync() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VFrameSync::eval() {
    VFrameSync__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VFrameSync::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VFrameSync::_eval_initial_loop(VFrameSync__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VFrameSync::_sequent__TOP__1(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_sequent__TOP__1\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /mnt/c/Users/dusij/Desktop/ubuntu/chiselprojects/ooktrx/test_run_dir/frame_sync_first_test/ooktrx.FrameSyncSpec945290574/FrameSync.v:43
    vlTOPp->FrameSync__DOT__fifoReg = (0xfU & ((IData)(vlTOPp->reset)
					        ? 0U
					        : (IData)(vlTOPp->FrameSync__DOT___T_14)));
}

VL_INLINE_OPT void VFrameSync::_combo__TOP__2(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_combo__TOP__2\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FrameSync__DOT___T_14 = (0x1fU & (((IData)(vlTOPp->FrameSync__DOT__fifoReg) 
					       << 1U) 
					      | (IData)(vlTOPp->io_in)));
    vlTOPp->io_syncOk = ((IData)(vlTOPp->FrameSync__DOT__fifoReg) 
			 == (IData)(vlTOPp->io_frameBits));
}

void VFrameSync::_eval(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_eval\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VFrameSync::_eval_initial(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_eval_initial\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFrameSync::final() {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::final\n"); );
    // Variables
    VFrameSync__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFrameSync::_eval_settle(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_eval_settle\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VFrameSync::_change_request(VFrameSync__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_change_request\n"); );
    VFrameSync* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VFrameSync::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_in = VL_RAND_RESET_I(1);
    io_frameBits = VL_RAND_RESET_I(4);
    io_syncOk = VL_RAND_RESET_I(1);
    FrameSync__DOT__fifoReg = VL_RAND_RESET_I(4);
    FrameSync__DOT___T_14 = VL_RAND_RESET_I(5);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VFrameSync::_configure_coverage(VFrameSync__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VFrameSync::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
