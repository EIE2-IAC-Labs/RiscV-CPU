module top #(
    parameter DATAWIDTH = 32,
            SHIFT_WIDTH = 5
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [3:0]                   ALUctrl_i,
    input logic [2:0]                   BranchCtrl_i,
    input logic                         clk,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Branch_o
);


ALU test_alu(
    .SrcA_i (SrcA_i),
    .SrcB_i (SrcB_i),
    .ALUctrl_i (ALUctrl_i),
    .BranchCtrl_i (BranchCtrl_i),
    .ALUResult_o (ALUResult_o),
    .Branch_o (Branch_o)
);

endmodule
