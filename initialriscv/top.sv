module top #(
    parameter DW=32
) (
    input logic clk,
    input logic rst,
    output logic [DW-1:0] a0out,
    output logic [DW-1:0] InstructionWire,
    output logic [DW-1:0] ImmOpWire,
    output logic  [DW-1:0] Aluop2Wire,
    output logic [DW-1:0] RD1Wire,
    output logic [DW-1:0] ALUoutWire
);

    logic PCsrcWire;
    
    logic [DW-1:0] PCWire;
    
    // logic [DW-1:0] ALUoutWire;
    // 
    logic [DW-1:0] RD2Wire;
    // logic [DW-1:0] Aluop2Wire;
    logic EQWire;
    logic RegWriteWire;
    logic ALUsrcWire;
    logic [2:0] ALUctrlWire;
    logic [2:0] ImmSrcWire;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rd;
    logic [DW-1:0] inc_PC;
    logic [DW-1:0] branch_PC;
    logic [DW-1:0] next_PC;
    
    assign branch_PC = PCWire+ImmOpWire;
    assign inc_PC=PCWire+4;
    assign next_PC=PCsrcWire ? branch_PC : inc_PC;

    PC PC(
        .clk(clk),
        .rst(rst),
        .PC_i(next_PC),
        .PC_o(PCWire)
    );
    
    romF romF(
        .a_i(PCWire),
        
        .rd_o(InstructionWire)
    );
   
    assign rs1 = InstructionWire[19:15];
    assign rs2 = InstructionWire[24:20];
    assign rd = InstructionWire[11:7];
    
    control control(
        .Eq_i(EQWire),
        .instr_i(InstructionWire),
        .RegWrite_o(RegWriteWire),
        .ALUctrl_o(ALUctrlWire),
        .ALUsrc_o(ALUsrcWire),
        .ImmSrc_o(ImmSrcWire),
        .PCsrc_o(PCsrcWire)
    );

    register_file RegFile(
        .clk(clk),
        .AD1_i(rs1),
        .AD2_i(rs2),
        .AD3_i(rd),
        .WE3_i(RegWriteWire),
        .WD3_i(ALUoutWire),

        .a0_o(a0out),
        .RD1_o(RD1Wire),
        .RD2_o(RD2Wire)
    );
    signextendo extendo(
        .instr_i(InstructionWire),
        .ImmSrc_i(ImmSrcWire),

        .ImmOp_o(ImmOpWire)
    );

    assign Aluop2Wire = ALUsrcWire ? ImmOpWire : RD2Wire;
    ALU aluCPU(
        .ALUop1_i(RD1Wire),
        .ALUop2_i(Aluop2Wire),
        .ALUctrl_i(ALUctrlWire),

        .ALUout_o(ALUoutWire),
        .Eq_o(EQWire)
    );
    

    
endmodule
