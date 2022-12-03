module top #(
    parameter DATAWIDTH = 32,
            SHIFT_WIDTH = 5
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [3:0]                   ALUctrl_i,
    input logic                         clk,
    input logic [SHIFT_WIDTH-1:0]       shift,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Zero_o
);


ALU test_alu(
    .SrcA_i (SrcA_i),
    .SrcB_i (SrcB_i),
    .shift (shift),
    .ALUctrl_i (ALUctrl_i),
    .ALUResult_o (ALUResult_o),
    .Zero_o (Zero_o)
);

endmodule