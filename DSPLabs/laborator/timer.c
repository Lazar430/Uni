#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void init_timer(){
  //1 secunda
  unsigned int N = 0xE100;
  OCR1AH = (N >> 8) & 0xFF;
  OCR1AL = N & 0xFF;
  TCCR1B = (1 << CS12) | (1 << WGM12);
}

int main(void){
      
  init_timer();
  DDRB |= 1;
  
  while (1){          
    if((TIFR & (1 << 4)) != 0){
      PORTB ^= (1 << 0);
      TIFR |= 1 << 4;
    }
  }
}

