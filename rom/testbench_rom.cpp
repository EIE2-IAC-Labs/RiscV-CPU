#include "Vrom.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc,char **argv, char **env){
    int i;
    int clk;
    

    Verilated::commandArgs(argc, argv);
    Vrom* top = new Vrom;
    VerilatedVcdC* tfp= new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace (tfp,99);
    tfp->open ("rom.vcd");

    top->a_i=0;

    for (i=0; i<5; i++){ 
            
        for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->eval();
        }
        
        top->a_i = top->a_i + 4;
        std::cout << top->rd_o << std::endl;



    if (Verilated::gotFinish()) exit(0);
    }
    
    
    tfp->close();
    exit(0);

}