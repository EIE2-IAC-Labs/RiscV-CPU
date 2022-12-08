#include "Vram_top.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc,char **argv, char **env){
    int i;
    int clk;
    

    Verilated::commandArgs(argc, argv);
    Vram_top* top = new Vram_top;
    VerilatedVcdC* tfp= new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace (tfp,99);
    tfp->open ("ram_top.vcd");

    top->clk_i = 0;
    top->write_en_i = 0;
    top->memtype_i = 10;
    top->a_i = 0;
    top->wd_i = 2864434397; //AABBCCDD

    for (i=0; i<5; i++){ 
            
        for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk_i = !top->clk_i;
                top->eval();
        }
        if (i==1){
            std::cout << top->rd_o << std::endl; //LOAD WORD DDCCBBAA
            std::cout << "clk 1 " << std::endl;
         
            
        }
        if (i==2){
            top->a_i = 4;
            std::cout << top->rd_o << std::endl; //LOAD BYTE 11
             std::cout << "clk 2 " << std::endl;
              
        }
        if (i==3){
            top->a_i = 8;  
            std::cout << top->rd_o << std::endl; //LOAD BYTE 11
             std::cout << "clk 3 " << std::endl;
        }   

        if (i==4){
            top->a_i = 12;  
            std::cout << top->rd_o << std::endl;
             std::cout << "clk 4 " << std::endl;
        }

             
        
         //STORE WORD AABBCCDD

    if (Verilated::gotFinish()) exit(0);
    }
    
    tfp->close();
    exit(0);

}
