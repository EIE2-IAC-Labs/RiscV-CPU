#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 

  // initialize simulation inputs
  top->clk = 0;
  top->addressWord_i = 2880154460;
  top->dataWord_i = 12345;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    if(simcyc == 1){
      top->addressWord_i = 2880154456;
      top->dataWord_i = 12345;
    }
    if(simcyc == 2){
      top->addressWord_i = 2882190428;
      top->dataWord_i = 67890;
    }
    
    if(simcyc == 4){
      top->addressWord_i = 2880154460;
      //top->dataWord_i = 4;
      //hit -> data out 12345
    }

    if(simcyc == 5){
      top->addressWord_i = 2883239260;
      top->dataWord_i = 10000;
    }
    if(simcyc == 6){
      top->addressWord_i = 2883239260;
      top->dataWord_i = 10001;
      top->overwrite_i = 1;
    }

    

    if (Verilated::gotFinish())  exit(0);
  }

  tfp->close(); 
  exit(0);
}
