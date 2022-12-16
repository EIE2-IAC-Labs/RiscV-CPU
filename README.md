
# Group 14 IAC Coursework
##### Nik Lewis, Benedict Short, Ana Dimoska, Ahmed Elkouny

## File Written by Benedict Short

### Two Types of Cache:
- direct mapped cache
- two_way_associative cache

#### direct_mapped_cache

##### input:
- clk
- dataWord_i
- addressWord_i
- overwrite_i

##### output:
- dataWord_o
- hit_o

#### two_way_associative_cache

##### input:
- clk
- dataWord_i
- addressWord_i
- overwrite_i

##### output:
- dataWord_o
- hit_o

## Evidence

### direct_mapped_cache

### two_way_associative_cache

![Test Program Sketch](img/test_program.png?raw=true "Test Program Sketch")

![Test Cases C++](img/test_program.png?raw=true "Test Cases C++")

![GTKWave Output](img/test_program.png?raw=true "GTKWave output of functioning Cache")