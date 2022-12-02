// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vram.h for the primary calling header

#ifndef VERILATED_VRAM___024ROOT_H_
#define VERILATED_VRAM___024ROOT_H_  // guard

#include "verilated.h"

class Vram__Syms;

class Vram___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(write_en_i,0,0);
    VL_IN8(AddrsCtrl_i,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(a_i,31,0);
    VL_IN(wd_i,31,0);
    VL_OUT(rd_o,31,0);
    VlUnpacked<CData/*7:0*/, 4096> ram__DOT__ram_array;

    // INTERNAL VARIABLES
    Vram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vram___024root(Vram__Syms* symsp, const char* name);
    ~Vram___024root();
    VL_UNCOPYABLE(Vram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
