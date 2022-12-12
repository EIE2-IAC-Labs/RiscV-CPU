addi x3, x0, 1      
addi x4, x0, 11     
addi x5, x0, 3  

#start (line 4)

srli x6, x5, 5  
andi x7, x5, 31              
srli x7, x7, 4    
xor x8, x6, x7                     
andi x8, x8, 1                 
slli x5, x5, 1      
add x5, x5, x8                      #10

# the eight lights */

addi x1, x0, 0
+| jal x9, 36(x0)

addi x1, x0, 1    #/* one light on */
+| jal x9, 36(x0)

addi x1, x0, 2  #/* two lights on */
+| jal x9, 36(x0)


addi x1, x0, 4  #/* three lights on */
+| jal x9, 36(x0)

addi x1, x0, 8  #/* four lights on */
+| jal x9, 36(x0)

addi x1, x0, 16  #/* five lights on */
+| jal x9, 36(x0)

addi x1, x0, 32  #/* six lights on */
+| jal x9, 36(x0)

addi x1, x0, 64  #/* seven lights on */
+| jal x9, 36(x0) 

addi x1, x0, 128  #/* eight lights on */      #// 17

#/* the delay */
sra x2, x2, x3 /divide by 2(right shift by 1) because every iteration has 2 cycles/
sub x2, x2, x3           
bne x2, x0, (-1) 
addi x1, x0, 0  #/* turn off lights */
j 4                         #  //5

sub x4, x4, x3
bne x4, x0, (-1) 
addi x4, x0, 10
jalr x11, 0(x9)       # //4    #//36