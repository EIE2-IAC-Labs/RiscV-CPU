// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__RegFile__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__romF__DOT__rom_array[0]),8);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__romF__DOT__rom_array[1]),8);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__romF__DOT__rom_array[2]),8);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__romF__DOT__rom_array[3]),8);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__romF__DOT__rom_array[4]),8);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__romF__DOT__rom_array[5]),8);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__romF__DOT__rom_array[6]),8);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__romF__DOT__rom_array[7]),8);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__romF__DOT__rom_array[8]),8);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__romF__DOT__rom_array[9]),8);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__romF__DOT__rom_array[10]),8);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__romF__DOT__rom_array[11]),8);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__romF__DOT__rom_array[12]),8);
        bufp->chgCData(oldp+14,(vlSelf->top__DOT__romF__DOT__rom_array[13]),8);
        bufp->chgCData(oldp+15,(vlSelf->top__DOT__romF__DOT__rom_array[14]),8);
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__romF__DOT__rom_array[15]),8);
        bufp->chgCData(oldp+17,(vlSelf->top__DOT__romF__DOT__rom_array[16]),8);
        bufp->chgCData(oldp+18,(vlSelf->top__DOT__romF__DOT__rom_array[17]),8);
        bufp->chgCData(oldp+19,(vlSelf->top__DOT__romF__DOT__rom_array[18]),8);
        bufp->chgCData(oldp+20,(vlSelf->top__DOT__romF__DOT__rom_array[19]),8);
        bufp->chgCData(oldp+21,(vlSelf->top__DOT__romF__DOT__rom_array[20]),8);
        bufp->chgCData(oldp+22,(vlSelf->top__DOT__romF__DOT__rom_array[21]),8);
        bufp->chgCData(oldp+23,(vlSelf->top__DOT__romF__DOT__rom_array[22]),8);
        bufp->chgCData(oldp+24,(vlSelf->top__DOT__romF__DOT__rom_array[23]),8);
        bufp->chgCData(oldp+25,(vlSelf->top__DOT__romF__DOT__rom_array[24]),8);
        bufp->chgCData(oldp+26,(vlSelf->top__DOT__romF__DOT__rom_array[25]),8);
        bufp->chgCData(oldp+27,(vlSelf->top__DOT__romF__DOT__rom_array[26]),8);
        bufp->chgCData(oldp+28,(vlSelf->top__DOT__romF__DOT__rom_array[27]),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__PCWire),32);
        bufp->chgCData(oldp+30,(vlSelf->top__DOT__ImmSrcWire),3);
        bufp->chgIData(oldp+31,(((IData)(4U) + vlSelf->top__DOT__PCWire)),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__RegFile__DOT__register_array[0]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__RegFile__DOT__register_array[1]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__RegFile__DOT__register_array[2]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__RegFile__DOT__register_array[3]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__RegFile__DOT__register_array[4]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__RegFile__DOT__register_array[5]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__RegFile__DOT__register_array[6]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__RegFile__DOT__register_array[7]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__RegFile__DOT__register_array[8]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__RegFile__DOT__register_array[9]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__RegFile__DOT__register_array[10]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__RegFile__DOT__register_array[11]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__RegFile__DOT__register_array[12]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__RegFile__DOT__register_array[13]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__RegFile__DOT__register_array[14]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__RegFile__DOT__register_array[15]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__RegFile__DOT__register_array[16]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__RegFile__DOT__register_array[17]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__RegFile__DOT__register_array[18]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__RegFile__DOT__register_array[19]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__RegFile__DOT__register_array[20]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__RegFile__DOT__register_array[21]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__RegFile__DOT__register_array[22]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__RegFile__DOT__register_array[23]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__RegFile__DOT__register_array[24]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__RegFile__DOT__register_array[25]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__RegFile__DOT__register_array[26]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__RegFile__DOT__register_array[27]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__RegFile__DOT__register_array[28]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__RegFile__DOT__register_array[29]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__RegFile__DOT__register_array[30]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__RegFile__DOT__register_array[31]),32);
        bufp->chgSData(oldp+64,(vlSelf->top__DOT__extendo__DOT__immediate),12);
        bufp->chgBit(oldp+65,(vlSelf->top__DOT__extendo__DOT__msb));
    }
    bufp->chgBit(oldp+66,(vlSelf->clk));
    bufp->chgBit(oldp+67,(vlSelf->rst));
    bufp->chgIData(oldp+68,(vlSelf->a0out),32);
    bufp->chgIData(oldp+69,(vlSelf->InstructionWire),32);
    bufp->chgIData(oldp+70,(vlSelf->ImmOpWire),32);
    bufp->chgIData(oldp+71,(vlSelf->Aluop2Wire),32);
    bufp->chgIData(oldp+72,(vlSelf->RD1Wire),32);
    bufp->chgIData(oldp+73,(vlSelf->ALUoutWire),32);
    bufp->chgBit(oldp+74,(((0x13U != (0x7fU & vlSelf->InstructionWire)) 
                           & ((0x63U == (0x7fU & vlSelf->InstructionWire)) 
                              & (vlSelf->RD1Wire != vlSelf->Aluop2Wire)))));
    bufp->chgIData(oldp+75,(vlSelf->top__DOT__RegFile__DOT__register_array
                            [(0x1fU & (vlSelf->InstructionWire 
                                       >> 0x14U))]),32);
    bufp->chgBit(oldp+76,((vlSelf->RD1Wire == vlSelf->Aluop2Wire)));
    bufp->chgBit(oldp+77,((0x13U == (0x7fU & vlSelf->InstructionWire))));
    bufp->chgCData(oldp+78,((7U & (vlSelf->InstructionWire 
                                   >> 0xcU))),3);
    bufp->chgCData(oldp+79,((0x1fU & (vlSelf->InstructionWire 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+80,((0x1fU & (vlSelf->InstructionWire 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+81,((0x1fU & (vlSelf->InstructionWire 
                                      >> 7U))),5);
    bufp->chgIData(oldp+82,((vlSelf->top__DOT__PCWire 
                             + vlSelf->ImmOpWire)),32);
    bufp->chgIData(oldp+83,((((0x13U != (0x7fU & vlSelf->InstructionWire)) 
                              & ((0x63U == (0x7fU & vlSelf->InstructionWire)) 
                                 & (vlSelf->RD1Wire 
                                    != vlSelf->Aluop2Wire)))
                              ? (vlSelf->top__DOT__PCWire 
                                 + vlSelf->ImmOpWire)
                              : ((IData)(4U) + vlSelf->top__DOT__PCWire))),32);
    bufp->chgCData(oldp+84,((0x7fU & vlSelf->InstructionWire)),7);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
