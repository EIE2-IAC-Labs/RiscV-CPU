# Basic Control Unit

Current worksplit:
Ben - ALU and sign extend
Ahmed - Control Unit and linking in top
Ana - Memory and assembly code F1 program
Nik - Control Unit and assembly code F1 program

---
### CURRENTLY WORKING ON:

- [x] Create Basic Skeleton
- [ ] Fill in R-Type Instructions
- [ ] Fill in I-Type Load instructions
- [ ] Fill in I-Type Bitwise instructions
- [ ] Fill in S-Type instructions
- [ ] Fill in B-Type instructions
- [ ] Miscellaneous instructions at the bottom (probably not required but might do anyway. These might require more work.)

---

### Inputs:

* `eq_i` : the eq flag from the ALU, 1 bit
* `instr_i` : 32-bit current instruction for decoding

### Outputs:
* `regWrite_en_o` : 1 bit register write enable
* `ALUctrl_o` : ALU control signal, 4 bits, previously was 3
* `ALUsrc_o` : Selects between regOp and ImmOp
* `IMMctrl_o` : Sign extension control
* `PCsrc_o` : Selects between branching and incr pc
* `ADDRctrl_o` : 1 Bit, selects between word and byte addressing. 

