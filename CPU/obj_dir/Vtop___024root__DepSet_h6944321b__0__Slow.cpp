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
    VlWide<4>/*127:0*/ __Vtemp_he8d6983c__0;
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
    __Vtemp_he8d6983c__0[0U] = 0x2e6d656dU;
    __Vtemp_he8d6983c__0[1U] = 0x696f6e73U;
    __Vtemp_he8d6983c__0[2U] = 0x72756374U;
    __Vtemp_he8d6983c__0[3U] = 0x696e7374U;
    VL_READMEM_N(true, 8, 4096, 3217031168, VL_CVT_PACK_STR_NW(4, __Vtemp_he8d6983c__0)
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
    vlSelf->top__DOT__InstructionWire = ((vlSelf->top__DOT__rom__DOT__rom_array
                                          [(0xfffU 
                                            & vlSelf->top__DOT__PC_wire)] 
                                          << 0x18U) 
                                         | ((vlSelf->top__DOT__rom__DOT__rom_array
                                             [(0xfffU 
                                               & ((IData)(1U) 
                                                  + vlSelf->top__DOT__PC_wire))] 
                                             << 0x10U) 
                                            | ((vlSelf->top__DOT__rom__DOT__rom_array
                                                [(0xfffU 
                                                  & ((IData)(2U) 
                                                     + vlSelf->top__DOT__PC_wire))] 
                                                << 8U) 
                                               | vlSelf->top__DOT__rom__DOT__rom_array
                                               [(0xfffU 
                                                 & ((IData)(3U) 
                                                    + vlSelf->top__DOT__PC_wire))])));
    vlSelf->top__DOT__RD1Wire = vlSelf->top__DOT__register_file__DOT__register_array
        [(0x1fU & (vlSelf->top__DOT__InstructionWire 
                   >> 0xfU))];
    vlSelf->top__DOT__RD2Wire = vlSelf->top__DOT__register_file__DOT__register_array
        [(0x1fU & (vlSelf->top__DOT__InstructionWire 
                   >> 0x14U))];
    if ((0x13U == (0x7fU & vlSelf->top__DOT__InstructionWire))) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    }
    if ((0x40U & vlSelf->top__DOT__InstructionWire)) {
        vlSelf->top__DOT__ImmSrcWire = ((0x20U & vlSelf->top__DOT__InstructionWire)
                                         ? ((0x10U 
                                             & vlSelf->top__DOT__InstructionWire)
                                             ? 0U : 
                                            ((8U & vlSelf->top__DOT__InstructionWire)
                                              ? 0U : 
                                             ((4U & vlSelf->top__DOT__InstructionWire)
                                               ? 0U
                                               : ((2U 
                                                   & vlSelf->top__DOT__InstructionWire)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 2U
                                                    : 0U)
                                                   : 0U))))
                                         : 0U);
    } else if ((0x20U & vlSelf->top__DOT__InstructionWire)) {
        if ((0x10U & vlSelf->top__DOT__InstructionWire)) {
            if ((8U & vlSelf->top__DOT__InstructionWire)) {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            } else if ((4U & vlSelf->top__DOT__InstructionWire)) {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            } else if ((2U & vlSelf->top__DOT__InstructionWire)) {
                if ((1U & vlSelf->top__DOT__InstructionWire)) {
                    vlSelf->top__DOT__ALUctrlWire = 
                        ((0x4000U & vlSelf->top__DOT__InstructionWire)
                          ? ((0x2000U & vlSelf->top__DOT__InstructionWire)
                              ? ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                  ? 2U : 3U) : ((0x1000U 
                                                 & vlSelf->top__DOT__InstructionWire)
                                                 ? 
                                                ((0x40000000U 
                                                  & vlSelf->top__DOT__InstructionWire)
                                                  ? 9U
                                                  : 7U)
                                                 : 4U))
                          : ((0x2000U & vlSelf->top__DOT__InstructionWire)
                              ? ((0x1000U & vlSelf->top__DOT__InstructionWire)
                                  ? 6U : 5U) : ((0x1000U 
                                                 & vlSelf->top__DOT__InstructionWire)
                                                 ? 8U
                                                 : 
                                                ((0x40000000U 
                                                  & vlSelf->top__DOT__InstructionWire)
                                                  ? 1U
                                                  : 0U))));
                } else {
                    vlSelf->top__DOT__ImmSrcWire = 0U;
                }
            } else {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            }
        } else if ((8U & vlSelf->top__DOT__InstructionWire)) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((4U & vlSelf->top__DOT__InstructionWire)) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((2U & vlSelf->top__DOT__InstructionWire)) {
            if ((1U & vlSelf->top__DOT__InstructionWire)) {
                vlSelf->top__DOT__ALUctrlWire = 0xfU;
                vlSelf->top__DOT__ImmSrcWire = 1U;
                if ((0U == (7U & (vlSelf->top__DOT__InstructionWire 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__addrSelectWire = 0U;
                } else if (VL_LIKELY((2U == (7U & (vlSelf->top__DOT__InstructionWire 
                                                   >> 0xcU))))) {
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
    } else if ((0x10U & vlSelf->top__DOT__InstructionWire)) {
        if ((8U & vlSelf->top__DOT__InstructionWire)) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((4U & vlSelf->top__DOT__InstructionWire)) {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        } else if ((2U & vlSelf->top__DOT__InstructionWire)) {
            if ((1U & vlSelf->top__DOT__InstructionWire)) {
                vlSelf->top__DOT__ALUctrlWire = ((0x4000U 
                                                  & vlSelf->top__DOT__InstructionWire)
                                                  ? 
                                                 ((0x2000U 
                                                   & vlSelf->top__DOT__InstructionWire)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 2U
                                                    : 3U)
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 
                                                   ((0x40000000U 
                                                     & vlSelf->top__DOT__InstructionWire)
                                                     ? 9U
                                                     : 7U)
                                                    : 4U))
                                                  : 
                                                 ((0x2000U 
                                                   & vlSelf->top__DOT__InstructionWire)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 6U
                                                    : 5U)
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->top__DOT__InstructionWire)
                                                    ? 8U
                                                    : 
                                                   ((0x40000000U 
                                                     & vlSelf->top__DOT__InstructionWire)
                                                     ? 1U
                                                     : 0U))));
            } else {
                vlSelf->top__DOT__ImmSrcWire = 0U;
            }
        } else {
            vlSelf->top__DOT__ImmSrcWire = 0U;
        }
    } else if ((8U & vlSelf->top__DOT__InstructionWire)) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    } else if ((4U & vlSelf->top__DOT__InstructionWire)) {
        vlSelf->top__DOT__ImmSrcWire = 0U;
    } else if ((2U & vlSelf->top__DOT__InstructionWire)) {
        if ((1U & vlSelf->top__DOT__InstructionWire)) {
            vlSelf->top__DOT__ALUctrlWire = 0xfU;
            vlSelf->top__DOT__ImmSrcWire = 0U;
            if ((0U == (7U & (vlSelf->top__DOT__InstructionWire 
                              >> 0xcU)))) {
                vlSelf->top__DOT__addrSelectWire = 0U;
            } else if (VL_LIKELY((2U == (7U & (vlSelf->top__DOT__InstructionWire 
                                               >> 0xcU))))) {
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
                                                             (vlSelf->top__DOT__InstructionWire 
                                                              >> 0x1fU))) 
                                                  << 0xbU) 
                                                 | (0x7ffU 
                                                    & (vlSelf->top__DOT__InstructionWire 
                                                       >> 0x14U)))
                                              : ((1U 
                                                  == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->top__DOT__InstructionWire 
                                                               >> 0x1fU))) 
                                                   << 0xbU) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->top__DOT__InstructionWire 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlSelf->top__DOT__InstructionWire 
                                                           >> 7U))))
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->top__DOT__InstructionWire 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0x800U 
                                                       & (vlSelf->top__DOT__InstructionWire 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlSelf->top__DOT__InstructionWire 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & vlSelf->top__DOT__InstructionWire))))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__InstructionWire 
                                                                 >> 0x1fU))) 
                                                     << 0x13U) 
                                                    | (0x7ffffU 
                                                       & (vlSelf->top__DOT__InstructionWire 
                                                          >> 0xcU)))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__ImmSrcWire))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__InstructionWire 
                                                                  >> 0x1fU))) 
                                                      << 0x14U) 
                                                     | ((0xff000U 
                                                         & vlSelf->top__DOT__InstructionWire) 
                                                        | ((0x800U 
                                                            & vlSelf->top__DOT__InstructionWire) 
                                                           | (0x7feU 
                                                              & (vlSelf->top__DOT__InstructionWire 
                                                                 >> 0x14U)))))
                                                     : 0U)))));
    vlSelf->top__DOT__Aluop2Wire = (((0x13U == (0x7fU 
                                                & vlSelf->top__DOT__InstructionWire)) 
                                     | (3U == (0x7fU 
                                               & vlSelf->top__DOT__InstructionWire)))
                                     ? vlSelf->top__DOT__ImmediateExtendWire
                                     : vlSelf->top__DOT__RD2Wire);
    vlSelf->top__DOT__next_PC = (((0x63U == (0x7fU 
                                             & vlSelf->top__DOT__InstructionWire)) 
                                  & ((0x4000U & vlSelf->top__DOT__InstructionWire)
                                      ? ((~ (vlSelf->top__DOT__InstructionWire 
                                             >> 0xdU)) 
                                         & ((0x1000U 
                                             & vlSelf->top__DOT__InstructionWire)
                                             ? (vlSelf->top__DOT__RD1Wire 
                                                >= vlSelf->top__DOT__Aluop2Wire)
                                             : (vlSelf->top__DOT__RD1Wire 
                                                < vlSelf->top__DOT__Aluop2Wire)))
                                      : ((0x2000U & vlSelf->top__DOT__InstructionWire)
                                          ? ((0x1000U 
                                              & vlSelf->top__DOT__InstructionWire)
                                              ? VL_GTES_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire)
                                              : VL_LTS_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire))
                                          : ((0x1000U 
                                              & vlSelf->top__DOT__InstructionWire)
                                              ? (vlSelf->top__DOT__RD1Wire 
                                                 != vlSelf->top__DOT__Aluop2Wire)
                                              : (vlSelf->top__DOT__RD1Wire 
                                                 == vlSelf->top__DOT__Aluop2Wire)))))
                                  ? (vlSelf->top__DOT__PC_wire 
                                     + vlSelf->top__DOT__ImmediateExtendWire)
                                  : ((IData)(4U) + vlSelf->top__DOT__PC_wire));
    vlSelf->top__DOT__ALUResultWire = ((8U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                        ? ((4U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                            ? ((2U 
                                                & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? vlSelf->top__DOT__Aluop2Wire
                                                    : 0U)
                                                : 0U)
                                            : ((2U 
                                                & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    << 
                                                    (0x1fU 
                                                     & vlSelf->top__DOT__Aluop2Wire)))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__RD1Wire, 
                                                                  (0x1fU 
                                                                   & vlSelf->top__DOT__Aluop2Wire))
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    << 
                                                    (0x1fU 
                                                     & vlSelf->top__DOT__Aluop2Wire)))))
                                        : ((4U & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                            ? ((2U 
                                                & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    >> 
                                                    (0x1fU 
                                                     & vlSelf->top__DOT__Aluop2Wire))
                                                    : 
                                                   ((vlSelf->top__DOT__RD1Wire 
                                                     >= vlSelf->top__DOT__Aluop2Wire)
                                                     ? 0U
                                                     : 1U))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 
                                                   (VL_GTES_III(32, vlSelf->top__DOT__RD1Wire, vlSelf->top__DOT__Aluop2Wire)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    ^ vlSelf->top__DOT__Aluop2Wire)))
                                            : ((2U 
                                                & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    | vlSelf->top__DOT__Aluop2Wire)
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    & vlSelf->top__DOT__Aluop2Wire))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__ALUctrlWire))
                                                    ? 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    - vlSelf->top__DOT__Aluop2Wire)
                                                    : 
                                                   (vlSelf->top__DOT__RD1Wire 
                                                    + vlSelf->top__DOT__Aluop2Wire)))));
    if (((0x23U != (0x7fU & vlSelf->top__DOT__InstructionWire)) 
         & (IData)(vlSelf->top__DOT__addrSelectWire))) {
        vlSelf->top__DOT__RamOutWire = ((vlSelf->top__DOT__ram__DOT__ram_array
                                         [(0xfffU & vlSelf->top__DOT__ALUResultWire)] 
                                         << 0x18U) 
                                        | ((vlSelf->top__DOT__ram__DOT__ram_array
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->top__DOT__ALUResultWire))] 
                                            << 0x10U) 
                                           | ((vlSelf->top__DOT__ram__DOT__ram_array
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->top__DOT__ALUResultWire))] 
                                               << 8U) 
                                              | vlSelf->top__DOT__ram__DOT__ram_array
                                              [(0xfffU 
                                                & ((IData)(3U) 
                                                   + vlSelf->top__DOT__ALUResultWire))])));
    }
    if (((0x23U != (0x7fU & vlSelf->top__DOT__InstructionWire)) 
         & (~ (IData)(vlSelf->top__DOT__addrSelectWire)))) {
        if ((1U & (~ (vlSelf->top__DOT__ram__DOT__ram_array
                      [(0xfffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultWire))] 
                      >> 7U)))) {
            vlSelf->top__DOT__RamOutWire = vlSelf->top__DOT__ram__DOT__ram_array
                [(0xfffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultWire))];
        }
        if ((0x80U & vlSelf->top__DOT__ram__DOT__ram_array
             [(0xfffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultWire))])) {
            vlSelf->top__DOT__RamOutWire = (0xffffff00U 
                                            | vlSelf->top__DOT__ram__DOT__ram_array
                                            [(0xfffU 
                                              & ((IData)(3U) 
                                                 + vlSelf->top__DOT__ALUResultWire))]);
        }
    }
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
    vlSelf->data_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PC_wire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD1Wire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2Wire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Aluop2Wire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUResultWire = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__InstructionWire = VL_RAND_RESET_I(32);
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
    vlSelf->top__DOT__register_file__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
