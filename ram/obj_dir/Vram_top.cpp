// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vram_top.h"
#include "Vram_top__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vram_top::Vram_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vram_top__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , write_en_i{vlSymsp->TOP.write_en_i}
    , memtype_i{vlSymsp->TOP.memtype_i}
    , memsign_i{vlSymsp->TOP.memsign_i}
    , wd_i{vlSymsp->TOP.wd_i}
    , a_i{vlSymsp->TOP.a_i}
    , rd_o{vlSymsp->TOP.rd_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vram_top::Vram_top(const char* _vcname__)
    : Vram_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vram_top::~Vram_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vram_top___024root___eval_initial(Vram_top___024root* vlSelf);
void Vram_top___024root___eval_settle(Vram_top___024root* vlSelf);
void Vram_top___024root___eval(Vram_top___024root* vlSelf);
#ifdef VL_DEBUG
void Vram_top___024root___eval_debug_assertions(Vram_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vram_top___024root___final(Vram_top___024root* vlSelf);

static void _eval_initial_loop(Vram_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vram_top___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vram_top___024root___eval_settle(&(vlSymsp->TOP));
        Vram_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vram_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vram_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vram_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vram_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vram_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vram_top::final() {
    Vram_top___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vram_top::hierName() const { return vlSymsp->name(); }
const char* Vram_top::modelName() const { return "Vram_top"; }
unsigned Vram_top::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vram_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vram_top___024root__trace_init_top(Vram_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vram_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_top___024root*>(voidSelf);
    Vram_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vram_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vram_top___024root__trace_register(Vram_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vram_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vram_top::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vram_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
