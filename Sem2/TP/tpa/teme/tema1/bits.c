#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define CHUNK_MEMORIE 10
#define DIMENSIUNE_LINIE 5

FILE* obtine_fisier(char*); 

void verifica_si_realoca_memorie_tablou(uint16_t** tablou, uint32_t*, uint32_t);

void salveaza_numere(uint16_t**, uint32_t*, FILE*);

void afiseaza_tablou(uint16_t*, uint32_t);

int main(int, char** argumente){
  FILE* input;
  uint16_t* tablou_numere = NULL;
  uint32_t dimensiune_tablou;

  input = obtine_fisier(argumente[1]);

  salveaza_numere(&tablou_numere, &dimensiune_tablou, input);

  afiseaza_tablou(tablou_numere, dimensiune_tablou);

  free(tablou_numere);
  
  return 0;
}

FILE* obtine_fisier(char* cale_fisier){
  FILE* fisier;

  if( (fisier = fopen(cale_fisier, "r")) == NULL ){
    perror(cale_fisier);
    exit(-1);
  }

  return fisier;
}

void verifica_si_realoca_memorie_tablou(uint16_t** tablou, uint32_t* memorie_actuala, uint32_t decalaj_actual){
  if(*memorie_actuala == decalaj_actual){
    *memorie_actuala += CHUNK_MEMORIE;
    if( (*tablou = realloc(*tablou, *memorie_actuala * sizeof(uint16_t))) == NULL ){
      perror("(re)alocare tablou");
      exit(-1);
    }
  }
}

void salveaza_numere(uint16_t** tablou, uint32_t* dimensiune_tablou, FILE* input){
  uint32_t memorie_actuala = 0;
  uint32_t decalaj_curent = 0;

  char linie[DIMENSIUNE_LINIE];

  while(fgets(linie, DIMENSIUNE_LINIE, input) != NULL){
    verifica_si_realoca_memorie_tablou(tablou, &memorie_actuala, decalaj_curent);
    sscanf(linie, "%hu", (*tablou + decalaj_curent));
    ++decalaj_curent;
  }
  *dimensiune_tablou = decalaj_curent;
}

void afiseaza_tablou(uint16_t* tablou, uint32_t dimensiune_tablou){
  for(uint32_t i = 0; i < dimensiune_tablou; ++i){
    printf("%hu\n", *(tablou + i));
  }
}
