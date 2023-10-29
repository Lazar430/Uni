#include<stdio.h>
#include<stdint.h>

void afisare_binar_uint8(uint8_t numar){
  uint8_t masca = 1 << 7;

  while(masca != 0){
    printf(numar & masca ? "1" : "0");
    masca >>= 1;
  }
  printf("\n");
}

void setare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar |= 1 << pozitie;
}

void resetare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar &= ~(1 << pozitie);
}

void complementare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar ^= (1 << pozitie);
}

void stocare_char(char* container, uint8_t numar1, uint8_t numar2){
  *container |= numar1 << 4;
  *container |= numar2;
}

uint8_t suma_biti_uint8(uint8_t numar, uint8_t biti){
  uint8_t suma = 0;
  
  uint8_t masca = 1;
  for(uint8_t i = 0; i < biti; ++i, masca <<= 1){
    suma += ((numar & masca) != 0);
  }

  return suma;
}
