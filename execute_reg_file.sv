module execute_reg_file #(
    parameter DATA_WIDTH = 32
)(
input logic                     clk,
input logic                     RegWriteE_i
input logic                     ResultSrcE_i
input logic                     MemWriteE_i
input logic [DATA_WIDTH-1:0]    ALUResult_i
input logic [DATA_WIDTH-1:0]    WriteDataE_i
input logic [3:0]               RdE_i
input logic [DATA_WIDTH-1:0]    PcPlus4E_i

output logic                    RegWriteM_o
output logic                    ResultSrcM_o
output logic                    MemWriteM_o
output logic [DATA_WIDTH-1:0]   ALUResultM_o
output logic [DATA_WIDTH-1:0]   WriteDataM_o
output logic [3:0]              RdM_o
output logic [DATA_WIDTH-1:0]   PCPlus4M_o
);

always_ff @(posedge clk) begin
    RegWriteM_o <= RegWriteE_i;
    ResultSrcM_o <= ResultSrcE_i;
    MemWriteM_o <= MemWriteE_i;
    ALUResultM_o <= ALUResult_i;
    WriteDataM_o <= WriteDataE_i;
    RdM_o <= RdE_i;
    PCPlus4M_o <= PcPlus4E_i;
end

endmodule