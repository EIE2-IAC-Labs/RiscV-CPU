// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram_top__Syms.h"


void Vram_top___024root__trace_chg_sub_0(Vram_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vram_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_chg_top_0\n"); );
    // Init
    Vram_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_top___024root*>(voidSelf);
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vram_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vram_top___024root__trace_chg_sub_0(Vram_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->write_en_i));
    bufp->chgBit(oldp+1,(vlSelf->clk_i));
    bufp->chgCData(oldp+2,(vlSelf->memtype_i),2);
    bufp->chgBit(oldp+3,(vlSelf->memsign_i));
    bufp->chgIData(oldp+4,(vlSelf->wd_i),32);
    bufp->chgIData(oldp+5,(vlSelf->a_i),32);
    bufp->chgIData(oldp+6,(vlSelf->rd_o),32);
    bufp->chgQData(oldp+7,(vlSelf->ram_top__DOT__WDWire),40);
    bufp->chgIData(oldp+9,(vlSelf->ram_top__DOT__RDWire),32);
    bufp->chgIData(oldp+10,((0xfffffffcU & vlSelf->a_i)),32);
    bufp->chgCData(oldp+11,((3U & vlSelf->a_i)),2);
}

void Vram_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_cleanup\n"); );
    // Init
    Vram_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_top___024root*>(voidSelf);
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
