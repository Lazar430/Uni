#include<stdio.h>
#include<stdint.h>

#include "../../helper.h"

int main(void){
  uint32_t numar_32_biti;
  uint8_t numar_8_biti, pozitie_byte;

  printf("numarul 1 (32 biti) = ");
  scanf("%u", &numar_32_biti);

  printf("numarul 2 (8 biti) = ");
  scanf("%hhu", &numar_8_biti);

  printf("Numarul %u scris in baza 2 este: ", numar_32_biti);
  afisare_binar_uint32(numar_32_biti);

  printf("Numarul %hhu scris in baza 2 este: ", numar_8_biti);
  afisare_binar_uint8(numar_8_biti);

  printf("Byte-ul pe care vreti sa-l inlocuiti: ");
  scanf("%hhu", &pozitie_byte);

  printf("Numarul pe 32 de biti modificat: ");
  afisare_binar_uint32(inlocuire_byte(numar_32_biti, numar_8_biti, pozitie_byte));
  
  return 0;

}
