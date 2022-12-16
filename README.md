# Single Cycle RV32I CPU

---

### PDF of sine.mem:

![sinepdf](/test/sinepdf.jpg)

### PDF of gaussian.mem:

![gaussianpdf](/test/gaussianpdf.jpg)

### PDF of triangle.mem:

![trianglepdf](/test/trianglepdf.jpg)

### PDF of noisy.mem:

![noisypdf](/test/noisypdf.jpg)

Please also find the ReferenceProgram.vcd trace file for the sine.mem pdf. 

---

## F1 Program:

Please find inside the evidence folder, 2 videos showing obvious but not that random delay and limited random delay (less than 3 seconds following F1 rules) with the F1 program. F1.vcd is also provided in this repo. The third video shows the working trigger. If you run the code it will wait for the trigger every time after one sequence is finished and the delay of the lights to turn off will be random, always less than 3 seconds.

---
# Testing instructions (same as for VERSION-3)

## 1. Clone repo and configure _vbuddy.cfg_ file

I will not explain how to do this :)

## 2. Execute shell script 

This branch has been configured for testing both the **F1** and **PDF** programs in the **Single Cycle** processor. To test the **F1** program, please run the following shell script:
```bash
$ ./f1.sh
```
And push the trigger to start it. This will run for a maximum of 2000 cycles. Please note that trigger is mapped to the register `t0`, within the register file. 

Or likewise for the pdf distribution calculation,
```bash
$ ./pdf.sh
```
Please note that there is one test-bench, but the shell scripts will configure it accordingly. 

>  When testing the PDF function, the default dataset is the gaussian one. To change this, please go to ram.sv >  line 18 and change it manually. 

> The assembly code that is run is provided in `f1.txt` and `pdf.s`, but these are not directly linked to the shell scripts. Therefore, if you wish to run alternate code then the `pdf.mem` and `f1.mem` files need to be changed manually, apologies for this. 

