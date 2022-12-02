// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram.h for the primary calling header

#include "verilated.h"

#include "Vram___024root.h"

VL_INLINE_OPT void Vram___024root___sequent__TOP__0(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->write_en_i) & (IData)(vlSelf->AddrsCtrl_i)))) {
        vlSelf->ram__DOT__ram_array[(0xfffU & vlSelf->a_i)] 
            = (vlSelf->wd_i >> 0x18U);
        vlSelf->ram__DOT__ram_array[(0xfffU & ((IData)(1U) 
                                               + vlSelf->a_i))] 
            = (0xffU & (vlSelf->wd_i >> 0x10U));
        vlSelf->ram__DOT__ram_array[(0xfffU & ((IData)(2U) 
                                               + vlSelf->a_i))] 
            = (0xffU & (vlSelf->wd_i >> 8U));
        vlSelf->ram__DOT__ram_array[(0xfffU & ((IData)(3U) 
                                               + vlSelf->a_i))] 
            = (0xffU & vlSelf->wd_i);
        VL_WRITEF("%3#%3#%3#%3#\n",8,vlSelf->ram__DOT__ram_array
                  [(0xfffU & ((IData)(3U) + vlSelf->a_i))],
                  8,vlSelf->ram__DOT__ram_array[(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->a_i))],
                  8,vlSelf->ram__DOT__ram_array[(0xfffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->a_i))],
                  8,vlSelf->ram__DOT__ram_array[(0xfffU 
                                                 & vlSelf->a_i)]);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->write_en_i) & 
                     (~ (IData)(vlSelf->AddrsCtrl_i))))) {
        vlSelf->ram__DOT__ram_array[(0xfffU & vlSelf->a_i)] 
            = (0xffU & vlSelf->wd_i);
        VL_WRITEF("%3#\n",8,vlSelf->ram__DOT__ram_array
                  [(0xfffU & vlSelf->a_i)]);
    }
}

VL_INLINE_OPT void Vram___024root___combo__TOP__0(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___combo__TOP__0\n"); );
    // Body
    if (((~ (IData)(vlSelf->write_en_i)) & (IData)(vlSelf->AddrsCtrl_i))) {
        vlSelf->rd_o = ((vlSelf->ram__DOT__ram_array
                         [(0xfffU & vlSelf->a_i)] << 0x18U) 
                        | ((vlSelf->ram__DOT__ram_array
                            [(0xfffU & ((IData)(1U) 
                                        + vlSelf->a_i))] 
                            << 0x10U) | ((vlSelf->ram__DOT__ram_array
                                          [(0xfffU 
                                            & ((IData)(2U) 
                                               + vlSelf->a_i))] 
                                          << 8U) | 
                                         vlSelf->ram__DOT__ram_array
                                         [(0xfffU & 
                                           ((IData)(3U) 
                                            + vlSelf->a_i))])));
    }
    if ((1U & ((~ (IData)(vlSelf->write_en_i)) & (~ (IData)(vlSelf->AddrsCtrl_i))))) {
        if ((1U & (~ (vlSelf->ram__DOT__ram_array[(0xfffU 
                                                   & ((IData)(3U) 
                                                      + vlSelf->a_i))] 
                      >> 7U)))) {
            vlSelf->rd_o = vlSelf->ram__DOT__ram_array
                [(0xfffU & ((IData)(3U) + vlSelf->a_i))];
        }
        if ((0x80U & vlSelf->ram__DOT__ram_array[(0xfffU 
                                                  & ((IData)(3U) 
                                                     + vlSelf->a_i))])) {
            vlSelf->rd_o = (0xffffff00U | vlSelf->ram__DOT__ram_array
                            [(0xfffU & ((IData)(3U) 
                                        + vlSelf->a_i))]);
        }
    }
}

void Vram___024root___eval(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vram___024root___sequent__TOP__0(vlSelf);
    }
    Vram___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vram___024root___eval_debug_assertions(Vram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->write_en_i & 0xfeU))) {
        Verilated::overWidthError("write_en_i");}
    if (VL_UNLIKELY((vlSelf->AddrsCtrl_i & 0xfeU))) {
        Verilated::overWidthError("AddrsCtrl_i");}
}
#endif  // VL_DEBUG
