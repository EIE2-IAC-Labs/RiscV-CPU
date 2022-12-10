# Memory and assembly code
##### Ana Dimoska

---
### RAM first version (not in use anymore)


#### Inputs, outputs and controls:

|inputs|outputs|
| --- | --- |
|clk_i|rd_o|
|write_en_i||
|AddrsCtrl_i||
|a_i||
|wd_i||

|AddrsCtrl_i|meaning|
| --- | --- |
|0|byte|
|1|word|

#### Testing:

|write_en_i|AddrsCtrl_i| tested |
| --- | --- | ---|
|0|0|yes|
|0|1|yes|
|1|0|yes|
|1|1|yes|

Done by using `testbench_ram.cpp`(different values for `wd_i`) and different versions of `data.mem`.

---

### RAM new version and its additional modules

The main module is `ramnew.sv` which is accompanied by `ram_i.sv`(i -> input) and `ram_o.sv`(o -> output)

#### Inputs, outputs and controls:

#### ram_i.sv

|controls|inputs|outputs|
| --- | --- | --- |
|memtype_i|rd_i|wd_o|
||wd_i||
||a_i||

#### ramnew.sv

|controls|inputs|outputs|
| --- | --- | --- |
|clk_i|a_i|rd_o|
|write_en_i|wd_i||

#### ram_i.sv

|controls|inputs|outputs|
| --- | --- | --- |
|memtype_i|rd_i| rd_o|
|memsign_i|a_i||

#### Wiring

ram_i:
    .memtype_i(memtype_i),
    .a_i(a_i),
    .rd_i(RDWire),
    .wd_i(wd_i),
    .wd_o(WDWire)

ramnew:
    .write_en_i(write_en_i),
    .clk_i(clk_i),
    .a_i(a_ii),
    .wd_i(WDWire),
    .rd_o(RDWire)

ram_o:
    .memtype_i(memtype_i),
    .memsign_i(memsign_i),
    .a_i(a_i),
    .rd_i(RDWire),
    .rd_o(rd_o)
    
`clk_i` -> 1 bit

`memtype_i` -> 2 bits

`memsign_i` -> 1 bit

`write_en_i` -> 1 bit

`wd_i` -> 32 bits

`a_i` -> 32 bits

`a_ii` -> 2 bits

`rd_o` -> 32 bits

`WDWire` -> 32 bits

`RDWire` -> 32 bits
    
#### Testing:

Done by using `ram_new.cpp`(different values for all the inputs and controls) and different versions of `data.mem`.




### R0M

#### Inputs, outputs and controls:

|inputs|outputs|
| --- | --- |
|a_i|rd_o|

`a_i`-> 12 bits

`rd_0`-> 32 bits

#### Testing:

Done by using `testbench_rom.cpp` and `instructions.mem`.



# Assembly code

---

#### First attempt

The code written in `assembly.txt` is using r1 to store the value that turns on and turns off the lights. The next light is turned on after 24 cycles = 1 second. All lights go off after random number of cycles. The random number is generated from `random_number.cpp` and it is stored in the RAM. More explanation is provided in the files `random_number.cpp` and `assembly.txt`.

#### Second attempt

The random numbers are generated with the code and don't repeat. The delay is much tidier and memory efficient. See `assembly1.txt` for more information.

#### 3rd version of the random number generator

The random numbers are generated with the code by left shifting the previous random number and putting the `XORed` `5th` and `6th` bit as last bit. See `assembly1.txt` for more information.

#### 4th version of the random number generator
The random numbers are generated with the code by storing the `4th` and `3rd` byte and `XORing` them. The XORed byte is added to the previously left shifted number by one byte. See `assembly1.txt` for more information.


