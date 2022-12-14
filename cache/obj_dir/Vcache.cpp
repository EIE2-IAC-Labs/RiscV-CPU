// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcache.h"
#include "Vcache__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcache::Vcache(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcache__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , hit_o{vlSymsp->TOP.hit_o}
    , dataWord0_i{vlSymsp->TOP.dataWord0_i}
    , dataWord1_i{vlSymsp->TOP.dataWord1_i}
    , dataWord2_i{vlSymsp->TOP.dataWord2_i}
    , dataWord3_i{vlSymsp->TOP.dataWord3_i}
    , addressWord_i{vlSymsp->TOP.addressWord_i}
    , dataWord_o{vlSymsp->TOP.dataWord_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcache::Vcache(const char* _vcname__)
    : Vcache(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcache::~Vcache() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcache___024root___eval_initial(Vcache___024root* vlSelf);
void Vcache___024root___eval_settle(Vcache___024root* vlSelf);
void Vcache___024root___eval(Vcache___024root* vlSelf);
#ifdef VL_DEBUG
void Vcache___024root___eval_debug_assertions(Vcache___024root* vlSelf);
#endif  // VL_DEBUG
void Vcache___024root___final(Vcache___024root* vlSelf);

static void _eval_initial_loop(Vcache__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcache___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcache___024root___eval_settle(&(vlSymsp->TOP));
        Vcache___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcache::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcache::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcache___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcache___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcache::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcache::final() {
    Vcache___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcache::hierName() const { return vlSymsp->name(); }
const char* Vcache::modelName() const { return "Vcache"; }
unsigned Vcache::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcache::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcache___024root__trace_init_top(Vcache___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcache___024root*>(voidSelf);
    Vcache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcache___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcache___024root__trace_register(Vcache___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcache::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcache::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcache___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
