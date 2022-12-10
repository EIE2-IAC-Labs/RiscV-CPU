rm -rf obj_dir
rm -f ram.vcd
verilator -Wall --cc --trace ram.sv --exe test.cpp
make -j -C obj_dir/ -f Vram.mk Vram
obj_dir/Vram 
