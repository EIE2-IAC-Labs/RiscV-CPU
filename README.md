# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
## Component Written by Benedict Short

### Input

- SrcA_i
- SrcB_i
- ALUctrl_i
- BranchCtrl_i

### Output

- ALUResult_o
- Branch_o

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
| 1011 | JAL | y |
| 1100 | JALR | y |

| BranchCtrl | operation | Fully Tested? |
| --- | --- | --- |
| 000 | Equal | y |
| 001 | Not Equal | y |
| 100 | < | y |
| 101 | >= | y |
| 110 | < unsigned | y |
| 111 | >= unsigned | y |
