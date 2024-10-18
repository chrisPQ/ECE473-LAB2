#include <stdint.h>
#include <stdint.h>
#include <avr/io.h>
#include "delay_cycles.h"

int button_press = 0;
int
delay_debounce(uint8_t volatile *port, uint8_t pin, uint16_t cycles)
{

  // check button value once
  if(!bit_is_set(*port, pin)) {
    button_press = 1;
  }
  else {
    button_press = 0;
  }
  delay_cycles(cycles);
  // check value again, if same, return 0
  if(bit_is_set(*port, pin) && button_press == 1) {
    return 1;
  }
  return 0;
}
