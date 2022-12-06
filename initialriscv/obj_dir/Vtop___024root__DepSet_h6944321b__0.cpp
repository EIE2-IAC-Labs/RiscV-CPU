// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__RegFile__DOT__register_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__RegFile__DOT__register_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__RegFile__DOT__register_array__v0;
    // Body
    __Vdlyvset__top__DOT__RegFile__DOT__register_array__v0 = 0U;
    vlSelf->top__DOT__PCWire = ((IData)(vlSelf->rst)
                                 ? 0U : vlSelf->top__DOT__next_PC);
    if ((0x13U == (0x7fU & vlSelf->InstructionWire))) {
        __Vdlyvval__top__DOT__RegFile__DOT__register_array__v0 
            = vlSelf->ALUoutWire;
        __Vdlyvset__top__DOT__RegFile__DOT__register_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__RegFile__DOT__register_array__v0 
            = (0x1fU & (vlSelf->InstructionWire >> 7U));
    }
    if (__Vdlyvset__top__DOT__RegFile__DOT__register_array__v0) {
        vlSelf->top__DOT__RegFile__DOT__register_array[__Vdlyvdim0__top__DOT__RegFile__DOT__register_array__v0] 
            = __Vdlyvval__top__DOT__RegFile__DOT__register_array__v0;
    }
    vlSelf->a0out = vlSelf->top__DOT__RegFile__DOT__register_array
        [0xaU];
    vlSelf->InstructionWire = ((((0x1bU >= (0x1fU & vlSelf->top__DOT__PCWire))
                                  ? vlSelf->top__DOT__romF__DOT__rom_array
                                 [(0x1fU & vlSelf->top__DOT__PCWire)]
                                  : 0U) << 0x18U) | 
                               ((((0x1bU >= (0x1fU 
                                             & ((IData)(1U) 
                                                + vlSelf->top__DOT__PCWire)))
                                   ? vlSelf->top__DOT__romF__DOT__rom_array
                                  [(0x1fU & ((IData)(1U) 
                                             + vlSelf->top__DOT__PCWire))]
                                   : 0U) << 0x10U) 
                                | ((((0x1bU >= (0x1fU 
                                                & ((IData)(2U) 
                                                   + vlSelf->top__DOT__PCWire)))
                                      ? vlSelf->top__DOT__romF__DOT__rom_array
                                     [(0x1fU & ((IData)(2U) 
                                                + vlSelf->top__DOT__PCWire))]
                                      : 0U) << 8U) 
                                   | ((0x1bU >= (0x1fU 
                                                 & ((IData)(3U) 
                                                    + vlSelf->top__DOT__PCWire)))
                                       ? vlSelf->top__DOT__romF__DOT__rom_array
                                      [(0x1fU & ((IData)(3U) 
                                                 + vlSelf->top__DOT__PCWire))]
                                       : 0U))));
    vlSelf->RD1Wire = vlSelf->top__DOT__RegFile__DOT__register_array
        [(0x1fU & (vlSelf->InstructionWire >> 0xfU))];
    vlSelf->top__DOT__ImmSrcWire = ((0x13U == (0x7fU 
                                               & vlSelf->InstructionWire))
                                     ? 0U : ((0x63U 
                                              == (0x7fU 
                                                  & vlSelf->InstructionWire))
                                              ? 1U : 0U));
    if ((0U == (IData)(vlSelf->top__DOT__ImmSrcWire))) {
        vlSelf->top__DOT__extendo__DOT__immediate = 
            (vlSelf->InstructionWire >> 0x14U);
        vlSelf->top__DOT__extendo__DOT__msb = (1U & 
                                               ((IData)(vlSelf->top__DOT__extendo__DOT__immediate) 
                                                >> 0xbU));
        vlSelf->ImmOpWire = (((- (IData)((IData)(vlSelf->top__DOT__extendo__DOT__msb))) 
                              << 0xcU) | (IData)(vlSelf->top__DOT__extendo__DOT__immediate));
    } else if ((1U == (IData)(vlSelf->top__DOT__ImmSrcWire))) {
        vlSelf->top__DOT__extendo__DOT__immediate = 
            ((0x800U & (vlSelf->InstructionWire >> 0x14U)) 
             | ((0x400U & (vlSelf->InstructionWire 
                           << 3U)) | ((0x3f0U & (vlSelf->InstructionWire 
                                                 >> 0x15U)) 
                                      | (0xfU & (vlSelf->InstructionWire 
                                                 >> 8U)))));
        vlSelf->top__DOT__extendo__DOT__msb = (1U & 
                                               ((IData)(vlSelf->top__DOT__extendo__DOT__immediate) 
                                                >> 0xbU));
        vlSelf->ImmOpWire = (((- (IData)((IData)(vlSelf->top__DOT__extendo__DOT__msb))) 
                              << 0xcU) | (IData)(vlSelf->top__DOT__extendo__DOT__immediate));
    } else {
        vlSelf->ImmOpWire = 0U;
    }
    vlSelf->Aluop2Wire = ((0x13U == (0x7fU & vlSelf->InstructionWire))
                           ? vlSelf->ImmOpWire : vlSelf->top__DOT__RegFile__DOT__register_array
                          [(0x1fU & (vlSelf->InstructionWire 
                                     >> 0x14U))]);
    vlSelf->ALUoutWire = ((0x4000U & vlSelf->InstructionWire)
                           ? ((0x2000U & vlSelf->InstructionWire)
                               ? ((0x1000U & vlSelf->InstructionWire)
                                   ? 0U : 0U) : 0U)
                           : ((0x2000U & vlSelf->InstructionWire)
                               ? 0U : ((0x1000U & vlSelf->InstructionWire)
                                        ? 0U : (vlSelf->RD1Wire 
                                                + vlSelf->Aluop2Wire))));
    vlSelf->top__DOT__next_PC = (((0x13U != (0x7fU 
                                             & vlSelf->InstructionWire)) 
                                  & ((0x63U == (0x7fU 
                                                & vlSelf->InstructionWire)) 
                                     & (vlSelf->RD1Wire 
                                        != vlSelf->Aluop2Wire)))
                                  ? (vlSelf->top__DOT__PCWire 
                                     + vlSelf->ImmOpWire)
                                  : ((IData)(4U) + vlSelf->top__DOT__PCWire));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
