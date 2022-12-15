module fetch_reg_file #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         en,
    input logic [DATA_WIDTH-1:0]        instrD_i,
    input logic [DATA_WIDTH-1:0]        incPCD_i,
    input logic [DATA_WIDTH-1:0]        PCD_i,

    output logic [DATA_WIDTH-1:0]       instrE_o,
    output logic [DATA_WIDTH-1:0]       incPCE_o,
    output logic [DATA_WIDTH-1:0]       PCE_o
);

always_ff @(negedge clk) begin
    if(en) begin
        instrE_o <= instrD_i;
        incPCE_o <= incPCD_i;
        PCE_o <= PCD_i;
    end
end

endmodule
