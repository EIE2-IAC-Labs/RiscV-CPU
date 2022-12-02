// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram.h for the primary calling header

#include "verilated.h"

#include "Vram__Syms.h"
#include "Vram___024root.h"

void Vram___024root___ctor_var_reset(Vram___024root* vlSelf);

Vram___024root::Vram___024root(Vram__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vram___024root___ctor_var_reset(this);
}

void Vram___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vram___024root::~Vram___024root() {
}
