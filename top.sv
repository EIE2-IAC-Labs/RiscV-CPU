module top # (
    parameter DATAWIDTH = 32,
)(
    input logic [2:0]               ImmSrc_i,
    input logic [DATAWIDTH-1:0]     Imm_i,

    output logic [DATAWIDTH-1:0]    ImmExt_o
);

extend test_extend(
    .ImmSrc_i(ImmSrc_i),
    .Imm_i(Imm_i),
    .ImmExt_o(ImmExt_o)
);

endmodule
