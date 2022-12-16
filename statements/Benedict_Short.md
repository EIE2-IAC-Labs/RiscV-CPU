# Personal Statement - Benedict Short:


# I worked on the following components:



### ******************************************Used in Final Project******************************************

-----


- ALU ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/9c3c2ad206729ce93d93b4a6f9721499c17859d6))
- Sign Extend ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/a83f6df37b37a67f2618dafdb002c7759cd09b65))
- Register File ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/fbc664735a7086b4cc8a226dcb58a162f261879e))
- Pipelining Registers (all four) ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/8c28c049dcc600c6b9c44c4b03577ac5279d2c71))
- Pipelined Top-file ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/c1f7ad8b7066b7cc5ab9fd0b341f2d6caa9ecab8/top.sv))



### ****Worked on and Debugged, but not implemented:****

-----

- direct_mapped_cache ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/96a65428efdab64c67847c99ba9f7c0c0b1ceef3/direct_mapped_cache.sv), in cache branch)
- two_way_associative_cache ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/96a65428efdab64c67847c99ba9f7c0c0b1ceef3/two_way_associative_cache.sv), in cache branch)
- Cache Top-File ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/748c79b77696a3e5942a1c10dfa9600bfc9c8b53/top.sv), in cache-pipelining-playground branch)


# Explanation of work and Reflection

---

I wrote the ALU, Sign Extend, Register File and the Pipelining Registers and ensured that each component was tested with a test-bench and GTKWave ([example testbench](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/57d934c001c7dc2e352b4107524a48f96c0dfd0c/ALU_tb.cpp) - 1) before allowing the components to be merged. I also came up with the initial scheme by which to split the CPU into its separate pipelines. The evidence for this is linked in the component section. This section in particular reinforced my SystemVerilog skills, my understanding of the function of the individual core components of a RISC-V CPU and my ability to analyse the RV32I documentation to understand what each module needs to contain. 

### ********ALU, Register File and Sign Extend:********

-----

There are no ‘set’ ALU instructions to implement. Instead I needed to analyse the Instruction Set and work out what type of instructions the processor would require to function correctly. The following commit shows me adding new functionality (Signed Less Than) to ALU as the number of instructions supported by the CPU was expanded ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/5df411bf2577158a17063475d5ca581c1b75c140) - 2), which was then tested and fixed accordingly in later commits, such as in this one ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/583b7194fc3a339f3d5d8ab2e8ee801a32ded487) - 3). This function was later simplified in this commit ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/ac947c6af1baca64fbffbaf8802fa3818d9b032c) - 4). The same was done with the branch functionality, with me introducing JAL and JALR into the branch logic in the following commit ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/374ef6e617c396ee9108c29b0837f8187235bccc) - 5). The Register file was designed and then later modified with the introduction of read-only protection on x0, as per the specification, in the following commit ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/90142baea7e55ca33bc4fa09f20e8da781e482b6) - 6) and was debugged and corrected in the following commit ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/b9fe63291a632db5b4879c04be311d1da0ac57d0) - 7). The Sign Extend block also required listing the possible combinations of inputs to extend and writing a scheme ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/a83f6df37b37a67f2618dafdb002c7759cd09b65#readme) - 8) that would the control to extend accordingly ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/a83f6df37b37a67f2618dafdb002c7759cd09b65/extend.sv) - 9). I worked with Ahmed to ensure that the bits were being extended in the correct format.

### **********************Pipelining:**********************

-----

