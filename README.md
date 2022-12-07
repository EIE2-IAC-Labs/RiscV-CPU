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
- PCF_i
- PCPlus4D_i


#### decode_reg_file
##### Input:
- RegWriteD
- ResultSrcD
- MemWriteD
- JumpD
- BranchD
- ALUControlD
- ALUSrcD
- RD1
- RD2
- PCD
- RdD
- ImmExtD
- PCPlus4D

##### Output:
- RegWriteE
- ResultSrcE
- MemWriteE
- JumpE
- BranchE
- ALUControlE
- ALUSrcE
- RD1E
- RD2E
- PCE
- RdE
- ImmExtE
- PCPlus4E



#### execute_reg_file
##### Input:
- RegWriteE
- ResultSrcE
- MemWriteE
- ALUResult
- WriteDataE
- RdE
- PcPlus4E

##### Output:
- RegWriteM
- ResultSrcM
- MemWriteM
- ALUResultM
- WriteDataM
- RdM
- PCPlus4M

#### writeback_reg_file

##### Input:
- RegWriteM
- ResultSrcM
- ALUResultM
- RD
- RdM
- PCPlus4M

##### Output:
- RegWriteW
- ResultSrcW
- ALUResultMM
- ReadDataW
- RdW




### Important Details:

- [ ] Implement each reg file
- [ ] Check signals that cut over different sections
- [ ] Find Bitwidths of each input/output