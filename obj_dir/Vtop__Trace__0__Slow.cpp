// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+2,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+3,"ALUctrl_i", false,-1, 3,0);
    tracep->declBus(c+4,"BranchCtrl_i", false,-1, 2,0);
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBus(c+6,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+7,"Branch_o", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+8,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"SHIFT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+2,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+3,"ALUctrl_i", false,-1, 3,0);
    tracep->declBus(c+4,"BranchCtrl_i", false,-1, 2,0);
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBus(c+6,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+7,"Branch_o", false,-1);
    tracep->pushNamePrefix("test_alu ");
    tracep->declBus(c+8,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"SHIFT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+2,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+3,"ALUctrl_i", false,-1, 3,0);
    tracep->declBus(c+4,"BranchCtrl_i", false,-1, 2,0);
    tracep->declBus(c+6,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+7,"Branch_o", false,-1);
    tracep->declBus(c+1,"SrcA_Signed", false,-1, 31,0);
    tracep->declBus(c+2,"SrcB_Signed", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->SrcA_i),32);
    bufp->fullIData(oldp+2,(vlSelf->SrcB_i),32);
    bufp->fullCData(oldp+3,(vlSelf->ALUctrl_i),4);
    bufp->fullCData(oldp+4,(vlSelf->BranchCtrl_i),3);
    bufp->fullBit(oldp+5,(vlSelf->clk));
    bufp->fullIData(oldp+6,(vlSelf->ALUResult_o),32);
    bufp->fullBit(oldp+7,(vlSelf->Branch_o));
    bufp->fullIData(oldp+8,(0x20U),32);
    bufp->fullIData(oldp+9,(5U),32);
}
