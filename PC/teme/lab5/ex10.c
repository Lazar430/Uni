#include "../../helper.h"

int main(void){
  uint8_t numar;
  printf("numar = ");
  scanf("%hhu", &numar);
  printf("Numarul %hhu scris in baza 2 este: ", numar);
  afisare_binar_uint8(numar);
  
  printf("Suma LSB: %hhu\n", suma_biti_uint8(numar, 4));
  
  return 0;
}
