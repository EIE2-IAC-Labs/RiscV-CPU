module top #(
    parameter DATAWIDTH = 32
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [3:0]                   ALUctrl_i,
    input logic                         clk,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Zero_o
);


ALU test_alu(
    .SrcA_i (SrcA_i),
    .SrcB_i (SrcB_i),
    .ALUctrl_i (ALUctrl_i),
    .ALUResult_o (ALUResult_o),
    .Zero_o (Zero_o)
);

endmodule
