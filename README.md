# Single Cycle RV32I CPU

---

### PDF of sine.mem:

![sinepdf](/images/sinepdf.jpg)

Please also find the ReferenceProgram.vcd trace file for the sine.mem pdf. 

### Instructions not implemented:
SH, LH, LHU. 

### pdf.s changes made
---
In order for the program to run correctly, a few changes needed to be made to the instructions. 

#### Decrement instruction corrected
 
```assembly
ADDI a1, zero, -1 -----> ADDI a1, a1, -1
```
Otherwise this is not a decrement but setting `a1` to a constant value of -1.

#### RET and JAL instructions corrected in machine code

This may have been due to misuse of the hexfile generator but for some reason the RET instruction was encoded as `67 80 00 00` instead of
`E7 80 00 00` which resulted in the next `PC` value being stored in `zero` instead of `ra`, which caused a lot of problems downstream. Similar problem with the JAL instructions.

 


