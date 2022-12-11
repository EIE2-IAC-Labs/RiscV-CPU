// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrom.h for the primary calling header

#include "verilated.h"

#include "Vrom__Syms.h"
#include "Vrom___024root.h"

void Vrom___024root___ctor_var_reset(Vrom___024root* vlSelf);

Vrom___024root::Vrom___024root(Vrom__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vrom___024root___ctor_var_reset(this);
}

void Vrom___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vrom___024root::~Vrom___024root() {
}
