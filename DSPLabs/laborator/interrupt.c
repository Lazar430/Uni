#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/iom16.h>
#include <avr/interrupt.h>

void init_timer(){
  //1 secunda
  sei(); // enable ATMEGA global interrupts
  unsigned int N = 0xE100;
  OCR1AH = (N >> 8) & 0xFF;
  OCR1AL = N & 0xFF;
  TIMSK |= (1 << OCIE1A);
  TCCR1B = (1 << CS12);
}

ISR(TIMER1_COMPA_vect)
{
  PORTB ^= (1 << 0);
}

int main(void){

  init_timer();
  DDRB |= 1;
  while (1){

  }
}

