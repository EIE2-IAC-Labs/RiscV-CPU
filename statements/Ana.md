### Introduction

I was working on the memory part of the CPU, I wrote few versions for the assembly code and worked together with my teammates on the pipelining and the cache memory. So, I will describe my work in the following 4 parts:

#### 1.[Memory](#Memory)
#### 2.[Pipelining](#pipelining)
#### 3.[Assembly](#Assembly)
#### 4.[Cache](#cache)

#### * [Mistakes](#here)

#### * [Learned](#here)

#### * [Future work](#here)

<div id="Memory"/>

## MEMORY

---

All the files are in the memory branch.
#### 1.[The ROM](#TheROM)
#### 2.[The RAM](#TheRAM)

<div id="TheROM"/>

### The ROM

When I started to work on the rom module I had a pretty clear idea of what I needed to do because of the previous knowledge from the lectures. The only thing I wasn't sure about was whether I needed to build a big or a little endian addressed ROM, so I made a big endian version first [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/ab0584d936815ced67513e0471cc655dd1513a8a#) and I decided to change it to little endian later as advised by the teaching assistants [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/5d1bf78f938858cf952d8cc6675ea532f94f5fc0). Initially, I have experimented with different ranges of memory and offsets of the address multiple times because I didn’t know how the file with the reference assembly code will be written. 

#### Testing:

Tested by using `testbench_rom.cpp.` The data was read from `instructions.mem` from the memory branch.

<div id="TheRAM"/>

### The RAM

The RAM was more challenging than the simple ROM. First, I built a RAM `ram.sv`[link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/blob/memory/ram/ram.sv) that was able to perform LW, LB, SW and  SB, because we tought that we will need these instructions only. I didn’t find the first version good because the sign extension was done in the RAM. Also, I wanted to make sure that there is no such memory instruction that couldn’t be performed by our memory block. So I started over again from scratch. I divided the memory in three modules:

* `ram_i.sv`, the module that prepares the data to be stored (like moving the byte to the correct part of the word), 

* `ramnew.sv` is the new ram that stores and loads just words and 

* `ram_o.sv`, the module that outputs the information in the needed version (ex. signed or unsigned).

I faced a lot of dilemmas like loading a half word at address a, my opinion was that I need to store the halfword at the first half of the corresponding word in the RAM with a[31:2, {2b’0}] or second half  depending on a[1]. After I finished, I was advised that actually the first half of the halfword needs to be stored at a and the second half at a+1 in this case if a[1:0]= 11 means that the second half needs to be stored in the next word in the RAM meaning that I needed to make significant number of changes and implement completely different logic. After attempting to implement the new logic I discussesed with the teaching assistants and we concluded that the initial logic was correct, so I didn’t commit any of the new changes and went back to the last commit followed by some minor changes [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/88608017f793ac5570fb26ced41267238975c989).  

![ram_scheme](/statements/images/ram_scheme.jpeg)

#### Testing:

I tested the first version `ram.sv` **(not in use)** with `testbench_ram.cpp` and `test.cpp` (there is nearly no difference between these two files)  by setting variety of inputs and analysing the outputs. The data was read from data.mem. When used within the whole CPU no errors were found in this module.

I tested the new ram modules all together by using `ram_top.sv` with `ram_new.cpp` by setting variety of inputs and analysing the outputs. The data was read from data.mem. When used within the whole CPU no errors were found in these modules.
Examples:
[link1](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/0903a18fb381f8cb6a1901bdc9517082ad1c53ce)
[link2](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/b3bf6ce5083374e8fb42fae290d7fbf0cf64fcd5)
[link3](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/64625ed2e535f99a22c64773ca08de911ed00138)




<div id="pipelining"/>

## PIPELINING

---


In the pipelining I took part by drawing the scheme for verification and debugging of the pipelining, and by making the changes in the pipelining files for the new memory. The scheme was used for verifying and debugging the new pipelining modules and other changes needed for the pipelining. For drawing the scheme, I was mainly following the scheme from the notes, but additionaly, I was referring to the control module which gives all the control signals and the other modules inputs and outputs to see which signals need to reach which stages. 
#### 1.[Scheme](#Scheme)
#### 2.[Changes](#Changes)

<div id="Scheme"/>

### Scheme


![pipeliningscheme](/statements/images/pipelining_scheme.jpeg)

<div id="Changes"/>