I wrote the Pipelining Registers ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/8c28c049dcc600c6b9c44c4b03577ac5279d2c71) - 10), came up with the stages to implement and split the top-file into its appropriate pipelining stages ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/6ae5fc18cee93446964ce3ad045b3ec334266605/top.sv) - 11). I then implemented all of the pipelining registers, while restructuring the file to allow for the stages and corresponding register files to be laid out logically for easier debugging. I then tested the arithmetic functionality of the pipelined CPU and made bug-fixes as required, with the file at this point in time shown in this [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/3fdee793342eb58524334bf9b30df2768d3b8d2b/top.sv) (12). From this point, I started to work with Nik to fully debug the pipelined CPU and continued to make changes to ensure the CPU fully worked, with an example shown in this commit [](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/cac18fe623ec26e5eca4c6bccd3f4279f1045904)([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/cac18fe623ec26e5eca4c6bccd3f4279f1045904) - 13) and to update the pipelined CPU in-line with changes made in the single-cycle development, like the write protection being introduced into the pipelined CPU in this [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/ec5f69b54184b0f475f56ded2c19071fb2627128) (14) and being updated in this [commit](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/1a23d21faf1c1aac70a5ed8facdb83c39aab47b3) (15). 

### ************Cache - Not used in Final CPU:************

-----

I also implemented multiple types of cache and tested them separately from the CPU accordingly ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/cache#readme) - 16). The aim was to integrate a write-through cache. While the standalone caches work, (direct_mapped_cache [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/750bde6b8d7c206d772e9cf135408d1172da3f3d/direct_mapped_cache.sv) (17) and two_way_associative_cache [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/750bde6b8d7c206d772e9cf135408d1172da3f3d/two_way_associative_cache.sv) (18)), I ran out of time debugging the integration and implementation into the top-file. In order to get the cached and pipelined CPU working, we would need to ‘freeze’ CPU at its pipelined stages and at the PC, to allow a cycle delay for the cache to be written to before reading the data required out of the cache. However, with more time we would be able to release a working cached and pipelined CPU, as it was only a case of implementing a scheme that successfully freezes the CPU for one cycle. The testing of the individual caches can be found in this readme ([link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/df081640c1d045bd836ade11acea0297a3761f54/README.md) - 19).

Overall, during development I ensured that any bugs found were fixed and design changes were implemented across all affected branches to ensure that the CPU development was kept up to date.

# Reflection

---

- While writing the ALU and Sign Extend modules, I improved my SystemVerilog skills and learnt more efficient methods of handling signed and unsigned numbers as well as concatenation within the language. This is demonstrated in this [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/57d934c001c7dc2e352b4107524a48f96c0dfd0c/ALU.sv) (20) on lines 18, 19, 37, 44, 100 and 103. I also learnt about testing using GTKWave to verify that the module works as intended and that it is important to write a comprehensive list of test-cases that test all possible combinations of inputs.
- During the implementation of pipelining and its registers, I learnt in much greater depth how a CPU is split up into the different pipelined stages and which control and data signals need to pass through each stage, which is something I have not had hands on experience with before.
- When converting the single-cycle CPU to pipelining, I also discovered the importance of paying attention to whether or not the clocked modules run on the positive edge or negative edge of the clock. Converting the negative edge to clock in the memory locations made logical sense as we first want to process our data before writing, but was not something that I had previously considered.
- I learnt lot about caches and their structure when writing the caches themselves and debugging within the top-file. This is an entirely new concept not introduced last year, making my understanding of the implementation particularly difficult. The first cache implemented, the direct_mapped_cache was simple enough to teach me about the basics of a cache-memory while also providing a stable foundation to implement the two_way_associative_cache.
- With the two_way_associative cache I learnt about schemes to ‘evict’ memory as required, and decided to use a scheme where the least memory is evicted. This can be seen in this [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/df081640c1d045bd836ade11acea0297a3761f54/two_way_associative_cache.sv) (21) where the ‘evict’ is updated accordingly at each read/write stage.
- I also learnt about the use of GitHub and README files to stay organised and split up development branches among a group. I did not have much previous experience with this.

# Special Design Decisions:

---

#### Fully Implemented:

-----
- The first special design decision was also to implement branch instructions within the ALU. These instructions would be processed at the same time as the ALU instructions, with more simple implementations of the branch logic using the ALU to test for specific conditions, such as Less Than. To simplify the top-level design and provide the option of using ALU hardware to calculate branch instruction conditions, I decided to keep this within the ALU block.
- Another special design decision was to split the pipelining into five sections using four registers: fetch, decode, execute and memory. This would provide a significant speed-up on silicon by reducing the number of cycles needed for an instruction to run, excluding jump and branch instructions. Four registers limit the performance hit (wasted clock cycles) taken due to branching and jumping without a hazard unit to predict branches and limit their effect. Long pipelines also significantly increase the likelihood of a data and control hazards, and with the lack of forwarding or a hazard unit, NOPs would need to be used accordingly instead, which would actually decrease the CPU’s performance.

