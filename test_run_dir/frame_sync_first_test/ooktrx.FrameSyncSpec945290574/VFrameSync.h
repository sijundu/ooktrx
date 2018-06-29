// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFrameSync_H_
#define _VFrameSync_H_

#include "verilated.h"
class VFrameSync__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VFrameSync) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_in,0,0);
    VL_IN8(io_frameBits,3,0);
    VL_OUT8(io_syncOk,0,0);
    //char	__VpadToAlign5[3];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(FrameSync__DOT__fifoReg,3,0);
    VL_SIG8(FrameSync__DOT___T_14,4,0);
    //char	__VpadToAlign14[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign21[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFrameSync__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VFrameSync& operator= (const VFrameSync&);	///< Copying not allowed
    VFrameSync(const VFrameSync&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VFrameSync(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFrameSync();
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
    static void _eval_initial_loop(VFrameSync__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFrameSync__Syms* symsp, bool first);
  private:
    static QData	_change_request(VFrameSync__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__2(VFrameSync__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VFrameSync__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VFrameSync__Syms* __restrict vlSymsp);
    static void	_eval_initial(VFrameSync__Syms* __restrict vlSymsp);
    static void	_eval_settle(VFrameSync__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VFrameSync__Syms* __restrict vlSymsp);
    static void	traceChgThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VFrameSync__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
