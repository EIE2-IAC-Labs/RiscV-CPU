module two_way_associative_cache #(
    parameter SET_WIDTH = 2,
    TAG_WIDTH = 28,
    DATA_WIDTH = 32,
    CACHE_LENGTH = 4

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



logic [DATA_WIDTH-1:0] cache_memory [0:CACHE_LENGTH-1][0:6];

//current input data
logic [SET_WIDTH-1:0] data_set;
logic [TAG_WIDTH-1:0] data_tag;


assign data_tag = addressWord_i[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
assign data_set = addressWord_i[SET_WIDTH+1:2];

//hit logic implementationS
logic hit0;
logic hit1;


//tag_0[data_set]-> cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH]
//V_0-> cache_memory[data_set][0][0]
//tag_1[data_set]-> cache_memory[data_set][4][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH]
//V_1-> cache_memory[data_set][3][0]
//data_0[data_set]-> cache_memory[data_set][2]
//data_1[data_set]-> cache_memory[data_set][5]


assign hit0 = (cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH] == data_tag) && cache_memory[data_set][0][0];
assign hit1 = (cache_memory[data_set][4][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH] == data_tag) && cache_memory[data_set][3][0];
assign hit_o = hit0 ^ hit1;



always_comb begin
    if(hit_o)begin
        if(data_tag == cache_memory[data_set][4][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH]) begin
            dataWord_o = cache_memory[data_set][5];
            cache_memory[data_set][6][0] = 0;
        end
        else if(data_tag == cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH]) begin
            dataWord_o = cache_memory[data_set][2];
            cache_memory[data_set][6][0] = 1;
        end
    end
end

always_ff @(negedge clk) begin
    if((data_tag != cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH]) && (cache_memory[data_set][3][0] == 1'b0)) begin
        if((cache_memory[data_set][0][0] == 1'b0) && (cache_memory[data_set][3][0] == 1'b0)) begin
            cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH] <= data_tag;
            cache_memory[data_set][2] <= dataWord_i;
            cache_memory[data_set][0][0] <= 1'b1;
            cache_memory[data_set][6][0] <= 1; //evict
        end
        else if (evict[data_set] == 1'b0) begin
            cache_memory[data_set][1][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH] [data_set] <= data_tag;
            cache_memory[data_set][2] <= dataWord_i;
            cache_memory[data_set][0][0] <= 1'b1;
            cache_memory[data_set][6][0] <= 1; //evict
        end
        else if (evict[data_set] == 1'b1) begin
            cache_memory[data_set][4][DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH] <= data_tag;
            cache_memory[data_set][5] <= dataWord_i;
            cache_memory[data_set][3][0] <= 1'b1;
            cache_memory[data_set][6][0] <= 0; //evict
        end
    end
end

endmodule
