  .globl delay_cycles
  .type delay_cycles, @function
delay_cycles:
  subi r24, 1
  sbc r25, r1
  cp r24, r1
  BRNE delay_cycles
  cp r25, r1
  BRNE delay_cycles

  ret ; 5 cycles
  .size delay_cycles, .-delay_cycles
