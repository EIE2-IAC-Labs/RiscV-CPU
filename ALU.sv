module ALU #(
    parameter DATAWIDTH = 32
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [3:0]                   ALUctrl_i,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Zero_o
);

//add appropriate word
     
always_comb begin
    case (ALUctrl_i)
        //add
        4'b0000: ALUResult_o = SrcA_i + SrcB_i;

        //sub
        4'b0001: ALUResult_o = SrcA_i - SrcB_i;

        //bitwise and
        4'b0010: ALUResult_o = SrcA_i & SrcB_i;

        //bitwise or
        4'b0011: ALUResult_o = SrcA_i | SrcB_i;

        //TODO WHY NO 4'b0100 ??
        //signed less than
        4'b0101: begin
                    if ((SrcA_i [DATAWIDTH - 1] < SrcB_i [DATAWIDTH - 1])) ALUResult_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] > SrcB_i [DATAWIDTH - 1])) ALUResult_o = 1;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b0)) begin
                        if ((SrcA_i [DATAWIDTH - 2:0] - SrcB_i [DATAWIDTH - 2:0]) > 0) ALUResult_o = 0;
                        else ALUResult_o = 1;
                    end
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b1) && (SrcB_i [DATAWIDTH - 1] == 0'b1)) begin
                        if ((SrcA_i [DATAWIDTH - 2:0] - SrcB_i [DATAWIDTH - 2:0]) < 0) ALUResult_o = 0;
                        else ALUResult_o = 1;
                    end
                end
        //unsigned less than
        4'b0110: begin
                    if ((SrcA_i - SrcB_i) > 0) ALUResult_o = 0;
                    else ALUResult_o = 1;
                end
    
        
        default: ALUResult_o = 0;
    endcase
    
end

endmodule 
