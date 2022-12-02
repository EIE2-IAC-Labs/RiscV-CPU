# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
- [ ]  ALU ctrl codes
- [ ]  outline what operations we need for the first version of the CPU
- [ ]  Come up with input, output
- [ ]  come up with surround logic that drives the ALU


To start with the project am doing the follow:
- [ ] register file
- [ ] mux going into SrcB
- [ ] check that EXTEND works in all cases
- [ ] check the part of the cycle where read/write occurs is correct for the register file
- [ ] come up ALU control
- [ ] Write testbench for Regfile, ALU, Extend for local testing


### Input

- SrcA_i
- SrcB_i
- ALUctrl_i

### Output

- ALUResult_o
- Zero_o

ALUctrl_i:
![Alt text](images/ALUctrl.png?raw=true "ALUctrl")
