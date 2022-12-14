#include "Vcache.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc,char **argv, char **env){
    int i;
    int clk;
    

    Verilated::commandArgs(argc, argv);
    Vcache* top = new Vcache;
    VerilatedVcdC* tfp= new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace (tfp,99);
    tfp->open ("cache.vcd");

    top->clk = 0;
    top->dataWord0_i=16;
    top->dataWord1_i=12;
    top->dataWord2_i=8;
    top->dataWord3_i=4;
    top->addressWord_i= 0;          //287454020;11223344            //2864434397; //AABBCCDD
    
    

    for (i=0; i<5; i++){ 
            
        for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval();
        }
        if (i==1){
            std::cout << top->dataWord_o << std::endl; //LOAD WORD DDCCBBAA
            std::cout << "clk 1 " << std::endl;
            top->addressWord_i= 0;
    
         
            
        }
        if (i==2){
            
            std::cout << top->dataWord_o << std::endl; //LOAD BYTE 11
            std::cout << "clk 2 " << std::endl;
            
              
        }
        if (i==3){
            
            std::cout << top->dataWord_o << std::endl; //LOAD BYTE 11
             std::cout << "clk 3 " << std::endl;
             
        }   

        /*if (i==4){
            top->a_i = 12;  
             std::cout << top->rd_o << std::endl;
             std::cout << "clk 4 " << std::endl;
        }

             
        
         //STORE WORD AABBCCDD */

    if (Verilated::gotFinish()) exit(0);
    }
    
    tfp->close();
    exit(0);

}
