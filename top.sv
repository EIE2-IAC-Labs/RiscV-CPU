module top #(
    parameter ADDRESS_WIDTH = 5,
                DATA_WIDTH = 32
)(
    input logic                             clk,
    input logic [ADDRESS_WIDTH-1:0]         AD1_i,
    input logic [ADDRESS_WIDTH-1:0]         AD2_i,
    input logic [ADDRESS_WIDTH-1:0]         AD3_i,
    input logic                             WE3_i,
    input logic [DATA_WIDTH-1:0]            WD3_i,
    input logic                             TRIGGER_i,

    output logic [DATA_WIDTH-1:0]           RD1_o,
    output logic [DATA_WIDTH-1:0]           RD2_o,
    output logic [DATA_WIDTH-1:0]           a0_o  
);


register_file register_file(
    .clk(clk),
    .AD1_i(AD1_i),
    .AD2_i(AD2_i),
    .AD3_i(AD3_i),
    .WE3_i(WE3_i),
    .WD3_i(WD3_i),
    .TRIGGER_i(TRIGGER_i),

    .RD1_o(RD1_o),
    .RD2_o(RD2_o),
    .a0_o(a0_o)
);

endmodule
