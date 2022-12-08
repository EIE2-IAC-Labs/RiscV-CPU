module fetch_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic [DATA_WIDTH-1:0]        RD_i,
    input logic [DATA_WIDTH-1:0]        PCF_i,
    input logic [DATA_WIDTH-1:0]        PCPlus4F_i,

    output logic [DATA_WIDTH-1:0]       InstrD_o,
    output logic [DATA_WIDTH-1:0]       PCD_o,
    output logic [DATA_WIDTH-1:0]       PCPlus4D_o
);

always_ff @(posedge clk) begin
    InstrD_o <= RD_i;
    PCD_o <= PCF_i;
    PCPlus4D_o <= PCPlus4F_i;
end

endmodule