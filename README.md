
# Memory
##### Ana Dimoska

---
### RAM

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

The code written in `assembly.txt` is using r1 to store the value that turns on and turns off the lights. The next light is turned on after 24 cycles = 1 second. All lights go off after random number of cycles. The random number is generated from `random_number.cpp` and it is stored in the RAM. More explanation is provided in the files `random_number.cpp` and `assembly.txt`.
