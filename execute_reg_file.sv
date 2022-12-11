module execute_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk,
    input logic                     resultSRCD_i,
    input logic                     memWriteD_i,
    input logic [DATA_WIDTH-1:0]    ALUresultD_i,
    input logic [DATA_WIDTH-1:0]    RD2D_i,
    input logic [1:0]               memTypeD_i,
    input logic                     memSignD_i,
    input logic                     AUIPCD_i,

    output logic                    resultSRCE_o,
    output logic                    memWriteE_o,
    output logic [DATA_WIDTH-1:0]   ALUresultE_o,
    output logic [DATA_WIDTH-1:0]   RD2E_o
    output logic [1:0]              memTypeE_o,
    output logic                    memSignE_o,
    output logic                    AUIPCE_o
);

always_ff @(negedge clk) begin
    resultSRCE_o <= resultSRCD_i;
    memWriteE_o <= memWriteD_i;
    ALUresultE_o <= ALUresultD_i;
    RD2E_o <= RD2D_i;
    memTypeE_o <= memTypeD_i;
    memSignE_o <= memSignD_i;
    AUIPCE_o <= AUIPCD_i;
end

endmodule
