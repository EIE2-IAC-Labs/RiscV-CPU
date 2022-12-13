module decode_reg_file #(
    parameter DATA_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    //decode stage to branch
    //if so, emtpy just loaded instruction as it might be the wrong instruction
    //remove addr wire
    input logic                         clk,
    input logic                         en_i,
    input logic                         resultSrcD_i,
    input logic                         memWriteD_i,
    input logic [1:0]                   memTypeWireD_i,
    input logic                         AUIPCWireD_i,
    input logic                         branchSrcD_i,
    input logic [3:0]                   ALUCtrlD_i,
    input logic                         JALRD_i,
    input logic [DATA_WIDTH-1:0]        PCD_i,
    input logic [DATA_WIDTH-1:0]        RD1D_i,
    input logic [DATA_WIDTH-1:0]        SrcBD_i,
    input logic [DATA_WIDTH-1:0]        RD2D_i,
    input logic [DATA_WIDTH-1:0]        ImmExtD_i,
    input logic [2:0]                   funct3D_i,
    input logic                         memSignWireD_i,
    input logic                         regWriteD_i,
    input logic [REGISTER_ADDRESS_WIDTH-1:0] AD3D_i,
    input logic                         JALD_i,
    input logic [DATA_WIDTH-1:0]        incPC2_i,

    output logic                        AUIPCWireE_o,
    output logic [1:0]                  memTypeWireE_o,
    output logic                        resultSrcE_o,
    output logic                        memWriteE_o,
    output logic                        branchSrcE_o,
    output logic [3:0]                  ALUctrlE_o,
    output logic                        JALRE_o,
    output logic [DATA_WIDTH-1:0]       PCE_o,
    output logic [DATA_WIDTH-1:0]       RD1E_o,
    output logic [DATA_WIDTH-1:0]       SrcBE_o,
    output logic [DATA_WIDTH-1:0]       RD2E_o,
    output logic [DATA_WIDTH-1:0]       ImmExtE_o,
    output logic [2:0]                  funct3E_o,
    output logic                        memSignWireE_o,
    output logic                        regWriteE_o,
    output logic [REGISTER_ADDRESS_WIDTH-1:0] AD3E_o,
    output logic                        JALE_o,
    output logic [DATA_WIDTH-1:0]       incPC3_o,

);

always_ff @(negedge clk) begin
    if(en_i) begin
        resultSrcE_o <= resultSrcD_i;
        memWriteE_o <= memWriteD_i;
        branchSrcE_o <= branchSrcD_i;
        ALUctrlE_o <= ALUCtrlD_i;
        JALRE_o <= JALRD_i;
        PCE_o <= PCD_i;
        RD1E_o <= RD1D_i;
        SrcBE_o <= SrcBD_i;
        RD2E_o <= RD2D_i;
        ImmExtE_o <= ImmExtD_i;
        funct3E_o <= funct3D_i;
        memTypeWireE_o <= memTypeWireD_i;
        memSignWireE_o <= memSignWireD_i;
        AUIPCWireE_o <= AUIPCWireD_i;
        regWriteE_o <= regWriteD_i; 
        AD3E_o <= AD3D_i;
        JALE_o <= JALD_i;
        incPC3_o <= incPC2_i;
    end
end

endmodule
