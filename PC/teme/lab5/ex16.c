#include "../../helper.h"

int main(void){
  uint8_t numar1, numar2;
  uint16_t suma;
  
  printf("numar1 = ");
  scanf("%hhu", &numar1);

  printf("numar2 = ");
  scanf("%hhu", &numar2);

  printf("Numarul %hhu scris in baza 2 este: ", numar1);
  afisare_binar_uint8(numar1);

  printf("Numarul %hhu scris in baza 2 este: ", numar2);
  afisare_binar_uint8(numar2);

  suma = operatie_pe_biti(numar1, numar2, adunare);
  
  printf("Suma este %hhu, iar scrierea ei in baza 2 este: ", suma);
  afisare_binar_uint16(suma);
  
  return 0;
}
