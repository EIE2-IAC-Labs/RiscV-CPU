// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrom.h"
#include "Vrom__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vrom::Vrom(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrom__Syms(contextp(), _vcname__, this)}
    , a_i{vlSymsp->TOP.a_i}
    , rd_o{vlSymsp->TOP.rd_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vrom::Vrom(const char* _vcname__)
    : Vrom(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrom::~Vrom() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vrom___024root___eval_initial(Vrom___024root* vlSelf);
void Vrom___024root___eval_settle(Vrom___024root* vlSelf);
void Vrom___024root___eval(Vrom___024root* vlSelf);
#ifdef VL_DEBUG
void Vrom___024root___eval_debug_assertions(Vrom___024root* vlSelf);
#endif  // VL_DEBUG
void Vrom___024root___final(Vrom___024root* vlSelf);

static void _eval_initial_loop(Vrom__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vrom___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vrom___024root___eval_settle(&(vlSymsp->TOP));
        Vrom___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vrom::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrom::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrom___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vrom___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vrom::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vrom::final() {
    Vrom___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrom::hierName() const { return vlSymsp->name(); }
const char* Vrom::modelName() const { return "Vrom"; }
unsigned Vrom::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vrom::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vrom___024root__trace_init_top(Vrom___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrom___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrom___024root*>(voidSelf);
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vrom___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vrom___024root__trace_register(Vrom___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vrom::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vrom::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vrom___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
