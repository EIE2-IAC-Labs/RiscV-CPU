#include <iostream>
#include <bitset>
#include "Vcontrol.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

using namespace std;

int main(int argc, char **argv, char **env){

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vcontrol* top = new Vcontrol;

    //init simulation inputs
    top->op_i = 0b0110011;
    top->funct3_i = 0b000;
    top->funct7bit_i = 0b1;

    top->eval();

    cout << endl;
    cout << "----- INPUTS ---------------------------" << endl << endl;

    cout << "OP: " << bitset<7>(top->op_i) << " , FUNCT3: " 
    << bitset<3>(top->funct3_i) << " , FUNCT7BIT: " 
    << bitset<1>(top->funct7bit_i) << endl << endl;

    cout << "----- OUTPUTS ---------------------------" << endl << endl;

    cout << "regwrite: " << bitset<1>(top->regWrite_en_o) << endl;
    cout << "AluCtrl: " << bitset<4>(top->ALUctrl_o) << endl;
    cout << "ALUsrc_o: " << bitset<1>(top->ALUsrc_o) << endl;
    cout << "ImmSrc_o: " << bitset<3>(top->ImmSrc_o) << endl;
    cout << "BranchSrc_o: " << bitset<1>(top->BranchSrc_o) << endl;
    cout << "addrSelect_o: " << bitset<1>(top->addrSelect_o) << endl;
    cout << "ResultSrc_o: " << bitset<1>(top->ResultSrc_o) << endl;

    exit(0);
}

