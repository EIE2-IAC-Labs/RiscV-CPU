// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*2:0*/ top__DOT__ImmSrcWire;
    CData/*0:0*/ top__DOT__extendo__DOT__msb;
    CData/*0:0*/ __Vclklast__TOP__clk;
    SData/*11:0*/ top__DOT__extendo__DOT__immediate;
    VL_OUT(a0out,31,0);
    VL_OUT(InstructionWire,31,0);
    VL_OUT(ImmOpWire,31,0);
    VL_OUT(Aluop2Wire,31,0);
    VL_OUT(RD1Wire,31,0);
    VL_OUT(ALUoutWire,31,0);
    IData/*31:0*/ top__DOT__PCWire;
    IData/*31:0*/ top__DOT__next_PC;
    IData/*31:0*/ top__DOT__RegFile__DOT__unnamedblk1__DOT__i;
    VlUnpacked<CData/*7:0*/, 28> top__DOT__romF__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__RegFile__DOT__register_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
