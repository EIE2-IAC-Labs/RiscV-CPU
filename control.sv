module control (
    input logic [6:0]                   op_i,           // input opcode, last 7 bits of instr
    input logic [2:0]                   funct3_i,
    input logic                         funct7bit_i,    // bit 30 of instruction
    output logic                        memWrite_en_o,  // memory write enable         
    output logic                        regWrite_en_o,  // Register write enable
    output logic [3:0]                  ALUctrl_o,      // determines alu op
    output logic                        ALUsrc_o,       // selects immOp or regOp
    output logic [2:0]                  ImmSrc_o,       // control signal for sign extension
    output logic                        BranchSrc_o,    // gives control of PCsrc to branchctrl module
    output logic                        ResultSrc_o,    // toggles between using ALUresult and ReadData from RAM. 
    output logic [1:0]                  memType_o,      // memory address type
    output logic                        memSign_o,      // determines signed or unsigned memory addressing
    output logic                        jal_o,          // overrides WD3
    output logic                        jalr_o,         // overrides WD3 and PCbranch
    output logic                        auipc_o         // overrides WD3 with immext + pc
);

    always_comb begin
        memWrite_en_o = (op_i ==  7'b0100011) ? 1'b1 : 1'b0;
        BranchSrc_o = ((op_i == 7'b1100011) || (op_i == 7'b1100111) || (op_i == 7'b1101111)) ? 1'b1 : 1'b0;
        ALUsrc_o = ((op_i == 7'b0010011) || (op_i == 7'b0000011) || (op_i == 7'b1100111) || (op_i == 7'b1101111) || (op_i == 7'b0110111) || (op_i ==  7'b0100011)) ? 1'b1 : 1'b0; 
        regWrite_en_o = ((op_i == 7'b0110011) || (op_i == 7'b0010011) || (op_i == 7'b0000011) || (op_i == 7'b1100111) || (op_i == 7'b1101111) || (op_i == 7'b0010111) || (op_i == 7'b0110111)) ? 1'b1 : 1'b0;
        ResultSrc_o = (op_i == 7'b0000011) ? 1'b1 : 1'b0;
        jal_o = ((op_i == 7'b1100111) || (op_i == 7'b1101111)) ? 1'b1 : 1'b0;
        jalr_o = (op_i == 7'b1100111) ? 1'b1 : 1'b0;
        auipc_o = (op_i == 7'b0010111) ? 1'b1 : 1'b0;
    end

    always_comb begin

        if (op_i == 7'b0010011) ImmSrc_o = 3'b000; // hack, taking this outside the case statement allow grouping cases below

        case (op_i)
            7'b0110011, 7'b0010011: // R-type and I-type bitwise instructions
                case (funct3_i) // switch-casing funct3, as this determines the ops
                    3'b000:
                        if (funct7bit_i) begin // bit 5 of funct7
                            if (op_i == 7'b0110011) ALUctrl_o = 4'b0001; // sub
                        end else begin
                            ALUctrl_o = 4'b0000; // add
                        end    
                    3'b001: ALUctrl_o = 4'b1000; // sll | slli
                    3'b010: ALUctrl_o = 4'b0101; // slt | slti
                    3'b011: ALUctrl_o = 4'b0110; // sltu | sltiu
                    3'b100: ALUctrl_o = 4'b0100; // xor | xori
                    3'b101:
                        if (funct7bit_i) begin
                            ALUctrl_o = 4'b1001; // shift right arithmetic
                        end else begin
                            ALUctrl_o = 4'b0111; // shift right logical
                        end
                    3'b110: ALUctrl_o = 4'b0011; // or  
                    3'b111: ALUctrl_o = 4'b0010; // and
                    default: ;
                endcase

            7'b1100011: ImmSrc_o = 3'b010; // B-Type instructions

            7'b0000011: begin // I-type load instructions
                ALUctrl_o = 4'b0000;
                ImmSrc_o = 3'b000;
                case (funct3_i)
                    3'b000: begin // lb
                        memType_o = 2'b01;
                        memSign_o = 0;
                    end
                    3'b001: begin // lh
                        memType_o = 2'b10;
                        memSign_o = 0;
                    end
                    3'b010: begin // lw
                        memType_o = 2'b00;
                        memSign_o = 0;
                    end
                    3'b100: begin // lbu
                        memType_o = 2'b01;
                        memSign_o = 1;
                    end
                    3'b101: begin // lhu
                        memType_o = 2'b10;
                        memSign_o = 1;
                    end
                    default: ;
                endcase
            end

            7'b0100011: begin // S-type instructions
                ALUctrl_o = 4'b0000;
                ImmSrc_o = 3'b001;
                case (funct3_i)
                    3'b000: begin // sb
                        memType_o = 2'b01;
                        memSign_o = 0;
                    end
                    3'b001: begin // sh
                        memType_o = 2'b10;
                        memSign_o = 0;
                    end
                    3'b010: begin // sw
                        memType_o = 2'b00;
                        memSign_o = 0;
                    end
                    default: ;
                endcase
            end 
            
            7'b0010111: begin // Add Upper Immediate to PC
                ImmSrc_o = 3'b011;
                ALUctrl_o = 4'b0000; // realistically this is a don't care but preventing errors
            end

            7'b0110111: begin // Load Upper Immediate
                ImmSrc_o = 3'b011;
                ALUctrl_o = 4'b0000;
            end

            7'b1100111: begin // Jump and Link Register
                ImmSrc_o = 3'b000;
                ALUctrl_o = 4'b1100; // ALU will forward SrcB to ALUresult, and set branch_o = 1
            end

            7'b1101111: begin // Jump and Link 
                ImmSrc_o = 3'b100;
                ALUctrl_o = 4'b1011;  // add srca and srcb, but set branch_o to 1
            end

            default: ImmSrc_o = 3'b000; // this should have no effect if ALUsrc is 0, just precaution
        endcase
    end

endmodule
