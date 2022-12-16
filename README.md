
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

#### Test Program Sketch:

![Test Program Sketch](img/TestProgram.png?raw=true "Test Program Sketch")

##### Updated to Test Overwrite:

![Test Program Sketch Overwrite](img/OverWriteTestSketch.png?raw=true "Test Program Sketch with Overwrite")


#### Test Cases in C++

![Test Cases C++](img/TestCases.png?raw=true "Test Cases C++")

##### Updated to Test Overwrite:

![Test Cases C++ Overwrite](img/OverwriteTestingC++.png?raw=true "Test Cases C++ with Overwrite")


### direct_mapped_cache

![GTKWave Output](img/GTKDirectMappedCache.png?raw=true "GTKWave output of functioning Cache")

##### Updated to Test Overwrite:

![GTKWave Output](img/OverwriteDirectMappedCache.png?raw=true "GTKWave output of functioning Cache with Overwrite")


### two_way_associative_cache

![GTKWave Output](img/GTKTwoWayCache.png?raw=true "GTKWave output of functioning Cache")

##### Updated to Test Overwrite:

![GTKWave Output](img/Overwrite2Way.png?raw=true "GTKWave output of functioning Cache with Overwrite")
