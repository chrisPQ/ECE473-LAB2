#include <stdint.h>
#include <avr/io.h>

int
shift_debounce(uint8_t volatile *port, uint8_t pin)
{
  uint16_t shift_reg = 0x0055;
  int i;
  for(i = 0; i < 16; i++) {
    shift_reg = (shift_reg << 1) | !bit_is_set(*port, pin);

    if(shift_reg == 0xFFFF && !bit_is_set(*port, pin)) {
      return 1;
    }
    else if(shift_reg == 0x0000 && bit_is_set(*port, pin)) {
      return 0;
    }
  }

  return -1;
}
