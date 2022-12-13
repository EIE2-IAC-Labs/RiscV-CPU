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
  top->dataWord_i = 357913949;
  //1555555D
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    if(simcyc == 1){
      top->dataWord_i = 357913945;
      //15555559
    }
    if(simcyc == 2){
      top->dataWord_i = 357913949;
      //1555555D, HIT
    }
    if(simcyc == 3){
      top->dataWord_i = 357813949;
      //1553CEBD, 
    }
    if(simcyc == 4){
      top->dataWord_i = 357913945;
      //15555559, HIT
    }

    if(simcyc == 5){
      top->dataWord_i = 357945021;
      //1555CEBD, NO HIT, put into data_1
    }
    if(simcyc == 6){
      top->dataWord_i = 290805085;
      //1155555D, HIT
    }
    

    if (Verilated::gotFinish())  exit(0);
  }

  tfp->close(); 
  exit(0);
}
