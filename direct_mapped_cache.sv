module direct_mapped_cache #(
    parameter SET_WIDTH = 3,
    TAG_WIDTH = 27,
    DATA_WIDTH = 32,
    CACHE_LENGTH = 8

)(
    input logic                                 clk,
    input logic [DATA_WIDTH-1:0]                dataWord_i,
    input logic [DATA_WIDTH-1:0]                addressWord_i,

    output logic [DATA_WIDTH-1:0]               dataWord_o,
    output logic                                hit_o
);

//add overwrite and when to write V flag
//combine into one memory block
//check combinational logic warning
//check it is of the correct type (i.e correct parts are combinational and vice versa)


logic [DATA_WIDTH-1:0] cache_memory [0:CACHE_LENGTH-1][0:2];


logic [SET_WIDTH-1:0] data_set;
logic [TAG_WIDTH-1:0] data_tag;
logic overwrite;

assign data_tag = addressWord_i[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
assign data_set = addressWord_i[SET_WIDTH+1:2];
assign hit_o = (cache_memory[data_set][1][TAG_WIDTH-1:0] == data_tag) && cache_memory[data_set][0][0];

always_comb begin
    if(hit_o) dataWord_o = cache_memory[data_set][2];
    else overwrite = 1'b1;        
end

always_ff @(negedge clk) begin
    if(overwrite) begin
        cache_memory[data_set][1][TAG_WIDTH-1:0] <= data_tag;
        cache_memory[data_set][2] <= dataWord_i;
        overwrite = 0'b0;
        cache_memory[data_set][0][0] <= 1'b1;
    end
end

endmodule
