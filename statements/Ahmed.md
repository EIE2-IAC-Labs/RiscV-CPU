# Ahmed Elkouny's Personal Statement
#### CID: 01902185, Github username: Elkouny

---

# Creating the [top.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/top.sv) file

First, Nik and I designed the overall architecture of the CPU, including the registers, the control unit, the instruction and data memory, and the ALU. 

![Single Cycle Cpu Design (Drawn by Nik)](https://i.postimg.cc/cLY7tbgH/image.png)

Using the schematic drawn by Nik I wired all the componented and added the required multiplexers to create the [top.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/top.sv) file.([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/e3098c8abc5a81ea15247dd7d48028411bd814fa)) 


## Changes compared to the orginal schematic

![Changes highlighted](https://i.postimg.cc/DzHYVypz/Changes.jpg)

 1. A multiplexer with `JAL` as the selector bit. When high it will store our current
    instruction   adress into  [regfile.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/register_file.sv) . This allows us to return
    to that instruction when a `JALR` instruction is called. ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/9808aba0f717b948281634143a10df9e52e390dd)) 
    
 2. Another multiplexer with `JALR` as the selector bit. When high it will load the ALU
        result value into the PC. This is because we will have the
        instruction adress from the [regfile.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/register_file.sv) come out of
        `rd2`-->`srcB`-->`AluResult`. ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/db4b085839e2e1bcfa5f8dead682b64c299086f9))
    
 3. A third and final multiplexer with `BranchSrc` as the selector bit was added for the branch instructions. `BranchSrc` would be high if a branch instruction was called and the comparison of `SrcA` and `SrcB` was done in the ALU and outputed from the ALU `Branch` Port. For example if we had a `BEQ rd1, rd2, label` instruction. `BranchSrc` Would be `1'b1` and the boolean output of `rd1==rd2` would be outputed from the ALU `branch` port.
 4.  `addrselect` was a control signal created for all the load and store instructions.

## Testing

Making sure the single cycle cpu was fully working was a top prioity as we intended to do the pipelining and cache extension tasks which will be built on top of this CPU. Although each component was tested individually we needed to make sure that the components together worked

## ALU testing

I designed an ALU test program ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/ae9de208d73fa38c2c9744e9ca19ca056ae1730d)) and created a truth table for it ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/f4486b7eb9a7a75b2ad4ab1d8024856030ec5515#diff-a09f9c2cd36fdf82048f4706e1efc944498122e8ccd08342e3f0ad6fdef86989)). It worked on the first try ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/9fdeb1b49472db6421cde7dd77c648cd6435e30b)) 

[ALU test Folder Documentation](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/VERSION-2-SINGLE-CYCLE/ALUTests)


## Branch Testing

Once again I designed a branch test program and ran it. ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/VERSION-2-SINGLE-CYCLE/BranchTests)) 
Test all branches by setting a flag in a3
logic:

a3 == 0 all branches work 

a3 == 1 beq doesn't work (test stopped and bne,blt,bge,bltu,bgeu not tested)

a3 == 2 beq works bne doesn't work (test stopped and blt,bge,bltu,bgeu not tested)

a3 == 3 beq works bne works blt doesn't work (test stopped and bge,bltu,bgeu not tested)

a3 == 4 beq works bne works blt works bge doesn't work (test stopped and bltu,bgeu not tested)

a3 == 5 beq works bne works blt works bge works bltu doesn't work (test stopped and bgeu not tested)

a3 == 6 beq works bne works blt works bge works bltu works and bgeu doesn't work

When running the test the branch instructions were not working this was expected as branch instructions depend on several components such as the [extend.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/extend.sv), [alu.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/ALU.sv), and the [control.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/rtl/control.sv). The issue was with the signextend logic as it was only extending to 25 bits. I fixed this error ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/8e91b305c2deecb71d8813ed761df40f5664a466)). The other error was with the ALU logic for func3 which produced the branch output. This was fixed ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/caca639e937406466ec40a5be78be52b018855fd)) and the branches were now all fully working ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/1b23748ea2f1bb521afd160a820b1ea49d2973ce)).


## JAL and JALR Testing

To test JAL and JALR we used the [f1assembly.txt]https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-2-SINGLE-CYCLE/test/f1.txt).  The program however didn't work so me and Nik looked at the GTKWave and saw that the signextention wasn't working properly. After looking at the RISC-V isa we noticed that for JALR we need to add `Imm12` not `Imm20` to the PC ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/7b877d067427cc420918834914f75bd066d8b1dc))
After all this testing we ran a working F1 Program ! ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/b8d7325772fe518e631ce72a22a6cf0e188b0b3c))


# Pipelining

Contribution:
 - Overlooking the [top.sv](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/VERSION-3-PIPELINED/rtl/top.sv) file rewiring that Ben and Nik worked on with the addition of the registers for each block. 
   
 - Testing the pipelined CPU using the the previous    single cycle
   assembly code but added noops for register dependancies  that would
   have caused data hazards and noops for the start of subroutines that would have caused control hazards as we need to flush the code before the jump instruction ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/98da956e2a5c764276d555b533d8e796e2df4423))
   
 - Rewriting the the f1 program with noops. ([Commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/e437a59b672d612e43d66d5fe8e737fd576b3cea))
 - Extra: Created a python script that took the initial instruction memory and detected  all register dependency data hazards and produced a new instruction memory with noops added ([commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/documentation/noOp.py))
 
