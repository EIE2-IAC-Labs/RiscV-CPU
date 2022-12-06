// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->Branch_o = ((4U & (IData)(vlSelf->BranchCtrl_i))
                         ? ((~ ((IData)(vlSelf->BranchCtrl_i) 
                                >> 1U)) & ((1U & (IData)(vlSelf->BranchCtrl_i))
                                            ? (vlSelf->SrcA_i 
                                               >= vlSelf->SrcB_i)
                                            : (vlSelf->SrcA_i 
                                               < vlSelf->SrcB_i)))
                         : ((2U & (IData)(vlSelf->BranchCtrl_i))
                             ? ((1U & (IData)(vlSelf->BranchCtrl_i))
                                 ? VL_GTES_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i)
                                 : VL_LTS_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i))
                             : ((1U & (IData)(vlSelf->BranchCtrl_i))
                                 ? (vlSelf->SrcA_i 
                                    != vlSelf->SrcB_i)
                                 : (vlSelf->SrcA_i 
                                    == vlSelf->SrcB_i))));
    vlSelf->ALUResult_o = ((8U & (IData)(vlSelf->ALUctrl_i))
                            ? ((4U & (IData)(vlSelf->ALUctrl_i))
                                ? ((2U & (IData)(vlSelf->ALUctrl_i))
                                    ? ((1U & (IData)(vlSelf->ALUctrl_i))
                                        ? vlSelf->SrcB_i
                                        : 0U) : 0U)
                                : ((2U & (IData)(vlSelf->ALUctrl_i))
                                    ? ((1U & (IData)(vlSelf->ALUctrl_i))
                                        ? 0U : (vlSelf->SrcA_i 
                                                << 
                                                (0x1fU 
                                                 & vlSelf->SrcB_i)))
                                    : ((1U & (IData)(vlSelf->ALUctrl_i))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelf->SrcA_i, 
                                                         (0x1fU 
                                                          & vlSelf->SrcB_i))
                                        : 0U))) : (
                                                   (4U 
                                                    & (IData)(vlSelf->ALUctrl_i))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ALUctrl_i))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ALUctrl_i))
                                                      ? 
                                                     (vlSelf->SrcA_i 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->SrcB_i))
                                                      : 
                                                     ((vlSelf->SrcA_i 
                                                       >= vlSelf->SrcB_i)
                                                       ? 0U
                                                       : 1U))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ALUctrl_i))
                                                      ? 
                                                     (VL_GTES_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i)
                                                       ? 0U
                                                       : 1U)
                                                      : 
                                                     (vlSelf->SrcA_i 
                                                      ^ vlSelf->SrcB_i)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ALUctrl_i))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ALUctrl_i))
                                                      ? 
                                                     (vlSelf->SrcA_i 
                                                      | vlSelf->SrcB_i)
                                                      : 
                                                     (vlSelf->SrcA_i 
                                                      & vlSelf->SrcB_i))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ALUctrl_i))
                                                      ? 
                                                     (vlSelf->SrcA_i 
                                                      - vlSelf->SrcB_i)
                                                      : 
                                                     (vlSelf->SrcA_i 
                                                      + vlSelf->SrcB_i)))));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ALUctrl_i & 0xf0U))) {
        Verilated::overWidthError("ALUctrl_i");}
    if (VL_UNLIKELY((vlSelf->BranchCtrl_i & 0xf8U))) {
        Verilated::overWidthError("BranchCtrl_i");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
