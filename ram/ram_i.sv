module ram_i #(
    parameter WIDTH = 32

)(
    input  logic    [1:0]           memtype_i,
    input  logic    [WIDTH-1:0]     rd_i,
    input  logic    [WIDTH-1:0]     wd_i,
    input  logic    [WIDTH-1:0]     a_i,
    output logic    [WIDTH-1:0]     wd_o

);

logic [1:0] whichbyte_i;

assign whichbyte_i = a_i[1:0];

always_comb begin

    case (memtype_i)
        2'b01:
            case (whichbyte_i)
                2'b00: wd_o ={rd_i[31:8], wd_i[7:0]};
                2'b01: wd_o ={rd_i[31:16], wd_i[7:0], rd_i[7:0]};
                2'b10: wd_o ={rd_i[31:24], wd_i[7:0], rd_i[15:0]};
                2'b11: wd_o ={wd_i[7:0], rd_i[23:0]};
            endcase

        2'b10:  
            wd_o = whichbyte_i[1] ? {wd_i[31:16], rd_i[15:0]} : {rd_i[31:16], wd_i[15:0]};
        default: wd_o = wd_i;

    endcase
end

endmodule

