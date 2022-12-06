module top # (
    parameter DATAWIDTH = 32
)(
    input logic [2:0]               ImmSrc_i,
    input logic [DATAWIDTH-1:7]     Imm_i,
    input logic                     clk,

    output logic [DATAWIDTH-1:7]    ImmExt_o
);

extend test_extend(
    .ImmSrc_i(ImmSrc_i),
    .Imm_i(Imm_i),
    .ImmExt_o(ImmExt_o)
);

endmodule
