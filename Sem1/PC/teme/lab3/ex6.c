#include<stdio.h>
#include<stdint.h>

void afisare_tabla_inmultirii(){
  for(uint32_t i = 0; i < 11; ++i){
    for(uint32_t j = 0; j < 11; ++j){
      printf("%u * %u = %u", i, j, i * j);
      if(j != 10){
	printf(", ");
      }
    }
    printf("\n");
  }
}

int main(){
  afisare_tabla_inmultirii();
  
  return 0;
}
