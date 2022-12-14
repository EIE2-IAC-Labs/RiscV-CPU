module top #(
    parameter DATA_WIDTH = 32
)(
    input logic                                 clk,
    input logic [DATA_WIDTH-1:0]                dataWord_i,
    input logic [DATA_WIDTH-1:0]                addressWord_i,

    output logic [DATA_WIDTH-1:0]               dataWord_o,
    output logic                                hit_o   
);

two_way_associative_cache two_way_associative_cache(
    .clk (clk),
    .dataWord_i(dataWord_i),
    .addressWord_i(addressWord_i),

    .dataWord_o(dataWord_o),
    .hit_o(hit_o)
);

endmodule
