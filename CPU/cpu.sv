module cpu #(
    parameter DW=32
) (
    input logic rst_i,
    input logic trigger_i,
    input logic clk_i,
    output logic [7:0] data_out
);
    // extenstion block
    
    //pc wires
    logic [DW-1:0]        inc_PC;
    logic [DW-1:0]     branch_PC;
    logic [DW-1:0]       next_PC;
    logic [DW-1:0]       PC_wire;
    logic              PCsrcWire;
    //alu wires
    logic [DW-1:0]       RD1Wire;
    logic [DW-1:0]       RD2Wire;
    logic [DW-1:0]    Aluop2Wire;
    logic             branchWire;
    logic [DW-1:0] ALUResultWire;
    // rom wires
    logic [DW-1:0] InstructionWire;
    // control wires
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic funct7;
    logic memWrite_enWire;
    logic regWrite_enWire;
    logic ALUctrlWire;
    logic ALUsrcWire;
    logic ImmSrcWire;
    logic BranchSrcWire;
    logic addrSelectWire;
    logic ResultSrcWire;
    // register wires
    logic [4:0] rs1Wire;
    logic [4:0] rs2Wire;
    logic [4:0] rdWire;
    logic [DW-1:0] wd3Wire;




    assign inc_PC = PC_wire+4;
    assign next_PC = PCsrcWire ? inc_PC : branch_PC;
    PC PC(
        .clk(clk),
        .rst(rst),
        .PC_i(next_PC),

        .PC_op(PC_wire)
    );

    rom rom(
        .a_i(PC_wire),

        rd_o(InstructionWire)
    );

    assign opcode = InstructionWire[6:0];
    assign funct3 = InstructionWire[14:12];
    assign funct7 = InstructionWire[30];

    control control(
        op_i(opcode),
        funct3_i(funct3),
        funct7bit_i(funct7),

        memWrite_en_o(memWrite_enWire),
        regWrite_en_o(regWrite_enWire),
        ALUctrl_o(ALUctrlWire),
        ALUsrc_o(ALUsrcWire),
        ImmSrc_o(ImmSrcWire),
        BranchSrc_o(BranchSrcWire),
        addrSelect_o(addrSelectWire),
        ResultSrc_o(ResultSrcWire)
    );
    assign rs1Wire=InstructionWire[19:15];
    assign rs2Wire=InstructionWire[24:20];
    assign rdWire=InstructionWire[11:7];


    register register(
        .clk(clk),
        .AD1_i(rs1Wire),
        .AD2_i(rs2Wire),
        .AD3_i(rdWire),
        .WE3_i(regWrite_enWire),
        .WD3_i(wd3Wire),

        .RD1_o(RD1Wire),
        .RD2_o(RD2Wire),
        .a0_o(data_out)

    );

    




    




endmodule