# open file
import os
fp = open("/Users/ahmedelkouny/PycharmProjects/pythonProject1/iac/instruction.mem")
os.remove("/Users/ahmedelkouny/PycharmProjects/pythonProject1/iac/newinstruction.mem")
fn = open("/Users/ahmedelkouny/PycharmProjects/pythonProject1/iac/newinstruction.mem", "x")
# put all lines in list
instruction=fp.readlines()
# remove linespaces from lines convert hext to binary
# extract rd,rs1,rs2 from instructions
for i in range(len(instruction)):
    instruction[i]=instruction[i].strip()
    instruction[i]=instruction[i].replace(" ","")
    instruction[i]="{0:032b}".format(int(instruction[i], 16))
    opcode=instruction[i][25:]
    # check if we have an S,B,U,I,J instruction then rd is not in the instruction
    if opcode=="0100011" or opcode=="1100011" or opcode=="110111" or opcode=="1100111" or opcode=="00100111":
        instrHex=hex(int(instruction[i], 2))
        # format of instrHex is 0x{hexnumber} so 0x need to be removed
        instrHex=instrHex[2:]
        # make it 8 bytes
        instrHex=instrHex.zfill(8)
        t = iter(instrHex)
        instrHex=' '.join(a + b for a, b in zip(t, t))
        fn.write(instrHex+"\n")
    else:
        instrHex = hex(int(instruction[i], 2))
        instrHex = instrHex[2:]
        instrHex = instrHex.zfill(8)
        t = iter(instrHex)
        instrHex = ' '.join(a + b for a, b in zip(t, t))
        fn.write(instrHex + "\n")
        # adding noops
        fn.write("00 00 00 13\n")
        fn.write("00 00 00 13\n")
        fn.write("00 00 00 13\n")
        fn.write("00 00 00 13\n")
        fn.write("00 00 00 13\n")

fn.close()
fp.close()
