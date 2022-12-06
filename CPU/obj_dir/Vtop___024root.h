// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger_i,0,0);
    VL_OUT8(opcode,6,0);
    VL_OUT8(funct3,2,0);
    VL_OUT8(funct7,0,0);
    VL_OUT8(rs1Wire,4,0);
    VL_OUT8(rs2Wire,4,0);
    VL_OUT8(rdWire,4,0);
    CData/*3:0*/ top__DOT__ALUctrlWire;
    CData/*2:0*/ top__DOT__ImmSrcWire;
    CData/*0:0*/ top__DOT__addrSelectWire;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(PC_wire,31,0);
    VL_OUT(InstructionWire,31,0);
    VL_OUT(wd3Wire,31,0);
    VL_OUT(data_out,31,0);
    VL_OUT(RD1Wire,31,0);
    VL_OUT(Aluop2Wire,31,0);
    VL_OUT(ALUResultWire,31,0);
    IData/*31:0*/ top__DOT__next_PC;
    IData/*31:0*/ top__DOT__RD2Wire;
    IData/*31:0*/ top__DOT__ImmediateExtendWire;
    IData/*31:0*/ top__DOT__RamOutWire;
    IData/*31:0*/ top__DOT__register_file__DOT__a1;
    IData/*31:0*/ top__DOT__register_file__DOT__unnamedblk1__DOT__i;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__rom__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__register_file__DOT__register_array;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__ram__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
