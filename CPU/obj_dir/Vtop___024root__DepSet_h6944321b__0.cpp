// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__register_file__DOT__register_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__register_file__DOT__register_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__register_file__DOT__register_array__v0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__ram_array__v0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__ram_array__v1;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__ram_array__v2;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__ram_array__v3;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__DOT__ram_array__v4;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__DOT__ram_array__v4;
    // Body
    __Vdlyvset__top__DOT__register_file__DOT__register_array__v0 = 0U;
    __Vdlyvset__top__DOT__ram__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__ram__DOT__ram_array__v4 = 0U;
    if ((((0x33U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
          | (0x13U == (0x7fU & vlSelf->top__DOT__InstructionWire))) 
         | (3U == (0x7fU & vlSelf->top__DOT__InstructionWire)))) {
        __Vdlyvval__top__DOT__register_file__DOT__register_array__v0 
            = ((3U == (0x7fU & vlSelf->top__DOT__InstructionWire))
                ? vlSelf->top__DOT__RamOutWire : vlSelf->top__DOT__ALUResultWire);
        __Vdlyvset__top__DOT__register_file__DOT__register_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__register_file__DOT__register_array__v0 
            = (0x1fU & (vlSelf->top__DOT__InstructionWire 
                        >> 7U));
    }
    if (VL_UNLIKELY(((0x23U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                     & (IData)(vlSelf->top__DOT__addrSelectWire)))) {
        VL_WRITEF("%3#%3#%3#%3#\n",8,vlSelf->top__DOT__ram__DOT__ram_array
                  [(0xfffU & vlSelf->top__DOT__ALUResultWire)],
                  8,vlSelf->top__DOT__ram__DOT__ram_array
                  [(0xfffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultWire))],
                  8,vlSelf->top__DOT__ram__DOT__ram_array
                  [(0xfffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultWire))],
                  8,vlSelf->top__DOT__ram__DOT__ram_array
                  [(0xfffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultWire))]);
        __Vdlyvval__top__DOT__ram__DOT__ram_array__v0 
            = (vlSelf->top__DOT__RD2Wire >> 0x18U);
        __Vdlyvset__top__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v0 
            = (0xfffU & vlSelf->top__DOT__ALUResultWire);
        __Vdlyvval__top__DOT__ram__DOT__ram_array__v1 
            = (0xffU & (vlSelf->top__DOT__RD2Wire >> 0x10U));
        __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v1 
            = (0xfffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultWire));
        __Vdlyvval__top__DOT__ram__DOT__ram_array__v2 
            = (0xffU & (vlSelf->top__DOT__RD2Wire >> 8U));
        __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v2 
            = (0xfffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultWire));
        __Vdlyvval__top__DOT__ram__DOT__ram_array__v3 
            = (0xffU & vlSelf->top__DOT__RD2Wire);
        __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v3 
            = (0xfffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultWire));
    }
    if (VL_UNLIKELY(((0x23U == (0x7fU & vlSelf->top__DOT__InstructionWire)) 
                     & (~ (IData)(vlSelf->top__DOT__addrSelectWire))))) {
        VL_WRITEF("%3#\n",8,vlSelf->top__DOT__ram__DOT__ram_array
                  [(0xfffU & vlSelf->top__DOT__ALUResultWire)]);
        __Vdlyvval__top__DOT__ram__DOT__ram_array__v4 
            = (0xffU & vlSelf->top__DOT__RD2Wire);
        __Vdlyvset__top__DOT__ram__DOT__ram_array__v4 = 1U;
        __Vdlyvdim0__top__DOT__ram__DOT__ram_array__v4 
            = (0xfffU & vlSelf->top__DOT__ALUResultWire);
    }
    vlSelf->top__DOT__PC_wire = ((IData)(vlSelf->rst)
                                  ? 0U : vlSelf->top__DOT__next_PC);
    if (__Vdlyvset__top__DOT__register_file__DOT__register_array__v0) {
        vlSelf->top__DOT__register_file__DOT__register_array[__Vdlyvdim0__top__DOT__register_file__DOT__register_array__v0] 
            = __Vdlyvval__top__DOT__register_file__DOT__register_array__v0;
    }
    if (__Vdlyvset__top__DOT__ram__DOT__ram_array__v0) {
        vlSelf->top__DOT__ram__DOT__ram_array[__Vdlyvdim0__top__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__ram__DOT__ram_array__v0;
        vlSelf->top__DOT__ram__DOT__ram_array[__Vdlyvdim0__top__DOT__ram__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__ram__DOT__ram_array__v1;
        vlSelf->top__DOT__ram__DOT__ram_array[__Vdlyvdim0__top__DOT__ram__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__ram__DOT__ram_array__v2;
        vlSelf->top__DOT__ram__DOT__ram_array[__Vdlyvdim0__top__DOT__ram__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__ram__DOT__ram_array__v3;
    }
    if (__Vdlyvset__top__DOT__ram__DOT__ram_array__v4) {
        vlSelf->top__DOT__ram__DOT__ram_array[__Vdlyvdim0__top__DOT__ram__DOT__ram_array__v4] 
            = __Vdlyvval__top__DOT__ram__DOT__ram_array__v4;
    }
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

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger_i & 0xfeU))) {
        Verilated::overWidthError("trigger_i");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
