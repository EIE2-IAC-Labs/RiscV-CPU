
# Formatting the testbench
sed -i 's/2000/1000000/' cpu_tb.cpp
sed -i 's/F1 Program/PDF Program/' cpu_tb.cpp
sed -i 's/pdfstartX/pdfstart\*\//' cpu_tb.cpp
sed -i 's/Ypdfend/\/\*pdfend/' cpu_tb.cpp
sed -i 's/f1start\*\//f1startX/' cpu_tb.cpp
sed -i 's/\/\*f1end/Yf1end/' cpu_tb.cpp

# Formatting instructions
sed -i 's/f1.mem/pdf.mem/' rtl/rom.sv

# Do it !!
./doit.sh
