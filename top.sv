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


    /////////////////////////////////////////////////////////////
    ///////////               FETCH                   ///////////
    /////////////////////////////////////////////////////////////

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

    //wires to leave regfile
    logic [DATA_WIDTH-1:0]       InstrDwire;
    logic [DATA_WIDTH-1:0]       PCDwire;
    logic [DATA_WIDTH-1:0]       PCPlus4Dwire;

    fetch_reg_file fetch_reg_file(
        .clk(clk).
        .rdWire(InstructionWire),
        .PCF_i(PC_wire),
        .PCPlus4F_i(inc_PC)

        .InstrD_o(InstrD_o),
        .PCD_o(PCD_o),
        .PCPlus4D_o(PCPlus4D_o)

    );

    /////////////////////////////////////////////////////////////
    ///////////               DECODE                  ///////////
    /////////////////////////////////////////////////////////////


    assign opcode = InstrDwire[6:0];
    assign funct3 = InstrDwire[14:12];
    assign funct7 = InstrDwire[30];

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

    logic                        RegWriteE_wire;
    logic                        ResultSrcE_wire;
    logic                        MemWriteE_wire;
    logic                        BranchE_wire;
    logic [3:0]                  ALUCtrlE_wire;
    logic                        ALUSrcE_wire;
    logic [2:0]                  ImmSrcE_wire;
    logic                        JALRD_wire;
    logic [DATA_WIDTH-1:0]       RD1E_wire;
    logic [DATA_WIDTH-1:0]       RD2E_wire;
    logic [DATA_WIDTH-1:0]       PCE_wire;
    logic [3:0]                  RdE_wire;
    logic [DATA_WIDTH-1:0]       ImmExtE_wire;
    logic [DATA_WIDTH-1:0]       PCPlus4E_wire;

    decode_reg_file decode_reg_file (
        .clk(clk),
        .RegWriteD_i(regWrite_enWire),
        .ResultSrcD_i(ResultSrcWire),
        .MemWriteD_i (memWrite_enWire),
        .BranchD_i(BranchSrcWire),
        .ALUCtrlD_i(ALUctrlWire),
        .ALUSrcD_i(ALUsrcWire),
        .RD1_i(RD1Wire),
        .RD2_i(RD2Wire),
        .PCD_i(PCDwire),
        .RdD_i(rdWire),
        .ImmExtD_i(ImmediateExtendWire),
        .PCPlus4D_i(PCPlus4Dwire),

        .RegWriteE_o(RegWriteE_wire),
        .ResultSrcE_o(ResultSrcE_wire),
        .MemWriteE_o(MemWriteE_wire),
        .BranchE_o (BranchE_wire),
        .ALUControlE_o (ALUCtrlE_Wire),
        .ALUSrcE_o (ALUSrcE_wire),
        .RD1E_o (RD1E_wire),
        .RD2E_o (RD2E_wire),
        .PCE_o (PCE_wire),
        .RdE_o (RdE_wire),
        .ImmExtE_o (ImmExtE_wire),
        .PCPlus4E_o (PCPlus4Ewire)

    );

    /////////////////////////////////////////////////////////////
    ///////////               EXECUTE                 ///////////
    /////////////////////////////////////////////////////////////


    ALU ALU(
        .SrcA_i(RD1Wire),
        .SrcB_i(Aluop2Wire),
        .ALUctrl_i(ALUctrlWire),
        .BranchCtrl_i(funct3),
        
        .ALUResult_o(ALUResultWire),
        .Branch_o(branchWire)
    );

    assign PCsrcWire = BranchSrcWire ? branchWire : 1'b0;

    /////////////////////////////////////////////////////////////
    ///////////                 MEMORY                ///////////
    /////////////////////////////////////////////////////////////

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
