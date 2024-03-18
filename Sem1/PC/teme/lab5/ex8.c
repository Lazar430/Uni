#include "../../helper.h"

int main(void){
  uint8_t numar;
  printf("numar = ");
  scanf("%hhu", &numar);
  printf("Numarul %hhu scris in baza 2 este: ", numar);
  afisare_binar_uint8(numar);

  setare_bit_uint8(&numar, 0);
  setare_bit_uint8(&numar, 2);
  setare_bit_uint8(&numar, 3);

  resetare_bit_uint8(&numar, 1);
  resetare_bit_uint8(&numar, 5);
  resetare_bit_uint8(&numar, 6);

  complementare_bit_uint8(&numar, 4);
  complementare_bit_uint8(&numar, 7);
  
  printf("Numarul modificat scris in baza 2 este: ");
  afisare_binar_uint8(numar);
  
  return 0;
}
