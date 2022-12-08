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
  tfp->open ("ALU_test.vcd");

  // initialize simulation input 
  top->SrcA_i = 20;
  top->SrcB_i = 10;
  top->ALUctrl_i = 0;

  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    //sub
    if(simcyc == 1){
      top->ALUctrl_i = 1;
    }

    //and
    if(simcyc == 2){
      top->ALUctrl_i = 2;
    }

    //or
    if(simcyc == 3){
      top->ALUctrl_i = 3;
    }

    //SLT
    if(simcyc == 4){
      top->ALUctrl_i = 5;
    }  //0
    if(simcyc == 5){
      top->SrcB_i = 30;
      top->ALUctrl_i = 5;
    } //1
    if(simcyc == 6){
      top->SrcB_i = -30;
      top->ALUctrl_i = 5;
    } // 1
    if(simcyc == 7){
      top->SrcA_i = -20;
      top->ALUctrl_i = 5;
    } // 0
    if(simcyc == 8){
      top->SrcA_i = -40;
      top->ALUctrl_i = 5;
    } //1
    if(simcyc == 9){
      top->SrcA_i = -30;
      top->ALUctrl_i = 5;
    } //0
    if(simcyc == 10){
      top->SrcA_i = 30;
      top->SrcB_i = 30;
      top->ALUctrl_i = 5;
    } //0

    //todo test edge cases

    //ULT
    if(simcyc == 11){
      top->SrcA_i = 40;
      top->ALUctrl_i = 6;
    } //0
    if(simcyc == 12){
      top->SrcA_i = 20;
      top->ALUctrl_i = 6;
    } //1
    if(simcyc == 13){
      top->SrcA_i = -30;
      top->SrcB_i = -31;
      top->ALUctrl_i = 6;
    } //1


    //Zero_o
    if(simcyc == 14){
      top->SrcA_i = -30;
      top->SrcB_i = -30;
    } //1


    //lsl
    if(simcyc == 15){
      top->SrcA_i = 10;
      top->SrcB_i = 1;
      top->ALUctrl_i = 7;
    } //10

    //lsr
    if(simcyc == 16){
      top->SrcA_i = 10;
      top->SrcB_i = 1;
      top->ALUctrl_i = 8;
    } //10


    //xor
    if(simcyc == 17){
      top->SrcA_i = 1;
      top->SrcB_i = 1;
      top->ALUctrl_i = 4;
    } //0
    if(simcyc == 18){
      top->SrcA_i = 2;
      top->SrcB_i = 1;
      top->ALUctrl_i = 4;
    } //3


    //Testing Branch Functionality:
    //equal
    if(simcyc == 19){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
      top->BranchCtrl_i = 0;
    } //1
    if(simcyc == 20){
      top->SrcA_i = 2;
      top->SrcB_i = 1;
    } //0

    //not equal
    if(simcyc == 21){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
      top->BranchCtrl_i = 1;
    } //0
    if(simcyc == 22){
      top->SrcA_i = 2;
      top->SrcB_i = 1;
    } //1

    //signed <
    if(simcyc == 23){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
      top->BranchCtrl_i = 2;
    } //0
    if(simcyc == 24){
      top->SrcA_i = 3;
      top->SrcB_i = 2;
    } //0
    if(simcyc == 25){
      top->SrcA_i = 1;
      top->SrcB_i = 2;
    } //1
    if(simcyc == 26){
      top->SrcA_i = -1;
      top->SrcB_i = 2;
    } //1
    if(simcyc == 27){
      top->SrcA_i = -2;
      top->SrcB_i = -1;
    } //1
    if(simcyc == 28){
      top->SrcA_i = -1;
      top->SrcB_i = -2;
    } //0

    //signed >=
    if(simcyc == 29){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
      top->BranchCtrl_i = 3;
    } //1
    if(simcyc == 30){
      top->SrcA_i = 3;
      top->SrcB_i = 2;
    } //1
    if(simcyc == 31){
      top->SrcA_i = 1;
      top->SrcB_i = 2;
    } //0
    if(simcyc == 32){
      top->SrcA_i = -1;
      top->SrcB_i = 2;
    } //0
    if(simcyc == 33){
      top->SrcA_i = -2;
      top->SrcB_i = -1;
    } //0
    if(simcyc == 34){
      top->SrcA_i = -1;
      top->SrcB_i = -2;
    } //1

    // <
    if(simcyc == 35){
      top->SrcA_i = 2;
      top->SrcB_i = 1;
      top->BranchCtrl_i = 4;
    } //0
    if(simcyc == 36){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
    } //0
    if(simcyc == 37){
      top->SrcA_i = 2;
      top->SrcB_i = 3;
    } //1

    // >=
    if(simcyc == 38){
      top->SrcA_i = 2;
      top->SrcB_i = 1;
      top->BranchCtrl_i = 5;
    } //1
    if(simcyc == 39){
      top->SrcA_i = 2;
      top->SrcB_i = 2;
    } //1
    if(simcyc == 40){
      top->SrcA_i = 1;
      top->SrcB_i = 2;
    } //0

    //SRA
    if(simcyc == 41){
      top->SrcA_i = 10;
      top->SrcB_i = 1;
      top->ALUctrl_i = 9;
    } //5
    if(simcyc == 42){
      top->SrcA_i = -10;
    } //-5

    //SLA
    if(simcyc == 43){
      top->SrcA_i = 10;
      top->SrcB_i = 1;
      top->ALUctrl_i = 10;
    } //20
    if(simcyc == 44){
      top->SrcA_i = -10;
    } //-20


    //generic load/store
    if(simcyc == 44){
      top->SrcB_i = -10;
      top->ALUctrl_i = 15;
    } //-20


    //JAL
    //if(simcyc == 44){
    //  top->SrcB_i = -10;
    //  top->ALUctrl_i = 15;
    //} //-20


    // either simulation finished, or 'q' is pressed
    if (Verilated::gotFinish()) 
      exit(0);
  }

  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}