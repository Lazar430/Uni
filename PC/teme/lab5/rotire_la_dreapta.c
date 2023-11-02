#include<stdio.h>
#include<stdint.h>

#include "../../helper.h"

int main(void){
  uint32_t numar;
  uint16_t pozitii;
  printf("numar = ");
  scanf("%u", &numar);
  printf("Numarul %u scris in baza 2 este: ", numar);
  afisare_binar_uint32(numar);

  printf("Numarul de rotiri la dreapta: ");
  scanf("%hu", &pozitii);
  printf("Numarul rotit la dreapta de %hu ori: ", pozitii);
  afisare_binar_uint32(rotire_la_dreapta(numar, pozitii));
  
  return 0;
}
