module memory_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input logic                             clk,
    input logic                             RegWriteM_i,
    input logic                             ResultSrcM_i,
    input logic [DATAWIDTH-1:0]             ALUResultM_i,
    input logic [DATAWIDTH-1:0]             RD_i,
    input logic [3:0]                       RdM_i,
    input logic [DATAWIDTH-1:0]             PCPlus4M_i,

    output logic                            RegWriteW_o,
    output logic                            ResultSrcW_o,
    output logic [DATAWIDTH-1:0]            ALUResultMM_o,
    output logic [DATAWIDTH-1:0]            ReadDataW_o,
    output logic [3:0]                      RdW_o,
    output logic [DATAWIDTH-1:0]            PCPlus4W_o
);

always_ff @(posedge clk) begin
    RegWriteW_o <= RegWriteM_i;
    ResultSrcW_o <= ResultSrcM_i;
    ALUResultMM_o <= ALUResultM_i;
    ReadDataW_o <= RD_i;
    RdW_o <= RdM_i;
    PCPlus4W_o <= PCPlus4M_i;
end

endmodule
