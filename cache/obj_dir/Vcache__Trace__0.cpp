// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcache__Syms.h"


void Vcache___024root__trace_chg_sub_0(Vcache___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcache___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_chg_top_0\n"); );
    // Init
    Vcache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcache___024root*>(voidSelf);
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcache___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcache___024root__trace_chg_sub_0(Vcache___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgIData(oldp+1,(vlSelf->dataWord0_i),32);
    bufp->chgIData(oldp+2,(vlSelf->dataWord1_i),32);
    bufp->chgIData(oldp+3,(vlSelf->dataWord2_i),32);
    bufp->chgIData(oldp+4,(vlSelf->dataWord3_i),32);
    bufp->chgIData(oldp+5,(vlSelf->addressWord_i),32);
    bufp->chgIData(oldp+6,(vlSelf->dataWord_o),32);
    bufp->chgBit(oldp+7,(vlSelf->hit_o));
    bufp->chgBit(oldp+8,((1U & (vlSelf->addressWord_i 
                                >> 4U))));
    bufp->chgIData(oldp+9,((vlSelf->addressWord_i >> 5U)),27);
    bufp->chgCData(oldp+10,((3U & (vlSelf->addressWord_i 
                                   >> 2U))),2);
}

void Vcache___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_cleanup\n"); );
    // Init
    Vcache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcache___024root*>(voidSelf);
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
