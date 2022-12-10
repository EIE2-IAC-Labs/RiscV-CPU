module top #(
    parameter DW=32,
) (
    input logic rst,
    input logic trigger_i,
    input logic clk,

    output logic [DW-1:0]       data_out  

);
   
    /////////////////////////////////////////////////////////////
    ///////////               FETCH                   ///////////
    /////////////////////////////////////////////////////////////

    ///////////////           PC BLOCK            ///////////////
    logic [DW-1:0]        inc_PC;
    logic [DW-1:0]     branch_PC;
    logic [DW-1:0]       next_PC;
    logic [DW-1:0]       jump_PC;
    logic [DW-1:0]       PC_wire;
    logic              PCsrcWire;

    assign inc_PC = PC_wire+4;
    assign next_PC = PCsrcWire ? jump_PC : inc_PC;

    PC PC(
        .clk(clk),
        .rst(rst),
        .PC_i(next_PC),

        .PC_o(PC_wire)
    );


    ///////////////           ROM BLOCK          ///////////////
    logic [DW-1:0]          InstructionWire;

    rom rom(
        .a_i(PC_wire),

        .rd_o(InstructionWire)
    );


    ///////////////        PIPELINING BLOCK      ///////////////

    logic [DW-1:0]       instrE;
    logic [DW-1:0]       incPCE;
    logic [DW-1:0]       PCE;

    fetch_reg_file fetch_reg_file(
        .clk(clk),
        .instrD_i(InstructionWire),
        .PCD_i(PC_wire),
        .incPCD_i(inc_PC),

        .instrE_o(instrE),
        .incPCE_o(incPCE),
        .PCE_o(PCE)

    );

    /////////////////////////////////////////////////////////////
    ///////////               DECODE                  ///////////
    /////////////////////////////////////////////////////////////

    ///////////////         CONTROL BLOCK         ///////////////
    logic [6:0]             opcode;
    logic [2:0]             funct3;
    logic                   funct7;
    logic                   memWrite_enWire;
    logic                   regWrite_enWire;
    logic [3:0]             ALUctrlWire;
    logic                   ALUsrcWire;
    logic [2:0]             ImmSrcWire;
    logic                   BranchSrcWire;
    logic                   addrSelectWire;
    logic                   ResultSrcWire;
    logic                   JALWire;
    logic                   JALRWire;

    assign opcode = instrE[6:0];
    assign funct3 = instrE[14:12];
    assign funct7 = instrE[30];

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

    ///////////////        REGISTER FILE        ///////////////
    logic [4:0]                 rs1Wire;
    logic [4:0]                 rs2Wire;
    logic [4:0]                 rdWire;
    logic [DW-1:0]              wd3Wire;
    logic [DW-1:0]              wd3Wire0; 

    assign wd3Wire = JALWire ? incPCE :wd3Wire0;
    assign rs1Wire = instrE[19:15];
    assign rs2Wire = instrE[24:20];
    assign rdWire = instrE[11:7];

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

    ///////////////         EXTEND BLOCK          ///////////////
    logic [DW-8:0]          ImmediateWire;
    logic [DW-1:0]          ImmediateExtendWire;

    assign ImmediateWire = instrE[31:7];
    
    extend extend(
        .ImmSrc_i(ImmSrcWire),
        .Imm_i(ImmediateWire),

        .ImmExt_o(ImmediateExtendWire)
    );

    ///////////////        PIPELINE BLOCK        ///////////////
    

    logic                        resultSrcE_2;
    logic                        memWriteE_2;
    logic                        addrSelectE_2;
    logic                        branchSrcE_2;
    logic [3:0]                  ALUctrlDE_2;
    logic                        JALE_2;
    logic                        JALRE_2;
    logic [DW-1:0]       PCE_2;
    logic [DW-1:0]       RD1E_2;
    logic [DW-1:0]       SrcBE_2;
    logic [DW-1:0]       RD2E_2;
    logic [DW-1:0]       ImmExtE_2;
    logic [2:0]                  funct3E_2;

    assign Aluop2Wire = ALUsrcWire ? ImmediateExtendWire : RD2Wire;

    decode_reg_file decode_reg_file (
        .clk(clk),
        .resultSrcD_i(ResultSrcWire),
        .memWriteD_i(memWrite_enWire),
        .addrSelectD_i (addrSelectWire),
        .branchSrcD_i(BranchSrcWire),
        .ALUCtrlD_i(ALUctrlWire),
        .JALD_i (JALWire),
        .JALRD_i (JALRWire),
        .PCD_i(PCE),
        .RD1D_i(RD1Wire),
        .SrcBD_i(Aluop2Wire),
        .RD2D_i(RD2Wire),
        .ImmExtD_i(ImmediateExtendWire),
        .funct3D_i(funct3),
        
        .resultSrcE_o(resultSrcE_2),
        .memWriteE_o(memWriteE_2),
        .addrSelectE_o(addrSelectE_2),
        .branchSrcE_o (branchSrcE_2),
        .ALUctrlE_o (ALUctrlDE_2),
        .JALE_o (JALE_2),
        .JALRE_o (JALRE_2),
        .PCE_o (PCE_2),
        .RD1E_o (RD1E_2),
        .SrcBE_o (SrcBE_2),
        .RD2E_o (RD2E_2),
        .ImmExtE_o (ImmExtE_2),
        .funct3E_o(funct3E_2)
    );

    

    /////////////////////////////////////////////////////////////
    ///////////               EXECUTE                 ///////////
    /////////////////////////////////////////////////////////////

    ///////////////           ALU BLOCK           ///////////////

    //alu wires
    logic [DW-1:0]       RD1Wire;
    logic [DW-1:0]       Aluop2Wire;
    logic [DW-1:0]       ALUResultWire;
    logic [DW-1:0]       RD2Wire;
    logic                branchWire;

    ALU ALU(
        .SrcA_i(RD1E_2),
        .SrcB_i(SrcBE_2),
        .ALUctrl_i(ALUctrlDE_2),
        .BranchCtrl_i(funct3E_2),
        
        .ALUResult_o(ALUResultWire),
        .Branch_o(branchWire)
    );

    ///////////////        PIPELINING BLOCK       ///////////////

    logic resultSrcE_3;
    logic memWriteE_3;
    logic [DW-1:0] ALUResultE_3;
    logic [DW-1:0] RD2E_3;
    logic addrSelectE_3;

    assign branch_PC=PC_wire + ImmediateExtendWire;
    assign jump_PC = JALRE_2 ? ALUResultWire : branch_PC;
    assign PCsrcWire = branchSrcE_2 ? branchWire : 1'b0;

    execute_reg_file execute_reg_file(
        .clk(clk),
        .resultSRCD_i(resultSrcE_2),
        .memWriteD_i(memWriteE_2),
        .addrSelectD_i(addrSelectE_2),
        .ALUresultD_i(ALUResultWire),
        .RD2D_i (RD2E_2),

        .resultSRCE_o (resultSrcE_3),
        .memWriteE_o (memWriteE_3),
        .addrSelectE_o (addrSelectE_3),
        .ALUresultE_o (ALUResultE_3),
        .RD2E_o (RD2E_3)
    );

    /////////////////////////////////////////////////////////////
    ///////////                 MEMORY                ///////////
    /////////////////////////////////////////////////////////////

    ///////////////           RAM BLOCK           ///////////////
    logic [DW-1:0]          RamOutWire;

    ram ram(
        .clk_i(clk),
        .write_en_i(memWriteE_3),
        .a_i(ALUResultE_3),
        .AddrsCtrl_i(addrSelectE_3),
        .wd_i(RD2E_3),

        .rd_o(RamOutWire)

    );

    ///////////////        PIPELINING BLOCK       ///////////////
    logic [DW-1:0]      ALUResultE_4;
    logic [DW-1:0]      RamOutWireE_4;
    logic                       resultSrcE_4;

    mem_reg_file mem_reg_file(
        .clk(clk),
        .ALUResultD_i(ALUResultE_3),
        .RD2D_i (RamOutWire),
        .ResultSrcD_i (resultSrcE_3),

        .ALUResultE_o (ALUResultE_4),
        .RD2E_o (RamOutWireE_4),
        .ResultSrcE_o (resultSrcE_4)
    );



    /////////////////////////////////////////////////////////////
    ///////////               FINAL STAGE             ///////////
    /////////////////////////////////////////////////////////////

    assign wd3Wire0 = resultSrcE_4 ? RamOutWireE_4 : ALUResultE_4;
    

endmodule
