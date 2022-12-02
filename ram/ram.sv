module ram #(
    parameter WIDTH = 32, 
              DATA_W = 8
) (
    input  logic  clk_i,
    input  logic  write_en_i,
    input  logic  AddrsCtrl_i,
    input  logic [WIDTH-1:0] a_i,
    input  logic [WIDTH-1:0] wd_i,
    output logic [WIDTH-1:0] rd_o
);

logic [DATA_W-1:0] ram_array [32'h1FFF : 32'h1000]; 

initial begin 
    $display  ("Loading ram.");
    $readmemh ("data.mem", rom_array);
end;

always_ff @(posedge clk) begin
    if (write_en_i==1 & AddrsCtrl_i==1) begin
        ram_array[a_i] <= wd_i[31:24];
        ram_array[a_i + 1] <= wd_i[23:16];
        ram_array[a_i + 2] <= wd_i[15:8];
        ram_array[a_i + 3] <= wd_i[7:0];
    end

    if (write_en_i==1 & AddrsCtrl_i==0) 
        ram_array[a_i] <= wd_i[7:0];     
end 


always_comb  begin
    if (write_en_i==0 & AddrsCtrl_i==1)
    rd_o <=  {ram_array[a_i],rom_array[a_i+1],rom_array[a_i+2],rom_array[a_i+3]};
    
    if (write_en_i==0 & AddrsCtrl_i==0) begin
        //sign extension
        if (ram_array[a_i][7]==0) rd_o <= {{24'h0},{ram_array[a_i]}};
        if (ram_array[a_i][7]==1) rd_o <= {{24'hFFFFFF},{ram_array[a_i]}};
    end

end 

endmodule