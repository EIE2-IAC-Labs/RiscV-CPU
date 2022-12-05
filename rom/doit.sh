rm -rf obj_dir
rm -f rom.vcd
verilator -Wall --cc --trace rom.sv --exe testbench_rom.cpp
make -j -C obj_dir/ -f Vrom.mk Vrom
obj_dir/Vrom 
