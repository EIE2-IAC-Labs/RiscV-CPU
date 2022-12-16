module rom #(
    parameter  WIDTH = 32, 
               DATA_W = 8 //because we have PC+4 so 4 * 8 = 32 bits
               
)(
    input  logic [WIDTH-1:0] a_i,
    output logic [WIDTH-1:0] rd_o
);

    logic [WIDTH-1:0] offset_addr;
    assign offset_addr = a_i - 32'hBFC00000;  // (NIK) - added this but not sure if necessary
    logic [DATA_W-1:0] rom_array [12'hfff : 12'h0]; 

    initial begin 
        $display ("Loading rom.");  
        $readmemh("instructions.mem", rom_array);
    end;

    always_comb begin 
        rd_o = {rom_array[offset_addr[11:0] + 3], rom_array[offset_addr[11:0] + 2], rom_array[offset_addr[11:0] + 1], rom_array[offset_addr[11:0]]}; // I do concatenation to get 32 bits( the instruction) from 8 bit parts
    end

endmodule
