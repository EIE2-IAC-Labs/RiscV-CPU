rm -rf obj_dir
rm -f cache.vcd
verilator -Wall --cc --trace cache.sv --exe cache.cpp
make -j -C obj_dir/ -f Vcache.mk Vcache
obj_dir/Vcache