module decode_reg_file #(
    parameter DATA_WIDTH = 32
)(
    //decode stage to branch
    //if so, emtpy just loaded instruction as it might be the wrong instruction
    input logic                         clk,
    input logic                         RegWriteD_i,
    input logic                         ResultSrcD_i,
    input logic                         MemWriteD_i,
    input logic                         BranchSrcD_i,
    input logic [3:0]                   ALUCtrlD_i,
    input logic                         ALUSrcD_i,
    input logic [2:0]                   ImmSrcD_i,
    input logic                         JALRD_i,
    input logic [DATA_WIDTH-1:0]        RD1_i,
    input logic [DATA_WIDTH-1:0]        RD2_i,
    input logic [DATA_WIDTH-1:0]        PCD_i,
    input logic [3:0]                   RdD_i,
    input logic [DATAWIDTH-1:0]         ImmExtD_i,
    input logic [DATAWIDTH-1:0]         PCPlus4D_i,

    input logic [DATA_WIDTH-1:0]        AddrSelD_i,
    output logic [DATA_WIDTH-1:0]       AddrSelE_o,

    input logic [2:0]                   funct3D_i,
    output logic [2:0]                  funct3D_o,

    output logic                        RegWriteE_o,
    output logic                        ResultSrcE_o,
    output logic                        MemWriteE_o,
    output logic                        BranchE_o,
    output logic [3:0]                  ALUCtrlE_o,
    output logic                        ALUSrcE_o,
    output logic [2:0]                  ImmSrcE_o,
    output logic                        JALRD_o,
    output logic [DATA_WIDTH-1:0]       RD1E_o,
    output logic [DATA_WIDTH-1:0]       RD2E_o,
    output logic [DATA_WIDTH-1:0]       PCE_o,
    output logic [3:0]                  RdE_o,
    output logic [DATA_WIDTH-1:0]       ImmExtE_o,
    output logic [DATA_WIDTH-1:0]       PCPlus4E_o
);

always_ff @(posedge clk) begin
    RegWriteE_o <= RegWriteD_i;
    ResultSrcE_o <= ResultSrcD_i;
    MemWriteE_o <= MemWriteD_i;
    BranchSrcE_o <= BranchSrcD_i;
    ALUCtrlE_o <= ALUCtrlD_i;
    ALUSrcE_o <= ALUSrcD_i;
    ImmSrcE_o <= ImmSrcD_i;
    JALRD_o <= JALRD_i;
    RD1E_o <= RD1_i;
    RD2E_o <= RD2_i;
    PCE_o <= PCD_i;
    RdE_o <= RdD_i;
    ImmExtE_o <= ImmExtD_i;
    PCPlus4E_o <= PCPlus4D_i;
    funct3D_o <= funct3D_i;
    AddrSelE_o <= AddrSelD_i;
end

endmodule