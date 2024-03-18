#include "../helper.h"

#include<stdlib.h>

int8_t compar_numere(const void* numar_1, const void* numar_2){
  
  int32_t* valoare_1 = (int32_t*)numar_1;
  int32_t* valoare_2 = (int32_t*)numar_2;

  return *valoare_1 <= *valoare_2;
}

int8_t compar_siruri(const void* numar_1, const void* numar_2){
  
  char** valoare_1 = (char**)numar_1;
  char** valoare_2 = (char**)numar_2;

  printf("%s %s\n", *valoare_1, *valoare_2);

  return strcmp(*valoare_1, *valoare_2);
}

int sortstring( const void *str1, const void *str2 )
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;

    printf("%s %s\n", *pp1, *pp2);

    return strcmp(*pp1, *pp2);
}


int main(void){
  int32_t tablou[] = { -390, -31, 54, -4, 59, 20, 14, -4, 15, 69, -732, 391, 6943, 0, 248, 4, 193, 23, -538, 7 };

  sortare_rapida(tablou, sizeof(int32_t), 0, 19, compar_numere);

  char* tablou2[] = { "sfgaw", "gweqwgs", "OAOKQOWK", "O@JShadfa", "aasdo1", "52adsfv", "flsgpbm", "pospw" };

  //sortare_rapida(tablou2, sizeof(char*), 0, 7, sortstring);
  qsort(&tablou2, 8, sizeof(char*), sortstring);
  
  for(size_t i = 0; i < 20; ++i){
    printf("%d ", tablou[i]);
  }
  printf("\n");

  for(size_t i = 0; i < 8; ++i){
    printf("%s ", tablou2[i]);
  }
  printf("\n");
  
  return 0;
}
