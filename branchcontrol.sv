module branchcontrol #(
    parameter DW=32
) (
    input logic [DW-1:0]    rd1_i,
    input logic [DW-1:0]    rd2_i,
    input logic [2:0]       funct3_i,
    output logic            branch_o //1 or 0 deciding if we branch_o or not
);

always_comb begin
    case (funct3_i)
        3'b000: branch_o = rd1_i == rd2_i ? 1'b1 : 1'b0; //beq if rd1_i equal rd2_i
        3'b001: branch_o = rd1_i != rd2_i ? 1'b1 : 1'b0; //bne if rd1_i not equal rd2_i
        3'b100: begin
                    if( rd1_i == rd2_i) branch_o = 0;
                    else if ((rd1_i [DW - 1] == 0'b0) && (rd2_i [DW - 1] == 0'b1)) branch_o = 0;
                    else if ((rd1_i [DW - 1] > rd2_i [DW - 1])) branch_o = 1;
                    else if ((rd1_i [DW - 1] == 0'b0) && (rd2_i [DW - 1] == 0'b0)) begin
                        if (rd1_i [DW - 2:0] > rd2_i [DW - 2:0]) branch_o = 0;
                        else branch_o = 1;
                    end
                    else if ((rd1_i [DW - 1] == 1'b1) && (rd2_i [DW - 1] == 1'b1)) begin
                        if (rd1_i [DW - 2:0] > rd2_i [DW - 2:0]) branch_o = 0;
                        else branch_o = 1;
                    end
                end //blt branch_o if rd1_i less than rd2_i
        3'b101: branch_o = rd1_i >= rd2_i ? 1'b1 : 1'b0; //bge branch_o if rd1_i greater than or equal than rd2_i
        3'b110: branch_o = rd1_i < rd2_i ? 1'b1 : 1'b0; //
        3'b111: branch_o = rd1_i >= rd2_i ? 1'b1 : 1'b0; 
        default: branch_o=1'b0;    
    endcase
end
    
endmodule
