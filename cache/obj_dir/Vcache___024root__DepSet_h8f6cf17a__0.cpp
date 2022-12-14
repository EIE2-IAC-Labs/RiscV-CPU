// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcache.h for the primary calling header

#include "verilated.h"

#include "Vcache___024root.h"

VL_INLINE_OPT void Vcache___024root___combo__TOP__0(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->hit_o = ((vlSelf->cache__DOT__tag[(1U & 
                                               (vlSelf->addressWord_i 
                                                >> 4U))] 
                      == (vlSelf->addressWord_i >> 5U)) 
                     & vlSelf->cache__DOT__V[(1U & 
                                              (vlSelf->addressWord_i 
                                               >> 4U))]);
    if (vlSelf->hit_o) {
        vlSelf->dataWord_o = ((8U & vlSelf->addressWord_i)
                               ? ((4U & vlSelf->addressWord_i)
                                   ? vlSelf->cache__DOT__data3
                                  [(1U & (vlSelf->addressWord_i 
                                          >> 4U))] : 
                                  vlSelf->cache__DOT__data2
                                  [(1U & (vlSelf->addressWord_i 
                                          >> 4U))])
                               : ((4U & vlSelf->addressWord_i)
                                   ? vlSelf->cache__DOT__data1
                                  [(1U & (vlSelf->addressWord_i 
                                          >> 4U))] : 
                                  vlSelf->cache__DOT__data0
                                  [(1U & (vlSelf->addressWord_i 
                                          >> 4U))]));
    }
}

void Vcache___024root___eval(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___eval\n"); );
    // Body
    Vcache___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vcache___024root___eval_debug_assertions(Vcache___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
