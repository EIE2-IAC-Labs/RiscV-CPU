memory memory(
        .clk_i(clk),
        .write_en_i(memWriteE_3),
        .a_i(ALUResultE_3),
        .wd_i(RD2E_3),
        .rd_o(RamOutWire),
        .memtype_i(memTypeWireE_3),
        .memsign_i(memSignWireE_3)
    );
    