#include<stdio.h>
#include<stdint.h>

uint8_t element_minim(int8_t vector[], uint8_t dimensiune_vector){
  int8_t element_minim = vector[0];
  for(uint8_t index = 0; index < dimensiune_vector; ++index){
    element_minim = vector[index] < element_minim ? vector[index] : element_minim;
  }

  return element_minim;
}

int main(void){
  int8_t vector[] = {7, -5, 4, 3, -9, 2, -8};
  printf("Elementul minim: %hhd\n", element_minim(vector, sizeof(vector) / sizeof(uint8_t)));
  
  return 0;
}
