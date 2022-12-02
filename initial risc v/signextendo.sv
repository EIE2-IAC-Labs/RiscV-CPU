module signextendo #(
    DW=32
) (
    input logic[2:0] ImmSrc_i,
    /* verilator lint_off UNUSED */
    input logic [DW-1:0] instr_i,
    /* verilator lint_on UNUSED */
    output logic [DW-1:0] ImmOp_o
);
    logic [11:0] immediate;
    logic msb;
    always_comb begin
        case (ImmSrc_i)
        3'b000:begin //imm in bit[31:20] of inst
            immediate=instr_i[31:20];
            msb=immediate[11];
            ImmOp_o={{5'd20{msb}},{immediate[11:0]}};
        end
        3'b001:begin
            immediate={instr_i[31],instr_i[7],instr_i[30:25],instr_i[11:8]};
            msb=immediate[11];
            ImmOp_o={{5'd20{msb}},{immediate[11:0]}};
        end
        default:begin
            ImmOp_o=0;
        end
        endcase
    end
    
endmodule
