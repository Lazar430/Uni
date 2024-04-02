#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

static const uint8_t digitmap[10] = {
  0xC0,//0
  0xF9,//1
  0xA4,//2
  0xB0,//3
  0x99,//4
  0x92,//5
  0x82,//6
  0xF8,//7
  0x80,//8
  0x90//9
};


int main(void)
{
  DDRA = 0xFF;
  
  while (1) 
    {
      for(uint8_t i = 0; i < 10; ++i)
	{
	  PORTA = digitmap[i];
	  _delay_ms(700);
	  PORTA = 0xFF;
	  _delay_ms(700);
	}
    }
}
