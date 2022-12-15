# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny

## File Written By Benedict Short 

### Input

- ImmSrc_i [2:0]
- Imm_i

### Output

- ImmExt_o


### Input Scheme:
| ImmSrc | instruction word bits into imm_i | Use Case | Implemented? | Fully Tested? |
| --- | --- | --- | --- | --- | --- |
| 000 | instruction[31:20] | I and S type | y | y |
| 001 | instruction[31:25], instruction[11:7] | I and S type | y | y |
| 010 | instruction[31], instruction[7], instruction[30:25], instruction[11:8] | branch offset | y | y |
| 011 | instruction[31:12] | U and I Type | y | y |
| 100 | instruction[31], instruction[19:12], instruction[20], instruction [30:21] | U and I Type | y | y |