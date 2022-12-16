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
  tfp->open ("register_file.vcd");

  // initialize simulation input 
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    if(simcyc == 1){
      top->WE3_i = 1;
      top->AD3_i = 5;
      top->WD3_i = 10;
      top->AD1_i = 0; 
    }
    if(simcyc == 2){
      top->WE3_i = 0;
      top->AD3_i = 6;
      top->WD3_i = 10;
      top->AD1_i = 5; 
    }
    if(simcyc == 3){
      top->WE3_i = 1;
      top->AD3_i = 0;
      top->WD3_i = 10;
      top->AD1_i = 0; 
    }


    // either simulation finished, or 'q' is pressed
    if (Verilated::gotFinish()) 
      exit(0);
  }

  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
