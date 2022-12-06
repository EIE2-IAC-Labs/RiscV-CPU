module ALU #(
    parameter DW = 32
)(
    input logic [DW-1:0]                ALUop1_i,
    input logic [2:0]                   ALUctrl_i,
    input logic [DW-1:0]                ALUop2_i,
    

    output logic [DW-1:0]           ALUout_o,
    output logic                        Eq_o
);

always_comb begin
    
    case (ALUctrl_i)
        3'b000: ALUout_o = ALUop1_i + ALUop2_i;
        3'b001: ALUout_o= 32'b0;
        3'b010: ALUout_o= 32'b0;
        3'b011: ALUout_o= 32'b0;
        3'b100: ALUout_o= 32'b0;
        3'b101: ALUout_o= 32'b0;
        3'b110: ALUout_o= 32'b0;
        default: ALUout_o = 0;
    endcase
    
end
assign Eq_o = (ALUop1_i==ALUop2_i);


endmodule 
