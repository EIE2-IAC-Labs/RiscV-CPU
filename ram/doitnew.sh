rm -rf obj_dir
rm -f ram_top.vcd
verilator -Wall --cc --trace ram_top.sv --exe ram_new.cpp
make -j -C obj_dir/ -f Vram_top.mk Vram_top
obj_dir/Vram_top
