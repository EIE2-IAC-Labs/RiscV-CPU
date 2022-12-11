module top #(
    parameter DW = 32
) (
    input logic             rst,
    input logic             trigger_i,
    input logic             clk,
    output logic [DW-1:0]   data_out  
);
   
    //pc wires
    logic [DW-1:0]  inc_PC;
    logic [DW-1:0]  branch_PC;
    logic [DW-1:0]  next_PC;
    logic [DW-1:0]  jump_PC;
    logic [DW-1:0]  PC_wire;
    logic           PCsrcWire;

    //alu wires
    logic [DW-1:0]  RD1Wire;
    logic [DW-1:0]  Aluop2Wire;
    logic [DW-1:0]  ALUResultWire;
    logic [DW-1:0]  RD2Wire;
    logic           branchWire;
    
    // rom wires
    logic [DW-1:0]  InstructionWire;

    // control wires
    logic [6:0]     opcode;
    logic [2:0]     funct3;
    logic           funct7;
    logic           memWrite_enWire;
    logic           regWrite_enWire;
    logic [3:0]     ALUctrlWire;
    logic           ALUsrcWire;
    logic [2:0]     ImmSrcWire;
    logic           BranchSrcWire;
    logic           ResultSrcWire;
    logic           JALWire;
    logic           JALRWire;
    logic           AUIPCWire;
    logic [1:0]     memTypeWire;
    logic           memSignWire;

    // register wires
    logic [4:0]     rs1Wire;
    logic [4:0]     rs2Wire;
    logic [4:0]     rdWire;
    logic [DW-1:0]  wd3Wire;
    logic [DW-1:0]  wd3Wire0; 
    logic [DW-1:0]  wd3Wire1;

    // extend wire
    logic [DW-8:0]  ImmediateWire;
    logic [DW-1:0]  ImmediateExtendWire;

    // memory wires
    logic [DW-1:0]  RamOutWire;
    
    PC PC(
        .clk(clk),
        .rst(rst),
        .PC_i(next_PC),

        .PC_o(PC_wire)
    );

    rom rom(
        .a_i(PC_wire),
        .rd_o(InstructionWire)
    );

    control control(
        .op_i(opcode),
        .funct3_i(funct3),
        .funct7bit_i(funct7),
        .memWrite_en_o(memWrite_enWire),
        .memType_o(memTypeWire),
        .memSign_o(memSignWire),
        .regWrite_en_o(regWrite_enWire),
        .ALUctrl_o(ALUctrlWire),
        .ALUsrc_o(ALUsrcWire),
        .ImmSrc_o(ImmSrcWire),
        .BranchSrc_o(BranchSrcWire),
        .ResultSrc_o(ResultSrcWire),
        .jal_o(JALWire),
        .jalr_o(JALRWire),
        .auipc_o(AUIPCWire)
    );

    register_file register_file(
        .clk(clk),
        .AD1_i(rs1Wire),
        .AD2_i(rs2Wire),
        .AD3_i(rdWire),
        .WE3_i(regWrite_enWire),
        .WD3_i(wd3Wire),
        .TRIGGER_i(trigger_i),
        .RD1_o(RD1Wire),
        .RD2_o(RD2Wire),
        .a0_o(data_out)
    );

    extend extend(
        .ImmSrc_i(ImmSrcWire),
        .Imm_i(ImmediateWire),

        .ImmExt_o(ImmediateExtendWire)
    );
    
    ALU ALU(
        .SrcA_i(RD1Wire),
        .SrcB_i(Aluop2Wire),
        .ALUctrl_i(ALUctrlWire),
        .BranchCtrl_i(funct3),
        .ALUResult_o(ALUResultWire),
        .Branch_o(branchWire)
    );

    memory memory(
        .clk_i(clk),
        .write_en_i(memWrite_enWire),
        .a_i(ALUResultWire),
        .wd_i(RD2Wire),
        .rd_o(RamOutWire),
        .memtype_i(memTypeWire),
        .memsign_i(memSignWire)
    );

    always_comb begin
        opcode = InstructionWire[6:0];
        funct3 = InstructionWire[14:12];
        funct7 = InstructionWire[30];
        
        rs1Wire = InstructionWire[19:15];
        rs2Wire = InstructionWire[24:20];
        rdWire = InstructionWire[11:7];

        ImmediateWire = InstructionWire[31:7];
        Aluop2Wire = ALUsrcWire ? ImmediateExtendWire : RD2Wire;

        PCsrcWire = BranchSrcWire ? branchWire : 1'b0;
        branch_PC = PC_wire + ImmediateExtendWire;
        jump_PC = JALRWire ? ALUResultWire : branch_PC;
        inc_PC = PC_wire + 4;
        next_PC = PCsrcWire ? jump_PC : inc_PC;

        wd3Wire0 = ResultSrcWire ? RamOutWire : ALUResultWire;
        wd3Wire1 = AUIPCWire ? branch_PC : wd3Wire0;
        wd3Wire = JALWire ? inc_PC : wd3Wire1;
    end

endmodule
