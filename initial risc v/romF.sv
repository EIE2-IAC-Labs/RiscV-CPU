module romF #(
    parameter   ADDRESS_WIDTH = 32,
                DATA_WIDTH = 8
)(
    input logic     [ADDRESS_WIDTH-1:0]         a_i,
    output logic    [ADDRESS_WIDTH-1:0]         rd_o
);
// 28 bytes
logic [DATA_WIDTH-1:0] rom_array [27:0];

initial begin
    $display("Loading rom.");
    $readmemh("example_rom.mem", rom_array);
    $display("rom loaded");
end

always_comb begin
    rd_o = {{rom_array[a_i]},{rom_array[a_i+1]},{rom_array[a_i+2]},{rom_array[a_i+3]}};
end
endmodule
