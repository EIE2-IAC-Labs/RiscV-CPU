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

//cache
logic V [CACHE_LENGTH-1:0];
logic [TAG_WIDTH-1:0] tag [CACHE_LENGTH-1:0];
logic [DATA_WIDTH-1:0] data [CACHE_LENGTH-1:0];

//current input data
logic [SET_WIDTH-1:0] data_set;
logic [TAG_WIDTH-1:0] data_tag;


assign data_tag = addressWord_i[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
assign data_set = addressWord_i[SET_WIDTH+1:2];
assign hit_o = (tag[data_set] == data_tag) && V[data_set];




always_comb begin
    if(hit_o) dataWord_o = data[data_set];
end

always_ff @(negedge clk) begin
    if(data_tag != tag[data_set]) begin
        tag [data_set] <= data_tag;
        data [data_set] <= dataWord_i;
        V [data_set] <= 1'b1;
    end
    if(overwrite_i) begin
        if(data_tag == tag [data_set]) begin
            tag [data_set] <= data_tag;
            data [data_set] <= dataWord_i;
        end
    end
end
endmodule
