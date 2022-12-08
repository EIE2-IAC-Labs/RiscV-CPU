# Basic Control Unit
##### Nik Lewis

---
### CURRENTLY WORKING ON:

- [x] Create Basic Skeleton
- [x] Fill in R-Type Instructions
- [x] Fill in I-Type Load instructions
- [x] Fill in I-Type Bitwise instructions
- [x] Fill in S-Type instructions
- [x] Fill in B-Type instructions
- [x] Create testbench and doit.sh file
- [x] Jump and Link Instructions

---

### Inputs:

* `op_i` : 7-bit opcode for decoding
* `funct3_i` : funct3, 3 bits used for decoding
* `funct7bit_i` : additional funct7 bit used for decoding

### Outputs:
* `regWrite_en_o` : 1 bit register write enable
* `ALUctrl_o` : ALU control signal, 4 bits, previously was 3
* `ALUsrc_o` : Selects between regOp and ImmOp
* `immSrc_o` : Sign extension control, 3 bits
* `BRANCHsrc_o` : Selects between branching and incr pc
* `memWrite_en_o` : Enables writing to RAM
* `ResultSrc_o` : toggles between using ALUResult and RAM output for WD3
* `memType_o` : Address type for the RAM
* `memSign_o` : Determines whether signed or unsigned load instruction
* `jal_o` : overrides ONLY WD3 to implement jump and link functionality
* `jalr_o` : overrides both WD3 AND PCbranch to load register + offset into PC.
 

---

## Design Decisions:

* Added an extra bit to ALUctrl (was 3, now 4) in order to account for extra instructions.
> This was less of a creative decision and more of a necessity to allow all instructions to be represented.
* Not including any upper immediate instructions.
* Decided to do branches inside ALU by passing funct3 into it. Alternative was to decode the branch instructions in the control, but it would still require passing a 3-bit control signal to the ALU which is redundant.

### Testbench usage:

Testbench iterates over all implemented instructions, all inputs + outputs displayed using cout so no need for vbuddy. 
