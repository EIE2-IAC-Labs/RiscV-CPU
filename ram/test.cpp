#include "Vram.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc,char **argv, char **env){
    int i;
    int clk;
    

    Verilated::commandArgs(argc, argv);
    Vram* top = new Vram;
    VerilatedVcdC* tfp= new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace (tfp,99);
    tfp->open ("ram.vcd");

    top->clk_i = 0;
    top->write_en_i = 0;
    top->AddrsCtrl_i = 1;
    top->a_i = 0;
    top->wd_i = 2864434397; //AABBCCDD

    for (i=0; i<6; i++){ 
            
        for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk_i = !top->clk_i;
                top->eval();
        }
        if (i==1){
            std::cout << top->rd_o << std::endl; //LOAD WORD DDCCBBAA
            top->AddrsCtrl_i  = 0;
            top->a_i = 4;
        }
        if (i==2){
            std::cout << top->rd_o << std::endl; //LOAD BYTE 11
            top->write_en_i = 1;
            top->AddrsCtrl_i  = 1;
            top->a_i = 12;   
        }
        if (i==3){
             std::cout << "*" << top->rd_o << std::endl;
                                         //STORE BYTE AABBCCDD
            top->write_en_i = 1;
            top->AddrsCtrl_i  = 0;
        }
        if (i==4){
            std::cout << "*" << top->rd_o << std::endl;
            top->write_en_i = 0;
            top->AddrsCtrl_i  = 0;
            std::cout << "final output" << top->rd_o << std::endl;
        }

                 
        
         //STORE WORD AABBCCDD

    if (Verilated::gotFinish()) exit(0);
    }
    
    tfp->close();
    exit(0);

}