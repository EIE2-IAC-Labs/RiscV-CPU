module ram #(
    parameter 
              WIDTH = 32, 
              DATA_W = 8
) (
    input  logic                clk_i,
    input  logic                write_en_i,
    input  logic [WIDTH-1:0]    a_i,
    input  logic [WIDTH-1:0]    wd_i,
    output logic [WIDTH-1:0]    rd_o
);

    logic [DATA_W-1:0] ram_array [17'h1FFFF : 17'h0]; 


    initial begin 
        $display  ("Loading ram.");
        $readmemh("sine.mem", ram_array, 17'h10000);
        $display ("ram finished loading !!!!");
    end;

    assign rd_o = {ram_array[a_i[16:0] + 3],ram_array[a_i[16:0] + 2],ram_array[a_i[16:0] + 1],ram_array[a_i[16:0]]};
        

    always_ff @(negedge clk_i) begin
        if (write_en_i) begin
            ram_array[a_i[16:0]] <= wd_i[7:0];
            ram_array[a_i[16:0] + 1] <= wd_i[15:8];
            ram_array[a_i[16:0] + 2] <= wd_i[23:16];
            ram_array[a_i[16:0] + 3] <= wd_i[31:24];
            // $display(ram_array[a_i[16:0] + 3], ram_array[a_i[16:0] + 2], ram_array[a_i[16:0] + 1], ram_array[a_i[16:0]]);

        end
    end 

endmodule
