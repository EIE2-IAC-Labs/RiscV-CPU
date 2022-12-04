module branchcontrol #(
    parameter DW=32
) (
    input logic [DW-1:0] rd1,
    input logic [DW-1:0] rd2,
    input logic func3,
    output logic branch //1 or 0 deciding if we branch or not
);

always_comb begin
    case (func3)
    3'b000:branch = rd1==rd2 ? 1'b1:1'b0; //beq if rd1 equal rd2
    3'b001:branch = rd1!=rd2 ? 1'b1:1'b0; //bne if rd1 not equal rd2
    3'b100:branch = rd1<rd2 ? 1'b1:1'b0; //blt branch if rd1 less than rd2
    3'b101:branch = rd1>=rd2 ? 1'b1:1'b0; //bge branch if rd1 greater than or equal than rd2
    3'b110:begin
        rd1={{rd1[31]},{rd1}}; //sign extend rd1 by 1 bit
        rd2={{1'b0},{rd2}}; //make rd2 unsigned
        branch = rd1<rd2 ? 1'b1:1'b0; //bltu branch if rd2 unisigned less than rd1
    end
    3'b111:begin
        rd1={{rd1[31]},{rd1}}; //sign extend rd1 by 1 bit
        rd2={{1'b0},{rd2}}; //make rd2 unsigned
        branch = rd1>=rd2 ? 1'b1:1'b0; //bgeu branch if rd2 unisigned greater than rd1
    end
    default:branch=1'b0;
        
    endcase
end
    
endmodule