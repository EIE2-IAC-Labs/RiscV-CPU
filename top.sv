module top #(
    parameter DATA_WIDTH = 32
)(
    input logic                                 clk,
    input logic [DATA_WIDTH-1:0]                dataWord_i,

    output logic [DATA_WIDTH-1:0]               dataWord_o     
);

direct_mapped_cache direct_mapped_cache(
    .clk (clk),
    .dataWord_i(dataWord_i),

    .dataWord_o(dataWord_o)
);

endmodule
