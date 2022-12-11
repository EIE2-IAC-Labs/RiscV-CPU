// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vram_top.h for the primary calling header

#ifndef VERILATED_VRAM_TOP___024ROOT_H_
#define VERILATED_VRAM_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vram_top__Syms;

class Vram_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(write_en_i,0,0);
    VL_IN8(memtype_i,1,0);
    VL_IN8(memsign_i,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(wd_i,31,0);
    VL_IN(a_i,31,0);
    VL_OUT(rd_o,31,0);
    IData/*31:0*/ ram_top__DOT__RDWire;
    QData/*39:0*/ ram_top__DOT__WDWire;
    VlUnpacked<CData/*7:0*/, 131072> ram_top__DOT__ramnew__DOT__ram_array;

    // INTERNAL VARIABLES
    Vram_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vram_top___024root(Vram_top__Syms* symsp, const char* name);
    ~Vram_top___024root();
    VL_UNCOPYABLE(Vram_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
