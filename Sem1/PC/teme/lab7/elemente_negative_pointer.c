#include<stdio.h>
#include<stdint.h>

uint32_t elemente_negative(int32_t vector[], uint32_t dimensiune_vector){
  uint32_t contor = 0;
  for(uint32_t decalaj = 0; decalaj < dimensiune_vector; ++decalaj){
    if(*(vector + decalaj) < 0){
      ++contor;
    }
  }

  return contor;
}

int main(){
  int32_t vector[] = {7, -5, 4, 3, -9, 2, -8};
  uint32_t contor_elemente_negative;

  contor_elemente_negative = elemente_negative(vector, sizeof(vector) / sizeof(vector[0]));

  printf("Numar elemente negative: %u\n", contor_elemente_negative);
  
  return 0;
}
