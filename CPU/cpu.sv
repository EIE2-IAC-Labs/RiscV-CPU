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
    logic                 ALUsrc;
    logic [DW-1:0]       RD2Wire;
    logic [DW-1:0]    Aluop2Wire;
    logic             branchWire;
    logic [DW-1:0] ALUResultWire;

    logic [DW-1:0] InstructionWire;




endmodule