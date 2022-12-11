// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram_top__Syms.h"


VL_ATTR_COLD void Vram_top___024root__trace_init_sub__TOP__0(Vram_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"write_en_i", false,-1);
    tracep->declBit(c+2,"clk_i", false,-1);
    tracep->declBus(c+3,"memtype_i", false,-1, 1,0);
    tracep->declBit(c+4,"memsign_i", false,-1);
    tracep->declBus(c+5,"wd_i", false,-1, 31,0);
    tracep->declBus(c+6,"a_i", false,-1, 31,0);
    tracep->declBus(c+7,"rd_o", false,-1, 31,0);
    tracep->pushNamePrefix("ram_top ");
    tracep->declBus(c+13,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"write_en_i", false,-1);
    tracep->declBit(c+2,"clk_i", false,-1);
    tracep->declBus(c+3,"memtype_i", false,-1, 1,0);
    tracep->declBit(c+4,"memsign_i", false,-1);
    tracep->declBus(c+5,"wd_i", false,-1, 31,0);
    tracep->declBus(c+6,"a_i", false,-1, 31,0);
    tracep->declBus(c+7,"rd_o", false,-1, 31,0);
    tracep->declQuad(c+8,"WDWire", false,-1, 39,0);
    tracep->declBus(c+10,"RDWire", false,-1, 31,0);
    tracep->declBus(c+11,"a_ii", false,-1, 31,0);
    tracep->declBus(c+12,"a_i_end", false,-1, 1,0);
    tracep->pushNamePrefix("ram_i ");
    tracep->declBus(c+13,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"memtype_i", false,-1, 1,0);
    tracep->declBus(c+10,"rd_i", false,-1, 31,0);
    tracep->declBus(c+5,"wd_i", false,-1, 31,0);
    tracep->declBus(c+6,"a_i", false,-1, 31,0);
    tracep->declQuad(c+8,"wd_o", false,-1, 39,0);
    tracep->declBus(c+12,"whichbyte_i", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram_o ");
    tracep->declBus(c+13,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"memtype_i", false,-1, 1,0);
    tracep->declBit(c+4,"memsign_i", false,-1);
    tracep->declBus(c+10,"rd_i", false,-1, 31,0);
    tracep->declBus(c+6,"a_i", false,-1, 31,0);
    tracep->declBus(c+7,"rd_o", false,-1, 31,0);
    tracep->declBus(c+12,"whichbyte_i", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ramnew ");
    tracep->declBus(c+13,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+14,"DATA_W", false,-1, 31,0);
    tracep->declBit(c+2,"clk_i", false,-1);
    tracep->declBit(c+1,"write_en_i", false,-1);
    tracep->declBus(c+3,"memtype_i", false,-1, 1,0);
    tracep->declBus(c+11,"a_i", false,-1, 31,0);
    tracep->declBus(c+12,"a_i_end", false,-1, 1,0);
    tracep->declQuad(c+8,"wd_i", false,-1, 39,0);
    tracep->declBus(c+10,"rd_o", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vram_top___024root__trace_init_top(Vram_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_init_top\n"); );
    // Body
    Vram_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vram_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vram_top___024root__trace_register(Vram_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vram_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vram_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vram_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vram_top___024root__trace_full_sub_0(Vram_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vram_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_full_top_0\n"); );
    // Init
    Vram_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_top___024root*>(voidSelf);
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vram_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vram_top___024root__trace_full_sub_0(Vram_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->write_en_i));
    bufp->fullBit(oldp+2,(vlSelf->clk_i));
    bufp->fullCData(oldp+3,(vlSelf->memtype_i),2);
    bufp->fullBit(oldp+4,(vlSelf->memsign_i));
    bufp->fullIData(oldp+5,(vlSelf->wd_i),32);
    bufp->fullIData(oldp+6,(vlSelf->a_i),32);
    bufp->fullIData(oldp+7,(vlSelf->rd_o),32);
    bufp->fullQData(oldp+8,(vlSelf->ram_top__DOT__WDWire),40);
    bufp->fullIData(oldp+10,(vlSelf->ram_top__DOT__RDWire),32);
    bufp->fullIData(oldp+11,((0xfffffffcU & vlSelf->a_i)),32);
    bufp->fullCData(oldp+12,((3U & vlSelf->a_i)),2);
    bufp->fullIData(oldp+13,(0x20U),32);
    bufp->fullIData(oldp+14,(8U),32);
}
