#cleanup
rm -rf obj_dir

verilator -Wall --cc control.sv --exe control_tb.cpp

make -j -C obj_dir/ -f Vcontrol.mk Vcontrol

obj_dir/Vcontrol
