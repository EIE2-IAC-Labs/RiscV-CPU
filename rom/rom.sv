module rom #(
    parameter  WIDTH = 32, 
               DATA_W = 8, //because we have PC+4 so 4 * 8 = 32 bits
               PC_W = 12
)(
    input  logic [PC_W-1:0] a_i,
    output logic [WIDTH-1:0] rd_o
);

logic [DATA_W-1:0] rom_array [32'hfff : 32'h0]; 

initial begin 
    $display ("Loading rom.");
    $readmemh("instructions.mem", rom_array);
end;

always_comb begin 
    rd_o = {rom_array[a_i],rom_array[a_i+1],rom_array[a_i+2],rom_array[a_i+3]}; // I do concatenation to get 32 bits( the instruction) from 8 bit parts
end

endmodule

