// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_top.h for the primary calling header

#include "verilated.h"

#include "Vram_top___024root.h"

VL_ATTR_COLD void Vram_top___024root___initial__TOP__0(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___initial__TOP__0\n"); );
    // Body
    VL_WRITEF("Loading ram.\n");
    VL_READMEM_N(true, 8, 131072, 0, std::string{"data.mem"}
                 ,  &(vlSelf->ram_top__DOT__ramnew__DOT__ram_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vram_top___024root___eval_initial(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    Vram_top___024root___initial__TOP__0(vlSelf);
}

void Vram_top___024root___combo__TOP__0(Vram_top___024root* vlSelf);

VL_ATTR_COLD void Vram_top___024root___eval_settle(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___eval_settle\n"); );
    // Body
    Vram_top___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vram_top___024root___final(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___final\n"); );
}

VL_ATTR_COLD void Vram_top___024root___ctor_var_reset(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->write_en_i = VL_RAND_RESET_I(1);
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->memtype_i = VL_RAND_RESET_I(2);
    vlSelf->memsign_i = VL_RAND_RESET_I(1);
    vlSelf->wd_i = VL_RAND_RESET_I(32);
    vlSelf->a_i = VL_RAND_RESET_I(32);
    vlSelf->rd_o = VL_RAND_RESET_I(32);
    vlSelf->ram_top__DOT__WDWire = VL_RAND_RESET_Q(40);
    vlSelf->ram_top__DOT__RDWire = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
}
