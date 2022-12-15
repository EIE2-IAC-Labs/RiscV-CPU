# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny
## Component Written by Benedict Short, merged from a non-empty main at the start

### Input
- clk
- AD1_i
- AD2_i
- AD3_i
- WE3_i
- WD3_i
- TRIGGER_i

### Output

- RD1_o
- RD2_o
- a0_o

### Important Details:
When trigger active, register t0 automatically overwrite to a value of 1.
Register x0 is protected (read only).
Register file tested and verified to be correct using GTKWave in the top-file.