#### Experimental Development:

-----
- We started the integration of the pipelined-cpu with a two-way-associative cache, as this reduces the miss-rate of the cache significantly by providing extra memory for each ‘set’ of eight memory instructions. The evict scheme used was to keep the most recently used memory stored and remove the older piece of memory. On silicon, this would provide a significant speedup as the RAM would use DRAM, which can take multiple read-cycles, along with the cache using expensive SRAM. This would allow the use of much cheaper DRAM to still provide a very high level of performance.

# Future Work


---

If given more time, I would have completed the integration of the two-way-associative cache. This would significantly increase the performance of the CPU if the CPU were implemented in Silicon and if the RAM were to be made with DRAM. Another improvement would be to modify the two-way-associative cache to utilise spatial locality, significantly decreasing the number of cycles to load large arrays of data by loading other sequential memory locations ahead of them in case they are used in subsequent instructions.

I would also implement forwarding and a hazard unit to decrease the likelihood of stalling a CPU due to Data and Control Hazards. Utilisation of branch prediction and forwarding would decrease the number of cycles wasted by a branch, jump instruction or data hazard by decreasing the number of NOPs needed in the program, aswell as decreasing the size of the programs. This would also allow us to manage more pipeline stages easier, leading to more performance benefits if the design were to be implemented on silicon. The other benefit would be to allow larger programs to be stored in the memory of the 32-bit processor.

The implementation of multiply, divide and an FPU to handle floats would make the CPU more usable for real-world applications. The expansion to the 64-bit ISA would allow more addressable memory, however this is unrealistic requirement for the simple test-programs written.

### **************************Commit Appendix**************************

| Link Label | Commit |
| --- | --- |
| 1 | 57d934c001c7dc2e352b4107524a48f96c0dfd0c - ALU_tb.cpp |
| 2 | 5df411bf2577158a17063475d5ca581c1b75c140 |
| 3 | 583b7194fc3a339f3d5d8ab2e8ee801a32ded487 |
| 4 | ac947c6af1baca64fbffbaf8802fa3818d9b032c |
| 5 | 374ef6e617c396ee9108c29b0837f8187235bccc |
| 6 | 90142baea7e55ca33bc4fa09f20e8da781e482b6 |
| 7 | b9fe63291a632db5b4879c04be311d1da0ac57d0 |
| 8 | a83f6df37b37a67f2618dafdb002c7759cd09b65 - branch at this point in time |
| 9 | a83f6df37b37a67f2618dafdb002c7759cd09b65 - extend.sv |
| 10 | 8c28c049dcc600c6b9c44c4b03577ac5279d2c71 |
| 11 | 6ae5fc18cee93446964ce3ad045b3ec334266605 - top.sv |
| 12 | 3fdee793342eb58524334bf9b30df2768d3b8d2b - top.sv |
| 13 | cac18fe623ec26e5eca4c6bccd3f4279f1045904 |
| 14 | ec5f69b54184b0f475f56ded2c19071fb2627128 |
| 15 | 1a23d21faf1c1aac70a5ed8facdb83c39aab47b3 |
| 16 | Cache branch readme |
| 17 | 750bde6b8d7c206d772e9cf135408d1172da3f3d - direct_mapped_cache.sv |
| 18 | 750bde6b8d7c206d772e9cf135408d1172da3f3d - two_way_associative_cache.sv |
| 19 | df081640c1d045bd836ade11acea0297a3761f54 - readme.md |
| 20 | 57d934c001c7dc2e352b4107524a48f96c0dfd0c - ALU.sv |
| 21 | df081640c1d045bd836ade11acea0297a3761f54 - two_way_associative_cache.sv |
