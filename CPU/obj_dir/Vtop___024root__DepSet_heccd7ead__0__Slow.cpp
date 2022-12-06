// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_he5f77a3e__0;
    // Body
    vlSelf->top__DOT__register_file__DOT__register_array[0U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[1U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[2U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[3U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[4U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[5U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[6U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[7U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[8U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[9U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xaU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xbU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xcU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xdU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xeU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0xfU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x10U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x11U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x12U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x13U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x14U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x15U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x16U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x17U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x18U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x19U] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1aU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1bU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1cU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1dU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1eU] = 0U;
    vlSelf->top__DOT__register_file__DOT__register_array[0x1fU] = 0U;
    vlSelf->top__DOT__register_file__DOT__unnamedblk1__DOT__i = 0x20U;
    VL_WRITEF("Loading rom.\n");
    __Vtemp_he5f77a3e__0[0U] = 0x2e6d656dU;
    __Vtemp_he5f77a3e__0[1U] = 0x696f6e73U;
    __Vtemp_he5f77a3e__0[2U] = 0x72756374U;
    __Vtemp_he5f77a3e__0[3U] = 0x696e7374U;
    VL_READMEM_N(true, 8, 4096, 3217031168, VL_CVT_PACK_STR_NW(4, __Vtemp_he5f77a3e__0)
                 ,  &(vlSelf->top__DOT__rom__DOT__rom_array)
                 , 3217031168, ~0ULL);
    VL_WRITEF("rom done\nLoading ram.\n");
    VL_READMEM_N(true, 8, 4096, 0, std::string{"data.mem"}
                 ,  &(vlSelf->top__DOT__ram__DOT__ram_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->data_out = vlSelf->top__DOT__register_file__DOT__register_array
        [0xaU];
    vlSelf->InstructionWire = ((vlSelf->top__DOT__rom__DOT__rom_array
                                [(0xfffU & vlSelf->PC_wire)] 
                                << 0x18U) | ((vlSelf->top__DOT__rom__DOT__rom_array
                                              [(0xfffU 
                                                & ((IData)(1U) 
                                                   + vlSelf->PC_wire))] 
                                              << 0x10U) 
                                             | ((vlSelf->top__DOT__rom__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->PC_wire))] 
                                                 << 8U) 
                                                | vlSelf->top__DOT__rom__DOT__rom_array
                                                [(0xfffU 
                                                  & ((IData)(3U) 
                                                     + vlSelf->PC_wire))])));
    vlSelf->rdWire = (0x1fU & (vlSelf->InstructionWire 
                               >> 7U));
    vlSelf->rs1Wire = (0x1fU & (vlSelf->InstructionWire 
                                >> 0xfU));
    vlSelf->rs2Wire = (0x1fU & (vlSelf->InstructionWire 
                                >> 0x14U));
    vlSelf->funct7 = (1U & (vlSelf->InstructionWire 
                            >> 0x1eU));
    vlSelf->funct3 = (7U & (vlSelf->InstructionWire 
                            >> 0xcU));
    vlSelf->opcode = (0x7fU & vlSelf->InstructionWire);
    vlSelf->RD1Wire = vlSelf->top__DOT__register_file__DOT__register_array
        [vlSelf->rs1Wire];
    vlSelf->top__DOT__RD2Wire = vlSelf->top__DOT__register_file__DOT__register_array
        [vlSelf->rs2Wire];
    if ((0x13U == (IData)(vlSelf->opcode))) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    }
    if ((0x40U & (IData)(vlSelf->opcode))) {
        vlSelf->top__DOT__ImmSrcWire = ((0x20U & (IData)(vlSelf->opcode))
                                         ? ((0x10U 
                                             & (IData)(vlSelf->opcode))
                                             ? 0U : 
                                            ((8U & (IData)(vlSelf->opcode))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelf->opcode))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelf->opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->opcode))
                                                    ? 2U
                                                    : 0U)
                                                   : 0U))))
                                         : 0U);
    } else if ((0x20U & (IData)(vlSelf->opcode))) {
        if ((0x10U & (IData)(vlSelf->opcode))) {
            if ((8U & (IData)(vlSelf->opcode))) {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            } else if ((4U & (IData)(vlSelf->opcode))) {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            } else if ((2U & (IData)(vlSelf->opcode))) {
                if ((1U & (IData)(vlSelf->opcode))) {
                    vlSelf->top__DOT__ALUctrlWire = 
                        ((4U & (IData)(vlSelf->funct3))
                          ? ((2U & (IData)(vlSelf->funct3))
                              ? ((1U & (IData)(vlSelf->funct3))
                                  ? 2U : 3U) : ((1U 
                                                 & (IData)(vlSelf->funct3))
                                                 ? 
                                                ((IData)(vlSelf->funct7)
                                                  ? 9U
                                                  : 7U)
                                                 : 4U))
                          : ((2U & (IData)(vlSelf->funct3))
                              ? ((1U & (IData)(vlSelf->funct3))
                                  ? 6U : 5U) : ((1U 
                                                 & (IData)(vlSelf->funct3))
                                                 ? 8U
                                                 : 
                                                ((IData)(vlSelf->funct7)
                                                  ? 1U
                                                  : 0U))));
                } else {
                    vlSelf->top__DOT__ImmSrcWire = 0U;
                }
            } else {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            }
        } else if ((8U & (IData)(vlSelf->opcode))) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((4U & (IData)(vlSelf->opcode))) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((2U & (IData)(vlSelf->opcode))) {
            if ((1U & (IData)(vlSelf->opcode))) {
                vlSelf->top__DOT__ALUctrlWire = 0xfU;
                vlSelf->top__DOT__ImmSrcWire = 1U;
                if ((0U == (IData)(vlSelf->funct3))) {
                    vlSelf->top__DOT__addrSelectWire = 0U;
                } else if (VL_LIKELY((2U == (IData)(vlSelf->funct3)))) {
                    vlSelf->top__DOT__addrSelectWire = 1U;
                } else {
                    VL_WRITEF("Store Half has not been implemented!! \n");
                }
            } else {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            }
        } else {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        }
    } else if ((0x10U & (IData)(vlSelf->opcode))) {
        if ((8U & (IData)(vlSelf->opcode))) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((4U & (IData)(vlSelf->opcode))) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((2U & (IData)(vlSelf->opcode))) {
            if ((1U & (IData)(vlSelf->opcode))) {
                vlSelf->top__DOT__ALUctrlWire = ((4U 
                                                  & (IData)(vlSelf->funct3))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->funct3))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->funct3))
                                                    ? 2U
                                                    : 3U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->funct3))
                                                    ? 
                                                   ((IData)(vlSelf->funct7)
                                                     ? 9U
                                                     : 7U)
                                                    : 4U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->funct3))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->funct3))
                                                    ? 6U
                                                    : 5U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->funct3))
                                                    ? 8U
                                                    : 
                                                   ((IData)(vlSelf->funct7)
                                                     ? 1U
                                                     : 0U))));
            } else {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            }
        } else {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        }
    } else if ((8U & (IData)(vlSelf->opcode))) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    } else if ((4U & (IData)(vlSelf->opcode))) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    } else if ((2U & (IData)(vlSelf->opcode))) {
        if ((1U & (IData)(vlSelf->opcode))) {
            vlSelf->top__DOT__ALUctrlWire = 0xfU;
            vlSelf->top__DOT__ImmSrcWire = 0U;
            if ((0U == (IData)(vlSelf->funct3))) {
                vlSelf->top__DOT__addrSelectWire = 0U;
            } else if (VL_LIKELY((2U == (IData)(vlSelf->funct3)))) {
                vlSelf->top__DOT__addrSelectWire = 1U;
            } else {
                VL_WRITEF("Load Half, Load Half Unsigned and Load Byte Unsigned have not been implemented!!\n");
            }
        } else {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        }
    } else {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    }
    vlSelf->top__DOT__ImmediateExtendWire = ((0U == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                              ? (((- (IData)(
                                                             (vlSelf->InstructionWire 
                                                              >> 0x1fU))) 
                                                  << 0xbU) 
                                                 | (0x7ffU 
                                                    & (vlSelf->InstructionWire 
                                                       >> 0x14U)))
                                              : ((1U 
                                                  == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->InstructionWire 
                                                               >> 0x1fU))) 
                                                   << 0xbU) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->InstructionWire 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlSelf->InstructionWire 
                                                           >> 7U))))
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->InstructionWire 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0x800U 
                                                       & (vlSelf->InstructionWire 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlSelf->InstructionWire 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlSelf->InstructionWire 
                                                               >> 7U)))))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->InstructionWire 
                                                                 >> 0x1fU))) 
                                                     << 0x13U) 
                                                    | (0x7ffffU 
                                                       & (vlSelf->InstructionWire 
                                                          >> 0xcU)))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->InstructionWire 
                                                                  >> 0x1fU))) 
                                                      << 0x14U) 
                                                     | ((0xff000U 
                                                         & vlSelf->InstructionWire) 
                                                        | ((0x800U 
                                                            & vlSelf->InstructionWire) 
                                                           | (0x7feU 
                                                              & (vlSelf->InstructionWire 
                                                                 >> 0x14U)))))
                                                     : 0U)))));
    vlSelf->Aluop2Wire = (((0x13U == (IData)(vlSelf->opcode)) 
                           | (3U == (IData)(vlSelf->opcode)))
                           ? vlSelf->top__DOT__ImmediateExtendWire
                           : vlSelf->top__DOT__RD2Wire);
    vlSelf->top__DOT__next_PC = (((0x63U == (IData)(vlSelf->opcode)) 
                                  & ((4U & (IData)(vlSelf->funct3))
                                      ? ((~ ((IData)(vlSelf->funct3) 
                                             >> 1U)) 
                                         & ((1U & (IData)(vlSelf->funct3))
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
                                  ? (vlSelf->PC_wire 
                                     + vlSelf->top__DOT__ImmediateExtendWire)
                                  : ((IData)(4U) + vlSelf->PC_wire));
    vlSelf->ALUResultWire = ((8U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                              ? ((4U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                  ? ((2U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                      ? ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? vlSelf->Aluop2Wire
                                          : 0U) : 0U)
                                  : ((2U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                      ? ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? 0U : (vlSelf->RD1Wire 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->Aluop2Wire)))
                                      : ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? VL_SHIFTRS_III(32,32,5, vlSelf->RD1Wire, 
                                                           (0x1fU 
                                                            & vlSelf->Aluop2Wire))
                                          : (vlSelf->RD1Wire 
                                             << (0x1fU 
                                                 & vlSelf->Aluop2Wire)))))
                              : ((4U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                  ? ((2U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                      ? ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? (vlSelf->RD1Wire 
                                             >> (0x1fU 
                                                 & vlSelf->Aluop2Wire))
                                          : ((vlSelf->RD1Wire 
                                              >= vlSelf->Aluop2Wire)
                                              ? 0U : 1U))
                                      : ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? (VL_GTES_III(32, vlSelf->RD1Wire, vlSelf->Aluop2Wire)
                                              ? 0U : 1U)
                                          : (vlSelf->RD1Wire 
                                             ^ vlSelf->Aluop2Wire)))
                                  : ((2U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                      ? ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? (vlSelf->RD1Wire 
                                             | vlSelf->Aluop2Wire)
                                          : (vlSelf->RD1Wire 
                                             & vlSelf->Aluop2Wire))
                                      : ((1U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                          ? (vlSelf->RD1Wire 
                                             - vlSelf->Aluop2Wire)
                                          : (vlSelf->RD1Wire 
                                             + vlSelf->Aluop2Wire)))));
    if (((0x23U != (IData)(vlSelf->opcode)) & (IData)(vlSelf->top__DOT__addrSelectWire))) {
        vlSelf->top__DOT__RamOutWire = ((vlSelf->top__DOT__ram__DOT__ram_array
                                         [(0xfffU & vlSelf->ALUResultWire)] 
                                         << 0x18U) 
                                        | ((vlSelf->top__DOT__ram__DOT__ram_array
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->ALUResultWire))] 
                                            << 0x10U) 
                                           | ((vlSelf->top__DOT__ram__DOT__ram_array
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->ALUResultWire))] 
                                               << 8U) 
                                              | vlSelf->top__DOT__ram__DOT__ram_array
                                              [(0xfffU 
                                                & ((IData)(3U) 
                                                   + vlSelf->ALUResultWire))])));
    }
    if (((0x23U != (IData)(vlSelf->opcode)) & (~ (IData)(vlSelf->top__DOT__addrSelectWire)))) {
        if ((1U & (~ (vlSelf->top__DOT__ram__DOT__ram_array
                      [(0xfffU & ((IData)(3U) + vlSelf->ALUResultWire))] 
                      >> 7U)))) {
            vlSelf->top__DOT__RamOutWire = vlSelf->top__DOT__ram__DOT__ram_array
                [(0xfffU & ((IData)(3U) + vlSelf->ALUResultWire))];
        }
        if ((0x80U & vlSelf->top__DOT__ram__DOT__ram_array
             [(0xfffU & ((IData)(3U) + vlSelf->ALUResultWire))])) {
            vlSelf->top__DOT__RamOutWire = (0xffffff00U 
                                            | vlSelf->top__DOT__ram__DOT__ram_array
                                            [(0xfffU 
                                              & ((IData)(3U) 
                                                 + vlSelf->ALUResultWire))]);
        }
    }
    vlSelf->wd3Wire = ((3U == (IData)(vlSelf->opcode))
                        ? vlSelf->top__DOT__RamOutWire
                        : vlSelf->ALUResultWire);
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger_i = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->PC_wire = VL_RAND_RESET_I(32);
    vlSelf->InstructionWire = VL_RAND_RESET_I(32);
    vlSelf->opcode = VL_RAND_RESET_I(7);
    vlSelf->funct3 = VL_RAND_RESET_I(3);
    vlSelf->funct7 = VL_RAND_RESET_I(1);
    vlSelf->rs1Wire = VL_RAND_RESET_I(5);
    vlSelf->rs2Wire = VL_RAND_RESET_I(5);
    vlSelf->rdWire = VL_RAND_RESET_I(5);
    vlSelf->wd3Wire = VL_RAND_RESET_I(32);
    vlSelf->data_out = VL_RAND_RESET_I(32);
    vlSelf->RD1Wire = VL_RAND_RESET_I(32);
    vlSelf->Aluop2Wire = VL_RAND_RESET_I(32);
    vlSelf->ALUResultWire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2Wire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUctrlWire = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ImmSrcWire = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__addrSelectWire = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmediateExtendWire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RamOutWire = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__rom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__register_file__DOT__register_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__register_file__DOT__a1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__register_file__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
