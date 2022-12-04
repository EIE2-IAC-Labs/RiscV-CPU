# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny

## File Written By Benedict Short

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

- ImmSrc_i [1:0]
- Imm_i

### Output

- ImmExt_o


### Input Scheme:
| ImmSrc | instruction word bits into imm_i | bit size | Use Case | Implemented? | Fully Tested? |
| --- | --- | --- | --- | --- | --- |
| 000 | instruction[31:20] | [11:0] | I and S type | n | n |
| 001 | instruction[31:25], instruction[11:7] | [11:5],[4:0] | I and S type | n | n |
| 010 | instruction[31], instruction[7], instruction[30:25], instruction[4:1] | [12], [11], [10:5], [4:1] | branch offset | n | n |
| 011 | instruction[31:12] | [19:0] | U and I Type | n | n |
| 100 | instruction[31], instruction[19:12], instruction[11]instruction [30:21] | [20], [19:12], [11], [10:1] | U and I Type | n | n |


TODO:
- [ ] check if bit 1 from 0b10 goes to 0 (slide 20 L6)
- [x] decide schema and operations to implement
- [x] implement schema and operations
- [ ] test schema and operations


