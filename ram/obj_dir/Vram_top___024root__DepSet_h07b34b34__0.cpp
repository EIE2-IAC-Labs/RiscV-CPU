// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_top.h for the primary calling header

#include "verilated.h"

#include "Vram_top___024root.h"

VL_INLINE_OPT void Vram_top___024root___sequent__TOP__0(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___sequent__TOP__0\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v3;
    IData/*16:0*/ __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v4;
    CData/*0:0*/ __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v4;
    // Body
    __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v0 = 0U;
    __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v4 = 0U;
    if (VL_UNLIKELY(vlSelf->write_en_i)) {
        VL_WRITEF("%3#%3#%3#%3#\n",8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(3U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(2U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(1U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1fffcU & vlSelf->a_i)]);
        __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v0 
            = (0xffU & (IData)(vlSelf->ram_top__DOT__WDWire));
        __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v0 
            = (0x1fffcU & vlSelf->a_i);
        __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v1 
            = (0xffU & (IData)((vlSelf->ram_top__DOT__WDWire 
                                >> 8U)));
        __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v1 
            = (0x1ffffU & ((IData)(1U) + (0x1fffcU 
                                          & vlSelf->a_i)));
        __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v2 
            = (0xffU & (IData)((vlSelf->ram_top__DOT__WDWire 
                                >> 0x10U)));
        __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v2 
            = (0x1ffffU & ((IData)(2U) + (0x1fffcU 
                                          & vlSelf->a_i)));
        __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v3 
            = (0xffU & (IData)((vlSelf->ram_top__DOT__WDWire 
                                >> 0x18U)));
        __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v3 
            = (0x1ffffU & ((IData)(3U) + (0x1fffcU 
                                          & vlSelf->a_i)));
        if (((2U == (IData)(vlSelf->memtype_i)) & (3U 
                                                   == 
                                                   (3U 
                                                    & vlSelf->a_i)))) {
            __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v4 
                = (0xffU & (IData)((vlSelf->ram_top__DOT__WDWire 
                                    >> 0x20U)));
            __Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v4 = 1U;
            __Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v4 
                = (0x1ffffU & ((IData)(4U) + (0x1fffcU 
                                              & vlSelf->a_i)));
        }
    }
    if (__Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v0) {
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v0] 
            = __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v0;
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v1] 
            = __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v1;
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v2] 
            = __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v2;
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v3] 
            = __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v3;
    }
    if (__Vdlyvset__ram_top__DOT__ramnew__DOT__ram_array__v4) {
        vlSelf->ram_top__DOT__ramnew__DOT__ram_array[__Vdlyvdim0__ram_top__DOT__ramnew__DOT__ram_array__v4] 
            = __Vdlyvval__ram_top__DOT__ramnew__DOT__ram_array__v4;
    }
}

