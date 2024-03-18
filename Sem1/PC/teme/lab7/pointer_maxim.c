#include<stdio.h>
#include<stdint.h>

#include "../../helper.h"

void salvare_maxim(uint32_t numar1, uint32_t numar2, uint32_t** pointer_catre_maxim){
  *pointer_catre_maxim = numar1 > numar2 ? &numar1 : &numar2;
}

int main(void){
  uint32_t numar1, numar2;
  uint32_t* pointer_catre_maxim;

  citire_numar(&numar1, to_string(numar1));
  citire_numar(&numar2, to_string(numar2));

  salvare_maxim(numar1, numar2, &pointer_catre_maxim);

  printf("Maximul dintre cele doua numere introduse este: %d\n", *pointer_catre_maxim);
  
  return 0;
}
