module control #(
    parameter AW=32
) (
    input logic           Eq_i,
    /* verilator lint_off UNUSED */
    input logic [AW-1:0] instr_i,
    /* verilator lint_on UNUSED */
    output logic       RegWrite_o,
    output logic [2:0] ALUctrl_o,
    output logic        ALUsrc_o,
    output logic [2:0] ImmSrc_o,
    output logic        PCsrc_o
);
    logic [6:0] opcode;
    assign opcode=instr_i[6:0];

    // assign PCsrc_o = Eq_i && opcode == 7'd99 ? 1'b1 : 1'b0;
    
    always_comb begin
        
        ALUctrl_o=instr_i[14:12];
        // ALUsrc=instr[5]? 0: 1;
        case (opcode)
            7'd19: begin //store inst
                 ImmSrc_o=3'b000;
                 RegWrite_o=1'b1;
                 ALUsrc_o=1'b1;
                 PCsrc_o=1'b0;
                end
            7'd99:begin //jump instr
                ImmSrc_o=3'b001;
                RegWrite_o=1'b0;
                PCsrc_o=Eq_i?1'b0:1'b1;
                ALUsrc_o=1'b0;
            end
         default: begin
            ImmSrc_o=3'b000;
            RegWrite_o=1'b0;
            ALUsrc_o=1'b0;
            PCsrc_o=1'b0;
        end
            
        endcase




    end
     



    
endmodule
