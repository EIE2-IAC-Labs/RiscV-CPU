module rom #(
    parameter  WIDTH = 32, 
               DATA_W = 8, //because we have PC+4 so 4 * 8 = 32 bits
)(
    input  logic [WIDTH-1:0] a_i,
    output logic [WIDTH-1:0] rd_o,
);

logic [DATA_W-1:0] rom_array [32'hBFC00fff : 32'hBFC00000]; 

initial begin 
    $display ("Loading rom.");
    $readmemh("instructions.mem", rom_array);
end;

always_comb begin 
    rd_o = {rom_array[a_i],rom_array[a_i+1],rom_array[a_i+2],rom_array[a_i+3]}; // I do concatenation to get 32 bits( the instruction) from 8 bit parts
end

endmodule

