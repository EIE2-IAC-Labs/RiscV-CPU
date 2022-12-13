module register_file #(
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

logic [DATA_WIDTH-1:0] register_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) begin
    if(AD3_i != {{ADDRESS_WIDTH-1}{1'b0}}) begin
        if (WE3_i) register_array[AD3_i] <= WD3_i;
    end
    if(TRIGGER_i == 1'b1) register_array[5] <= 1;
end
always_comb begin 
    RD1_o = register_array[AD1_i];
    RD2_o = register_array[AD2_i];    
end

assign  a0_o = register_array[10];

endmodule
