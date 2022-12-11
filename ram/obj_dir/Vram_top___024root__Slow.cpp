// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_top.h for the primary calling header

#include "verilated.h"

#include "Vram_top__Syms.h"
#include "Vram_top___024root.h"

void Vram_top___024root___ctor_var_reset(Vram_top___024root* vlSelf);

Vram_top___024root::Vram_top___024root(Vram_top__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vram_top___024root___ctor_var_reset(this);
}

void Vram_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vram_top___024root::~Vram_top___024root() {
}