VL_INLINE_OPT void Vram_top___024root___combo__TOP__0(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___combo__TOP__0\n"); );
    // Body
    if (((2U == (IData)(vlSelf->memtype_i)) & (3U == 
                                               (3U 
                                                & vlSelf->a_i)))) {
        vlSelf->ram_top__DOT__RDWire = ((vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                         [(0x1ffffU 
                                           & ((IData)(4U) 
                                              + (0x1fffcU 
                                                 & vlSelf->a_i)))] 
                                         << 0x18U) 
                                        | (vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                           [(0x1ffffU 
                                             & ((IData)(3U) 
                                                + (0x1fffcU 
                                                   & vlSelf->a_i)))] 
                                           << 0x10U));
        VL_WRITEF("+++++++\n");
    } else {
        vlSelf->ram_top__DOT__RDWire = ((vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                         [(0x1ffffU 
                                           & ((IData)(3U) 
                                              + (0x1fffcU 
                                                 & vlSelf->a_i)))] 
                                         << 0x18U) 
                                        | ((vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                            [(0x1ffffU 
                                              & ((IData)(2U) 
                                                 + 
                                                 (0x1fffcU 
                                                  & vlSelf->a_i)))] 
                                            << 0x10U) 
                                           | ((vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                               [(0x1ffffU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    (0x1fffcU 
                                                     & vlSelf->a_i)))] 
                                               << 8U) 
                                              | vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                                              [(0x1fffcU 
                                                & vlSelf->a_i)])));
        VL_WRITEF("------\n%3#%3#%3#%3#\n",8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(3U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(2U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1ffffU & ((IData)(1U) + (0x1fffcU 
                                               & vlSelf->a_i)))],
                  8,vlSelf->ram_top__DOT__ramnew__DOT__ram_array
                  [(0x1fffcU & vlSelf->a_i)]);
    }
    if ((1U == (IData)(vlSelf->memtype_i))) {
        vlSelf->ram_top__DOT__WDWire = ((2U & vlSelf->a_i)
                                         ? ((1U & vlSelf->a_i)
                                             ? (((QData)((IData)(
                                                                 (0xffU 
                                                                  & vlSelf->wd_i))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  (0xffffffU 
                                                                   & vlSelf->ram_top__DOT__RDWire))))
                                             : (((QData)((IData)(
                                                                 (vlSelf->ram_top__DOT__RDWire 
                                                                  >> 0x18U))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  ((0xff0000U 
                                                                    & (vlSelf->wd_i 
                                                                       << 0x10U)) 
                                                                   | (0xffffU 
                                                                      & vlSelf->ram_top__DOT__RDWire))))))
                                         : ((1U & vlSelf->a_i)
                                             ? (((QData)((IData)(
                                                                 ((0xffff00U 
                                                                   & (vlSelf->ram_top__DOT__RDWire 
                                                                      >> 8U)) 
                                                                  | (0xffU 
                                                                     & vlSelf->wd_i)))) 
                                                 << 8U) 
                                                | (QData)((IData)(
                                                                  (0xffU 
                                                                   & vlSelf->ram_top__DOT__RDWire))))
                                             : (((QData)((IData)(
                                                                 (vlSelf->ram_top__DOT__RDWire 
                                                                  >> 8U))) 
                                                 << 8U) 
                                                | (QData)((IData)(
                                                                  (0xffU 
                                                                   & vlSelf->wd_i))))));
        if (vlSelf->memsign_i) {
            if (vlSelf->memsign_i) {
                vlSelf->rd_o = ((2U & vlSelf->a_i) ? 
                                ((1U & vlSelf->a_i)
                                  ? (vlSelf->ram_top__DOT__RDWire 
                                     >> 0x18U) : (0xffU 
                                                  & (vlSelf->ram_top__DOT__RDWire 
                                                     >> 0x10U)))
                                 : ((1U & vlSelf->a_i)
                                     ? (0xffU & (vlSelf->ram_top__DOT__RDWire 
                                                 >> 8U))
                                     : (0xffU & vlSelf->ram_top__DOT__RDWire)));
            }
        } else {
            vlSelf->rd_o = ((2U & vlSelf->a_i) ? ((1U 
                                                   & vlSelf->a_i)
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->ram_top__DOT__RDWire 
                                                                >> 0x1fU))) 
                                                    << 8U) 
                                                   | (vlSelf->ram_top__DOT__RDWire 
                                                      >> 0x18U))
                                                   : 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->ram_top__DOT__RDWire 
                                                                   >> 0x17U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & (vlSelf->ram_top__DOT__RDWire 
                                                         >> 0x10U))))
                             : ((1U & vlSelf->a_i) ? 
                                (((- (IData)((1U & 
                                              (vlSelf->ram_top__DOT__RDWire 
                                               >> 0xfU)))) 
                                  << 8U) | (0xffU & 
                                            (vlSelf->ram_top__DOT__RDWire 
                                             >> 8U)))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->ram_top__DOT__RDWire 
                                                    >> 7U)))) 
                                     << 8U) | (0xffU 
                                               & vlSelf->ram_top__DOT__RDWire))));
        }
    } else if ((2U == (IData)(vlSelf->memtype_i))) {
        vlSelf->ram_top__DOT__WDWire = ((2U & vlSelf->a_i)
                                         ? ((1U & vlSelf->a_i)
                                             ? (((QData)((IData)(
                                                                 (0xffffU 
                                                                  & vlSelf->wd_i))) 
                                                 << 0x18U) 
                                                | (QData)((IData)(
                                                                  (0xffffffU 
                                                                   & vlSelf->ram_top__DOT__RDWire))))
                                             : (((QData)((IData)(
                                                                 (0xffffU 
                                                                  & vlSelf->wd_i))) 
                                                 << 0x10U) 
                                                | (QData)((IData)(
                                                                  (0xffffU 
                                                                   & vlSelf->ram_top__DOT__RDWire)))))
                                         : ((1U & vlSelf->a_i)
                                             ? (((QData)((IData)(
                                                                 ((0xff0000U 
                                                                   & (vlSelf->ram_top__DOT__RDWire 
                                                                      >> 8U)) 
                                                                  | (0xffffU 
                                                                     & vlSelf->wd_i)))) 
                                                 << 8U) 
                                                | (QData)((IData)(
                                                                  (0xffU 
                                                                   & vlSelf->ram_top__DOT__RDWire))))
                                             : (((QData)((IData)(
                                                                 (vlSelf->ram_top__DOT__RDWire 
                                                                  >> 0x10U))) 
                                                 << 0x10U) 
                                                | (QData)((IData)(
                                                                  (0xffffU 
                                                                   & vlSelf->wd_i))))));
        if (vlSelf->memsign_i) {
            if (vlSelf->memsign_i) {
                vlSelf->rd_o = ((2U & vlSelf->a_i) ? 
                                ((1U & vlSelf->a_i)
                                  ? (vlSelf->ram_top__DOT__RDWire 
                                     >> 0x10U) : (vlSelf->ram_top__DOT__RDWire 
                                                  >> 0x10U))
                                 : ((1U & vlSelf->a_i)
                                     ? (0xffffU & (vlSelf->ram_top__DOT__RDWire 
                                                   >> 8U))
                                     : (0xffffU & vlSelf->ram_top__DOT__RDWire)));
            }
        } else {
            vlSelf->rd_o = ((2U & vlSelf->a_i) ? ((1U 
                                                   & vlSelf->a_i)
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->ram_top__DOT__RDWire 
                                                                >> 0x1fU))) 
                                                    << 0x10U) 
                                                   | (vlSelf->ram_top__DOT__RDWire 
                                                      >> 0x10U))
                                                   : 
                                                  (((- (IData)(
                                                               (vlSelf->ram_top__DOT__RDWire 
                                                                >> 0x1fU))) 
                                                    << 0x10U) 
                                                   | (vlSelf->ram_top__DOT__RDWire 
                                                      >> 0x10U)))
                             : ((1U & vlSelf->a_i) ? 
                                (((- (IData)((1U & 
                                              (vlSelf->ram_top__DOT__RDWire 
                                               >> 0x17U)))) 
                                  << 0x10U) | (0xffffU 
                                               & (vlSelf->ram_top__DOT__RDWire 
                                                  >> 8U)))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->ram_top__DOT__RDWire 
                                                    >> 0xfU)))) 
                                     << 0x10U) | (0xffffU 
                                                  & vlSelf->ram_top__DOT__RDWire))));
        }
    } else {
        vlSelf->ram_top__DOT__WDWire = (QData)((IData)(vlSelf->wd_i));
        vlSelf->rd_o = vlSelf->ram_top__DOT__RDWire;
    }
}

void Vram_top___024root___eval(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vram_top___024root___sequent__TOP__0(vlSelf);
    }
    Vram_top___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vram_top___024root___eval_debug_assertions(Vram_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->write_en_i & 0xfeU))) {
        Verilated::overWidthError("write_en_i");}
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->memtype_i & 0xfcU))) {
        Verilated::overWidthError("memtype_i");}
    if (VL_UNLIKELY((vlSelf->memsign_i & 0xfeU))) {
        Verilated::overWidthError("memsign_i");}
}
#endif  // VL_DEBUG
