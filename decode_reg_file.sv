module decode_reg_file #(
    parameter DATA_WIDTH = 32
)(
    //decode stage to branch
    //if so, emtpy just loaded instruction as it might be the wrong instruction
    input logic                         clk,
    input logic                         resultSrcD_i,
    input logic                         memWriteD_i,
    input logic [1:0]                   memTypeD_i,
    input logic                         memSignD_i,
   // input logic                         addrSelectD_i,
    input logic                         branchSrcD_i,
    input logic [3:0]                   ALUCtrlD_i,
    input logic                         JALRD_i,
    input logic [DATA_WIDTH-1:0]        PCD_i,
    input logic [DATA_WIDTH-1:0]        RD1D_i,
    input logic [DATA_WIDTH-1:0]        SrcBD_i,
    input logic [DATA_WIDTH-1:0]        RD2D_i,
    input logic [DATA_WIDTH-1:0]        ImmExtD_i,
    input logic [2:0]                   funct3D_i,

    output logic                        resultSrcE_o,
    output logic                        memWriteE_o,
    output logic [1:0]                  memTypeE_o,
    output logic                        memSignE_o,
   // output logic                           addrSelectE_o,
    output logic                        branchSrcE_o,
    output logic [3:0]                  ALUctrlE_o,
    output logic                        JALRE_o,
    output logic [DATA_WIDTH-1:0]       PCE_o,
    output logic [DATA_WIDTH-1:0]       RD1E_o,
    output logic [DATA_WIDTH-1:0]       SrcBE_o,
    output logic [DATA_WIDTH-1:0]       RD2E_o,
    output logic [DATA_WIDTH-1:0]       ImmExtE_o,
    output logic [2:0]                  funct3E_o
);

always_ff @(negedge clk) begin
    resultSrcE_o <= resultSrcD_i;
    memWriteE_o <= memWriteD_i;
    memTypeE_o <= memTypeD_i;
    memSignE_o <= memSignD_i;
  //addrSelectE_o <= addrSelectD_i;
    branchSrcE_o <= branchSrcD_i;
    ALUctrlE_o <= ALUCtrlD_i;
    JALRE_o <= JALRD_i;
    PCE_o <= PCD_i;
    RD1E_o <= RD1D_i;
    SrcBE_o <= SrcBD_i;
    RD2E_o <= RD2D_i;
    ImmExtE_o <= ImmExtD_i;
    funct3E_o <= funct3D_i;
end

endmodule
