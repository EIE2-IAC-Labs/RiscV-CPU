module decode_reg_file #(
    parameter DATA_WIDTH = 32
)(
input logic                         RegWriteD_i,
input logic                         ResultSrcD_i,
input logic                         MemWriteD_i,
input logic                         JumpD_i,
input logic                         BranchD_i,
input logic [3:0]                   ALUControlD_i,
input logic                         ALUSrcD_i,
input logic [DATA_WIDTH-1:0]        RD1_i,
input logic [DATA_WIDTH-1:0]        RD2_i,
input logic [DATA_WIDTH-1:0]        PCD_i,
input logic [3:0]                   RdD_i,
input logic [DATAWIDTH-1:0]         ImmExtD_i,
input logic [DATAWIDTH-1:0]         PCPlus4D_i,

output logic                        RegWriteE_o,
output logic                        ResultSrcE_o,
output logic                        MemWriteE_o,
output logic                        JumpE_o,
output logic                        BranchE_o,
output logic [3:0]                  ALUControlE_o,
output logic                        ALUSrcE_o,
output logic [DATA_WIDTH-1:0]       RD1E_o,
output logic [DATA_WIDTH-1:0]       RD2E_o,
output logic [DATA_WIDTH-1:0]       PCE_o,
output logic [3:0]                  RdE_o,
output logic [DATA_WIDTH-1:0]       ImmExtE_o,
output logic [DATA_WIDTH-1:0]       PCPlus4E_o
);

always_ff @(posedge clk) begin
    RegWriteD_i <= RegWriteE_o;
    ResultSrcD_i <= ResultSrcE_o;
    MemWriteD_i <= MemWriteE_o;
    JumpD_i <= JumpE_o;
    BranchD_i <= BranchE_o;
    ALUControlD_i <= ALUControlE_o;
    ALUSrcD_i <= ALUSrcE_o;
    RD1_i <= RD1E_o;
    RD2_i <= RD2E_o;
    PCD_i <= PCE_o;
    RdD_i <= RdE_o;
    ImmExtD_i <= ImmExtE_o;
    PCPlus4D_i <= PCPlus4E_o;
end

endmodule