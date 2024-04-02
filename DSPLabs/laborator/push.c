#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>

#define SHIFT 0
#define DELAY 100

int main(void)
{
  DDRB |= 1 << SHIFT;
  DDRB &= ~(1 << 4);
      
  int ok = 0;
  while (1)
    {
      _delay_ms(DELAY);
      if((PINB & (1 << 4)) == 0){
	ok = 1 - ok;
                  
	if(ok == 1){
	  _delay_ms(DELAY);
	  PORTB |= 1 << SHIFT;
	} else{
	  _delay_ms(DELAY);
	  PORTB &= ~(1 << SHIFT);
	}
      }
    }
}


