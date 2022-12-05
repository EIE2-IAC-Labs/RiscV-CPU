#include <iostream>
#include <bitset>
#include "Vcontrol.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

using namespace std;

void display(Vcontrol* top){

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
}

int main(int argc, char **argv, char **env){

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vcontrol* top = new Vcontrol;

    vector<int> funct3{0b000, 0b001, 0b010, 0b011, 0b100, 0b101, 0b110, 0b111};
    vector<int> funct3_load_store{0b000, 0b001, 0b010, 0b100, 0b101};
    vector<int> funct3_branch{0b000, 0b001, 0b100, 0b101, 0b110, 0b111};

    top->op_i = 0b0110011; // Testing R-Type instructions
    for(int i = 0; i < 8; i++){
        top->funct3_i = funct3[i];
        if (funct3[i] == 0b101){
            top->funct7bit_i = 0b1;
            top->eval();
            display(top);
            top->funct7bit_i = 0b0;
        }
        top->eval();
        display(top);
    }

    top->op_i = 0b0010011;  // Testing I-Type Bitwise Instructions
    for(int i = 0; i < 8; i++){
        top->funct3_i = funct3[i];
        if (funct3[i] == 0b101){
            top->funct7bit_i = 0b1;
            top->eval();
            display(top);
            top->funct7bit_i = 0b0;
        }
        top->eval();
        display(top);
    }

    top->op_i = 0b0000011;  // Testing I-Type Load Instructions
    for(int i = 0; i < 5; i++){
        top->funct3_i = funct3_load_store[i];
        top->eval();
        display(top);
    }

    top->op_i = 0b0100011;  // Testing I-Type Store Instructions
    for(int i = 0; i < 3; i++){
        top->funct3_i = funct3_load_store[i];
        top->eval();
        display(top);
    }

    top->op_i = 0b1100011;  // Testing Branch Instructions
    for(int i = 0; i < 6; i++){
        top->funct3_i = funct3_branch[i];
        top->eval();
        display(top);
    }

    top->eval();
    exit(0);
}

