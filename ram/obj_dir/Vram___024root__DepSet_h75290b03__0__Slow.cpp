// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram.h for the primary calling header

#include "verilated.h"

#include "Vram___024root.h"

VL_ATTR_COLD void Vram___024root___initial__TOP__0(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___initial__TOP__0\n"); );
    // Body
    VL_WRITEF("Loading ram.\n");
    VL_READMEM_N(true, 8, 4096, 0, std::string{"data.mem"}
                 ,  &(vlSelf->ram__DOT__ram_array), 0
                 , ~0ULL);
}

VL_ATTR_COLD void Vram___024root___eval_initial(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    Vram___024root___initial__TOP__0(vlSelf);
}

void Vram___024root___combo__TOP__0(Vram___024root* vlSelf);

VL_ATTR_COLD void Vram___024root___eval_settle(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_settle\n"); );
    // Body
    Vram___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vram___024root___final(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___final\n"); );
}

VL_ATTR_COLD void Vram___024root___ctor_var_reset(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->write_en_i = VL_RAND_RESET_I(1);
    vlSelf->AddrsCtrl_i = VL_RAND_RESET_I(1);
    vlSelf->a_i = VL_RAND_RESET_I(32);
    vlSelf->wd_i = VL_RAND_RESET_I(32);
    vlSelf->rd_o = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
}
