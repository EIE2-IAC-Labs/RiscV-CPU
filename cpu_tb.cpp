#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000  // max simulation cycles

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
  vbdHeader("PDF Program");
  vbdSetMode(1);        // Flag mode set to one-shot
  vbdBar(0); //clear lights

  // initialize simulation inputs
  top->clk = 0;
  top->rst = 0;
  top->trigger_i = 0;
 
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    // if(vbdFlag()){
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    //////////////////////////////////////////////////////
    ///// f1.sh and pdf.sh will format respectively //////
    //////////////////////////////////////////////////////

    /*pdfstart*/ 
       if (simcyc > 800000 && simcyc % 8 == 0){  // plot every 4th, convenient for pipelining due to nops in display
       vbdPlot(int(top->data_out), 0, 255);
       vbdCycle(simcyc);
     }
    /*pdfend*/

    /*f1startX
    vbdCycle(simcyc);
    top->trigger_i = vbdFlag();
    vbdBar(top->data_out & 0xFF);
    vbdHex(3,(int(top->data_out)>>8)&0xF);
    vbdHex(2,(int(top->data_out)>>4)&0xF);
    vbdHex(1,int(top->data_out)&0xF);
    Yf1end*/
}

vbdClose();     // ++++
tfp->close(); 
exit(0);
}
