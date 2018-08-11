// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopSimulator.h for the primary calling header

#include "VTopSimulator.h"     // For This
#include "VTopSimulator__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VTopSimulator) {
    VTopSimulator__Syms* __restrict vlSymsp = __VlSymsp = new VTopSimulator__Syms(this, name());
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VTopSimulator::__Vconfigure(VTopSimulator__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VTopSimulator::~VTopSimulator() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VTopSimulator::eval() {
    VTopSimulator__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VTopSimulator::eval\n"); );
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

void VTopSimulator::_eval_initial_loop(VTopSimulator__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VTopSimulator::_sequent__TOP__1(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_sequent__TOP__1\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state,2,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter,5,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr,0,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state,2,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter,5,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr,0,0);
    VL_SIG8(__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr,0,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvdim0__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0,6,0);
    VL_SIG8(__Vdlyvset__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0,0,0);
    VL_SIG16(__Vdlyvval__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0,15,0);
    VL_SIG16(__Vdlyvval__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0,15,0);
    VL_SIG16(__Vdlyvval__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0,15,0);
    VL_SIG16(__Vdlyvval__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0,15,0);
    //char	__VpadToAlign36[4];
    VL_SIG64(__Vdlyvval__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,35,0);
    VL_SIG64(__Vdlyvval__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,35,0);
    VL_SIG64(__Vdlyvval__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0,35,0);
    VL_SIG64(__Vdlyvval__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0,35,0);
    // Body
    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    __Vdlyvset__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 = 0U;
    __Vdlyvset__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 = 0U;
    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter;
    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter;
    __Vdlyvset__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 = 0U;
    __Vdlyvset__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 = 0U;
    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state;
    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state;
    __Vdlyvset__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0 = 0U;
    __Vdlyvset__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0 = 0U;
    __Vdlyvset__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0 = 0U;
    __Vdlyvset__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0 = 0U;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1506
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36) {
	    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
		= ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)) 
		   & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_47));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1506
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36) {
	    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
		= ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)) 
		   & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_47));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:531
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36)) 
					 & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:531
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36)) 
					 & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1493
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36)))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54) {
		__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
		    = ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)) 
		       & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_65));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1493
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36)))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54) {
		__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
		    = ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)) 
		       & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_65));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2565
    vlTOPp->TopSimulator__DOT__tx__DOT__counter = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_23)
						     ? 0U
						     : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_27)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2565
    vlTOPp->TopSimulator__DOT__rx__DOT__counter = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_23)
						     ? 0U
						     : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_27)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:540
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:540
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:908
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 0U;
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 1U;
	    } else {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:908
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 0U;
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 1U;
	    } else {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:316
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer 
		= vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:316
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer 
		= vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:309
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer 
		= vlTOPp->io_frameIndex;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:309
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer 
		= vlTOPp->io_frameIndex;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:302
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer 
		= vlTOPp->io_frameBits;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:302
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer 
		= vlTOPp->io_frameBits;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1347
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg 
	= (0xfU & ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_30)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1347
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg 
	= (0xfU & ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_30)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:929
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer = VL_ULL(0);
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
			= ((QData)((IData)(vlTOPp->io_frameBits)) 
			   << 0x20U);
		} else {
		    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
			    = (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
					      << 0x20U));
		    } else {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
					= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:929
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer = VL_ULL(0);
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
			= ((QData)((IData)(vlTOPp->io_frameBits)) 
			   << 0x20U);
		} else {
		    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
			    = (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
					      << 0x20U));
		    } else {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
					= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1841
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	= (0xffffffU & ((IData)(vlTOPp->reset) ? 0U
			 : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U]));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1841
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	= (0xffffffU & ((IData)(vlTOPp->reset) ? 0U
			 : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U]));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2778
    vlTOPp->TopSimulator__DOT__dataInAirB = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2774
    vlTOPp->TopSimulator__DOT__dataInAir = (1U & ((IData)(vlTOPp->io_error)
						   ? 
						  (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out))
						   : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:248
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter = 0U;
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U <= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)))) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter 
			    = vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_60;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:248
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter = 0U;
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U <= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)))) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter 
			    = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_60;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:268
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 0U;
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:268
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 0U;
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1820
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame 
		= (1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1820
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame 
		= (1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1845
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter = 0U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)))) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)))) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter 
			    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_50;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1845
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter = 0U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)))) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)))) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter 
			    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_50;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1490
    if (((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	 & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)))) {
	__Vdlyvval__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 
	    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame;
	__Vdlyvset__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 = 1U;
	__Vdlyvdim0__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 
	    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1490
    if (((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	 & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)))) {
	__Vdlyvval__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 
	    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame;
	__Vdlyvset__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 = 1U;
	__Vdlyvdim0__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0 
	    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1311
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))) {
	    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
		= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
		    ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40)
		    : 0U);
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_45) {
		    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
			= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_52) {
			__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
			    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40;
		    }
		}
	    } else {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))) {
		    if ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))) {
			__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
		    }
		} else {
		    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))) {
			__Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
		    } else {
			if ((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))) {
			    __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1311
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))) {
	    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
		= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
		    ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40)
		    : 0U);
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_45) {
		    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
			= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_52) {
			__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
			    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40;
		    }
		}
	    } else {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))) {
		    if ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))) {
			__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
		    }
		} else {
		    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))) {
			__Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
		    } else {
			if ((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))) {
			    __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2614
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT___T_97) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx = 1U;
	} else {
	    if ((7U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2625
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT___T_105) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx = 1U;
	} else {
	    if ((8U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2614
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT___T_97) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx = 1U;
	} else {
	    if ((7U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2625
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT___T_105) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx = 1U;
	} else {
	    if ((8U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2573
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__firstTx = 1U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT___T_23) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__firstTx = 0U;
	} else {
	    if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__firstTx = 1U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2573
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__firstTx = 1U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT___T_23) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__firstTx = 0U;
	} else {
	    if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__firstTx = 1U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:487
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	 & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut))) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1 
	    = vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut;
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:487
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	 & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut))) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1 
	    = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut;
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2584
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMode = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) {
		vlTOPp->TopSimulator__DOT__tx__DOT__txMode = 0U;
	    }
	} else {
	    vlTOPp->TopSimulator__DOT__tx__DOT__txMode = 1U;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2584
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMode = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) {
		vlTOPp->TopSimulator__DOT__rx__DOT__txMode = 0U;
	    }
	} else {
	    vlTOPp->TopSimulator__DOT__rx__DOT__txMode = 1U;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2178
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2178
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2178
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2178
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0 
	= vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr;
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:790
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_45) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail) {
		__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 2U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx) {
		    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 3U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend) {
			__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 4U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send) {
			    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 1U;
			}
		    }
		}
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_48) {
		__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 5U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_50) {
		    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_51) {
			__Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_52) {
			    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_53) {
				if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
				}
			    } else {
				if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_56) {
				    if ((0x24U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					if ((0x23U 
					     == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					    __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:790
    if (vlTOPp->reset) {
	__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_45) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail) {
		__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 2U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx) {
		    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 3U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend) {
			__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 4U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send) {
			    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 1U;
			}
		    }
		}
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_48) {
		__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 5U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_50) {
		    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_51) {
			__Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_52) {
			    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_53) {
				if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54) {
				    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 6U;
				}
			    } else {
				if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_56) {
				    if ((0x24U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					if ((0x23U 
					     == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					    __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2121
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)) 
	 & (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)))) {
	vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT____Vlvbound1 
	    = (0xffffU & (IData)((vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
				  >> 8U)));
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2121
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)) 
	 & (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)))) {
	vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT____Vlvbound1 
	    = (0xffffU & (IData)((vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
				  >> 8U)));
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2121
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)) 
	 & (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)))) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT____Vlvbound1 
	    = vlTOPp->TopSimulator__DOT__tx__DOT__loadDataBuffer;
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr;
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2121
    if (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)) 
	 & (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)))) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT____Vlvbound1 
	    = vlTOPp->TopSimulator__DOT__rx__DOT__loadDataBuffer;
	if ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr))) {
	    __Vdlyvval__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT____Vlvbound1;
	    __Vdlyvset__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0 = 1U;
	    __Vdlyvdim0__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0 
		= vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr;
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
	= __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr 
	= __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr;
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
	= __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1491
    if (__Vdlyvset__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack[__Vdlyvdim0__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0] 
	    = __Vdlyvval__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0;
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr 
	= __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr;
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1491
    if (__Vdlyvset__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack[__Vdlyvdim0__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0] 
	    = __Vdlyvval__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:488
    if (__Vdlyvset__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack[__Vdlyvdim0__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0] 
	    = __Vdlyvval__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:488
    if (__Vdlyvset__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack[__Vdlyvdim0__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0] 
	    = __Vdlyvval__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2122
    if (__Vdlyvset__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0) {
	vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem[__Vdlyvdim0__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0] 
	    = __Vdlyvval__TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2122
    if (__Vdlyvset__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0) {
	vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem[__Vdlyvdim0__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0] 
	    = __Vdlyvval__TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2122
    if (__Vdlyvset__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem[__Vdlyvdim0__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0] 
	    = __Vdlyvval__TopSimulator__DOT__tx__DOT__txMemory__DOT__mem__v0;
    }
    // ALWAYSPOST at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2122
    if (__Vdlyvset__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem[__Vdlyvdim0__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0] 
	    = __Vdlyvval__TopSimulator__DOT__rx__DOT__txMemory__DOT__mem__v0;
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_27 = (0x3ffU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_27 = (0x3ffU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:490
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36)))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_61)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_65));
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:490
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36)))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_61)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_65));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	   & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	   & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer) 
	    << 8U) | (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer) 
	    << 8U) | (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:526
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut 
	= ((IData)(vlTOPp->reset) ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:526
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut 
	= ((IData)(vlTOPp->reset) ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:841
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if ((6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				    if ((0x24U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out 
					    = (1U & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_67));
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:841
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if ((6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				    if ((0x24U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter))) {
					vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out 
					    = (1U & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_67));
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_60 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_60 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_50 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_50 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1307
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	= (VL_ULL(0xfffffffff) & ((IData)(vlTOPp->reset)
				   ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_32));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1307
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	= (VL_ULL(0xfffffffff) & ((IData)(vlTOPp->reset)
				   ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_32));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1265
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_32) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 1U;
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_43) {
		if ((0x20U <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
		    if ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
			if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_57) {
			    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 4U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_58) {
				vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 3U;
			    } else {
				if ((0x20U < (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 2U;
				}
			    }
			}
		    }
		}
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_61) {
		    if ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
		    }
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_64) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_67) {
			    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1265
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_32) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 1U;
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_43) {
		if ((0x20U <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
		    if ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
			if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_57) {
			    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 4U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_58) {
				vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 3U;
			    } else {
				if ((0x20U < (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 2U;
				}
			    }
			}
		    }
		}
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_61) {
		    if ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
		    }
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_64) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_67) {
			    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:503
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr 
		= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_43)
		    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_47));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:514
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed 
		= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_40;
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_58;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:323
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut = VL_ULL(0);
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut 
			= vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_49;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut 
			    = vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_55;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:286
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)) 
					 & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42) 
					    & ((0x100U 
						> vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
					       | (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:503
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr 
		= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_43)
		    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_47));
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:514
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed 
		= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_40;
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_58;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:323
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut = VL_ULL(0);
    } else {
	if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42) {
		if ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut 
			= vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_49;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut 
			    = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_55;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:286
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)) 
					 & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42) 
					    & ((0x100U 
						> vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
					       | (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1790
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1790
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2154
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr = 0U;
    } else {
	if ((0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage))) {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52));
	    }
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr 
			= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48)
			    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52));
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2154
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr = 0U;
    } else {
	if ((0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage))) {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52));
	    }
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr 
			= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48)
			    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52));
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2154
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr = 0U;
    } else {
	if ((0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))) {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52));
	    }
	} else {
	    if ((4U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr 
			= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48)
			    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52));
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2154
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr = 0U;
    } else {
	if ((0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))) {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52));
	    }
	} else {
	    if ((4U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr 
			= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48)
			    ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52));
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:875
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 0U;
    } else {
	if ((6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 1U;
	} else {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:864
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 0U;
    } else {
	if ((5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 1U;
	} else {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:886
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend = 0U;
    } else {
	if ((8U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend = 1U;
	} else {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:897
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send = 0U;
    } else {
	if ((7U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send = 1U;
	} else {
	    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:875
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 0U;
    } else {
	if ((6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 1U;
	} else {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:864
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 0U;
    } else {
	if ((5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 1U;
	} else {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:886
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend = 0U;
    } else {
	if ((8U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend = 1U;
	} else {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend = 0U;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:897
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send = 0U;
    } else {
	if ((7U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send = 1U;
	} else {
	    if ((5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send = 0U;
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1831
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn = VL_ULL(0);
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2141
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr = 0U;
    } else {
	if ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_37)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_41));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1831
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn = VL_ULL(0);
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut;
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2141
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr = 0U;
    } else {
	if ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_37)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_41));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2595
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__loadDataBuffer = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
	    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_110)))) {
		if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_111)))) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_114)))) {
			if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_115)))) {
			    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT___T_116)))) {
				if (vlTOPp->TopSimulator__DOT__tx__DOT___T_117) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__loadDataBuffer 
					= vlTOPp->io_txin_bits;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2141
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr = 0U;
    } else {
	if ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage))) {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_37)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_41));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2595
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__loadDataBuffer = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
	    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_110)))) {
		if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_111)))) {
		    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_114)))) {
			if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_115)))) {
			    if ((1U & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT___T_116)))) {
				if (vlTOPp->TopSimulator__DOT__rx__DOT___T_117) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__loadDataBuffer 
					= vlTOPp->io_rxin_bits;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2141
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr = 0U;
    } else {
	if ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage))) {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr 
		    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_37)
		        ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_41));
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack
	   [vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0]
	    : VL_ULL(0));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack
	   [vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0]
	    : VL_ULL(0));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
	= __Vdly__TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter;
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter 
	= __Vdly__TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter;
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:952
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if ((6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				    if (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_58) {
					vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter 
					    = vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_71;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:952
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter = 0U;
	} else {
	    if ((1U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		if ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
		    if ((3U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			if ((4U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
			    if ((5U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				if ((6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state))) {
				    if (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_58) {
					vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter 
					    = vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_71;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_45 
	= (0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_52 
	= (0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_43 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_61 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_64 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_67 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_97 = ((4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						 | ((0x3e8U 
						     == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)) 
						    & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__firstTx)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_105 = ((3U 
						   == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						  | ((0x3e8U 
						      == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)) 
						     & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__firstTx))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1517
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed 
		= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_40;
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_58;
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_45 
	= (0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_52 
	= (0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_43 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_61 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_64 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_67 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_97 = ((4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						 | ((0x3e8U 
						     == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)) 
						    & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__firstTx)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_105 = ((3U 
						   == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						  | ((0x3e8U 
						      == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)) 
						     & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__firstTx))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1517
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36) {
	    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed 
		= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_40;
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_58;
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 
	= ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	   & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42 
	= (1U & ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut)) 
		 & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:264
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	= (0xffffffU & ((IData)(vlTOPp->reset) ? 0U
			 : vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 
	= ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	   & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42 
	= (1U & ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut)) 
		 & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData))));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:264
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	= (0xffffffU & ((IData)(vlTOPp->reset) ? 0U
			 : vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1529
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut 
	= ((IData)(vlTOPp->reset) ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data);
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2124
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_31) {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_45;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage 
			= vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57;
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1529
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut 
	= ((IData)(vlTOPp->reset) ? VL_ULL(0) : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data);
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2124
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_31) {
	    if ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_45;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage 
			= vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57;
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2124
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_31) {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57;
	    }
	} else {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_45;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage 
			= vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57;
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2124
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_31) {
	    if ((3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57;
	    }
	} else {
	    if ((4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state))) {
		vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage 
		    = vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_45;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage 
			= vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57;
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state 
	= __Vdly__TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state;
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state 
	= __Vdly__TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state;
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack
	[vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0];
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack
	[vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0];
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_58 
	= (0x24U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_71 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_67 
	= (VL_ULL(0xfffffffff) & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
				  >> (0x3fU & (((IData)(0x24U) 
						- (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter)) 
					       - (IData)(1U)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_45 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_48 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_50 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_51 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_52 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_53 
	= (5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_56 
	= (6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_58 
	= (0x24U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_71 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_67 
	= (VL_ULL(0xfffffffff) & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
				  >> (0x3fU & (((IData)(0x24U) 
						- (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter)) 
					       - (IData)(1U)))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_45 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_48 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_50 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_51 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_52 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_53 
	= (5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_56 
	= (6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 
	= (3U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 
	= (3U & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed) 
		 - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 
	= (3U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 
	= (3U & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed) 
		 - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage) 
		    - (IData)(1U)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2499
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT___T_109) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_110) {
		vlTOPp->TopSimulator__DOT__tx__DOT__state = 7U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT___T_111) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__state = 8U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_114) {
			vlTOPp->TopSimulator__DOT__tx__DOT__state 
			    = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass)
			        ? 5U : 6U);
		    } else {
			if (vlTOPp->TopSimulator__DOT__tx__DOT___T_115) {
			    vlTOPp->TopSimulator__DOT__tx__DOT__state = 2U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_116) {
				vlTOPp->TopSimulator__DOT__tx__DOT__state = 3U;
			    } else {
				if (vlTOPp->TopSimulator__DOT__tx__DOT___T_117) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__state = 4U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_118) {
		vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT___T_119) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_120) {
			vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__tx__DOT___T_121) {
			    vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_122) {
				vlTOPp->TopSimulator__DOT__tx__DOT__state = 1U;
			    } else {
				if (vlTOPp->TopSimulator__DOT__tx__DOT___T_123) {
				    vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
				} else {
				    if (vlTOPp->TopSimulator__DOT__tx__DOT___T_124) {
					vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
				    } else {
					if (vlTOPp->TopSimulator__DOT__tx__DOT___T_125) {
					    vlTOPp->TopSimulator__DOT__tx__DOT__state = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage) 
		    - (IData)(1U)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:2499
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT___T_109) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_110) {
		vlTOPp->TopSimulator__DOT__rx__DOT__state = 7U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT___T_111) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__state = 8U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_114) {
			vlTOPp->TopSimulator__DOT__rx__DOT__state 
			    = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass)
			        ? 5U : 6U);
		    } else {
			if (vlTOPp->TopSimulator__DOT__rx__DOT___T_115) {
			    vlTOPp->TopSimulator__DOT__rx__DOT__state = 2U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_116) {
				vlTOPp->TopSimulator__DOT__rx__DOT__state = 3U;
			    } else {
				if (vlTOPp->TopSimulator__DOT__rx__DOT___T_117) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__state = 4U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_118) {
		vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT___T_119) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_120) {
			vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
		    } else {
			if (vlTOPp->TopSimulator__DOT__rx__DOT___T_121) {
			    vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
			} else {
			    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_122) {
				vlTOPp->TopSimulator__DOT__rx__DOT__state = 1U;
			    } else {
				if (vlTOPp->TopSimulator__DOT__rx__DOT___T_123) {
				    vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
				} else {
				    if (vlTOPp->TopSimulator__DOT__rx__DOT___T_124) {
					vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
				    } else {
					if (vlTOPp->TopSimulator__DOT__rx__DOT___T_125) {
					    vlTOPp->TopSimulator__DOT__rx__DOT__state = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT___T_110 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_111 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_114 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) 
						  & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_116 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_110 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_111 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_114 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) 
						  & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_116 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->io_txin_ready = (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->io_txout_valid = (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_23 = ((7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)) 
						 | (8U 
						    == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_109 = (0U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_118 = (1U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_119 = (2U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_120 = (3U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_121 = (4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_122 = (5U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_123 = (6U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_124 = (7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_125 = (8U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33 
	= (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	    & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1805
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 0U;
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 1U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 0U;
		    }
		}
	    }
	}
    }
    vlTOPp->io_rxin_ready = (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->io_rxout_valid = (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_23 = ((7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)) 
						 | (8U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_109 = (0U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_118 = (1U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_119 = (2U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_120 = (3U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_121 = (4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_122 = (5U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_123 = (6U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_124 = (7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_125 = (8U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33 
	= (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	    & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1805
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 0U;
    } else {
	if ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
	    if ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))) {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 1U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = 0U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1862
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_32) {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = 1U;
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_40) {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44) {
		    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = 2U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = 2U;
		    }
		}
	    } else {
		if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_99) {
		    if (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102) {
			vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = 0U;
		    }
		}
	    }
	}
    }
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1862
    if (vlTOPp->reset) {
	vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = 0U;
    } else {
	if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_32) {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut) {
		vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = 1U;
	    }
	} else {
	    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_40) {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44) {
		    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = 2U;
		} else {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = 2U;
		    }
		}
	    } else {
		if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_99) {
		    if (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102) {
			vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = 0U;
		    }
		}
	    }
	}
    }
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)) 
	   & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)) 
	   & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_40 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_99 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1534
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36)) 
					 & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_40 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_99 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    // ALWAYS at /Users/sijun/Documents/work/projects/ooktrx/test_run_dir/TopSimulator_test_Random_Input/ooktrx.TopSimulatorSpec1999021112/TopSimulator.v:1534
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut 
	= ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36)) 
					 & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 
	= ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 
	= ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
}

void VTopSimulator::_settle__TOP__2(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_settle__TOP__2\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_27 = (0x3ffU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_27 = (0x3ffU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	   & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	   & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer) 
	    << 8U) | (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer) 
	    << 8U) | (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_60 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_60 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_50 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_50 
	= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem
	   [vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0]
	    : 0U);
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack
	   [vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0]
	    : VL_ULL(0));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data 
	= ((0x63U >= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0))
	    ? vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack
	   [vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0]
	    : VL_ULL(0));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
	   == (IData)(vlTOPp->io_frameBits));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
	   == (IData)(vlTOPp->io_frameBits));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_57 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
			      << 0x20U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_58 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == ((QData)((IData)(vlTOPp->io_frameBits)) 
	       << 0x20U));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_57 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
			      << 0x20U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_58 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == ((QData)((IData)(vlTOPp->io_frameBits)) 
	       << 0x20U));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_45 
	= (0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_52 
	= (0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_43 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_61 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_64 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_67 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_97 = ((4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						 | ((0x3e8U 
						     == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)) 
						    & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__firstTx)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_105 = ((3U 
						   == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						  | ((0x3e8U 
						      == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__counter)) 
						     & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__firstTx))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_45 
	= (0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_52 
	= (0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_43 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_61 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_64 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_67 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_97 = ((4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						 | ((0x3e8U 
						     == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)) 
						    & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__firstTx)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_105 = ((3U 
						   == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)) 
						  | ((0x3e8U 
						      == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__counter)) 
						     & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__firstTx))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 
	= ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	   & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42 
	= (1U & ((~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut)) 
		 & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 
	= ((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	   & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42 
	= (1U & ((~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut)) 
		 & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData))));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_37 
	= (0x63U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_41 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data 
	= vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack
	[vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0];
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data 
	= vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack
	[vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0];
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_58 
	= (0x24U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_71 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_67 
	= (VL_ULL(0xfffffffff) & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
				  >> (0x3fU & (((IData)(0x24U) 
						- (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter)) 
					       - (IData)(1U)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_45 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_48 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_50 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_51 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_52 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_53 
	= (5U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_56 
	= (6U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_58 
	= (0x24U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_71 
	= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_67 
	= (VL_ULL(0xfffffffff) & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer 
				  >> (0x3fU & (((IData)(0x24U) 
						- (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter)) 
					       - (IData)(1U)))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_45 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_48 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_50 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_51 
	= (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_52 
	= (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_53 
	= (5U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_56 
	= (6U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 
	= (3U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 
	= (3U & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed) 
		 - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 
	= (3U & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 
	= (3U & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed) 
		 - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	   == (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	   == (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_31 
	= (0x64U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_45 
	= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57 
	= (0x7fU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage) 
		    - (IData)(1U)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_110 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__crcPassAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_111 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__crcFailAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_114 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) 
						  & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMode)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_115 = ((IData)(vlTOPp->io_txout_ready) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_116 = ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_117 = ((IData)(vlTOPp->io_txin_valid) 
						  & (0x64U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_110 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__crcPassAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_111 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__crcFailAsTx) 
						  & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_114 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid) 
						  & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMode)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_115 = ((IData)(vlTOPp->io_rxout_ready) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_116 = ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_117 = ((IData)(vlTOPp->io_rxin_valid) 
						  & (0x64U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->io_txin_ready = (4U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->io_txout_valid = (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_23 = ((7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)) 
						 | (8U 
						    == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_109 = (0U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_118 = (1U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_119 = (2U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_120 = (3U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_121 = (4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_122 = (5U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_123 = (6U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_124 = (7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_125 = (8U 
						  == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33 
	= (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	    & (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)));
    vlTOPp->io_rxin_ready = (4U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->io_rxout_valid = (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_23 = ((7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)) 
						 | (8U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_109 = (0U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_118 = (1U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_119 = (2U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_120 = (3U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_121 = (4U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_122 = (5U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_123 = (6U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_124 = (7U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_125 = (8U 
						  == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46 
	= ((0U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33 
	= (((0x64U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed)) 
	    & (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData)) 
	   & (3U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__state)) 
	   & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44 
	= ((0U == vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
	   | (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	      == (IData)(vlTOPp->io_divisor)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	   < (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__state)) 
	   & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44 
	= ((0U == vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
	   | (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	      == (IData)(vlTOPp->io_divisor)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	   < (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_40 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_99 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_32 
	= (0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_40 
	= (1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_99 
	= (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 
	= ((2U != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 
	= ((2U != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)) 
	   & (2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 
	= (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame) 
	    & (~ (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut))) 
	   & (0U < (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_55 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((0xffffffU 
					 & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					    << 8U)))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_49 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					  << 8U) | 
					 (0xffU & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_55 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((0xffffffU 
					 & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					    << 8U)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_49 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					  << 8U) | 
					 (0xffU & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)))));
    vlTOPp->io_txout_bits = vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data;
    vlTOPp->io_rxout_bits = vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data;
}

VL_INLINE_OPT void VTopSimulator::_combo__TOP__3(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_combo__TOP__3\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp2,95,0,3);
    //char	__VpadToAlign124[4];
    VL_SIGW(__Vtemp3,95,0,3);
    //char	__VpadToAlign140[4];
    VL_SIGW(__Vtemp4,95,0,3);
    //char	__VpadToAlign156[4];
    VL_SIGW(__Vtemp5,95,0,3);
    //char	__VpadToAlign172[4];
    VL_SIGW(__Vtemp6,95,0,3);
    //char	__VpadToAlign188[4];
    VL_SIGW(__Vtemp7,95,0,3);
    //char	__VpadToAlign204[4];
    VL_SIGW(__Vtemp8,95,0,3);
    //char	__VpadToAlign220[4];
    VL_SIGW(__Vtemp12,95,0,3);
    //char	__VpadToAlign236[4];
    VL_SIGW(__Vtemp18,95,0,3);
    //char	__VpadToAlign252[4];
    VL_SIGW(__Vtemp23,95,0,3);
    //char	__VpadToAlign268[4];
    VL_SIGW(__Vtemp24,95,0,3);
    //char	__VpadToAlign284[4];
    VL_SIGW(__Vtemp25,95,0,3);
    //char	__VpadToAlign300[4];
    VL_SIGW(__Vtemp26,95,0,3);
    //char	__VpadToAlign316[4];
    VL_SIGW(__Vtemp27,95,0,3);
    //char	__VpadToAlign332[4];
    VL_SIGW(__Vtemp28,95,0,3);
    //char	__VpadToAlign348[4];
    VL_SIGW(__Vtemp29,95,0,3);
    //char	__VpadToAlign364[4];
    VL_SIGW(__Vtemp33,95,0,3);
    //char	__VpadToAlign380[4];
    VL_SIGW(__Vtemp39,95,0,3);
    //char	__VpadToAlign396[4];
    VL_SIGW(__Vtemp44,95,0,3);
    //char	__VpadToAlign412[4];
    VL_SIGW(__Vtemp45,95,0,3);
    //char	__VpadToAlign428[4];
    VL_SIGW(__Vtemp46,95,0,3);
    //char	__VpadToAlign444[4];
    VL_SIGW(__Vtemp47,95,0,3);
    //char	__VpadToAlign460[4];
    VL_SIGW(__Vtemp48,95,0,3);
    //char	__VpadToAlign476[4];
    VL_SIGW(__Vtemp49,95,0,3);
    //char	__VpadToAlign492[4];
    VL_SIGW(__Vtemp50,95,0,3);
    //char	__VpadToAlign508[4];
    VL_SIGW(__Vtemp54,95,0,3);
    //char	__VpadToAlign524[4];
    VL_SIGW(__Vtemp59,95,0,3);
    //char	__VpadToAlign540[4];
    VL_SIGW(__Vtemp66,95,0,3);
    //char	__VpadToAlign556[4];
    VL_SIGW(__Vtemp67,95,0,3);
    //char	__VpadToAlign572[4];
    VL_SIGW(__Vtemp68,95,0,3);
    //char	__VpadToAlign588[4];
    VL_SIGW(__Vtemp69,95,0,3);
    //char	__VpadToAlign604[4];
    VL_SIGW(__Vtemp70,95,0,3);
    //char	__VpadToAlign620[4];
    VL_SIGW(__Vtemp71,95,0,3);
    //char	__VpadToAlign636[4];
    VL_SIGW(__Vtemp72,95,0,3);
    //char	__VpadToAlign652[4];
    VL_SIGW(__Vtemp76,95,0,3);
    //char	__VpadToAlign668[4];
    VL_SIGW(__Vtemp81,95,0,3);
    // Body
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
	   == (IData)(vlTOPp->io_frameBits));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
	   == (IData)(vlTOPp->io_frameBits));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_57 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
			      << 0x20U)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_58 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == ((QData)((IData)(vlTOPp->io_frameBits)) 
	       << 0x20U));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_57 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == (VL_ULL(0xa) | ((QData)((IData)(vlTOPp->io_frameBits)) 
			      << 0x20U)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_58 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
	   == ((QData)((IData)(vlTOPp->io_frameBits)) 
	       << 0x20U));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	   == (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
	   == (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_115 = ((IData)(vlTOPp->io_txout_ready) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT___T_117 = ((IData)(vlTOPp->io_txin_valid) 
						  & (0x64U 
						     != (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_115 = ((IData)(vlTOPp->io_rxout_ready) 
						  & (0U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__rx__DOT___T_117 = ((IData)(vlTOPp->io_rxin_valid) 
						  & (0x64U 
						     != (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44 
	= ((0U == vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
	   | (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	      == (IData)(vlTOPp->io_divisor)));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46 
	= (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	   < (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44 
	= ((0U == vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
	   | (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	      == (IData)(vlTOPp->io_divisor)));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46 
	= (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
	   < (IData)(vlTOPp->io_divisor));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 
	= (0x1fU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
		     ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
			 ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			 : (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
			     << 1U) | (IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))
		     : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
			 ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
			     ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			     : ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
				 ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)))
			 : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 
	= (VL_ULL(0x1fffffffff) & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
				    ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
				        ? (QData)((IData)(
							  (0x1fU 
							   & (((IData)(vlTOPp->io_frameBits) 
							       << 1U) 
							      | (IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))))
				        : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				    : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
				        ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
					    ? ((vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
						<< 1U) 
					       | (QData)((IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))
					    : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				        : ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
					    ? ((2U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))
					        ? vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame
					        : VL_ULL(0))
					    : ((3U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
					        ? VL_ULL(0)
					        : (
						   (4U 
						    == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
						    ? VL_ULL(0)
						    : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame))))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 
	= (0x1fU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
		     ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
			 ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			 : (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
			     << 1U) | (IData)(vlTOPp->TopSimulator__DOT__dataInAir)))
		     : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
			 ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
			     ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			     : ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
				 ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)))
			 : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 
	= (VL_ULL(0x1fffffffff) & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
				    ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
				        ? (QData)((IData)(
							  (0x1fU 
							   & (((IData)(vlTOPp->io_frameBits) 
							       << 1U) 
							      | (IData)(vlTOPp->TopSimulator__DOT__dataInAir)))))
				        : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				    : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
				        ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
					    ? ((vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
						<< 1U) 
					       | (QData)((IData)(vlTOPp->TopSimulator__DOT__dataInAir)))
					    : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				        : ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
					    ? ((2U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))
					        ? vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame
					        : VL_ULL(0))
					    : ((3U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
					        ? VL_ULL(0)
					        : (
						   (4U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
						    ? VL_ULL(0)
						    : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame))))));
    VL_EXTEND_WI(72,24, __Vtemp2, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data) 
						<< 8U)));
    VL_EXTEND_WI(72,24, __Vtemp3, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp4, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp5, ((0xff8000U & ((0xffff8000U 
						  & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
						 ^ 
						 ((IData)(vlTOPp->io_divisor) 
						  << 0xfU))) 
				   | (0x7fffU & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)));
    VL_EXTEND_WI(72,9, __Vtemp6, (0x1ffU & ((IData)(
						    (VL_ULL(0xffffffffff) 
						     & (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
							 << (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)) 
							>> 0xfU))) 
					    ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp7, __Vtemp6, (0x1fU 
						& ((IData)(0xfU) 
						   - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp8, (0xffffffU & ((0xffffffU 
						 & (IData)(
							   (VL_ULL(0x7fffffffffffff) 
							    & ((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
							       << 
							       (0x1fU 
								& ((IData)(9U) 
								   + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))))))) 
						>> 
						(0x1fU 
						 & ((IData)(9U) 
						    + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp12, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp18, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp2[0U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			       ? ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				   ? __Vtemp3[0U] : 
				  ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				    ? __Vtemp4[0U] : 
				   ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
					   >> (0x1fU 
					       & ((IData)(0x17U) 
						  - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
				     ? ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					 ? __Vtemp5[0U]
					 : (__Vtemp7[0U] 
					    | __Vtemp8[0U]))
				     : __Vtemp12[0U])))
			       : __Vtemp18[0U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[1U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp2[1U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			       ? ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				   ? __Vtemp3[1U] : 
				  ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				    ? __Vtemp4[1U] : 
				   ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
					   >> (0x1fU 
					       & ((IData)(0x17U) 
						  - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
				     ? ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					 ? __Vtemp5[1U]
					 : (__Vtemp7[1U] 
					    | __Vtemp8[1U]))
				     : __Vtemp12[1U])))
			       : __Vtemp18[1U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[2U] 
	= (0xffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
		     ? __Vtemp2[2U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
				        ? ((0x100U 
					    > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
					    ? __Vtemp3[2U]
					    : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
					        ? __Vtemp4[2U]
					        : (
						   (1U 
						    & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						       >> 
						       (0x1fU 
							& ((IData)(0x17U) 
							   - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
						    ? 
						   ((0U 
						     == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						     ? 
						    __Vtemp5[2U]
						     : 
						    (__Vtemp7[2U] 
						     | __Vtemp8[2U]))
						    : 
						   __Vtemp12[2U])))
				        : __Vtemp18[2U])));
    VL_EXTEND_WI(72,24, __Vtemp23, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data) 
						 << 8U)));
    VL_EXTEND_WI(72,24, __Vtemp24, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp25, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp26, ((0xff8000U & ((0xffff8000U 
						   & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
						  ^ 
						  ((IData)(vlTOPp->io_divisor) 
						   << 0xfU))) 
				    | (0x7fffU & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)));
    VL_EXTEND_WI(72,9, __Vtemp27, (0x1ffU & ((IData)(
						     (VL_ULL(0xffffffffff) 
						      & (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
							  << (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)) 
							 >> 0xfU))) 
					     ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp28, __Vtemp27, (0x1fU 
						  & ((IData)(0xfU) 
						     - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp29, (0xffffffU & ((0xffffffU 
						  & (IData)(
							    (VL_ULL(0x7fffffffffffff) 
							     & ((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
								<< 
								(0x1fU 
								 & ((IData)(9U) 
								    + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))))))) 
						 >> 
						 (0x1fU 
						  & ((IData)(9U) 
						     + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp33, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp39, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp23[0U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			        ? ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				    ? __Vtemp24[0U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				        ? __Vtemp25[0U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					        ? __Vtemp26[0U]
					        : (
						   __Vtemp28[0U] 
						   | __Vtemp29[0U]))
					    : __Vtemp33[0U])))
			        : __Vtemp39[0U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[1U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp23[1U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			        ? ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				    ? __Vtemp24[1U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				        ? __Vtemp25[1U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					        ? __Vtemp26[1U]
					        : (
						   __Vtemp28[1U] 
						   | __Vtemp29[1U]))
					    : __Vtemp33[1U])))
			        : __Vtemp39[1U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[2U] 
	= (0xffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
		     ? __Vtemp23[2U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
					 ? ((0x100U 
					     > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
					     ? __Vtemp24[2U]
					     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
						 ? 
						__Vtemp25[2U]
						 : 
						((1U 
						  & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						     >> 
						     (0x1fU 
						      & ((IData)(0x17U) 
							 - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
						  ? 
						 ((0U 
						   == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						   ? 
						  __Vtemp26[2U]
						   : 
						  (__Vtemp28[2U] 
						   | __Vtemp29[2U]))
						  : 
						 __Vtemp33[2U])))
					 : __Vtemp39[2U])));
    VL_EXTEND_WI(72,24, __Vtemp44, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)
						  ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut)
						  : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,24, __Vtemp45, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp46, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp47, ((0xff8000U & ((0xffff8000U 
						   & vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
						  ^ 
						  ((IData)(vlTOPp->io_divisor) 
						   << 0xfU))) 
				    | (0x7fffU & vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,9, __Vtemp48, (0x1ffU & ((IData)(
						     (VL_ULL(0xffffffffff) 
						      & (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
							  << (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)) 
							 >> 0xfU))) 
					     ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp49, __Vtemp48, (0x1fU 
						  & ((IData)(0xfU) 
						     - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp50, (0xffffffU & ((0xffffffU 
						  & (IData)(
							    (VL_ULL(0x7fffffffffffff) 
							     & ((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
								<< 
								(0x1fU 
								 & ((IData)(9U) 
								    + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))))))) 
						 >> 
						 (0x1fU 
						  & ((IData)(9U) 
						     + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp54, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp59, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp44[0U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
			        ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				    ? __Vtemp45[0U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
				        ? __Vtemp46[0U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
					        ? __Vtemp47[0U]
					        : (
						   __Vtemp49[0U] 
						   | __Vtemp50[0U]))
					    : __Vtemp54[0U])))
			        : __Vtemp59[0U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[1U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp44[1U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
			        ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				    ? __Vtemp45[1U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
				        ? __Vtemp46[1U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
					        ? __Vtemp47[1U]
					        : (
						   __Vtemp49[1U] 
						   | __Vtemp50[1U]))
					    : __Vtemp54[1U])))
			        : __Vtemp59[1U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[2U] 
	= (0xffU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
		     ? __Vtemp44[2U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
					 ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
					     ? __Vtemp45[2U]
					     : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
						 ? 
						__Vtemp46[2U]
						 : 
						((1U 
						  & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						     >> 
						     (0x1fU 
						      & ((IData)(0x17U) 
							 - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
						  ? 
						 ((0U 
						   == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						   ? 
						  __Vtemp47[2U]
						   : 
						  (__Vtemp49[2U] 
						   | __Vtemp50[2U]))
						  : 
						 __Vtemp54[2U])))
					 : __Vtemp59[2U])));
    VL_EXTEND_WI(72,24, __Vtemp66, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)
						  ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut)
						  : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,24, __Vtemp67, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp68, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp69, ((0xff8000U & ((0xffff8000U 
						   & vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
						  ^ 
						  ((IData)(vlTOPp->io_divisor) 
						   << 0xfU))) 
				    | (0x7fffU & vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,9, __Vtemp70, (0x1ffU & ((IData)(
						     (VL_ULL(0xffffffffff) 
						      & (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
							  << (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)) 
							 >> 0xfU))) 
					     ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp71, __Vtemp70, (0x1fU 
						  & ((IData)(0xfU) 
						     - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp72, (0xffffffU & ((0xffffffU 
						  & (IData)(
							    (VL_ULL(0x7fffffffffffff) 
							     & ((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
								<< 
								(0x1fU 
								 & ((IData)(9U) 
								    + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))))))) 
						 >> 
						 (0x1fU 
						  & ((IData)(9U) 
						     + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp76, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp81, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp66[0U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
			        ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				    ? __Vtemp67[0U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
				        ? __Vtemp68[0U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
					        ? __Vtemp69[0U]
					        : (
						   __Vtemp71[0U] 
						   | __Vtemp72[0U]))
					    : __Vtemp76[0U])))
			        : __Vtemp81[0U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[1U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp66[1U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
			        ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				    ? __Vtemp67[1U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
				        ? __Vtemp68[1U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
					        ? __Vtemp69[1U]
					        : (
						   __Vtemp71[1U] 
						   | __Vtemp72[1U]))
					    : __Vtemp76[1U])))
			        : __Vtemp81[1U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[2U] 
	= (0xffU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
		     ? __Vtemp66[2U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
					 ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
					     ? __Vtemp67[2U]
					     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
						 ? 
						__Vtemp68[2U]
						 : 
						((1U 
						  & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						     >> 
						     (0x1fU 
						      & ((IData)(0x17U) 
							 - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
						  ? 
						 ((0U 
						   == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						   ? 
						  __Vtemp69[2U]
						   : 
						  (__Vtemp71[2U] 
						   | __Vtemp72[2U]))
						  : 
						 __Vtemp76[2U])))
					 : __Vtemp81[2U])));
}

VL_INLINE_OPT void VTopSimulator::_sequent__TOP__4(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_sequent__TOP__4\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_55 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((0xffffffU 
					 & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					    << 8U)))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_49 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					  << 8U) | 
					 (0xffU & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_55 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((0xffffffU 
					 & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					    << 8U)))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_49 
	= (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48)) 
	    << 0x18U) | (QData)((IData)((((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer) 
					  << 8U) | 
					 (0xffU & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)))));
    vlTOPp->io_txout_bits = vlTOPp->TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data;
    vlTOPp->io_rxout_bits = vlTOPp->TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data;
}

void VTopSimulator::_settle__TOP__5(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_settle__TOP__5\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign724[4];
    VL_SIGW(__Vtemp88,95,0,3);
    //char	__VpadToAlign740[4];
    VL_SIGW(__Vtemp89,95,0,3);
    //char	__VpadToAlign756[4];
    VL_SIGW(__Vtemp90,95,0,3);
    //char	__VpadToAlign772[4];
    VL_SIGW(__Vtemp91,95,0,3);
    //char	__VpadToAlign788[4];
    VL_SIGW(__Vtemp92,95,0,3);
    //char	__VpadToAlign804[4];
    VL_SIGW(__Vtemp93,95,0,3);
    //char	__VpadToAlign820[4];
    VL_SIGW(__Vtemp94,95,0,3);
    //char	__VpadToAlign836[4];
    VL_SIGW(__Vtemp98,95,0,3);
    //char	__VpadToAlign852[4];
    VL_SIGW(__Vtemp104,95,0,3);
    //char	__VpadToAlign868[4];
    VL_SIGW(__Vtemp109,95,0,3);
    //char	__VpadToAlign884[4];
    VL_SIGW(__Vtemp110,95,0,3);
    //char	__VpadToAlign900[4];
    VL_SIGW(__Vtemp111,95,0,3);
    //char	__VpadToAlign916[4];
    VL_SIGW(__Vtemp112,95,0,3);
    //char	__VpadToAlign932[4];
    VL_SIGW(__Vtemp113,95,0,3);
    //char	__VpadToAlign948[4];
    VL_SIGW(__Vtemp114,95,0,3);
    //char	__VpadToAlign964[4];
    VL_SIGW(__Vtemp115,95,0,3);
    //char	__VpadToAlign980[4];
    VL_SIGW(__Vtemp119,95,0,3);
    //char	__VpadToAlign996[4];
    VL_SIGW(__Vtemp125,95,0,3);
    //char	__VpadToAlign1012[4];
    VL_SIGW(__Vtemp130,95,0,3);
    //char	__VpadToAlign1028[4];
    VL_SIGW(__Vtemp131,95,0,3);
    //char	__VpadToAlign1044[4];
    VL_SIGW(__Vtemp132,95,0,3);
    //char	__VpadToAlign1060[4];
    VL_SIGW(__Vtemp133,95,0,3);
    //char	__VpadToAlign1076[4];
    VL_SIGW(__Vtemp134,95,0,3);
    //char	__VpadToAlign1092[4];
    VL_SIGW(__Vtemp135,95,0,3);
    //char	__VpadToAlign1108[4];
    VL_SIGW(__Vtemp136,95,0,3);
    //char	__VpadToAlign1124[4];
    VL_SIGW(__Vtemp140,95,0,3);
    //char	__VpadToAlign1140[4];
    VL_SIGW(__Vtemp145,95,0,3);
    //char	__VpadToAlign1156[4];
    VL_SIGW(__Vtemp152,95,0,3);
    //char	__VpadToAlign1172[4];
    VL_SIGW(__Vtemp153,95,0,3);
    //char	__VpadToAlign1188[4];
    VL_SIGW(__Vtemp154,95,0,3);
    //char	__VpadToAlign1204[4];
    VL_SIGW(__Vtemp155,95,0,3);
    //char	__VpadToAlign1220[4];
    VL_SIGW(__Vtemp156,95,0,3);
    //char	__VpadToAlign1236[4];
    VL_SIGW(__Vtemp157,95,0,3);
    //char	__VpadToAlign1252[4];
    VL_SIGW(__Vtemp158,95,0,3);
    //char	__VpadToAlign1268[4];
    VL_SIGW(__Vtemp162,95,0,3);
    //char	__VpadToAlign1284[4];
    VL_SIGW(__Vtemp167,95,0,3);
    // Body
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 
	= (0x1fU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
		     ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
			 ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			 : (((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
			     << 1U) | (IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))
		     : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
			 ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
			     ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			     : ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
				 ? 0U : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)))
			 : (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg))));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 
	= (VL_ULL(0x1fffffffff) & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
				    ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
				        ? (QData)((IData)(
							  (0x1fU 
							   & (((IData)(vlTOPp->io_frameBits) 
							       << 1U) 
							      | (IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))))
				        : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				    : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
				        ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
					    ? ((vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
						<< 1U) 
					       | (QData)((IData)(vlTOPp->TopSimulator__DOT__dataInAirB)))
					    : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				        : ((2U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
					    ? ((2U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))
					        ? vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame
					        : VL_ULL(0))
					    : ((3U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
					        ? VL_ULL(0)
					        : (
						   (4U 
						    == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state))
						    ? VL_ULL(0)
						    : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame))))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 
	= (0x1fU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
		     ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
			 ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			 : (((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg) 
			     << 1U) | (IData)(vlTOPp->TopSimulator__DOT__dataInAir)))
		     : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
			 ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
			     ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)
			     : ((0x1fU <= (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
				 ? 0U : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg)))
			 : (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg))));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 
	= (VL_ULL(0x1fffffffff) & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
				    ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk)
				        ? (QData)((IData)(
							  (0x1fU 
							   & (((IData)(vlTOPp->io_frameBits) 
							       << 1U) 
							      | (IData)(vlTOPp->TopSimulator__DOT__dataInAir)))))
				        : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				    : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
				        ? ((0x20U > (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter))
					    ? ((vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame 
						<< 1U) 
					       | (QData)((IData)(vlTOPp->TopSimulator__DOT__dataInAir)))
					    : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame)
				        : ((2U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
					    ? ((2U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed))
					        ? vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame
					        : VL_ULL(0))
					    : ((3U 
						== (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
					        ? VL_ULL(0)
					        : (
						   (4U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state))
						    ? VL_ULL(0)
						    : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame))))));
    VL_EXTEND_WI(72,24, __Vtemp88, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data) 
						 << 8U)));
    VL_EXTEND_WI(72,24, __Vtemp89, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp90, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp91, ((0xff8000U & ((0xffff8000U 
						   & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
						  ^ 
						  ((IData)(vlTOPp->io_divisor) 
						   << 0xfU))) 
				    | (0x7fffU & vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)));
    VL_EXTEND_WI(72,9, __Vtemp92, (0x1ffU & ((IData)(
						     (VL_ULL(0xffffffffff) 
						      & (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
							  << (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)) 
							 >> 0xfU))) 
					     ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp93, __Vtemp92, (0x1fU 
						  & ((IData)(0xfU) 
						     - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp94, (0xffffffU & ((0xffffffU 
						  & (IData)(
							    (VL_ULL(0x7fffffffffffff) 
							     & ((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
								<< 
								(0x1fU 
								 & ((IData)(9U) 
								    + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))))))) 
						 >> 
						 (0x1fU 
						  & ((IData)(9U) 
						     + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp98, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp104, vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp88[0U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			        ? ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				    ? __Vtemp89[0U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				        ? __Vtemp90[0U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					        ? __Vtemp91[0U]
					        : (
						   __Vtemp93[0U] 
						   | __Vtemp94[0U]))
					    : __Vtemp98[0U])))
			        : __Vtemp104[0U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[1U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp88[1U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
			        ? ((0x100U > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				    ? __Vtemp89[1U]
				    : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
				        ? __Vtemp90[1U]
				        : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						  >> 
						  (0x1fU 
						   & ((IData)(0x17U) 
						      - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					    ? ((0U 
						== (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
					        ? __Vtemp91[1U]
					        : (
						   __Vtemp93[1U] 
						   | __Vtemp94[1U]))
					    : __Vtemp98[1U])))
			        : __Vtemp104[1U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[2U] 
	= (0xffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
		     ? __Vtemp88[2U] : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
					 ? ((0x100U 
					     > vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
					     ? __Vtemp89[2U]
					     : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
						 ? 
						__Vtemp90[2U]
						 : 
						((1U 
						  & (vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						     >> 
						     (0x1fU 
						      & ((IData)(0x17U) 
							 - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
						  ? 
						 ((0U 
						   == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						   ? 
						  __Vtemp91[2U]
						   : 
						  (__Vtemp93[2U] 
						   | __Vtemp94[2U]))
						  : 
						 __Vtemp98[2U])))
					 : __Vtemp104[2U])));
    VL_EXTEND_WI(72,24, __Vtemp109, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data) 
						  << 8U)));
    VL_EXTEND_WI(72,24, __Vtemp110, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp111, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp112, ((0xff8000U & (
						   (0xffff8000U 
						    & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended) 
						   ^ 
						   ((IData)(vlTOPp->io_divisor) 
						    << 0xfU))) 
				     | (0x7fffU & vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)));
    VL_EXTEND_WI(72,9, __Vtemp113, (0x1ffU & ((IData)(
						      (VL_ULL(0xffffffffff) 
						       & (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
							   << (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)) 
							  >> 0xfU))) 
					      ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp114, __Vtemp113, 
		  (0x1fU & ((IData)(0xfU) - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp115, (0xffffffU & ((0xffffffU 
						   & (IData)(
							     (VL_ULL(0x7fffffffffffff) 
							      & ((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)) 
								 << 
								 (0x1fU 
								  & ((IData)(9U) 
								     + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))))))) 
						  >> 
						  (0x1fU 
						   & ((IData)(9U) 
						      + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp119, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    VL_EXTEND_WI(72,24, __Vtemp125, vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended);
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[0U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp109[0U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
				 ? ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				     ? __Vtemp110[0U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
					 ? __Vtemp111[0U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						 ? 
						__Vtemp112[0U]
						 : 
						(__Vtemp114[0U] 
						 | __Vtemp115[0U]))
					     : __Vtemp119[0U])))
				 : __Vtemp125[0U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[1U] 
	= ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
	    ? __Vtemp109[1U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
				 ? ((0x100U > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
				     ? __Vtemp110[1U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
					 ? __Vtemp111[1U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						 ? 
						__Vtemp112[1U]
						 : 
						(__Vtemp114[1U] 
						 | __Vtemp115[1U]))
					     : __Vtemp119[1U])))
				 : __Vtemp125[1U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20[2U] 
	= (0xffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33)
		     ? __Vtemp109[2U] : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42)
					  ? ((0x100U 
					      > vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended)
					      ? __Vtemp110[2U]
					      : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52)
						  ? 
						 __Vtemp111[2U]
						  : 
						 ((1U 
						   & (vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended 
						      >> 
						      (0x1fU 
						       & ((IData)(0x17U) 
							  - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter)))))
						   ? 
						  ((0U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter))
						    ? 
						   __Vtemp112[2U]
						    : 
						   (__Vtemp114[2U] 
						    | __Vtemp115[2U]))
						   : 
						  __Vtemp119[2U])))
					  : __Vtemp125[2U])));
    VL_EXTEND_WI(72,24, __Vtemp130, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)
						   ? (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut)
						   : vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,24, __Vtemp131, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp132, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp133, ((0xff8000U & (
						   (0xffff8000U 
						    & vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
						   ^ 
						   ((IData)(vlTOPp->io_divisor) 
						    << 0xfU))) 
				     | (0x7fffU & vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,9, __Vtemp134, (0x1ffU & ((IData)(
						      (VL_ULL(0xffffffffff) 
						       & (((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
							   << (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)) 
							  >> 0xfU))) 
					      ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp135, __Vtemp134, 
		  (0x1fU & ((IData)(0xfU) - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp136, (0xffffffU & ((0xffffffU 
						   & (IData)(
							     (VL_ULL(0x7fffffffffffff) 
							      & ((QData)((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
								 << 
								 (0x1fU 
								  & ((IData)(9U) 
								     + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))))))) 
						  >> 
						  (0x1fU 
						   & ((IData)(9U) 
						      + (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp140, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp145, vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp130[0U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
				 ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				     ? __Vtemp131[0U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
					 ? __Vtemp132[0U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						 ? 
						__Vtemp133[0U]
						 : 
						(__Vtemp135[0U] 
						 | __Vtemp136[0U]))
					     : __Vtemp140[0U])))
				 : __Vtemp145[0U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[1U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp130[1U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
				 ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				     ? __Vtemp131[1U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
					 ? __Vtemp132[1U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						 ? 
						__Vtemp133[1U]
						 : 
						(__Vtemp135[1U] 
						 | __Vtemp136[1U]))
					     : __Vtemp140[1U])))
				 : __Vtemp145[1U]));
    vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[2U] 
	= (0xffU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
		     ? __Vtemp130[2U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state))
					  ? ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
					      ? __Vtemp131[2U]
					      : ((IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
						  ? 
						 __Vtemp132[2U]
						  : 
						 ((1U 
						   & (vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						      >> 
						      (0x1fU 
						       & ((IData)(0x17U) 
							  - (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
						   ? 
						  ((0U 
						    == (IData)(vlTOPp->TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						    ? 
						   __Vtemp133[2U]
						    : 
						   (__Vtemp135[2U] 
						    | __Vtemp136[2U]))
						   : 
						  __Vtemp140[2U])))
					  : __Vtemp145[2U])));
    VL_EXTEND_WI(72,24, __Vtemp152, (0xffffffU & ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut)
						   ? (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut)
						   : vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,24, __Vtemp153, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp154, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp155, ((0xff8000U & (
						   (0xffff8000U 
						    & vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal) 
						   ^ 
						   ((IData)(vlTOPp->io_divisor) 
						    << 0xfU))) 
				     | (0x7fffU & vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)));
    VL_EXTEND_WI(72,9, __Vtemp156, (0x1ffU & ((IData)(
						      (VL_ULL(0xffffffffff) 
						       & (((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
							   << (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)) 
							  >> 0xfU))) 
					      ^ (IData)(vlTOPp->io_divisor))));
    VL_SHIFTL_WWI(72,72,5, __Vtemp157, __Vtemp156, 
		  (0x1fU & ((IData)(0xfU) - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))));
    VL_EXTEND_WI(72,24, __Vtemp158, (0xffffffU & ((0xffffffU 
						   & (IData)(
							     (VL_ULL(0x7fffffffffffff) 
							      & ((QData)((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal)) 
								 << 
								 (0x1fU 
								  & ((IData)(9U) 
								     + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))))))) 
						  >> 
						  (0x1fU 
						   & ((IData)(9U) 
						      + (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))))));
    VL_EXTEND_WI(72,24, __Vtemp162, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    VL_EXTEND_WI(72,24, __Vtemp167, vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal);
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[0U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp152[0U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
				 ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				     ? __Vtemp153[0U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
					 ? __Vtemp154[0U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						 ? 
						__Vtemp155[0U]
						 : 
						(__Vtemp157[0U] 
						 | __Vtemp158[0U]))
					     : __Vtemp162[0U])))
				 : __Vtemp167[0U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[1U] 
	= ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
	    ? __Vtemp152[1U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
				 ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
				     ? __Vtemp153[1U]
				     : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
					 ? __Vtemp154[1U]
					 : ((1U & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						   >> 
						   (0x1fU 
						    & ((IData)(0x17U) 
						       - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
					     ? ((0U 
						 == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						 ? 
						__Vtemp155[1U]
						 : 
						(__Vtemp157[1U] 
						 | __Vtemp158[1U]))
					     : __Vtemp162[1U])))
				 : __Vtemp167[1U]));
    vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28[2U] 
	= (0xffU & ((0U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
		     ? __Vtemp152[2U] : ((1U == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state))
					  ? ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44)
					      ? __Vtemp153[2U]
					      : ((IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46)
						  ? 
						 __Vtemp154[2U]
						  : 
						 ((1U 
						   & (vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal 
						      >> 
						      (0x1fU 
						       & ((IData)(0x17U) 
							  - (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter)))))
						   ? 
						  ((0U 
						    == (IData)(vlTOPp->TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter))
						    ? 
						   __Vtemp155[2U]
						    : 
						   (__Vtemp157[2U] 
						    | __Vtemp158[2U]))
						   : 
						  __Vtemp162[2U])))
					  : __Vtemp167[2U])));
}

void VTopSimulator::_eval(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_eval\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VTopSimulator::_eval_initial(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_eval_initial\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTopSimulator::final() {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::final\n"); );
    // Variables
    VTopSimulator__Syms* __restrict vlSymsp = this->__VlSymsp;
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTopSimulator::_eval_settle(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_eval_settle\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData VTopSimulator::_change_request(VTopSimulator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_change_request\n"); );
    VTopSimulator* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VTopSimulator::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_txin_ready = VL_RAND_RESET_I(1);
    io_txin_valid = VL_RAND_RESET_I(1);
    io_txin_bits = VL_RAND_RESET_I(16);
    io_txout_ready = VL_RAND_RESET_I(1);
    io_txout_valid = VL_RAND_RESET_I(1);
    io_txout_bits = VL_RAND_RESET_I(16);
    io_rxin_ready = VL_RAND_RESET_I(1);
    io_rxin_valid = VL_RAND_RESET_I(1);
    io_rxin_bits = VL_RAND_RESET_I(16);
    io_rxout_ready = VL_RAND_RESET_I(1);
    io_rxout_valid = VL_RAND_RESET_I(1);
    io_rxout_bits = VL_RAND_RESET_I(16);
    io_frameBits = VL_RAND_RESET_I(4);
    io_frameIndex = VL_RAND_RESET_I(8);
    io_divisor = VL_RAND_RESET_I(9);
    io_error = VL_RAND_RESET_I(1);
    TopSimulator__DOT__dataInAir = VL_RAND_RESET_I(1);
    TopSimulator__DOT__dataInAirB = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__state = VL_RAND_RESET_I(4);
    TopSimulator__DOT__tx__DOT__counter = VL_RAND_RESET_I(10);
    TopSimulator__DOT__tx__DOT___T_23 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_27 = VL_RAND_RESET_I(10);
    TopSimulator__DOT__tx__DOT__firstTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__txMode = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__loadDataBuffer = VL_RAND_RESET_I(16);
    TopSimulator__DOT__tx__DOT__crcPassAsTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__crcFailAsTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_97 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_105 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_109 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_110 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_111 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_114 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_115 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_116 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_117 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_118 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_119 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_120 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_121 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_122 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_123 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_124 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT___T_125 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__counter = VL_RAND_RESET_I(5);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended = VL_RAND_RESET_I(24);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__requestData = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__validOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer = VL_RAND_RESET_I(4);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer = VL_RAND_RESET_I(8);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer = VL_RAND_RESET_I(16);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_33 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_42 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_48 = VL_RAND_RESET_I(12);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_49 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_55 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___T_60 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(72,TopSimulator__DOT__tx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack[__Vi0] = VL_RAND_RESET_Q(36);
    }}
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__state = VL_RAND_RESET_I(3);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__out = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__crcFail = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__resend = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__send = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT__counter = VL_RAND_RESET_I(6);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_45 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_50 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_51 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_53 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_56 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_58 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_67 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ooktx__DOT__frameSend__DOT___T_71 = VL_RAND_RESET_I(6);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__state = VL_RAND_RESET_I(3);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = VL_RAND_RESET_I(6);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg = VL_RAND_RESET_I(4);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT__syncOk = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_32 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_40 = VL_RAND_RESET_I(6);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_43 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_45 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_57 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_58 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_61 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_64 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___T_67 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 = VL_RAND_RESET_I(5);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 = VL_RAND_RESET_Q(37);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack[__Vi0] = VL_RAND_RESET_Q(36);
    }}
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed = VL_RAND_RESET_I(2);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 = VL_RAND_RESET_I(2);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 = VL_RAND_RESET_I(2);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__frameIn = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__dataCal = VL_RAND_RESET_I(24);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__counter = VL_RAND_RESET_I(5);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT__state = VL_RAND_RESET_I(2);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_32 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_40 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_44 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_50 = VL_RAND_RESET_I(5);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_99 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___T_102 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(72,TopSimulator__DOT__tx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__tx__DOT__txMemory__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_data = VL_RAND_RESET_I(16);
    TopSimulator__DOT__tx__DOT__txMemory__DOT__memUsage = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_31 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_37 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_41 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_45 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_52 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT___T_57 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__txMemory__DOT____Vlvbound1 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_data = VL_RAND_RESET_I(16);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT__memUsage = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_31 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_37 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_41 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_45 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_52 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT___T_57 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__tx__DOT__rxMemory__DOT____Vlvbound1 = VL_RAND_RESET_I(16);
    TopSimulator__DOT__rx__DOT__state = VL_RAND_RESET_I(4);
    TopSimulator__DOT__rx__DOT__counter = VL_RAND_RESET_I(10);
    TopSimulator__DOT__rx__DOT___T_23 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_27 = VL_RAND_RESET_I(10);
    TopSimulator__DOT__rx__DOT__firstTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__txMode = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__loadDataBuffer = VL_RAND_RESET_I(16);
    TopSimulator__DOT__rx__DOT__crcPassAsTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__crcFailAsTx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_97 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_105 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_109 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_110 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_111 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_114 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_115 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_116 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_117 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_118 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_119 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_120 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_121 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_122 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_123 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_124 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT___T_125 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__counter = VL_RAND_RESET_I(5);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataExtended = VL_RAND_RESET_I(24);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__requestData = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__validOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameBitsBuffer = VL_RAND_RESET_I(4);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameIndexBuffer = VL_RAND_RESET_I(8);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__dataInBuffer = VL_RAND_RESET_I(16);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_33 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_42 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_48 = VL_RAND_RESET_I(12);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_49 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_55 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___T_60 = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(72,TopSimulator__DOT__rx__DOT__ooktx__DOT__crcEncode__DOT___GEN_20);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack[__Vi0] = VL_RAND_RESET_Q(36);
    }}
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_data = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stackUsed = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__frameValidOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_36 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_40 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_43 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_47 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_58 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_61 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT___T_65 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT__stack___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameStackTx__DOT____Vlvbound1 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__state = VL_RAND_RESET_I(3);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__out = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcPassAsRx = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__crcFail = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__resend = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__send = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__requestFrame = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__frameBuffer = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT__counter = VL_RAND_RESET_I(6);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_45 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_50 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_51 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_53 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_56 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_58 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_67 = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ooktx__DOT__frameSend__DOT___T_71 = VL_RAND_RESET_I(6);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__state = VL_RAND_RESET_I(3);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__wholeFrame = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__bitCounter = VL_RAND_RESET_I(6);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__frameBitsReg = VL_RAND_RESET_I(4);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT__syncOk = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_32 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_40 = VL_RAND_RESET_I(6);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_43 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_45 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_52 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_57 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_58 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_61 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_64 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___T_67 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_30 = VL_RAND_RESET_I(5);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameSync__DOT___GEN_32 = VL_RAND_RESET_Q(37);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack[__Vi0] = VL_RAND_RESET_Q(36);
    }}
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_data = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__readAddr = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__writeAddr = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stackUsed = VL_RAND_RESET_I(2);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameOut = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__frameValidOut = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_36 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_40 = VL_RAND_RESET_I(2);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_47 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_54 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_58 = VL_RAND_RESET_I(2);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT___T_65 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__frameStackRx__DOT__stack___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataOutValid = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__crcPass = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__requestFrame = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__frameIn = VL_RAND_RESET_Q(36);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__dataCal = VL_RAND_RESET_I(24);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__counter = VL_RAND_RESET_I(5);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT__state = VL_RAND_RESET_I(2);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_32 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_40 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_44 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_50 = VL_RAND_RESET_I(5);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_99 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___T_102 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(72,TopSimulator__DOT__rx__DOT__ookrx__DOT__crcCheck__DOT___GEN_28);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__rx__DOT__txMemory__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_data = VL_RAND_RESET_I(16);
    TopSimulator__DOT__rx__DOT__txMemory__DOT__memUsage = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_31 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_37 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_41 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_45 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_52 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT___T_57 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT__mem___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__txMemory__DOT____Vlvbound1 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<100; ++__Vi0) {
	    TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_data = VL_RAND_RESET_I(16);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT__memUsage = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT__writeAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT__readAddr = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_31 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_37 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_41 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_45 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_46 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_48 = VL_RAND_RESET_I(1);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_52 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT___T_57 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT__mem___05FT_29_addr_pipe_0 = VL_RAND_RESET_I(7);
    TopSimulator__DOT__rx__DOT__rxMemory__DOT____Vlvbound1 = VL_RAND_RESET_I(16);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VTopSimulator::_configure_coverage(VTopSimulator__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VTopSimulator::_configure_coverage\n"); );
}
