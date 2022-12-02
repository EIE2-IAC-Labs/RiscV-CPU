#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T2:kos");
  vbdSetMode(0);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 0;
  top->rst=0;
 
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    // if(vbdFlag()){
    for (tick=0; tick<2 && vbdFlag(); tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
     
    vbdCycle(simcyc);
    top->rst = (simcyc < 2);    // assert reset for 1st cycle

    vbdHex(3,(int(top->a0out)>>8)&0xF);
    vbdHex(2,(int(top->a0out)>>4)&0xF);
    vbdHex(1,int(top->a0out)&0xF);

}
vbdClose();     // ++++
tfp->close(); 
exit(0);
}