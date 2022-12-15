
# Formatting the testbench
sed -i 's/1000000/2000/' cpu_tb.cpp
sed -i 's/PDF Program/F1 Program/' cpu_tb.cpp
sed -i 's/f1startX/f1start\*\//' cpu_tb.cpp
sed -i 's/Yf1end/\/\*f1end/' cpu_tb.cpp
sed -i 's/pdfstart\*\//pdfstartX/' cpu_tb.cpp
sed -i 's/\/\*pdfend/Ypdfend/' cpu_tb.cpp


# Formatting instructions
sed -i 's/pdf.mem/f1.mem/' rtl/rom.sv


# Do it!!!
./doit.sh
