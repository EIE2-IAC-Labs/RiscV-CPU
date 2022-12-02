#1/bin/sh

# set -e

rm -rf obj_dir 
rm -f top.vcd
verilator -Wall --cc --trace top.sv --exe top_tb.cpp
make -j -C obj_dir/ -f Vtop.mk Vtop
obj_dir/Vtop
