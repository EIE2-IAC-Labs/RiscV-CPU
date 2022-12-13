init:
    addi s1, zero, 0x1  /* assigning required values */
    addi s2, zero, 0xff 
    addi s3, zero, 0x1  /* determines delay between lights */
    addi a3, zero, 0x1 

rst:
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi a0, zero, 0x0 /* reset all */
    addi a4, zero, 0x0 
    addi t0, zero, 0x0 

mainloop:
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    beq  t0, s1, fsm    /* trigger? */ 
    srli a2, a3, 0x3    /* LFSR */
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    andi a2, a2, 0x1
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    xor  a2, a2, a3
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    andi a2, a2, 0x1 
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    slli a3, a3, 0x1 
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    add  a3, a3, a2 
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    andi a3, a3, 0xf
    jal  ra, mainloop   /* Loop  */
fsm:
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    jal  ra, lightdelay      /* add const delay */
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    slli t1, a0, 0x1    /* shift left temp bits */
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi a0, t1, 0x1    /* add 1 to shifted temp bits */
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    bne  a0, s2, fsm    /* loop only if not all lights are on */

increment:
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    beq  a4, a3, rst
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    jal  ra, lightdelay      /* jump to counter */
    addi zero , zero, 0x0
    addi zero , zero, 0x0
    addi zero , zero, 0x0
    addi a4, a4, 0x1    /* inc delay */
    jal  ra, increment  /* run until delay finished */

lightdelay:
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi  a1, a1, 0x1   /* inc count */
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    addi zero, zero, 0x0
    bne   a1, s3, lightdelay
    addi zero , zero, 0x0
    addi zero , zero, 0x0
    addi zero , zero, 0x0
    addi  a1, zero, 0x0 /* reset count */
    jalr ra, ra, 0x0