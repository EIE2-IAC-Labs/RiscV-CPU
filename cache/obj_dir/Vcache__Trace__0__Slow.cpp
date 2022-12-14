// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcache__Syms.h"


VL_ATTR_COLD void Vcache___024root__trace_init_sub__TOP__0(Vcache___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBus(c+2,"dataWord0_i", false,-1, 31,0);
    tracep->declBus(c+3,"dataWord1_i", false,-1, 31,0);
    tracep->declBus(c+4,"dataWord2_i", false,-1, 31,0);
    tracep->declBus(c+5,"dataWord3_i", false,-1, 31,0);
    tracep->declBus(c+6,"addressWord_i", false,-1, 31,0);
    tracep->declBus(c+7,"dataWord_o", false,-1, 31,0);
    tracep->declBit(c+8,"hit_o", false,-1);
    tracep->pushNamePrefix("cache ");
    tracep->declBus(c+12,"TAG", false,-1, 31,0);
    tracep->declBus(c+13,"DATA", false,-1, 31,0);
    tracep->declBus(c+14,"CACHE", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBus(c+2,"dataWord0_i", false,-1, 31,0);
    tracep->declBus(c+3,"dataWord1_i", false,-1, 31,0);
    tracep->declBus(c+4,"dataWord2_i", false,-1, 31,0);
    tracep->declBus(c+5,"dataWord3_i", false,-1, 31,0);
    tracep->declBus(c+6,"addressWord_i", false,-1, 31,0);
    tracep->declBus(c+7,"dataWord_o", false,-1, 31,0);
    tracep->declBit(c+8,"hit_o", false,-1);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+15+i*1,"V", true,(i+0));
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+17+i*1,"tag", true,(i+0), 26,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+19+i*1,"data0", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+21+i*1,"data1", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+23+i*1,"data2", true,(i+0), 31,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+25+i*1,"data3", true,(i+0), 31,0);
    }
    tracep->declBit(c+9,"Set", false,-1);
    tracep->declBus(c+10,"Tag", false,-1, 26,0);
    tracep->declBus(c+11,"block_offset", false,-1, 1,0);
    tracep->declBit(c+27,"overwrite", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vcache___024root__trace_init_top(Vcache___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_init_top\n"); );
    // Body
    Vcache___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcache___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcache___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcache___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcache___024root__trace_register(Vcache___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcache___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcache___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcache___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcache___024root__trace_full_sub_0(Vcache___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcache___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_full_top_0\n"); );
    // Init
    Vcache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcache___024root*>(voidSelf);
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcache___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcache___024root__trace_full_sub_0(Vcache___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcache___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullIData(oldp+2,(vlSelf->dataWord0_i),32);
    bufp->fullIData(oldp+3,(vlSelf->dataWord1_i),32);
    bufp->fullIData(oldp+4,(vlSelf->dataWord2_i),32);
    bufp->fullIData(oldp+5,(vlSelf->dataWord3_i),32);
    bufp->fullIData(oldp+6,(vlSelf->addressWord_i),32);
    bufp->fullIData(oldp+7,(vlSelf->dataWord_o),32);
    bufp->fullBit(oldp+8,(vlSelf->hit_o));
    bufp->fullBit(oldp+9,((1U & (vlSelf->addressWord_i 
                                 >> 4U))));
    bufp->fullIData(oldp+10,((vlSelf->addressWord_i 
                              >> 5U)),27);
    bufp->fullCData(oldp+11,((3U & (vlSelf->addressWord_i 
                                    >> 2U))),2);
    bufp->fullIData(oldp+12,(0x1bU),32);
    bufp->fullIData(oldp+13,(0x20U),32);
    bufp->fullIData(oldp+14,(2U),32);
    bufp->fullBit(oldp+15,(vlSelf->cache__DOT__V[0]));
    bufp->fullBit(oldp+16,(vlSelf->cache__DOT__V[1]));
    bufp->fullIData(oldp+17,(vlSelf->cache__DOT__tag[0]),27);
    bufp->fullIData(oldp+18,(vlSelf->cache__DOT__tag[1]),27);
    bufp->fullIData(oldp+19,(vlSelf->cache__DOT__data0[0]),32);
    bufp->fullIData(oldp+20,(vlSelf->cache__DOT__data0[1]),32);
    bufp->fullIData(oldp+21,(vlSelf->cache__DOT__data1[0]),32);
    bufp->fullIData(oldp+22,(vlSelf->cache__DOT__data1[1]),32);
    bufp->fullIData(oldp+23,(vlSelf->cache__DOT__data2[0]),32);
    bufp->fullIData(oldp+24,(vlSelf->cache__DOT__data2[1]),32);
    bufp->fullIData(oldp+25,(vlSelf->cache__DOT__data3[0]),32);
    bufp->fullIData(oldp+26,(vlSelf->cache__DOT__data3[1]),32);
    bufp->fullBit(oldp+27,(0U));
}
