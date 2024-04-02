#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>

#define DELAY 100

int main(void)
{
  DDRB &= ~(1 << 4); //dierctie buton 1
  DDRB &= ~(1 << 5); //dierctie buton 2
      
  DDRB |= 1 << 0; //led1
  DDRB |= 1 << 1; //led2
  DDRB |= 1 << 2; //led3
  DDRB |= 1 << 3; //led4
      
  int shift = 0;
      
  if(((PINB & (1 << 4)) == 0 || (PINB & (1 << 5)) == 0)){
    _delay_ms(DELAY);
    PORTB |= 1 << 0;
  }
      
  while (1) 
    { 
      if((PINB & (1 << 5)) == 0){
	_delay_ms(DELAY);
	PORTB &= ~(1 << shift);
                  
	if(shift == 3)
	  shift = 0;
	else
	  shift ++;
                  
	_delay_ms(DELAY);
	PORTB |= 1 << shift;
      }
            
      if((PINB & (1 << 4)) == 0){
	_delay_ms(DELAY);
	PORTB &= ~(1 << shift);
                  
	if(shift == 0)
	  shift = 3;
	else
	  shift --;
                  
	_delay_ms(DELAY);
	PORTB |= 1 << shift;
      }
            
    }
}

