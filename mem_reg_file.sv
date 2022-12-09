module mem_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input [DATA_WIDTH-1:0]                  ALUResultD_i,
    input [DATA_WIDTH-1:0]                  RD2D_i,
    input [DATA_WIDTH-1:0]                  ResultSrcD_i,

    output [DATA_WIDTH-1:0]                 ALUResultE_o,
    output [DATA_WIDTH-1:0]                 RD2E_o,
    output [DATA_WIDTH-1:0]                 ResultSrcE_o
);

always_ff @(negedge clk) begin
    ALUResultE_o <= ALUResultD_i;
    RD2D_o <= RD2D_i;
    ResultSrcE_o <= ResultSrcD_i;
end

endmodule
