module ALU #(
    parameter DATAWIDTH = 32
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [2:0]                   ALUctrl_i,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Zero_o
);

//add appropriate word
     
always_comb begin
    case (ALUctrl)
        3'b000: ALUResult_o = SrcA_i + SrcB_i;
        3'b001: ALUResult_o = SrcA_i - SrcB_i;
        3'b010: ALUResult_o = SrcA_i & SrcB_i;
        3'b011: ALUResult_o = SrcA_i | SrcB_i;
        3'b011: ALUResult_o = SrcA_i | SrcB_i;
        3'b101: if ((SrcA_i - SrcB_i) > 0) ALUResult_o = 0;
                else ALUResult_o = 1;
        default: ALUResult_o = 0;
    endcase
    
end

endmodule 
