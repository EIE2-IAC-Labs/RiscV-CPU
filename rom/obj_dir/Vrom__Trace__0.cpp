// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrom__Syms.h"


void Vrom___024root__trace_chg_sub_0(Vrom___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vrom___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root__trace_chg_top_0\n"); );
    // Init
    Vrom___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrom___024root*>(voidSelf);
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vrom___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vrom___024root__trace_chg_sub_0(Vrom___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->a_i),32);
    bufp->chgIData(oldp+1,(vlSelf->rd_o),32);
}

void Vrom___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root__trace_cleanup\n"); );
    // Init
    Vrom___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrom___024root*>(voidSelf);
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
