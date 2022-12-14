// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcache.h for the primary calling header

#include "verilated.h"

#include "Vcache___024root.h"

VL_ATTR_COLD void Vcache___024root___eval_initial(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___eval_initial\n"); );
}

void Vcache___024root___combo__TOP__0(Vcache___024root* vlSelf);

VL_ATTR_COLD void Vcache___024root___eval_settle(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___eval_settle\n"); );
    // Body
    Vcache___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vcache___024root___final(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___final\n"); );
}

VL_ATTR_COLD void Vcache___024root___ctor_var_reset(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->dataWord0_i = VL_RAND_RESET_I(32);
    vlSelf->dataWord1_i = VL_RAND_RESET_I(32);
    vlSelf->dataWord2_i = VL_RAND_RESET_I(32);
    vlSelf->dataWord3_i = VL_RAND_RESET_I(32);
    vlSelf->addressWord_i = VL_RAND_RESET_I(32);
    vlSelf->dataWord_o = VL_RAND_RESET_I(32);
    vlSelf->hit_o = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__V[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__tag[__Vi0] = VL_RAND_RESET_I(27);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__data0[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__data1[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__data2[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->cache__DOT__data3[__Vi0] = VL_RAND_RESET_I(32);
    }
}
