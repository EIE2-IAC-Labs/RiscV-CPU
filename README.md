# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
## Components Written by Benedict Short

## Details:
We need 4 registers to divide the CPU into the 4 pipelined states:

### fetch_reg_file

| Input | Output |
| --- | --- |
| instrD_i | instrE_o |
| incPCD_i | incPCE_o |
| PCD_i | PCE_o |

### decode_reg_file
| Input | Output |
| --- | --- |
| resultSrcD_i | resultSrcE_o |
| memWriteD_i | memWriteE_o |
| memTypeWireD_i | memTypeWireE_o |
| AUIPCWireD_i | AUIPCWireE_o |
| branchSrcD_i | branchSrcE_o |
| ALUCtrlD_i | ALUCtrlE_o |
| JALRD_i | JALRE_o |
| PCD_i | PCE_o |
| RD1D_i | RD1E_o |
| SrcBD_i | SrcBE_o |
| RD2D_i | RD2E_o |
| ImmExtD_i | ImmExtE_o |
| funct3D_i | funct3E_o |
| memSignWireD_i | memSignWireE_o |
| regWriteD_i | regWriteE_o |
| AD3D_i | AD3E_o |
| JALD_i | JALE_o |
| incPC2_i | incPC3_o |


### execute_reg_file
| Input | Output |
| --- | --- |
| resultSRCD_i | resultSRCE_o |
| memWriteD_i | memWriteE_o |
| ALUresultD_i | ALUresultE_o |
| RD2D_i | RD2E_o |
| memTypeD_i | memTypeE_o |
| memSignD_i | memSignE_o |
| AUIPCD_i | AUIPCE_o |
| regWriteD_i | regWriteE_o |
| AD3D_i | AD3E_o |
| JALD_i | JALE_o |
| incPC3_i | incPC4_o |



### memory_reg_file

| Input | Output |
| --- | --- |
| ALUResultD_i | ALUResultE_o |
| RD2D_i | RD2E_o |
| ResultSrcD_i | ResultSrcE_o |
| regWriteD_i | regWriteE_o |
| AD3D_i | AD3E_o |
| JALD_i | JALE_o |
| incPC4_i | incPC5_o |
