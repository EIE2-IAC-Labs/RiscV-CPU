# Group 14 Pipelined RV32I

#### If desired, please skip ahead to:
1. [Repo Structure Explanation](#structure)
2. [Evidence](#evidence)
3.  [Test instructions](#test)

---
## Quick summary

The result of this coursework is two CPUs: a pipelined, and a single-cycle CPU. Here you will find a fully pipelined RV32I CPU. For the Single-Cycle version, please see the `VERSION-2-SINGLE-CYCLE` branch. Caching was attempted, but due to time constraints we did not manage to fully implement it. You can, however, find evidence of this work on the repository in the corresponding branches ([see below](#structure)). 

## Group Details

All Personal Statements are Located in the 'Documentation' Branch.

| Name           | CID      | GitHub   | Email                     | Link to Personal Statement|
|----------------|----------|----------|---------------------------|--------------|
| Nik Lewis      | 02031260 | **nlewxxs**  | nl621@imperial.ac.uk   &nbsp; &nbsp; &nbsp; &nbsp;   | [Nik's Statement](statements/Nik.md)
| Ana Dimoska    | 02061746 | **ADimoska** | ad2121@imperial.ac.uk     | [Ana's Statement](statements/Ana.md)
| Benedict Short | 02019656 | **BenShort** | benedictnjshort@gmail.com | [Benedict's Statement](statements/Benedict_Short.md)
| Ahmed Elkouny  | 01902185 | **elkouny**  | ahmedelkouny@hotmail.com  | [Ahmed's Statement](statements/Ahmed.md)

---

## Work Split 

| File Name     |  Ahmed  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  | Ben &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Nik  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Ana   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;         |
|:-------------|:----------------:|:----------:|:------------:|:--------------:|
| ALU.sv |  | x | |
| control.sv |p | | x |
| ram_i.sv | | | |x
| ram_o.sv | | | |x
| ram.sv | | | |x
| rom.sv |p | | |x
| register_file.sv | |x | |
| memory.sv | | | |x
| extend.sv |x |x | |
| fetch_reg_file.sv | |x | |
| decode_reg_file.sv | |x | |p
| execute_reg_file.sv | |x | |p
| mem_reg_file.sv | |x | |
| top.sv (singlecycle) |x | |p |
| top.sv (pipeline) |p |x |x |p
| cpu_tb.cpp |x | |x |
| F1Assembly.s |x | | |x

LEGEND :       `x` = full responsibility;  `p` = partial contribution; 

---
<div id="structure"/>

## Repo Structure Explained

* A new branch for each new feature

* a `playground` branch for each version. This is the branch where the tinkering and debugging is done in. Major required changes are made in separate branches and the playground is updated using either merges or cherry-picks.

* Once a version has been completed, the playground is branched out to a `VERSION-<NUMBER>-<NAME>` branch and to a new playground for the subsequent version.

> Note that nlewxxs (Nik) is named as a contributor on every branch - this is not the case, it is due to README commits to main at the very start setting group rules. 

| Version name | Explanation | 
| -----------------|-------------|
| `VERSION-1` | Partially implemented single cycle, Upper immediate and SH, LHU, LH not implemented (do not test)
| `VERSION-2-SINGLE-CYCLE` | Full implementation of single cycle processor, no AUIPC
| `VERSION-3-PIPELINED` | Full Pipelined implementation, all instructions

![branches](/images/branches.jpg)

> Note that merges are not shown on the diagram to make it easier to read. **Control** and **Memory** continued to be worked on even after the Single-Cycle implementation was complete. 

---
<div id="evidence"/>

## Evidence

> Apologies for the shaky video :/

PDF: 

https://user-images.githubusercontent.com/106165200/207968492-e1e6efba-45ab-4864-8c6d-bbfddae923c9.mp4


F1:

https://user-images.githubusercontent.com/106165200/207968519-64057ab9-2815-4b46-b02d-79db80c885e3.mp4

In the `test` folder, you can find copies of the following:
* The above videos (in case they have not loaded properly)
*  VCD trace files for both the PDF and F1 programs

---

<div id="test"/>

# Testing instructions

## 1. Clone repo and configure _vbuddy.cfg_ file

This is explained in the guide to set up VBuddy provided at the start of the course.

## 2. Execute shell script 

This branch has been configured for testing both the **F1** and **PDF** programs in the pipelined processor. To test the **F1** program, please run the following shell script:
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

> The assembly code that is run is provided in `F1Assembly.s` and `pdf.s`, but these are not directly linked to the shell scripts. Therefore, if you wish to run alternate code then the `pdf.mem` and `f1.mem` files need to be changed manually, apologies for this. 
