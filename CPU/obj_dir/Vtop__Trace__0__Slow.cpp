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
    tracep->declBit(c+40,"rst", false,-1);
    tracep->declBit(c+41,"trigger_i", false,-1);
    tracep->declBit(c+42,"clk", false,-1);
    tracep->declBus(c+43,"PC_wire", false,-1, 31,0);
    tracep->declBus(c+44,"InstructionWire", false,-1, 31,0);
    tracep->declBus(c+45,"opcode", false,-1, 6,0);
    tracep->declBus(c+46,"funct3", false,-1, 2,0);
    tracep->declBit(c+47,"funct7", false,-1);
    tracep->declBus(c+48,"rs1Wire", false,-1, 4,0);
    tracep->declBus(c+49,"rs2Wire", false,-1, 4,0);
    tracep->declBus(c+50,"rdWire", false,-1, 4,0);
    tracep->declBus(c+51,"wd3Wire", false,-1, 31,0);
    tracep->declBus(c+52,"data_out", false,-1, 31,0);
    tracep->declBus(c+53,"RD1Wire", false,-1, 31,0);
    tracep->declBus(c+54,"Aluop2Wire", false,-1, 31,0);
    tracep->declBus(c+55,"ALUResultWire", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+66,"DW", false,-1, 31,0);
    tracep->declBit(c+40,"rst", false,-1);
    tracep->declBit(c+41,"trigger_i", false,-1);
    tracep->declBit(c+42,"clk", false,-1);
    tracep->declBus(c+43,"PC_wire", false,-1, 31,0);
    tracep->declBus(c+44,"InstructionWire", false,-1, 31,0);
    tracep->declBus(c+45,"opcode", false,-1, 6,0);
    tracep->declBus(c+46,"funct3", false,-1, 2,0);
    tracep->declBit(c+47,"funct7", false,-1);
    tracep->declBus(c+48,"rs1Wire", false,-1, 4,0);
    tracep->declBus(c+49,"rs2Wire", false,-1, 4,0);
    tracep->declBus(c+50,"rdWire", false,-1, 4,0);
    tracep->declBus(c+51,"wd3Wire", false,-1, 31,0);
    tracep->declBus(c+52,"data_out", false,-1, 31,0);
    tracep->declBus(c+53,"RD1Wire", false,-1, 31,0);
    tracep->declBus(c+54,"Aluop2Wire", false,-1, 31,0);
    tracep->declBus(c+55,"ALUResultWire", false,-1, 31,0);
    tracep->declBus(c+56,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+57,"branch_PC", false,-1, 31,0);
    tracep->declBus(c+58,"next_PC", false,-1, 31,0);
    tracep->declBit(c+59,"PCsrcWire", false,-1);
    tracep->declBus(c+2,"RD2Wire", false,-1, 31,0);
    tracep->declBit(c+60,"branchWire", false,-1);
    tracep->declBit(c+61,"memWrite_enWire", false,-1);
    tracep->declBit(c+62,"regWrite_enWire", false,-1);
    tracep->declBus(c+3,"ALUctrlWire", false,-1, 3,0);
    tracep->declBit(c+63,"ALUsrcWire", false,-1);
    tracep->declBus(c+4,"ImmSrcWire", false,-1, 2,0);
    tracep->declBit(c+64,"BranchSrcWire", false,-1);
    tracep->declBit(c+5,"addrSelectWire", false,-1);
    tracep->declBit(c+65,"ResultSrcWire", false,-1);
    tracep->declBus(c+44,"ImmediateWire", false,-1, 31,0);
    tracep->declBus(c+6,"ImmediateExtendWire", false,-1, 31,0);
    tracep->declBus(c+7,"RamOutWire", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+66,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"SHIFT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+53,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+54,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+3,"ALUctrl_i", false,-1, 3,0);
    tracep->declBus(c+46,"BranchCtrl_i", false,-1, 2,0);
    tracep->declBus(c+55,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+60,"Branch_o", false,-1);
    tracep->declBus(c+53,"SrcA_Signed", false,-1, 31,0);
    tracep->declBus(c+54,"SrcB_Signed", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PC ");
    tracep->declBus(c+66,"DW", false,-1, 31,0);
    tracep->declBit(c+42,"clk", false,-1);
    tracep->declBit(c+40,"rst", false,-1);
    tracep->declBus(c+58,"PC_i", false,-1, 31,0);
    tracep->declBus(c+43,"PC_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("control ");
    tracep->declBus(c+45,"op_i", false,-1, 6,0);
    tracep->declBus(c+46,"funct3_i", false,-1, 2,0);
    tracep->declBit(c+47,"funct7bit_i", false,-1);
    tracep->declBit(c+61,"memWrite_en_o", false,-1);
    tracep->declBit(c+62,"regWrite_en_o", false,-1);
    tracep->declBus(c+3,"ALUctrl_o", false,-1, 3,0);
    tracep->declBit(c+63,"ALUsrc_o", false,-1);
    tracep->declBus(c+4,"ImmSrc_o", false,-1, 2,0);
    tracep->declBit(c+64,"BranchSrc_o", false,-1);
    tracep->declBit(c+5,"addrSelect_o", false,-1);
    tracep->declBit(c+65,"ResultSrc_o", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("extend ");
    tracep->declBus(c+66,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+4,"ImmSrc_i", false,-1, 2,0);
    tracep->declBus(c+44,"Imm_i", false,-1, 31,0);
    tracep->declBus(c+6,"ImmExt_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"DATA_W", false,-1, 31,0);
    tracep->declBit(c+42,"clk_i", false,-1);
    tracep->declBit(c+61,"write_en_i", false,-1);
    tracep->declBit(c+5,"AddrsCtrl_i", false,-1);
    tracep->declBus(c+55,"a_i", false,-1, 31,0);
    tracep->declBus(c+2,"wd_i", false,-1, 31,0);
    tracep->declBus(c+7,"rd_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file ");
    tracep->declBus(c+67,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+42,"clk", false,-1);
    tracep->declBus(c+48,"AD1_i", false,-1, 4,0);
    tracep->declBus(c+49,"AD2_i", false,-1, 4,0);
    tracep->declBus(c+50,"AD3_i", false,-1, 4,0);
    tracep->declBit(c+62,"WE3_i", false,-1);
    tracep->declBus(c+51,"WD3_i", false,-1, 31,0);
    tracep->declBus(c+53,"RD1_o", false,-1, 31,0);
    tracep->declBus(c+2,"RD2_o", false,-1, 31,0);
    tracep->declBus(c+52,"a0_o", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+8+i*1,"register_array", true,(i+0), 31,0);
    }
    tracep->declBus(c+69,"a1", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("rom ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"DATA_W", false,-1, 31,0);
    tracep->declBus(c+43,"a_i", false,-1, 31,0);
    tracep->declBus(c+44,"rd_o", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__register_file__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__RD2Wire),32);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__ALUctrlWire),4);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__ImmSrcWire),3);
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__addrSelectWire));
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__ImmediateExtendWire),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__RamOutWire),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__register_file__DOT__register_array[0]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__register_file__DOT__register_array[1]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__register_file__DOT__register_array[2]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__register_file__DOT__register_array[3]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__register_file__DOT__register_array[4]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__register_file__DOT__register_array[5]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__register_file__DOT__register_array[6]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__register_file__DOT__register_array[7]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__register_file__DOT__register_array[8]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__register_file__DOT__register_array[9]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__register_file__DOT__register_array[10]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__register_file__DOT__register_array[11]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__register_file__DOT__register_array[12]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__register_file__DOT__register_array[13]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__register_file__DOT__register_array[14]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__register_file__DOT__register_array[15]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__register_file__DOT__register_array[16]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__register_file__DOT__register_array[17]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__register_file__DOT__register_array[18]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__register_file__DOT__register_array[19]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__register_file__DOT__register_array[20]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__register_file__DOT__register_array[21]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__register_file__DOT__register_array[22]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__register_file__DOT__register_array[23]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__register_file__DOT__register_array[24]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__register_file__DOT__register_array[25]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__register_file__DOT__register_array[26]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__register_file__DOT__register_array[27]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__register_file__DOT__register_array[28]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__register_file__DOT__register_array[29]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__register_file__DOT__register_array[30]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__register_file__DOT__register_array[31]),32);
    bufp->fullBit(oldp+40,(vlSelf->rst));
    bufp->fullBit(oldp+41,(vlSelf->trigger_i));
    bufp->fullBit(oldp+42,(vlSelf->clk));
    bufp->fullIData(oldp+43,(vlSelf->PC_wire),32);
    bufp->fullIData(oldp+44,(vlSelf->InstructionWire),32);
    bufp->fullCData(oldp+45,(vlSelf->opcode),7);
    bufp->fullCData(oldp+46,(vlSelf->funct3),3);
    bufp->fullBit(oldp+47,(vlSelf->funct7));
    bufp->fullCData(oldp+48,(vlSelf->rs1Wire),5);
    bufp->fullCData(oldp+49,(vlSelf->rs2Wire),5);
    bufp->fullCData(oldp+50,(vlSelf->rdWire),5);
    bufp->fullIData(oldp+51,(vlSelf->wd3Wire),32);
    bufp->fullIData(oldp+52,(vlSelf->data_out),32);
    bufp->fullIData(oldp+53,(vlSelf->RD1Wire),32);
    bufp->fullIData(oldp+54,(vlSelf->Aluop2Wire),32);
    bufp->fullIData(oldp+55,(vlSelf->ALUResultWire),32);
    bufp->fullIData(oldp+56,(((IData)(4U) + vlSelf->PC_wire)),32);
    bufp->fullIData(oldp+57,((vlSelf->PC_wire + vlSelf->top__DOT__ImmediateExtendWire)),32);
    bufp->fullIData(oldp+58,((((0x63U == (IData)(vlSelf->opcode)) 
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
    bufp->fullBit(oldp+59,(((0x63U == (IData)(vlSelf->opcode)) 
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
    bufp->fullBit(oldp+60,(((4U & (IData)(vlSelf->funct3))
                             ? ((~ ((IData)(vlSelf->funct3) 
                                    >> 1U)) & ((1U 
                                                & (IData)(vlSelf->funct3))
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
    bufp->fullBit(oldp+61,((0x23U == (IData)(vlSelf->opcode))));
    bufp->fullBit(oldp+62,((((0x33U == (IData)(vlSelf->opcode)) 
                             | (0x13U == (IData)(vlSelf->opcode))) 
                            | (3U == (IData)(vlSelf->opcode)))));
    bufp->fullBit(oldp+63,(((0x13U == (IData)(vlSelf->opcode)) 
                            | (3U == (IData)(vlSelf->opcode)))));
    bufp->fullBit(oldp+64,((0x63U == (IData)(vlSelf->opcode))));
    bufp->fullBit(oldp+65,((3U == (IData)(vlSelf->opcode))));
    bufp->fullIData(oldp+66,(0x20U),32);
    bufp->fullIData(oldp+67,(5U),32);
    bufp->fullIData(oldp+68,(8U),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__register_file__DOT__a1),32);
}
