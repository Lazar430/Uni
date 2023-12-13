#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

#define DIMENSIUNE_MAXIMA 100

void citire_vector(uint8_t vector[], uint8_t numar_elemente){
  for(uint8_t index = 0; index < numar_elemente; ++index){
    scanf("%hhu", &vector[index]);
  }
  vector[numar_elemente] = 0;
}

void afisare_vector(uint8_t vector[], uint8_t numar_elemente){
  for(uint8_t index = 0; index < numar_elemente; ++index){
    printf("%hhu ", vector[index]);
  }
  printf("\n");
}

void sortare_par_impar(uint8_t vector[], uint8_t numar_elemente){
  uint8_t pozitie_par = 0, gasit_par = false, oprire = 0;
  for(uint8_t index = 0; index < numar_elemente; ++index){
    if(vector[index] % 2 == 0){
      if(gasit_par == false){
	pozitie_par = index;
	oprire = pozitie_par;
	gasit_par = true;
      }
    } else{
      if(gasit_par == true){
	uint8_t pozitie_impar = index + 1;
	for(uint8_t nou_index = numar_elemente; nou_index > oprire; --nou_index){
	  vector[nou_index] = vector[nou_index - 1];
	}
	vector[oprire] = vector[pozitie_impar];
	for(uint8_t nou_index = pozitie_impar; nou_index < numar_elemente; ++nou_index){
	  vector[nou_index] = vector[nou_index + 1];
	}
	++oprire;
      }
    }
  }
}

int main(void){
  uint8_t vector[DIMENSIUNE_MAXIMA], numar_elemente;

  scanf("%hhu", &numar_elemente);

  citire_vector(vector, numar_elemente);
  sortare_par_impar(vector, numar_elemente);
  afisare_vector(vector, numar_elemente);

  return 0;
}
