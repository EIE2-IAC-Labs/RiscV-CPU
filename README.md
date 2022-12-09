# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
## Components Written by Benedict Short

# DO NOT MERGE, work in progress


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
| addrSelectD_i | addrSelectE_o |
| branchSrcD_i | branchSrcE_o |
| ALUctrlD_i | ALUctrlE_o |
| JALRD_i | JALRE_o |
| PCD_i | PCE_o |
| RD1D_i | RD1E_o |
| SrcBD_i | SrcBE_o |
| RD2D_i | RD2E_o |
| ImmExtD_i | ImmExtE_o |
| JALD_i | JALE_o |



### execute_reg_file
| Input | Output |
| --- | --- |
| resultSRCD_i | resultSRCE_o |
| memWriteD_i | memWriteE_o |
| addrSelectD_i | addrSelectE_o |
| ALUresultD_i | ALUresultE_o |
| RD2D_i | RD2E_o |

### memory_reg_file

| Input | Output |
| --- | --- |
| ALUResultD_i | ALUResultE_o |
| RD2D_i | RD2E_o |
| ResultSrcD_i | ResultSrcE_o |




### Important Details:

- [x] Implement each reg file
- [x] Check signals that cut over different sections
- [ ] Find Bitwidths of each input/output
- [ ] is reg_file correct name for datastructure
- [x] rename inputs and outputs according to actual CPU
