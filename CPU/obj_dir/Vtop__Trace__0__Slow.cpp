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
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBit(c+63,"trigger_i", false,-1);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBus(c+65,"data_out", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+66,"DW", false,-1, 31,0);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBit(c+63,"trigger_i", false,-1);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBus(c+65,"data_out", false,-1, 31,0);
    tracep->declBus(c+2,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+3,"branch_PC", false,-1, 31,0);
    tracep->declBus(c+4,"next_PC", false,-1, 31,0);
    tracep->declBus(c+5,"PC_wire", false,-1, 31,0);
    tracep->declBit(c+6,"PCsrcWire", false,-1);
    tracep->declBus(c+7,"RD1Wire", false,-1, 31,0);
    tracep->declBus(c+8,"RD2Wire", false,-1, 31,0);
    tracep->declBus(c+9,"Aluop2Wire", false,-1, 31,0);
    tracep->declBit(c+10,"branchWire", false,-1);
    tracep->declBus(c+11,"ALUResultWire", false,-1, 31,0);
    tracep->declBus(c+12,"InstructionWire", false,-1, 31,0);
    tracep->declBus(c+13,"opcode", false,-1, 6,0);
    tracep->declBus(c+14,"funct3", false,-1, 2,0);
    tracep->declBit(c+15,"funct7", false,-1);
    tracep->declBit(c+16,"memWrite_enWire", false,-1);
    tracep->declBit(c+17,"regWrite_enWire", false,-1);
    tracep->declBus(c+18,"ALUctrlWire", false,-1, 3,0);
    tracep->declBit(c+19,"ALUsrcWire", false,-1);
    tracep->declBus(c+20,"ImmSrcWire", false,-1, 2,0);
    tracep->declBit(c+21,"BranchSrcWire", false,-1);
    tracep->declBit(c+22,"addrSelectWire", false,-1);
    tracep->declBit(c+23,"ResultSrcWire", false,-1);
    tracep->declBus(c+24,"rs1Wire", false,-1, 4,0);
    tracep->declBus(c+25,"rs2Wire", false,-1, 4,0);
    tracep->declBus(c+26,"rdWire", false,-1, 4,0);
    tracep->declBus(c+27,"wd3Wire", false,-1, 31,0);
    tracep->declBus(c+12,"ImmediateWire", false,-1, 31,0);
    tracep->declBus(c+28,"ImmediateExtendWire", false,-1, 31,0);
    tracep->declBus(c+29,"RamOutWire", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+66,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"SHIFT_WIDTH", false,-1, 31,0);
    tracep->declBus(c+7,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+9,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+18,"ALUctrl_i", false,-1, 3,0);
    tracep->declBus(c+14,"BranchCtrl_i", false,-1, 2,0);
    tracep->declBus(c+11,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+10,"Branch_o", false,-1);
    tracep->declBus(c+7,"SrcA_Signed", false,-1, 31,0);
    tracep->declBus(c+9,"SrcB_Signed", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PC ");
    tracep->declBus(c+66,"DW", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+62,"rst", false,-1);
    tracep->declBus(c+4,"PC_i", false,-1, 31,0);
    tracep->declBus(c+5,"PC_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("control ");
    tracep->declBus(c+13,"op_i", false,-1, 6,0);
    tracep->declBus(c+14,"funct3_i", false,-1, 2,0);
    tracep->declBit(c+15,"funct7bit_i", false,-1);
    tracep->declBit(c+16,"memWrite_en_o", false,-1);
    tracep->declBit(c+17,"regWrite_en_o", false,-1);
    tracep->declBus(c+18,"ALUctrl_o", false,-1, 3,0);
    tracep->declBit(c+19,"ALUsrc_o", false,-1);
    tracep->declBus(c+20,"ImmSrc_o", false,-1, 2,0);
    tracep->declBit(c+21,"BranchSrc_o", false,-1);
    tracep->declBit(c+22,"addrSelect_o", false,-1);
    tracep->declBit(c+23,"ResultSrc_o", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("extend ");
    tracep->declBus(c+66,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+20,"ImmSrc_i", false,-1, 2,0);
    tracep->declBus(c+12,"Imm_i", false,-1, 31,0);
    tracep->declBus(c+28,"ImmExt_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"DATA_W", false,-1, 31,0);
    tracep->declBit(c+64,"clk_i", false,-1);
    tracep->declBit(c+16,"write_en_i", false,-1);
    tracep->declBit(c+22,"AddrsCtrl_i", false,-1);
    tracep->declBus(c+11,"a_i", false,-1, 31,0);
    tracep->declBus(c+8,"wd_i", false,-1, 31,0);
    tracep->declBus(c+29,"rd_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file ");
    tracep->declBus(c+67,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBus(c+24,"AD1_i", false,-1, 4,0);
    tracep->declBus(c+25,"AD2_i", false,-1, 4,0);
    tracep->declBus(c+26,"AD3_i", false,-1, 4,0);
    tracep->declBit(c+17,"WE3_i", false,-1);
    tracep->declBus(c+27,"WD3_i", false,-1, 31,0);
    tracep->declBus(c+7,"RD1_o", false,-1, 31,0);
    tracep->declBus(c+8,"RD2_o", false,-1, 31,0);
    tracep->declBus(c+65,"a0_o", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+30+i*1,"register_array", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("rom ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"DATA_W", false,-1, 31,0);
    tracep->declBus(c+5,"a_i", false,-1, 31,0);
    tracep->declBus(c+12,"rd_o", false,-1, 31,0);
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
    bufp->fullIData(oldp+2,(((IData)(4U) + vlSelf->top__DOT__PC_wire)),32);
    bufp->fullIData(oldp+3,((vlSelf->top__DOT__PC_wire 
                             + vlSelf->top__DOT__ImmediateExtendWire)),32);
    bufp->fullIData(oldp+4,((((0x63U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                              & ((0x4000U & vlSelf->top__DOT__InstructionWire)
                                  ? ((~ (vlSelf->top__DOT__InstructionWire 
                                         >> 0xdU)) 
                                     & ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                         ? (vlSelf->top__DOT__RD1Wire 
                                            >= vlSelf->top__DOT__Aluop2Wire)
                                         : (vlSelf->top__DOT__RD1Wire 
                                            < vlSelf->top__DOT__Aluop2Wire)))
                                  : ((0x2000U & vlSelf->top__DOT__InstructionWire)
                                      ? ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                          ? VL_GTES_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire)
                                          : VL_LTS_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire))
                                      : ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                          ? (vlSelf->top__DOT__RD1Wire 
                                             != vlSelf->top__DOT__Aluop2Wire)
                                          : (vlSelf->top__DOT__RD1Wire 
                                             == vlSelf->top__DOT__Aluop2Wire)))))
                              ? (vlSelf->top__DOT__PC_wire 
                                 + vlSelf->top__DOT__ImmediateExtendWire)
                              : ((IData)(4U) + vlSelf->top__DOT__PC_wire))),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__PC_wire),32);
    bufp->fullBit(oldp+6,(((0x63U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                           & ((0x4000U & vlSelf->top__DOT__InstructionWire)
                               ? ((~ (vlSelf->top__DOT__InstructionWire 
                                      >> 0xdU)) & (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    >= vlSelf->top__DOT__Aluop2Wire)
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    < vlSelf->top__DOT__Aluop2Wire)))
                               : ((0x2000U & vlSelf->top__DOT__InstructionWire)
                                   ? ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                       ? VL_GTES_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire)
                                       : VL_LTS_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire))
                                   : ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                       ? (vlSelf->top__DOT__RD1Wire 
                                          != vlSelf->top__DOT__Aluop2Wire)
                                       : (vlSelf->top__DOT__RD1Wire 
                                          == vlSelf->top__DOT__Aluop2Wire)))))));
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__RD1Wire),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__RD2Wire),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__Aluop2Wire),32);
    bufp->fullBit(oldp+10,(((0x4000U & vlSelf->top__DOT__InstructionWire)
                             ? ((~ (vlSelf->top__DOT__InstructionWire 
                                    >> 0xdU)) & ((0x1000U 
                                                  & vlSelf->top__DOT__InstructionWire)
                                                  ? 
                                                 (vlSelf->top__DOT__RD1Wire 
                                                  >= vlSelf->top__DOT__Aluop2Wire)
                                                  : 
                                                 (vlSelf->top__DOT__RD1Wire 
                                                  < vlSelf->top__DOT__Aluop2Wire)))
                             : ((0x2000U & vlSelf->top__DOT__InstructionWire)
                                 ? ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                     ? VL_GTES_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire)
                                     : VL_LTS_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire))
                                 : ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                     ? (vlSelf->top__DOT__RD1Wire 
                                        != vlSelf->top__DOT__Aluop2Wire)
                                     : (vlSelf->top__DOT__RD1Wire 
                                        == vlSelf->top__DOT__Aluop2Wire))))));
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__ALUResultWire),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__InstructionWire),32);
    bufp->fullCData(oldp+13,((0x7fU & vlSelf->top__DOT__InstructionWire)),7);
    bufp->fullCData(oldp+14,((7U & (vlSelf->top__DOT__InstructionWire 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+15,((1U & (vlSelf->top__DOT__InstructionWire 
                                  >> 0x1eU))));
    bufp->fullBit(oldp+16,((0x23U == (0x7fU & vlSelf->top__DOT__InstructionWire))));
    bufp->fullBit(oldp+17,((((0x33U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                             | (0x13U == (0x7fU & vlSelf->top__DOT__InstructionWire))) 
                            | (3U == (0x7fU & vlSelf->top__DOT__InstructionWire)))));
    bufp->fullCData(oldp+18,(vlSelf->top__DOT__ALUctrlWire),4);
    bufp->fullBit(oldp+19,(((0x13U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                            | (3U == (0x7fU & vlSelf->top__DOT__InstructionWire)))));
    bufp->fullCData(oldp+20,(vlSelf->top__DOT__ImmSrcWire),3);
    bufp->fullBit(oldp+21,((0x63U == (0x7fU & vlSelf->top__DOT__InstructionWire))));
    bufp->fullBit(oldp+22,(vlSelf->top__DOT__addrSelectWire));
    bufp->fullBit(oldp+23,((3U == (0x7fU & vlSelf->top__DOT__InstructionWire))));
    bufp->fullCData(oldp+24,((0x1fU & (vlSelf->top__DOT__InstructionWire 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+25,((0x1fU & (vlSelf->top__DOT__InstructionWire 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+26,((0x1fU & (vlSelf->top__DOT__InstructionWire 
                                       >> 7U))),5);
    bufp->fullIData(oldp+27,(((3U == (0x7fU & vlSelf->top__DOT__InstructionWire))
                               ? vlSelf->top__DOT__RamOutWire
                               : vlSelf->top__DOT__ALUResultWire)),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__ImmediateExtendWire),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__RamOutWire),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__register_file__DOT__register_array[0]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__register_file__DOT__register_array[1]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__register_file__DOT__register_array[2]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__register_file__DOT__register_array[3]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__register_file__DOT__register_array[4]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__register_file__DOT__register_array[5]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__register_file__DOT__register_array[6]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__register_file__DOT__register_array[7]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__register_file__DOT__register_array[8]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__register_file__DOT__register_array[9]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__register_file__DOT__register_array[10]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__register_file__DOT__register_array[11]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__register_file__DOT__register_array[12]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__register_file__DOT__register_array[13]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__register_file__DOT__register_array[14]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__register_file__DOT__register_array[15]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__register_file__DOT__register_array[16]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__register_file__DOT__register_array[17]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__register_file__DOT__register_array[18]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__register_file__DOT__register_array[19]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__register_file__DOT__register_array[20]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__register_file__DOT__register_array[21]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__register_file__DOT__register_array[22]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__register_file__DOT__register_array[23]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__register_file__DOT__register_array[24]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__register_file__DOT__register_array[25]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__register_file__DOT__register_array[26]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__register_file__DOT__register_array[27]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__register_file__DOT__register_array[28]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__register_file__DOT__register_array[29]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__register_file__DOT__register_array[30]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__register_file__DOT__register_array[31]),32);
    bufp->fullBit(oldp+62,(vlSelf->rst));
    bufp->fullBit(oldp+63,(vlSelf->trigger_i));
    bufp->fullBit(oldp+64,(vlSelf->clk));
    bufp->fullIData(oldp+65,(vlSelf->data_out),32);
    bufp->fullIData(oldp+66,(0x20U),32);
    bufp->fullIData(oldp+67,(5U),32);
    bufp->fullIData(oldp+68,(8U),32);
}
