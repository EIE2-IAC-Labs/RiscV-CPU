module cache # (
    parameter
        TAG = 27,
        DATA = 32,
        CACHE = 2

)(
    input logic                            clk,
    input logic  [DATA-1:0]                dataWord0_i,
    input logic  [DATA-1:0]                dataWord1_i,
    input logic  [DATA-1:0]                dataWord2_i,
    input logic  [DATA-1:0]                dataWord3_i,
    input logic  [DATA-1:0]                addressWord_i,
    output logic [DATA-1:0]                dataWord_o,
    output logic                           hit_o

);

logic V [CACHE-1:0];
logic [TAG-1:0]  tag   [CACHE-1:0];
//logic [1:0]      block_offset   [CACHE-1:0];
logic [DATA-1:0] data0 [CACHE-1:0];
logic [DATA-1:0] data1 [CACHE-1:0];
logic [DATA-1:0] data2 [CACHE-1:0];
logic [DATA-1:0] data3 [CACHE-1:0];

logic Set;
logic [TAG-1:0] Tag;
logic [1:0] block_offset;
logic overwrite;  

assign overwrite = 1'b0;

assign Tag = addressWord_i[DATA-1:5];
assign Set = addressWord_i[4];
assign hit_o = (tag[Set] == Tag) && V[Set];
assign block_offset = addressWord_i [3:2];

always_comb begin
    if(hit_o)begin
        $display("load"); 
        case(block_offset)
            2'b0:  dataWord_o = data0[Set];
            2'b1:  dataWord_o = data1[Set];
            2'b10: dataWord_o = data2[Set];
            2'b11: dataWord_o = data3[Set];
        endcase 
    end
    else overwrite = 1'b1;      
end


always_ff @(negedge clk) begin
    if(overwrite) begin
        tag [Set] <= Tag;
        data0[Set] <= dataWord0_i;
        data1[Set] <= dataWord1_i;
        data2[Set] <= dataWord2_i;
        data3[Set] <= dataWord3_i;
        overwrite <= 0'b0;
        V [Set] <= 1'b1;
    end
end

endmodule
