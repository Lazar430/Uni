#include "../../helper.h"

int main(void){
  uint8_t numar1, numar2;
  char container;

  printf("numar1 = ");
  scanf("%hhu", &numar1);

  printf("numar2 = ");
  scanf("%hhu", &numar2);

  stocare_char(&container, numar1, numar2);
  
  afisare_binar_uint8((uint8_t)container);

  printf("numar1_stocat = %hhu\n", (container & 0xF0) >> 4);
  printf("numar2_stocat = %hhu\n", (container & 0xF));
  
  return 0;
}
