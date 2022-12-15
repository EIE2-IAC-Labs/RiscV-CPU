
module two_way_associative_cache_version2 #(
    parameter SET_WIDTH = 3,
    TAG_WIDTH = 27,
    DATA_WIDTH = 32,
    CACHE_LENGTH = 8

)(
    input logic                                 clk,
    input logic [DATA_WIDTH-1:0]                addressWord_i,
    input logic [DATA_WIDTH-1:0]                dataWord_i,
    input logic                                 overwrite_i,

    output logic [DATA_WIDTH-1:0]               dataWord_o,
    output logic                                hit_o
);

//add overwrite and when to write V flag
//combine into one memory block
//check combinational logic warning
//check it is of the correct type (i.e correct parts are combinational and vice versa)
//remove overwrite if needed, check if required


//logic [DATA_WIDTH-1:0] cache_memory_1 [DATA_WIDTH+TAG_WIDTH:0];

//cache way 1
logic V_1 [CACHE_LENGTH-1:0];
logic [TAG_WIDTH-1:0] tag_1 [CACHE_LENGTH-1:0];
logic [DATA_WIDTH-1:0] data_1 [CACHE_LENGTH-1:0];

//cache way 0
logic V_0 [CACHE_LENGTH-1:0];
logic [TAG_WIDTH-1:0] tag_0 [CACHE_LENGTH-1:0];
logic [DATA_WIDTH-1:0] data_0 [CACHE_LENGTH-1:0];


//current input data
logic [SET_WIDTH-1:0] data_set;
logic [TAG_WIDTH-1:0] data_tag;


assign data_tag = addressWord_i[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
assign data_set = addressWord_i[SET_WIDTH+1:2];

//hit logic implementationS
logic hit0;
logic hit1;

assign hit0 = (tag_0[data_set] == data_tag) && V_0[data_set];
assign hit1 = (tag_1[data_set] == data_tag) && V_1[data_set];
assign hit_o = hit0 || hit1;

//logic evict
//1 means evict cache location 1 and vice versa
logic evict [CACHE_LENGTH-1:0];

always_comb begin
    if(hit_o)begin
        if(data_tag == tag_1[data_set]) begin
            dataWord_o = data_1[data_set];
            evict [data_set] = 0;
        end
        else if(data_tag == tag_0[data_set]) begin
            dataWord_o = data_0[data_set];
            evict [data_set] = 1;
        end
    end
end

initial begin
    int i;
    for(i = 0; i < CACHE_LENGTH; i = i + 1) begin
        evict [i] = 1;
    end
end

always_ff @(negedge clk) begin
    if((data_tag != tag_0[data_set]) && (data_tag != tag_1[data_set])) begin
        if (evict[data_set] == 1'b0) begin
            tag_0 [data_set] <= data_tag;
            data_0[data_set] <= dataWord_i;
            V_0 [data_set] <= 1'b1;
            evict [data_set] <= 1;
        end
        else if (evict[data_set] == 1'b1) begin
            tag_1 [data_set] <= data_tag;
            data_1[data_set] <= dataWord_i;
            V_1 [data_set] <= 1'b1;
            evict [data_set] <= 0;
        end
    end
    if(overwrite_i) begin
        if(data_tag == tag_0[data_set]) begin
            tag_0 [data_set] <= data_tag;
            data_0[data_set] <= dataWord_i;
            evict [data_set] <= 1;
        end
        else if (data_tag == tag_1[data_set]) begin
            tag_1 [data_set] <= data_tag;
            data_1[data_set] <= dataWord_i;
            evict [data_set] <= 0;
        end
    end
end

endmodule
