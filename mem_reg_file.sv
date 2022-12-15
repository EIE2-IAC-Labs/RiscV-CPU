module mem_reg_file #(
    parameter DATA_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                             clk,
    input logic                             en,
    input logic [DATA_WIDTH-1:0]            ALUResultD_i,
    input logic [DATA_WIDTH-1:0]            RD2D_i,
    input logic                             ResultSrcD_i,
    input logic                             regWriteD_i,
    input logic [REGISTER_ADDRESS_WIDTH-1:0] AD3D_i,
    input logic                             JALD_i,
    input logic [DATA_WIDTH-1:0]            incPC4_i,
    input logic                             AUIPCD_i,


    output logic [DATA_WIDTH-1:0]           ALUResultE_o,
    output logic [DATA_WIDTH-1:0]           RD2E_o,
    output logic                            ResultSrcE_o,
    output logic                            regWriteE_o,
    output logic [REGISTER_ADDRESS_WIDTH-1:0] AD3E_o,
    output logic                            JALE_o,
    output logic [DATA_WIDTH-1:0]           incPC5_o,
    output logic                            AUIPCE_o

);

always_ff @(negedge clk) begin
    if(en) begin
        ALUResultE_o <= ALUResultD_i;
        RD2E_o <= RD2D_i;
        ResultSrcE_o <= ResultSrcD_i;
        regWriteE_o <= regWriteD_i;
        AD3E_o <= AD3D_i;
        JALE_o <= JALD_i;
        incPC5_o <= incPC4_i;
    end
end

endmodule
