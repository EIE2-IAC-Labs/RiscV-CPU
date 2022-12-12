module direct_mapped_cache #(
    parameter SET_WIDTH = 3,
    TAG_WIDTH = 27,
    DATA_WIDTH = 32,
    CACHE_LENGTH = 8

)(
    input logic                                 clk,
    input logic [DATA_WIDTH-1:0]                dataWord_i,

    output logic [DATA_WIDTH-1:0]               dataWord_o,
    output logic                                hit_o
);

//add overwrite and when to write V flag
//combine into one memory block
//check combinational logic warning


logic [DATA_WIDTH-1:0] cache_memory [DATA_WIDTH+TAG_WIDTH:0];
logic V [CACHE_LENGTH-1:0];
logic [TAG_WIDTH-1:0] Tag [CACHE_LENGTH-1:0];
logic [DATA_WIDTH-1:0] Data [CACHE_LENGTH-1:0];

logic [SET_WIDTH+1:1] data_set;
logic [TAG_WIDTH-1:0] data_tag;

logic overwrite;

assign data_tag = dataWord_i[DATA_WIDTH-1:DATA_WIDTH-1-TAG_WIDTH];
assign data_set = dataWord_i[SET_WIDTH+1:1];
assign hit_o = (Tag[data_set] && data_tag) ^ V [data_set];

always_comb begin
    if(hit_o) dataWord_o = Data[data_set];
    else overwrite = 1'b1;        
end

always_ff @(negedge clk) begin
    if(overwrite) begin
        Tag [data_set] <= data_tag;
        overwrite = 0'b0;
        V [data_set] <= 1'b1;
    end
end

endmodule
