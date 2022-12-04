# Basic Control Unit
##### Nik Lewis

---
### CURRENTLY WORKING ON:

- [x] Create Basic Skeleton
- [x] Fill in R-Type Instructions
- [x] Fill in I-Type Load instructions
- [ ] Fill in I-Type Bitwise instructions
- [ ] Fill in S-Type instructions
- [ ] Fill in B-Type instructions
- [ ] Miscellaneous instructions at the bottom (probably not required but might do anyway. These might require more work.)

---

### Inputs:

* `zero_i` : the zero flag from the ALU, 1 bit  [ CURRENTLY CONSIDERING REMOVING ]
* `op_i` : 7-bit opcode for decoding
* `funct3_i` : funct3, 3 bits used for decoding
* `funct7bit_i` : additional funct7 bit used for decoding

### Outputs:
* `regWrite_en_o` : 1 bit register write enable
* `ALUctrl_o` : ALU control signal, 4 bits, previously was 3
* `ALUsrc_o` : Selects between regOp and ImmOp
* `immSrc_o` : Sign extension control, 3 bits
* `BRANCHsrc_o` : Selects between branching and incr pc
* `addrSelect_o` : 1 Bit, selects between word and byte addressing. 

---

## Design Decisions:

* Added an extra bit to ALUctrl (was 3, now 4) in order to account for extra instructions.
> This was less of a creative decision and more of a necessity to allow all instructions to be represented.
* Not including `lh`, `lbu`, `lhu`, `sh` instructions.
* BranchSrc, ALUsrc and regWrite_en are driven by single assign statements, easier to debug. 
* Currently deciding whether to do branching as part of the control or as part of the ALU. (elaborate)
