#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

#define CHUNK_INREGISTRARI 10

typedef struct{
  char cheie[10];
  char valoare[10];
} inregistrare;

FILE* obtine_fisier(const char* cale_fisier){
  FILE* fisier;

  if( (fisier = fopen(cale_fisier, "r")) == NULL){
    perror(cale_fisier);
    exit(-1);
  }

  return fisier;
}

void verifica_si_realoca_memorie_tablou(inregistrare** tablou_inregistrari, uint32_t* memorie_actuala, uint32_t decalaj_curent){
  if(*memorie_actuala == decalaj_curent){
    *memorie_actuala += CHUNK_INREGISTRARI;
    if( (*tablou_inregistrari = realloc(*tablou_inregistrari, *memorie_actuala * sizeof(inregistrare))) == NULL){
      perror("(re)alocare tablou");
      exit(-1);
    }
  }
}

void salveaza_inregistrare(inregistrare** tablou_inregistrari, uint32_t* dimensiune_tablou, FILE* fisier){
  uint32_t memorie_actuala = 0;
  uint32_t decalaj_curent = 0;

  char linie[20];

  while( fgets(linie, 20, fisier) != NULL){
    verifica_si_realoca_memorie_tablou(tablou_inregistrari, &memorie_actuala, decalaj_curent);
    sscanf(linie, "%s = %s", (*tablou_inregistrari + decalaj_curent)->cheie, (*tablou_inregistrari + decalaj_curent)->valoare);
    ++decalaj_curent;
  }
  *dimensiune_tablou = decalaj_curent;
}

void afisare_inregistrari(inregistrare* tablou_inregistrari, uint32_t dimensiune_tablou){
  printf("%s = %s\n", tablou_inregistrari->cheie, tablou_inregistrari->valoare);
  for(uint32_t decalaj_curent = 1; decalaj_curent < dimensiune_tablou; ++decalaj_curent){
    if(strcmp((tablou_inregistrari + decalaj_curent)->cheie, (tablou_inregistrari + decalaj_curent - 1)->cheie) != 0){
      printf("%s = %s\n", (tablou_inregistrari + decalaj_curent)->cheie, (tablou_inregistrari + decalaj_curent)->valoare);
    }
  }
}

void swap(inregistrare* a, inregistrare* b){
  inregistrare copie;
  
  strcpy(copie.cheie, a->cheie);
  strcpy(copie.valoare, a->valoare);
  
  strcpy(a->cheie, b->cheie);
  strcpy(a->valoare, b->valoare);
  
  strcpy(b->cheie, copie.cheie);
  strcpy(b->valoare, copie.valoare);
}

void insertion_sort(inregistrare* array, uint32_t n){
  for(uint32_t i = 0; i < n - 1; ++i){
    for(uint32_t j = i + 1; j < n; ++j){
      //inregistrarile ar trebui swap-uite si atunci cand sunt identice, deoarece inregistrarea curenta e cea prioritara, fiind mai jos in lista, deci mai tarziu citita
      if(strcmp(array[i].cheie, array[j].cheie) >= 0){
	swap(&array[i], &array[j]);
      }
    }
  }
}

void quicksort(inregistrare* array, int32_t left_endpoint, int32_t right_endpoint){
  if(left_endpoint < right_endpoint){
    int32_t midpoint = (left_endpoint + right_endpoint) / 2;

    swap(&array[left_endpoint], &array[midpoint]);

    int32_t i = left_endpoint, j = right_endpoint, increment = 0;

    while(i < j){

      //inregistrarile ar trebui swap-uite si atunci cand sunt identice, deoarece inregistrarea curenta e cea prioritara, fiind mai jos in lista, deci mai tarziu citita
      if(strcmp(array[i].cheie, array[j].cheie) >= 0){
	swap(&array[i], &array[j]);
	increment = 1 - increment;
      }

      i += increment;
      j -= 1 - increment;
    
    }

    quicksort(array, left_endpoint, i - 1);
    quicksort(array, i + 1 , right_endpoint);
  }
  
}

int main(int numar_argumente, char** argumente){
  inregistrare* tablou_inregistrari = NULL;
  uint32_t dimensiune_tablou;

  FILE* fisier;

  fisier = obtine_fisier(argumente[numar_argumente - 1]);

  salveaza_inregistrare(&tablou_inregistrari, &dimensiune_tablou, fisier);

  //NOTA: habar n-am de fapt care este dimensiunea recomandata
  dimensiune_tablou > 15 ? quicksort(tablou_inregistrari, 0, dimensiune_tablou - 1) : insertion_sort(tablou_inregistrari, dimensiune_tablou);
  
  afisare_inregistrari(tablou_inregistrari, dimensiune_tablou);

  fclose(fisier);
  
  free(tablou_inregistrari);
  
  return 0;
}
