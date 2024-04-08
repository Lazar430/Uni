#define F_CPU 14745600UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/iom16.h>
#include <avr/interrupt.h>
#include <string.h>

#define FOSC 14745600UL// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int ubrr)
{
  UCSRC &= ~(1<<URSEL);
  UBRRH = (unsigned char)(ubrr>>8);
  UBRRL = (unsigned char)ubrr;
  UCSRA &= ~(1 << UDRE);
  UCSRB = (1 <<TXEN) | (1 << RXEN);
  UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

void USART_Transmit(unsigned char data)
{
  while (!(UCSRA & (1<<UDRE)));
  UDR = data;
}

unsigned char USART_Receive()
{
  while(!(UCSRA & (1<<RXC)));
  return UDR;
}



int main(void){
  DDRD |= (1 << 1);
  DDRD &= ~(1 << 0);
  USART_Init (MYUBRR);
  while (1){

    unsigned char a = USART_Receive();
    //_delay_ms(200);
    USART_Transmit(a);
    _delay_ms(200);
  }
}
