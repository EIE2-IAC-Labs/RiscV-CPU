rm -rf obj_dir
rm -f ram.vcd
verilator -Wall --cc --trace ram.sv --exe testbench_ram.cpp
make -j -C obj_dir/ -f Vram.mk Vram
obj_dir/Vram 
