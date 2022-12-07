# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
## Components Written by Benedict Short

### Details:
We need 4 registers to divide the CPU into the 4 pipelined states:

#### fetch_reg_file

##### Input:
- RD_i
- PCF_i
- PCPlus4F_i
##### Output:
- InstrD_o
- PCD_o
- PCF_o
- PCPlus4D_o


#### decode_reg_file
##### Input:
- RegWriteD_i
- ResultSrcD_i
- MemWriteD_i
- JumpD_i
- BranchD_i
- ALUControlD_i
- ALUSrcD_i
- RD1_i
- RD2_i
- PCD_i
- RdD_i
- ImmExtD_i
- PCPlus4D_i

##### Output:
- RegWriteE_o
- ResultSrcE_o
- MemWriteE_o
- JumpE_o
- BranchE_o
- ALUControlE_o
- ALUSrcE_o
- RD1E_o
- RD2E_o
- PCE_o
- RdE_o
- ImmExtE_o
- PCPlus4E_o



#### execute_reg_file
##### Input:
- RegWriteE_i
- ResultSrcE_i
- MemWriteE_i
- ALUResult_i
- WriteDataE_i
- RdE_i
- PcPlus4E_i

##### Output:
- RegWriteM_o
- ResultSrcM_o
- MemWriteM_o
- ALUResultM_o
- WriteDataM_o
- RdM_o
- PCPlus4M_o

#### writeback_reg_file

##### Input:
- RegWriteM_i
- ResultSrcM_i
- ALUResultM_i
- RD_i
- RdM_i
- PCPlus4M_i

##### Output:
- RegWriteW_o
- ResultSrcW_o
- ALUResultMM_o
- ReadDataW_o
- RdW_o




### Important Details:

- [ ] Implement each reg file
- [ ] Check signals that cut over different sections
- [ ] Find Bitwidths of each input/output