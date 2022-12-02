// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram__Syms.h"


VL_ATTR_COLD void Vram___024root__trace_init_sub__TOP__0(Vram___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"write_en_i", false,-1);
    tracep->declBit(c+3,"AddrsCtrl_i", false,-1);
    tracep->declBus(c+4,"a_i", false,-1, 31,0);
    tracep->declBus(c+5,"wd_i", false,-1, 31,0);
    tracep->declBus(c+6,"rd_o", false,-1, 31,0);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+7,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+8,"DATA_W", false,-1, 31,0);
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"write_en_i", false,-1);
    tracep->declBit(c+3,"AddrsCtrl_i", false,-1);
    tracep->declBus(c+4,"a_i", false,-1, 31,0);
    tracep->declBus(c+5,"wd_i", false,-1, 31,0);
    tracep->declBus(c+6,"rd_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vram___024root__trace_init_top(Vram___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_init_top\n"); );
    // Body
    Vram___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vram___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vram___024root__trace_register(Vram___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vram___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vram___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vram___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vram___024root__trace_full_sub_0(Vram___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vram___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_full_top_0\n"); );
    // Init
    Vram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram___024root*>(voidSelf);
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vram___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vram___024root__trace_full_sub_0(Vram___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk_i));
    bufp->fullBit(oldp+2,(vlSelf->write_en_i));
    bufp->fullBit(oldp+3,(vlSelf->AddrsCtrl_i));
    bufp->fullIData(oldp+4,(vlSelf->a_i),32);
    bufp->fullIData(oldp+5,(vlSelf->wd_i),32);
    bufp->fullIData(oldp+6,(vlSelf->rd_o),32);
    bufp->fullIData(oldp+7,(0x20U),32);
    bufp->fullIData(oldp+8,(8U),32);
}
