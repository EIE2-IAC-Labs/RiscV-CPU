module ALU #(
    parameter DATAWIDTH = 32
)(
    input logic [DATAWIDTH-1:0]         ALUop1,
    input logic [2:0]                   ALUctrl,
    input logic                         ALUsrc,
    input logic [DATAWIDTH-1:0]         regOp2,
    input logic [DATAWIDTH-1:0]         ImmOp,
    // input logic clk,

    output logic [DATAWIDTH-1:0]        ALUout,
    output logic Eq
);

    logic [DATAWIDTH-1:0] ALUop2;
     
always_comb begin
    ALUop2 = ALUsrc ? ImmOp : regOp2;
    case (ALUctrl)
        3'b000: ALUout = ALUop1 + ALUop2;
        3'b001: ALUout= ALUop1 - ALUop2;
        3'b010: ALUout= ALUop1 & ALUop2;
        default: ALUout = 0;
    endcase
    
end
assign Eq = (ALUop1==ALUop2);


endmodule 
