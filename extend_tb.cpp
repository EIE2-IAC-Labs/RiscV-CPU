#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

//#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 9
#define RAM_SZ pow(2,ADDRESS_WIDTH)

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop* top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("Extend_test.vcd");

  // initialize simulation input 
  top->ImmSrc_i = 0;
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    //000
    if(simcyc == 1){
      top->ImmSrc_i = 0;
      top->Imm_i = 2863591150;
    } // out: FFFFFAAA
    if(simcyc == 2){
      top->Imm_i = 447672046;
    } // out: 000001AA

    //001
    if(simcyc == 3){
      top->ImmSrc_i = 1;
      top->Imm_i = 2835346688;
    } // out: FFFFFA8A
    if(simcyc == 4){
      top->Imm_i = 419427584;
    } // out: 0000018A

    //010
    if(simcyc == 5){
      top->ImmSrc_i = 2;
      top->Imm_i = 2834230933;
    } // out: 00000A94
    if(simcyc == 6){
      top->Imm_i = 686747285;
    } // out: 00000A94
    
    //011
    if(simcyc == 7){
      top->ImmSrc_i = 3;
      top->Imm_i = 2863312622;
    } // out: FFFAAAAA
    if(simcyc == 8){
      top->Imm_i = 447393518;
    } // out: 0001AAAA

    //100 was tested inside the topfile manually with gtk wave

    // either simulation finished, or 'q' is pressed
    if (Verilated::gotFinish()) 
      exit(0);
  }

  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
