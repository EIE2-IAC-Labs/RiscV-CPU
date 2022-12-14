init:
    addi s1, zero, 0x1  /* assigning required values */
    addi s2, zero, 0xff 
    addi s3, zero, 0x1  /* determines delay between lights */
    addi a3, zero, 0x1 

rst:
    nop
    nop
    addi a0, zero, 0x0 /* reset all */
    addi a4, zero, 0x0 
    addi t0, zero, 0x0 

mainloop:
    nop
    nop
    beq  t0, s1, fsm    /* trigger? */ 
    srli a2, a3, 0x3    /* LFSR */
    nop
    nop
    nop
    andi a2, a2, 0x1
    nop
    nop
    nop
    xor  a2, a2, a3
    nop
    nop
    nop
    andi a2, a2, 0x1 
    nop
    nop
    nop
    slli a3, a3, 0x1 
    nop
    nop
    nop
    add  a3, a3, a2 
    nop
    nop
    nop
    andi a3, a3, 0xf
    jal  ra, mainloop   /* Loop  */

fsm:
    nop
    nop
    jal  ra, lightdelay      /* add const delay */
    nop
    nop
    nop
    slli t1, a0, 0x1    /* shift left temp bits */
    nop
    nop
    addi a0, t1, 0x1    /* add 1 to shifted temp bits */
    nop
    nop
    bne  a0, s2, fsm    /* loop only if not all lights are on */

increment:
    nop
    nop
    beq  a4, a3, rst
    nop
    nop
    jal  ra, lightdelay      /* jump to counter */
    nop
    nop
    addi a4, a4, 0x1    /* inc delay */
    jal  ra, increment  /* run until delay finished */

lightdelay:
    nop
    nop
    addi  a1, a1, 0x1   /* inc count */
    nop
    nop
    nop
    bne   a1, s3, lightdelay
    nop
    nop
    addi  a1, zero, 0x0 /* reset count */
    RET