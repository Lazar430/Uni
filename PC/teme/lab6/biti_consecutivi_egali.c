#include<stdio.h>
#include<stdint.h>

void afisare_pe_biti_8u(uint8_t numar){
  uint8_t masca = 1 << 7;
  while(masca){
    printf(numar & masca ? "1" : "0");
    masca >>= 1;
  }
  printf("\n");
}

uint8_t biti_consecutivi_egali(uint8_t numar){
  uint8_t bit_precedent = -1, masca = 1 << 7, contor_biti = 0;
  while(masca){
    uint8_t bit_curent = numar & masca ? 1 : 0;
    contor_biti += (bit_curent != bit_precedent);
    bit_precedent = bit_curent;
    masca >>= 1;
  }
  return contor_biti;
}

int main(void){
  uint8_t numar, contor_biti;

  printf("n = ");
  scanf("%hhu", &numar);

  printf("Numarul pe biti: ");
  afisare_pe_biti_8u(numar);
  
  contor_biti = biti_consecutivi_egali(numar);

  printf("Numar de segmente de biti consecutivi egali: %hhu\n", contor_biti);
  
  return 0;
}
