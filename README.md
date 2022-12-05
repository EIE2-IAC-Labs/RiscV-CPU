# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
- [x]  ALU ctrl codes
- [ ]  outline what operations we need for the first version of the CPU
- [x]  Come up with input, output
- [ ]  come up with surround logic that drives the ALU


To start with the project am doing the follow:
- [x] register file
- [ ] mux going into SrcB
- [ ] check that EXTEND works in all cases
- [ ] check the part of the cycle where read/write occurs is correct for the register file
- [x] come up ALU control
- [x] Write testbench for ALU
- [ ] Write testbench for Extend 
- [ ] Write testbench for Register 

### Input

- SrcA_i
- SrcB_i
- ALUctrl_i
- BranchCtrl_i

### Output

- ALUResult_o
- Zero_o

Note: SLT outputs 1 if A < B, 0 otherwise. //CHECK CORRECT

| ALUctrl | operation | Fully Tested? |
| --- | --- | --- |
| 0000 | add | y |
| 0001 | sub | y |
| 0010 | bitwise and | y |
| 0011 | bitwise or | y |
| 0100 | xor | y |
| 0101 | SLT | y |
| 0110 | ULT | y |
| 0111 | SRL | y |
| 1000 | SLL | y |
| 1001 | SRA | y |
| 1010 | SLA | y |
| 1111 | Generic Load/Store | y |


| BranchCtrl | operation | Fully Tested? |
| --- | --- | --- |
| 000 | Equal | y |
| 001 | Not Equal | y |
| 010 | < | y |
| 011 | >= | y |
| 100 | < unsigned | y |
| 101 | >= unsigned | y |


TO ADD:
- [x] bitwise shift left
- [x] bitwise shift right
- [x] Implement Zero_o logic
- [x] Implement SRA and SLA
- [x] implement Xor
- [x] implement branch logic
- [ ] check the overlap between ALUctrl and branchctrl
