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
| 0101 | SLT | y |
| 0110 | ULT | y |

TO ADD:
- [] bitwise shift left
- [] bitwise shift right
