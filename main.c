#include <avr/io.h>

#include "delay_debounce.h"
#include "shift_debounce.h"
#include "async_debounce.h"

int
main()
{
  /* Set up Port B for LED output */
  DDRB = 0xff;
  PORTB = 0x00;

  /* Set up Port D for Input */
  DDRD = 0x00;
  PORTD = 0xff; /* Pull-up pins */

  int8_t pd6_cnt = 0;
  uint8_t pd6_state = 0;
  for (;;) {


    if(delay_debounce(&PIND, 4, 10000)) {
      PORTB ^= (1<<3);
    }



    if(shift_debounce(&PIND, 5)) {
      PORTB ^= (1<<2);
    }


    async_debounce(&PIND, 6, &pd6_cnt);
    if (pd6_cnt > 32 && pd6_state == 0) {
      pd6_state = 1;
      PORTB ^= (1<<7);
    } else if (pd6_cnt < 32 && pd6_state == 1) {
      pd6_state = 0;
    }
    pd6_cnt = 0;
  }
}