### Changes 

I did the adaptations for the new RAM in the execute register, the decode register and the top file
[Link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/6d55adb8e66d31b829eb99e8d527203c111f5ec8)
The memory register was already passing the result from the memory, so no change was needed.

Changed from posedge to negedge:
[Link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/f9b254eae191aa12ac51f9d4bc6322b5459c005d)


<div id="Assembly"/>

## ASSEMBLY

---

I wrote the assembly code for formula one lights (single cycle version). I started by following the F1 rule: the lights turn on one by one with 1 second delay and all the lights turn off after random delay. I came up with 4 different ideas for generating a random number and chose the best one at the end. Firstly, I used NOP instructions to make the delay but later I came up with the idea to use jump instructions. The assembly codes and the explanations are in the memory branch.

First attempt

The random number is generated from `random_number.cpp` and it is stored in the RAM. More explanation is provided in the files `random_number.cpp` and `assembly.txt`.

Second attempt

The random numbers are generated with the code and don't repeat. The delay is much tidier and memory efficient. See `assembly1.txt` for more information.

3rd version of the random number generator

The random numbers are generated with the code by left shifting the previous random number and putting the XORed 5th and 6th bit as last bit. See `assembly1.txt` for more information. The logic is similar to lab 3. Since the formula 1 delay is never more than 3 seconds it’s easy to limit the delay with 6’b111111 = 63 cycles which is very close to 3 seconds. `f1final.mem` contains the final program with no limit which makes the delay not that random but obvious. `f1final_limited.mem` has limit of 63 cycles which is a little bit less than 3 sec(following the f1 rules) and gives random delay within the range 0-63 cycles. The trigger is added in `f1final_limited_trigger.mem` which is the final version we used.

#### Testing

When the program couldn't exit a loop:
![GTK1_pic](/statements/images/GTKcode1.png)
When the jump instruction was not jumping:
![GTK2_pic](/statements/images/GTKcode2.png)

##### The video with `f1final.mem`:
![video_obvious](/statements/images/obvious_delay_compressed.mp4)
##### The video with `f1final_limited.mem`:
![limited_video](/statements/images/limited_delay_compressed.mp4)
##### The video with `f1final_limited_trigger.mem`:
![triggervideo](/statements/images/trigger_compressed.mp4)

4th version of the random number generator

The random numbers are generated with the code by storing the 4th and 3rd byte and XORing them. The XORed byte is added to the previously left shifted number by one byte. See `assembly1.txt` for more information.  (max 2^33-1)



<div id="cache"/>

## CACHE

---

While Nick and Ahmed were improving the pipelining, Benedict and I started working on the cache. 

*	I wrote the spatial locality cache module `cache.sv` and it’s testbench `cache.cpp` [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/tree/memory/cache) We wanted to make at least one working cache so Benedict and I decided to focus on the 2 way set associative Cache and direct mapped cache.
* 	Converted the direct mapped cache in one data structure [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/a7382bfdae0af8950fe2fe9da8037004d53b6e34).
* 	After I practised the 2D array in the direct mapped cache I converted the 2 way set associative Cache too [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/b800bb891458d778b354efbf7e7322f7d303e519). After that me and Ben tried to improve it again [link](https://github.com/EIE2-IAC-Labs/iac-riscv-cw-14/commit/299326ce8f2d01524dac012671e01c5e4714d895).

#### I tested the 2 way set associative cache after being converted to one data structure:

![GTKcache](/statements/images/cacheGTK.png)

<div id="here"/>

### Learned

By doing this project I became better at writing codes in System Verilog and became quicker at fixing the warnings and errors. I learned how to use 2D arrays when I was working on the cache. I improved my debugging skills by using GTKwave and outputs from the test bench like `cout` and `display`. I had no previous experience with Github. By doing this project I learned how git works and how to use it. But the most important thing is that now I fully understand how a pipelined RISC-V CPU works.

### Mistakes

The first time I used the .ignore file I did a mistake and now I can't get rid of of some unnecessary files. I have previously mentioned some other mistakes. 

### Future work

We built the cache memory modules but didn't manged to debug the new pipelined CPU with cache on time, so that would be the first thing I would do. After that I would follow the recommendations from the project brief like:

* Adding Multi-Cycle Integer Multiply/Divide Instructions since multiplication and division are frequently used in daily life
* Adding Wishbone Bus interface

