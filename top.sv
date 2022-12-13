module top #(
    parameter DW=32
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

    logic               en_progression;

    assign inc_PC = PC_wire + 4;
    assign next_PC = PCsrcWire ? jump_PC : inc_PC;

    assign en_progression = ~hitWire;

    PC PC(
        .clk(clk),
        .en_i(en_progression),
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
        .en_i(en_progression),
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
    
    logic                   ResultSrcWire;
    logic                   AUIPCWire;
    logic [1:0]             memTypeWire;
    logic                   memSignWire;

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

    ///////////////        REGISTER FILE        ///////////////
    logic [4:0]                 rs1Wire;
    logic [4:0]                 rs2Wire;
    logic [4:0]                 rdWire;
    logic [DW-1:0]              wd3Wire;
    logic [DW-1:0]              wd3Wire0; 

    assign wd3Wire = JALE_4 ? incPC5 : wd3Wire0;
    assign rs1Wire = instrE[19:15];
    assign rs2Wire = instrE[24:20];
    assign rdWire = instrE[11:7];

    register_file register_file(
        .clk(clk),
        .AD1_i(rs1Wire),
        .AD2_i(rs2Wire),
        .AD3_i(AD3E_4),
        .WE3_i(regWriteWireE_4),
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
    logic                        branchSrcE_2;
    logic [3:0]                  ALUctrlDE_2;
    logic                        JALRE_2;
    logic                        JALE_2;
    logic [DW-1:0]       PCE_2;
    logic [DW-1:0]       RD1E_2;
    logic [DW-1:0]       SrcBE_2;
    logic [DW-1:0]       RD2E_2;
    logic [DW-1:0]       ImmExtE_2;
    logic [2:0]                  funct3E_2;
    logic [1:0]                 memTypeWireE_2;
    logic                       memSignWireE_2;
    logic                       AUIPCE_2;
    logic                       regWriteWireE_2;
    logic [4:0]                 AD3E_2;
    logic [DW-1:0]      instrE_2;

    assign Aluop2Wire = ALUsrcWire ? ImmediateExtendWire : RD2Wire;

    decode_reg_file decode_reg_file (
        .clk(clk),
        .en_i(en_progression),
        .resultSrcD_i(ResultSrcWire),
        .memWriteD_i(memWrite_enWire),
        .branchSrcD_i(BranchSrcWire),
        .ALUCtrlD_i(ALUctrlWire),
        .JALRD_i (JALRWire),
        .PCD_i(PCE),
        .RD1D_i(RD1Wire),
        .SrcBD_i(Aluop2Wire),
        .RD2D_i(RD2Wire),
        .ImmExtD_i(ImmediateExtendWire),
        .funct3D_i(funct3),
        .memTypeWireD_i (memTypeWire),
        .memSignWireD_i (memSignWire),
        .AUIPCWireD_i (AUIPCWire),
        .regWriteD_i(regWrite_enWire),
        .AD3D_i(rdWire),
        .JALD_i(JALWire),
        .incPC2_i(incPCE),
        
        .resultSrcE_o(resultSrcE_2),
        .memWriteE_o(memWriteE_2),
        .branchSrcE_o (branchSrcE_2),
        .ALUctrlE_o (ALUctrlDE_2),
        .JALRE_o (JALRE_2),
        .PCE_o (PCE_2),
        .RD1E_o (RD1E_2),
        .SrcBE_o (SrcBE_2),
        .RD2E_o (RD2E_2),
        .ImmExtE_o (ImmExtE_2),
        .funct3E_o(funct3E_2),
        .memTypeWireE_o (memTypeWireE_2),
        .memSignWireE_o (memSignWireE_2),
        .AUIPCWireE_o (AUIPCE_2),
        .regWriteE_o(regWriteWireE_2),
        .AD3E_o(AD3E_2),
        .JALE_o(JALE_2),
        .incPC3_o(incPC3),
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
    logic [1:0]                 memTypeWireE_3;
    logic                       memSignWireE_3;
    logic                       AUIPCE_3;
    logic                       regWriteWireE_3;
    logic [4:0]                 AD3E_3;
    logic                       JALE_3;
    logic [DW-1:0]              incPC3;
    logic [DW-1:0]              instrE_3;

    assign branch_PC=PCE_2 + ImmExtE_2;
    assign jump_PC = JALRE_2 ? ALUResultWire : branch_PC;
    assign PCsrcWire = branchSrcE_2 ? branchWire : 1'b0;

    execute_reg_file execute_reg_file(
        .clk(clk),
        .en_i(en_progression),
        .resultSRCD_i(resultSrcE_2),
        .memWriteD_i(memWriteE_2),
        .ALUresultD_i(ALUResultWire),
        .RD2D_i (RD2E_2),
        .memTypeD_i (memTypeWireE_2),
        .memSignD_i (memSignWireE_2),
        .AUIPCD_i (AUIPCE_2),
        .regWriteD_i (regWriteWireE_2),
        .AD3D_i(AD3E_2),
        .JALD_i (JALE_2),
        .incPC3_i(incPC3),

        .resultSRCE_o (resultSrcE_3),
        .memWriteE_o (memWriteE_3),
        .ALUresultE_o (ALUResultE_3),
        .RD2E_o (RD2E_3),
        .memTypeE_o (memTypeWireE_3),
        .memSignE_o (memSignWireE_3),
        .AUIPCE_o (AUIPCE_3),
        .regWriteE_o(regWriteWireE_3),
        .AD3E_o(AD3E_3),
        .JALE_o(JALE_3),
        .incPC4_o(incPC4),
    );

    /////////////////////////////////////////////////////////////
    ///////////                 MEMORY                ///////////
    /////////////////////////////////////////////////////////////

    ///////////////           RAM BLOCK           ///////////////
    logic [DW-1:0]          RamOutWire;

    memory memory(
        .clk_i(clk),
        .write_en_i(memWriteE_3),
        .a_i(ALUResultE_3),
        .wd_i(RD2E_3),
        .rd_o(RamOutWire),
        .memtype_i(memTypeWireE_3),
        .memsign_i(memSignWireE_3)
    );

    ///////////////          CACHE BLOCK          ///////////////
    //we have to disable the pc and disable the other registers to prevent the pipeline from moving on if NOT A HIT
    //else just take it from the cache
    //if hit, take Data Out Wire from CACHE and freeze one block to update
    logic [DW-1:0]              DataOutWire;
    logic [DW-1:0]              CacheOutWire;
    logic                       hitWire;

    //if this is high, we are reading from RAM.
    //add block to wait for new RAM read
    

    two_way_associative_cache two_way_associative_cache (
        .clk(clk),
        .dataWord_i(), //CONTENT OF MEMORY WE WANT GOES IN HERE
        .addressWord_i() // address of memory we want goes in here, IF NOT IN CACHE hit -> 0, so then read from RAM

        .dataWord_o(CacheOutWire),
        .hit_o(hitWire)
    );

    //check this is the correct way round
    //currently just blocking until it is in the CACHE, definitely faster way, costs us potentially an extra cycle
    assign DataOutWire = hitWire ? CacheOutWire : RamOutWire;

    ///////////////        PIPELINING BLOCK       ///////////////
    logic [DW-1:0]      ALUResultE_4;
    logic [DW-1:0]      DataE_4;
    logic                       resultSrcE_4;
    logic                       regWriteWireE_4;
    logic [4:0]                 AD3E_4;
    logic                       JALE_4;
    logic [DW-1:0]              incPC4;

    mem_reg_file mem_reg_file(
        .clk(clk),
        .en_i(en_progression),
        .ALUResultD_i(ALUResultE_3),
        .RD2D_i (DataOutWire),
        .ResultSrcD_i (resultSrcE_3),
        .regWriteD_i(regWriteWireE_3),
        .AD3D_i (AD3E_3),
        .JALD_i(JALE_3),
        .incPC4_i(incPC4),

        .ALUResultE_o (ALUResultE_4),
        .RD2E_o (DataE_4),
        .ResultSrcE_o (resultSrcE_4),
        .regWriteE_o(regWriteWireE_4),
        .AD3E_o(AD3E_4),
        .JALE_o (JALE_4),
        .incPC5_o(incPC5)
    );



    /////////////////////////////////////////////////////////////
    ///////////               FINAL STAGE             ///////////
    /////////////////////////////////////////////////////////////
    logic [DW-1:0]              incPC5;

    assign wd3Wire0 = resultSrcE_4 ? DataE_4 : ALUResultE_4;
    

endmodule
