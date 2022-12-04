module ALU #(
    parameter DATAWIDTH =   32, 
            SHIFT_WIDTH = 5
)(
    input logic [DATAWIDTH-1:0]         SrcA_i,
    input logic [DATAWIDTH-1:0]         SrcB_i,
    input logic [3:0]                   ALUctrl_i,
    input logic [2:0]                   BranchCtrl_i,
    input logic [SHIFT_WIDTH-1:0]       shift,

    output logic [DATAWIDTH-1:0]        ALUResult_o,
    output logic                        Zero_o
);

always_comb begin
    case (BranchCtrl_i)
        //Zero
        3'b000: begin
                if(SrcA_i == SrcB_i) Zero_o = 1;
                else Zero_o = 0;
        end

        //Not equal
        3'b001: begin
                if(SrcA_i != SrcB_i) Zero_o = 1;
                else Zero_o = 0;
        end

        //<
        3'b010: begin
                    if( SrcA_i == SrcB_i) Zero_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b1)) Zero_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] > SrcB_i [DATAWIDTH - 1])) Zero_o = 1;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b0)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) Zero_o = 0;
                        else Zero_o = 1;
                    end
                    else if ((SrcA_i [DATAWIDTH - 1] == 1'b1) && (SrcB_i [DATAWIDTH - 1] == 1'b1)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) Zero_o = 0;
                        else Zero_o = 1;
                    end
                end

        //>=
        3'b011: begin
                    if( SrcA_i == SrcB_i) Zero_o = 1;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b1)) Zero_o = 1;
                    else if ((SrcA_i [DATAWIDTH - 1] > SrcB_i [DATAWIDTH - 1])) Zero_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b0)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) Zero_o = 1;
                        else Zero_o = 0;
                    end
                    else if ((SrcA_i [DATAWIDTH - 1] == 1'b1) && (SrcB_i [DATAWIDTH - 1] == 1'b1)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) Zero_o = 1;
                        else Zero_o = 0;
                    end
                end

        //< unsigned
        3'b100: begin
                if(SrcA_i < SrcB_i) Zero_o = 1;
                else Zero_o = 0;
        end

        //>= unsigned
        3'b101: begin
                if(SrcA_i >= SrcB_i) Zero_o = 1;
                else Zero_o = 0;
        end

        default: Zero_o = 0;
    endcase
end

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

        //bitwise xor
        4'b0100: ALUResult_o = SrcA_i ^ SrcB_i;

        //signed less than
        4'b0101: begin
                    if( SrcA_i == SrcB_i) ALUResult_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b1)) ALUResult_o = 0;
                    else if ((SrcA_i [DATAWIDTH - 1] > SrcB_i [DATAWIDTH - 1])) ALUResult_o = 1;
                    else if ((SrcA_i [DATAWIDTH - 1] == 0'b0) && (SrcB_i [DATAWIDTH - 1] == 0'b0)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) ALUResult_o = 0;
                        else ALUResult_o = 1;
                    end
                    else if ((SrcA_i [DATAWIDTH - 1] == 1'b1) && (SrcB_i [DATAWIDTH - 1] == 1'b1)) begin
                        if (SrcA_i [DATAWIDTH - 2:0] > SrcB_i [DATAWIDTH - 2:0]) ALUResult_o = 0;
                        else ALUResult_o = 1;
                    end
                end
        //unsigned less than
        4'b0110: begin
                    if (SrcA_i >= SrcB_i) ALUResult_o = 0;
                    else ALUResult_o = 1;
                end
        
        //lsr
        4'b0111: ALUResult_o = SrcA_i >> shift;

        //lsl
        4'b01000: ALUResult_o = SrcA_i << shift;
    
        default: ALUResult_o = 0;
    endcase
    
end

endmodule 
