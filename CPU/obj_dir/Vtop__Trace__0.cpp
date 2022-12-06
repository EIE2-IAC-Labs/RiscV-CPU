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
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__register_file__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__RD2Wire),32);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__ALUctrlWire),4);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__ImmSrcWire),3);
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__addrSelectWire));
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__ImmediateExtendWire),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__RamOutWire),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__register_file__DOT__register_array[0]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__register_file__DOT__register_array[1]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__register_file__DOT__register_array[2]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__register_file__DOT__register_array[3]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__register_file__DOT__register_array[4]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__register_file__DOT__register_array[5]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__register_file__DOT__register_array[6]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__register_file__DOT__register_array[7]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__register_file__DOT__register_array[8]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__register_file__DOT__register_array[9]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__register_file__DOT__register_array[10]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__register_file__DOT__register_array[11]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__register_file__DOT__register_array[12]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__register_file__DOT__register_array[13]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__register_file__DOT__register_array[14]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__register_file__DOT__register_array[15]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__register_file__DOT__register_array[16]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__register_file__DOT__register_array[17]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__register_file__DOT__register_array[18]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__register_file__DOT__register_array[19]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__register_file__DOT__register_array[20]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__register_file__DOT__register_array[21]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__register_file__DOT__register_array[22]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__register_file__DOT__register_array[23]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__register_file__DOT__register_array[24]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__register_file__DOT__register_array[25]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__register_file__DOT__register_array[26]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__register_file__DOT__register_array[27]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__register_file__DOT__register_array[28]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__register_file__DOT__register_array[29]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__register_file__DOT__register_array[30]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__register_file__DOT__register_array[31]),32);
    }
    bufp->chgBit(oldp+39,(vlSelf->rst));
    bufp->chgBit(oldp+40,(vlSelf->trigger_i));
    bufp->chgBit(oldp+41,(vlSelf->clk));
    bufp->chgIData(oldp+42,(vlSelf->PC_wire),32);
    bufp->chgIData(oldp+43,(vlSelf->InstructionWire),32);
    bufp->chgCData(oldp+44,(vlSelf->opcode),7);
    bufp->chgCData(oldp+45,(vlSelf->funct3),3);
    bufp->chgBit(oldp+46,(vlSelf->funct7));
    bufp->chgCData(oldp+47,(vlSelf->rs1Wire),5);
    bufp->chgCData(oldp+48,(vlSelf->rs2Wire),5);
    bufp->chgCData(oldp+49,(vlSelf->rdWire),5);
    bufp->chgIData(oldp+50,(vlSelf->wd3Wire),32);
    bufp->chgIData(oldp+51,(vlSelf->data_out),32);
    bufp->chgIData(oldp+52,(vlSelf->RD1Wire),32);
    bufp->chgIData(oldp+53,(vlSelf->Aluop2Wire),32);
    bufp->chgIData(oldp+54,(vlSelf->ALUResultWire),32);
    bufp->chgIData(oldp+55,(((IData)(4U) + vlSelf->PC_wire)),32);
    bufp->chgIData(oldp+56,((vlSelf->PC_wire + vlSelf->top__DOT__ImmediateExtendWire)),32);
    bufp->chgIData(oldp+57,((((0x63U == (IData)(vlSelf->opcode)) 
                              & ((4U & (IData)(vlSelf->funct3))
                                  ? ((~ ((IData)(vlSelf->funct3) 
                                         >> 1U)) & 
                                     ((1U & (IData)(vlSelf->funct3))
                                       ? (vlSelf->RD1Wire 
                                          >= vlSelf->Aluop2Wire)
                                       : (vlSelf->RD1Wire 
                                          < vlSelf->Aluop2Wire)))
                                  : ((2U & (IData)(vlSelf->funct3))
                                      ? ((1U & (IData)(vlSelf->funct3))
                                          ? VL_GTES_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire)
                                          : VL_LTS_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire))
                                      : ((1U & (IData)(vlSelf->funct3))
                                          ? (vlSelf->RD1Wire 
                                             != vlSelf->Aluop2Wire)
                                          : (vlSelf->RD1Wire 
                                             == vlSelf->Aluop2Wire)))))
                              ? (vlSelf->PC_wire + vlSelf->top__DOT__ImmediateExtendWire)
                              : ((IData)(4U) + vlSelf->PC_wire))),32);
    bufp->chgBit(oldp+58,(((0x63U == (IData)(vlSelf->opcode)) 
                           & ((4U & (IData)(vlSelf->funct3))
                               ? ((~ ((IData)(vlSelf->funct3) 
                                      >> 1U)) & ((1U 
                                                  & (IData)(vlSelf->funct3))
                                                  ? 
                                                 (vlSelf->RD1Wire 
                                                  >= vlSelf->Aluop2Wire)
                                                  : 
                                                 (vlSelf->RD1Wire 
                                                  < vlSelf->Aluop2Wire)))
                               : ((2U & (IData)(vlSelf->funct3))
                                   ? ((1U & (IData)(vlSelf->funct3))
                                       ? VL_GTES_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire)
                                       : VL_LTS_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire))
                                   : ((1U & (IData)(vlSelf->funct3))
                                       ? (vlSelf->RD1Wire 
                                          != vlSelf->Aluop2Wire)
                                       : (vlSelf->RD1Wire 
                                          == vlSelf->Aluop2Wire)))))));
    bufp->chgBit(oldp+59,(((4U & (IData)(vlSelf->funct3))
                            ? ((~ ((IData)(vlSelf->funct3) 
                                   >> 1U)) & ((1U & (IData)(vlSelf->funct3))
                                               ? (vlSelf->RD1Wire 
                                                  >= vlSelf->Aluop2Wire)
                                               : (vlSelf->RD1Wire 
                                                  < vlSelf->Aluop2Wire)))
                            : ((2U & (IData)(vlSelf->funct3))
                                ? ((1U & (IData)(vlSelf->funct3))
                                    ? VL_GTES_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire)
                                    : VL_LTS_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire))
                                : ((1U & (IData)(vlSelf->funct3))
                                    ? (vlSelf->RD1Wire 
                                       != vlSelf->Aluop2Wire)
                                    : (vlSelf->RD1Wire 
                                       == vlSelf->Aluop2Wire))))));
    bufp->chgBit(oldp+60,((0x23U == (IData)(vlSelf->opcode))));
    bufp->chgBit(oldp+61,((((0x33U == (IData)(vlSelf->opcode)) 
                            | (0x13U == (IData)(vlSelf->opcode))) 
                           | (3U == (IData)(vlSelf->opcode)))));
    bufp->chgBit(oldp+62,(((0x13U == (IData)(vlSelf->opcode)) 
                           | (3U == (IData)(vlSelf->opcode)))));
    bufp->chgBit(oldp+63,((0x63U == (IData)(vlSelf->opcode))));
    bufp->chgBit(oldp+64,((3U == (IData)(vlSelf->opcode))));
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
