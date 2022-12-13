module extend # (
    parameter DATAWIDTH = 32
)(
    input logic [2:0]               ImmSrc_i,
    input logic [DATAWIDTH-1:7]     Imm_i,

    output logic [DATAWIDTH-1:0]    ImmExt_o
);

always_comb begin
    case (ImmSrc_i)
        //instruction[31:20]
        0'b000: ImmExt_o = {{21{Imm_i[31]}}, Imm_i[30:20]};

        //instruction[31:25], instruction[11:7]
        0'b001: ImmExt_o = {{21{Imm_i[31]}}, Imm_i[30:25], Imm_i[11:7]};

        //instruction[31], instruction[7], instruction[30:25], instruction[11:8]
        0'b010: ImmExt_o = {{20{Imm_i[31]}}, Imm_i[7], Imm_i[30:25], Imm_i[11:8], 1'b0};

        //instruction[31:12]
        0'b011: ImmExt_o = {Imm_i[31:12], {12{1'b0}}};
        
        //instruction[31], instruction[19:12], instruction[20]instruction [30:21]
        0'b100: ImmExt_o = {{12{Imm_i[31]}}, Imm_i[19:12], Imm_i[20], Imm_i[30:21], 1'b0};

        default: ImmExt_o = 32'b0;
    endcase
end

endmodule
