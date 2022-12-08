module top #(
    parameter DW=32
) (
    input logic rst,
    input logic trigger_i,
    input logic clk,

    output logic [DW-1:0]       data_out  

);
   
    //pc wires
    logic [DW-1:0]        inc_PC;
    logic [DW-1:0]     branch_PC;
    logic [DW-1:0]       next_PC;
    logic [DW-1:0]       jump_PC;
    logic [DW-1:0]       PC_wire;
    logic              PCsrcWire;
    //alu wires
    logic [DW-1:0]       RD1Wire;
    logic [DW-1:0]       Aluop2Wire;
    logic [DW-1:0]       ALUResultWire;
    logic [DW-1:0]       RD2Wire;
    logic             branchWire;
    
    // rom wires
    logic [DW-1:0] InstructionWire;
    // control wires
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic funct7;
    logic memWrite_enWire;
    logic regWrite_enWire;
    logic [3:0] ALUctrlWire;
    logic ALUsrcWire;
    logic [2:0] ImmSrcWire;
    logic BranchSrcWire;
    logic addrSelectWire;
    logic ResultSrcWire;
    logic JALWire;
    logic JALRWire;

    // register wires
    logic [4:0] rs1Wire;
    logic [4:0] rs2Wire;
    logic [4:0] rdWire;
    logic [DW-1:0] wd3Wire;
    logic [DW-1:0]       wd3Wire0; 
    // extend wire
    logic [DW-8:0] ImmediateWire;
    logic [DW-1:0] ImmediateExtendWire;
    // ram wire
    logic [DW-1:0] RamOutWire;



    assign branch_PC=PC_wire + ImmediateExtendWire;
    assign jump_PC = JALRWire ? ALUResultWire : branch_PC;
    assign inc_PC = PC_wire+4;
    assign next_PC = PCsrcWire ? jump_PC : inc_PC;
    
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

    assign opcode = InstructionWire[6:0];
    assign funct3 = InstructionWire[14:12];
    assign funct7 = InstructionWire[30];

    control control(
        .op_i(opcode),
        .funct3_i(funct3),
        .funct7bit_i(funct7),

        .memWrite_en_o(memWrite_enWire),
        .regWrite_en_o(regWrite_enWire),
        .ALUctrl_o(ALUctrlWire),
        .ALUsrc_o(ALUsrcWire),
        .ImmSrc_o(ImmSrcWire),
        .BranchSrc_o(BranchSrcWire),
        .addrSelect_o(addrSelectWire),
        .ResultSrc_o(ResultSrcWire),
        .jal_o(JALWire),
        .jalr_o(JALRWire)
    );
    assign rs1Wire=InstructionWire[19:15];
    assign rs2Wire=InstructionWire[24:20];
    assign rdWire=InstructionWire[11:7];


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

    assign ImmediateWire=InstructionWire[31:7];
    
    extend extend(
        .ImmSrc_i(ImmSrcWire),
        .Imm_i(ImmediateWire),

        .ImmExt_o(ImmediateExtendWire)
    );
    assign Aluop2Wire=ALUsrcWire ? ImmediateExtendWire : RD2Wire;

    ALU ALU(
        .SrcA_i(RD1Wire),
        .SrcB_i(Aluop2Wire),
        .ALUctrl_i(ALUctrlWire),
        .BranchCtrl_i(funct3),
        
        .ALUResult_o(ALUResultWire),
        .Branch_o(branchWire)
    );

    assign PCsrcWire = BranchSrcWire ? branchWire : 1'b0;

    ram ram(
        .clk_i(clk),
        .write_en_i(memWrite_enWire),
        .a_i(ALUResultWire),
        .AddrsCtrl_i(addrSelectWire),
        .wd_i(RD2Wire),

        .rd_o(RamOutWire)

    );

    assign wd3Wire0 = ResultSrcWire ? RamOutWire : ALUResultWire ;
    assign wd3Wire = JALWire ? inc_PC :wd3Wire0;
endmodule
