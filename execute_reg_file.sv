module execute_reg_file #(
    parameter DATA_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                     clk,
    input logic                     en_i,
    input logic                     resultSRCD_i,
    input logic                     memWriteD_i,
    input logic [DATA_WIDTH-1:0]    ALUresultD_i,
    input logic [DATA_WIDTH-1:0]    RD2D_i,
    input logic [1:0]               memTypeD_i,
    input logic                     memSignD_i,
    input logic                     AUIPCD_i,
    input logic                     regWriteD_i,
    input logic [REGISTER_ADDRESS_WIDTH-1:0] AD3D_i,
    input logic                     JALD_i,
    input logic [DATA_WIDTH-1:0]    incPC3_i,


    output logic                    resultSRCE_o,
    output logic                    memWriteE_o,
    output logic [DATA_WIDTH-1:0]   ALUresultE_o,
    output logic [DATA_WIDTH-1:0]   RD2E_o,
    output logic [1:0]              memTypeE_o,
    output logic                    memSignE_o,
    output logic                    AUIPCE_o,
    output logic                    regWriteE_o,
    output logic [REGISTER_ADDRESS_WIDTH-1:0] AD3E_o,
    output logic                    JALE_o,
    output logic [DATA_WIDTH-1:0]   incPC4_o,

);

always_ff @(negedge clk) begin
    if (en_i) begin
        resultSRCE_o <= resultSRCD_i;
        memWriteE_o <= memWriteD_i;
        ALUresultE_o <= ALUresultD_i;
        RD2E_o <= RD2D_i;
        memTypeE_o <= memTypeD_i;
        memSignE_o <= memSignD_i;
        AUIPCE_o <= AUIPCD_i;
        regWriteE_o <= regWriteD_i;
        AD3E_o <= AD3D_i;
        JALE_o <= JALD_i;
        incPC4_o <= incPC3_i;
    end
end

endmodule
