module two_way_associative_cache #(
    parameter SET_WIDTH = 3,
    TAG_WIDTH = 27,
    DATA_WIDTH = 32,
    CACHE_LENGTH = 8,
    OFFSET_ONE_WAY = 60

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
//remove overwrite if needed, check if required



logic [OFFSET_ONE_WAY+OFFSET_ONE_WAY-1:0] cache_memory [CACHE_LENGTH-1:0];

//current input data
logic [SET_WIDTH-1:0] data_set;
logic [TAG_WIDTH-1:0] data_tag;


assign data_tag = addressWord_i[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
assign data_set = addressWord_i[SET_WIDTH+1:2];

//hit logic implementationS
logic hit0;
logic hit1;

assign hit0 = (cache_memory[data_set] [TAG_WIDTH+DATA_WIDTH-1:DATA_WIDTH] == data_tag) && cache_memory[data_set] [DATA_WIDTH+TAG_WIDTH];
assign hit1 = (cache_memory[data_set] [TAG_WIDTH+DATA_WIDTH-1 + OFFSET_ONE_WAY:DATA_WIDTH+ OFFSET_ONE_WAY] == data_tag) && cache_memory[data_set] [DATA_WIDTH+TAG_WIDTH+OFFSET_ONE_WAY];
assign hit_o = hit0 || hit1;

logic evict [CACHE_LENGTH-1:0];

always_comb begin
    if(hit_o)begin
        if(data_tag == cache_memory [data_set] [TAG_WIDTH+DATA_WIDTH-1 + OFFSET_ONE_WAY:DATA_WIDTH + OFFSET_ONE_WAY]) begin
            dataWord_o = cache_memory [data_set] [DATA_WIDTH-1 + OFFSET_ONE_WAY:OFFSET_ONE_WAY];
            evict [data_set] = 0;
        end
        else if(data_tag == cache_memory [data_set] [TAG_WIDTH+DATA_WIDTH-1:DATA_WIDTH]) begin
            dataWord_o = cache_memory [data_set] [DATA_WIDTH-1:0];
            evict [data_set] = 1;
        end
    end
end

always_ff @(negedge clk) begin
    if((data_tag != cache_memory [data_set] [TAG_WIDTH+DATA_WIDTH-1:DATA_WIDTH]) && (data_tag != cache_memory [data_set] [TAG_WIDTH+DATA_WIDTH-1 + OFFSET_ONE_WAY:DATA_WIDTH + OFFSET_ONE_WAY])) begin
        if((cache_memory [data_set] [DATA_WIDTH+TAG_WIDTH] == 1'b0) && (cache_memory [data_set] [DATA_WIDTH+TAG_WIDTH + OFFSET_ONE_WAY] == 1'b0)) begin
            cache_memory [data_set] <= {cache_memory[data_set][OFFSET_ONE_WAY+OFFSET_ONE_WAY-1:OFFSET_ONE_WAY], 1'b1, data_tag, dataWord_i}
            evict [data_set] <= 1;
        end
        else if (evict[data_set] == 1'b0) begin
            cache_memory [data_set] <= {cache_memory[data_set][OFFSET_ONE_WAY+OFFSET_ONE_WAY-1:OFFSET_ONE_WAY], 1'b1, data_tag, dataWord_i}
            evict [data_set] <= 1;
        end
        else if (evict[data_set] == 1'b1) begin
            cache_memory [data_set] <= {1'b1, data_tag, dataWord_i, cache_memory[data_set] [OFFSET_ONE_WAY-1:0]};
            evict [data_set] <= 0;
        end
    end
end

endmodule
