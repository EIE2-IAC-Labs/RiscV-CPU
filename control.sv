module control #(
    parameter ADDRESS_WIDTH = 32
) (
    input logic                         eq_i,           // flag for if A = B in ALU
    input logic [ADDRESS_WIDTH-1:0]     instr_i,        // input instruction
    output logic                        regWrite_en_o,  // Register write enable
    output logic [3:0]                  ALUctrl_o,      // determines alu op
    output logic                        ALUsrc_o,       // selects immOp or regOp
    output logic [2:0]                  IMMctrl_o,      // control signal for sign extension
    output logic                        PCsrc_o         // selects between branch or incr pc
);
    logic [6:0] opcode;
    assign opcode = instr_i[6:0];

    always_comb begin
        case (opcode)
            // 7'b0110011: // R-type instructions
            //     case (instr_i[14:12]) // switch-casing funct3, as this determines the ops
            //         3'b000:
            //             if (instr_i[30]) begin // bit 5 of funct7
            //                 // sub
            //             end else begin
            //                 // add
            //             end    
            //         3'b001: // sll
            //         3'b010: // slt
            //         3'b011: // sltu
            //         3'b100: // xor
            //         3'b101:
            //             if (instr_i[30]) begin
            //                 // shift right arithmetic
            //             end else begin
            //                 // shift right logical
            //             end
            //         3'b110: // or
            //         3'b111: // and
            //         default: ;
            //     endcase
            // 7'b0000011: // I-type load instructions
            //     case (instr_i[14:12])
            //         3'b000: // lb
            //         3'b001: // lh
            //         3'b010: // lw
            //         3'b100: // lbu
            //         3'b101: // lhu
            //         default: $display("Immediate load: Something is very wrong");
            //     endcase
            // 7'b0010011: // I-type bitwise instructions
            //     case (instr_i[14:12])
            //         3'b000: // addi
            //         3'b001: // slli  //TODO: DOES THIS NEED TO CHECK FOR FUNCT7 TO BE 0000000???!!?!?!?!?!
            //         3'b010: // slti
            //         3'b011: // sltiu, set less than immediate unsigned
            //         3'b100: // xori
            //         3'b101:
            //             if (instr_i[30]) begin
            //                 // srai
            //             end else begin
            //                 // srli
            //             end
            //         3'b110: // ori
            //         3'b111: // andi
            //         default: ;
            //     endcase
            // 7'b0100011: // S-type instructions
            //     case (instr_i[14:12])
            //         3'b000: // sb, store byte
            //         3'b001: // sh, store half
            //         3'b010: // sw, store word
            //         default: $display("Store: Something is very wrong");
            //     endcase
            // 7'b1100011: // B-type instructions
                // case (instr_i[14:12])
                //     3'b000: // beq
                //     3'b001: // bne
                //     3'b100: // blt
                //     3'b101: // bge
                //     3'b110: // bltu
                //     3'b111: // bgeu
                //     default: $display("Branch: Something is very wrong");
                // endcase
            // 7'b0010111: // Add Upper Immediate to PC
            // 7'b0110111: // Load Upper Immediate
            // 7'b1100111: // Jump and Link Register
            // 7'b1101111: // Jump and Link 
            default: $display("BIG PROBLEM");
        endcase
    end
    
endmodule
