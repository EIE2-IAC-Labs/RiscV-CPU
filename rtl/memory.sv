module memory # (
    parameter WIDTH = 32
              
)(
    input  logic                     write_en_i,
    input  logic                     clk_i,
    input  logic     [1:0]           memtype_i,
    input  logic                     memsign_i,
    input  logic     [WIDTH-1:0]     wd_i,
    input  logic     [WIDTH-1:0]     a_i,
    output logic     [WIDTH-1:0]     rd_o

);

logic [WIDTH-1:0] WDWire;
logic [WIDTH-1:0] RDWire;
logic [WIDTH-1:0] a_ii;
assign a_ii = {{a_i[31:2]}, {2'b0}};

ram_i ram_i (
    .memtype_i(memtype_i),
    .a_i(a_i),
    .rd_i(RDWire),
    .wd_i(wd_i),
    .wd_o(WDWire)
    
);

ram ram(
    .write_en_i(write_en_i),
    .clk_i(clk_i),
    .a_i(a_ii),
    .wd_i(WDWire),
    .rd_o(RDWire)

);

ram_o ram_o(
    .memtype_i(memtype_i),
    .memsign_i(memsign_i),
    .a_i(a_i),
    .rd_i(RDWire),
    .rd_o(rd_o)
    

);

endmodule
