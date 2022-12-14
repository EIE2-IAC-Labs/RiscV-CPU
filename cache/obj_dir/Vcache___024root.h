// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcache.h for the primary calling header

#ifndef VERILATED_VCACHE___024ROOT_H_
#define VERILATED_VCACHE___024ROOT_H_  // guard

#include "verilated.h"

class Vcache__Syms;

class Vcache___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(hit_o,0,0);
    VL_IN(dataWord0_i,31,0);
    VL_IN(dataWord1_i,31,0);
    VL_IN(dataWord2_i,31,0);
    VL_IN(dataWord3_i,31,0);
    VL_IN(addressWord_i,31,0);
    VL_OUT(dataWord_o,31,0);
    VlUnpacked<CData/*0:0*/, 2> cache__DOT__V;
    VlUnpacked<IData/*26:0*/, 2> cache__DOT__tag;
    VlUnpacked<IData/*31:0*/, 2> cache__DOT__data0;
    VlUnpacked<IData/*31:0*/, 2> cache__DOT__data1;
    VlUnpacked<IData/*31:0*/, 2> cache__DOT__data2;
    VlUnpacked<IData/*31:0*/, 2> cache__DOT__data3;

    // INTERNAL VARIABLES
    Vcache__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcache___024root(Vcache__Syms* symsp, const char* name);
    ~Vcache___024root();
    VL_UNCOPYABLE(Vcache___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
