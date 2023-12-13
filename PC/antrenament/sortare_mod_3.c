#include<stdio.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>

#define DIMENSIUNE_MAXIMA 255

void populare_numere_aleatorii(uint32_t vector[], uint8_t dimensiune_vector);

void afisare_vector(uint32_t vector[], uint8_t dimensiune_vector);

void sortare_mod_3(uint32_t vector[], uint8_t dimensiune_vector);

void interschimbare_elemente_vector(uint32_t vector[], uint8_t decalaj1, uint8_t decalaj2);

int main(){
  srand(time(NULL));
  uint32_t vector[rand() % DIMENSIUNE_MAXIMA];

  size_t dimensiune_vector = sizeof(vector) / sizeof(vector[0]);

  populare_numere_aleatorii(vector, dimensiune_vector);
  
  printf("Vector initial: ");

  afisare_vector(vector, dimensiune_vector);

  sortare_mod_3(vector, dimensiune_vector);

  printf("Vector modificat: ");

  afisare_vector(vector, dimensiune_vector);
  
  return 0;
}

void populare_numere_aleatorii(uint32_t vector[], uint8_t dimensiune_vector){
  for (size_t decalaj = 0; decalaj < dimensiune_vector; ++decalaj){
    *(vector + decalaj) = rand() % 100;
  }
}

void afisare_vector(uint32_t vector[], uint8_t dimensiune_vector){
  for (size_t decalaj = 0; decalaj < dimensiune_vector; ++decalaj){
    printf("%u ", *(vector + decalaj));
  }
  printf("\n");
}

void interschimbare_elemente_vector(uint32_t vector[], uint8_t decalaj1, uint8_t decalaj2){
  uint32_t copie = *(vector + decalaj1);
  *(vector + decalaj1) = *(vector + decalaj2);
  *(vector + decalaj2) = copie;
}

void mini_sortare_mod3(uint32_t vector[], uint8_t dimensiune_vector, uint8_t mod){
  static uint8_t decalaj_nou = 0;
  for(uint8_t decalaj = decalaj_nou; decalaj < dimensiune_vector; ++decalaj){
    if(*(vector + decalaj) % 3 == mod){
      interschimbare_elemente_vector(vector, decalaj, decalaj_nou++);
    }
  }
}

void sortare_mod_3(uint32_t vector[], uint8_t dimensiune_vector){
  mini_sortare_mod3(vector, dimensiune_vector, 0);
  mini_sortare_mod3(vector, dimensiune_vector, 1);
}
