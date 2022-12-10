module ram_o #(
    parameter 
              WIDTH = 32 
             

)(
    input  logic    [1:0]           memtype_i,
    input  logic                    memsign_i,
    input  logic    [WIDTH-1:0]     rd_i,
    input  logic    [WIDTH-1:0]     a_i,
    output logic    [WIDTH-1:0]     rd_o
);

logic [1:0] whichbyte_i;

assign whichbyte_i = a_i[1:0];

always_comb begin
    case (memtype_i)
        2'b01:
            case (memsign_i)
                1'b0: 
                    case(whichbyte_i)
                        2'b00: rd_o ={{24{rd_i[7]}},  {rd_i[7:0]}};
                        2'b01: rd_o ={{24{rd_i[15]}}, {rd_i[15:8]}};
                        2'b10: rd_o ={{24{rd_i[23]}}, {rd_i[23:16]}};
                        2'b11: rd_o ={{24{rd_i[31]}}, {rd_i[31:24]}};
                    endcase
                1'b1:
                    case(whichbyte_i)
                        2'b00: rd_o ={{24{1'b0}}, {rd_i[7:0]}};
                        2'b01: rd_o ={{24{1'b0}}, {rd_i[15:8]}};
                        2'b10: rd_o ={{24{1'b0}}, {rd_i[23:16]}};
                        2'b11: rd_o ={{24{1'b0}}, {rd_i[31:24]}};
                    endcase
            endcase
                        
        2'b10:
            case (memsign_i)
                1'b0: 
                    rd_o = whichbyte_i[1] ? {{16{rd_i[31]}}, rd_i[31:16]} : {{16{rd_i[15]}}, rd_i[15:0]};
                1'b1:
                    rd_o = whichbyte_i[1] ? {{16{1'b0}}, rd_i[31:16]} : {{16{1'b0}}, rd_i[15:0]};
            endcase
    
        
        default: rd_o = rd_i;
        endcase 
end

endmodule
