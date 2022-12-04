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
        3'b100: branch_o = rd1_i < rd2_i ? 1'b1 : 1'b0; //blt branch_o if rd1_i less than rd2_i
        3'b101: branch_o = rd1_i >= rd2_i ? 1'b1 : 1'b0; //bge branch_o if rd1_i greater than or equal than rd2_i
        3'b110: begin
            rd1_i = {{rd1_i[31]},{rd1_i}}; //sign extend rd1_i by 1 bit
            rd2_i = {{1'b0},{rd2_i}}; //make rd2_i unsigned
            branch_o = rd1_i < rd2_i ? 1'b1 : 1'b0; //bltu branch_o if rd2_i unisigned less than rd1_i
        end
        3'b111: begin
            rd1_i = {{rd1_i[31]},{rd1_i}}; //sign extend rd1_i by 1 bit
            rd2_i = {{1'b0},{rd2_i}}; //make rd2_i unsigned
            branch_o = rd1_i >= rd2_i ? 1'b1 : 1'b0; //bgeu branch_o if rd2_i unisigned greater than rd1_i
        end
        default: branch_o=1'b0;    
    endcase
end
    
endmodule
