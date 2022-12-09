module execute_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk,
    input logic                     resultSRCD_i,
    input logic                     memWriteD_i,
    input logic [DATA_WIDTH-1:0]    addrSelectD_i,
    input logic [DATA_WIDTH-1:0]    ALUresultD_i,
    input logic [DATA_WIDTH-1:0]    RD2D_i,

    output logic                    resultSRCE_o,
    output logic                    memWriteE_o,
    output logic [DATA_WIDTH-1:0]   addrSelectE_o,
    output logic [DATA_WIDTH-1:0]   ALUresultE_o,
    output logic [DATA_WIDTH-1:0]   RD2E_o
);

always_ff @(negedge clk) begin
    resultSRCE_o <= resultSRCD_i;
    memWriteE_o <= memWriteD_i;
    addrSelectE_o <= addrSelectD_i;
    ALUresultE_o <= ALUresultD_i;
    RD2E_o <= RD2D_i;
end

endmodule