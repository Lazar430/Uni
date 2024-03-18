#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define MEMORIE_DISCRETA_LINIE 8
#define MEMORIE_DISCRETA_TABLOU 10

FILE* obtine_fisier(const char* nume_fisier){
  FILE* fisier = fopen(nume_fisier, "r");

  if(fisier == NULL){
    printf("Erorare: nu s-a putut deschide fisierul selectat. Abandonare program.\n");
  }

  return fisier;
}

void verifica_memorie_actuala_linie(char** linie, uint32_t decalaj_linie, uint32_t* memorie_actuala_linie){
  if(decalaj_linie == *memorie_actuala_linie){
    *memorie_actuala_linie += MEMORIE_DISCRETA_LINIE;
    *linie = realloc(*linie, *memorie_actuala_linie);
    if(linie == NULL){
      printf("Erorare: o linie nu s-a putut aloca dinamic. Abandonare program.\n");
      exit(-1);
    }
  }
}

void verifica_memorie_actuala_tablou(char*** tablou, uint32_t decalaj_tablou, uint32_t* memorie_actuala_tablou){
  if(decalaj_tablou == *memorie_actuala_tablou){
    *memorie_actuala_tablou += MEMORIE_DISCRETA_TABLOU;
    *tablou = realloc(*tablou, *memorie_actuala_tablou * sizeof(char*));
    if(tablou == NULL){
      printf("Erorare: tabloul nu s-a putut aloca dinamic. Abandonare program.\n");
      exit(-1);
    }
  }
}

char* obtine_linie_din_fisier(FILE* fisier){
  char* linie = NULL;
  uint32_t decalaj_linie = 0;
  uint32_t memorie_actuala_linie = 0;

  char caracter_curent;
  while((caracter_curent = fgetc(fisier)) != EOF){
    verifica_memorie_actuala_linie(&linie, decalaj_linie, &memorie_actuala_linie);

    if(caracter_curent != '\n'){
      *(linie + decalaj_linie++) = caracter_curent;
    } else{
      *(linie + decalaj_linie) = '\0';
      break;
    }
  }

  return linie;
}

char** obtine_tablou_linii_fisier(FILE* fisier){
  char** tablou_linii_fisier = NULL;
  uint32_t decalaj_tablou = 0;
  uint32_t memorie_actuala_tablou = 0;
  
  char* linie_curenta;
  while((linie_curenta = obtine_linie_din_fisier(fisier)) != NULL){
    //printf("(decalaj: %u)%s\n", decalaj_tablou, linie_curenta);
    verifica_memorie_actuala_tablou(&tablou_linii_fisier, decalaj_tablou, &memorie_actuala_tablou);
    *(tablou_linii_fisier + decalaj_tablou++) = linie_curenta;
  }
  verifica_memorie_actuala_tablou(&tablou_linii_fisier, decalaj_tablou, &memorie_actuala_tablou);
  *(tablou_linii_fisier + decalaj_tablou) = NULL;
  
  return tablou_linii_fisier;
}

void printeaza_linii_fisier(char** tablou_linii_fisier){
  while(*tablou_linii_fisier != NULL){
    printf("%s\n", *tablou_linii_fisier);
    ++tablou_linii_fisier;
  }
}

void goleste_memorie_tablou_linii_fisier(char** tablou_linii_fisier){
  while(*tablou_linii_fisier != NULL){
    free(*tablou_linii_fisier);
    ++tablou_linii_fisier;
  }
}

int main(int numar_argumente, char** argumente){
  if(numar_argumente != 2){
    if(numar_argumente < 2){
      printf("Eroare: nu au fost introduse suficiente argumente in linia de comanda. Abandonare program.\n");
    }
    else if(numar_argumente > 2){
      printf("Eroare: prea multe argumente introduse in linia de comanda. Abandonare program.\n");
    }

    return -1;
  }
    
  FILE* scrisoare = obtine_fisier(argumente[1]);
  char** tablou_linii_fisier;

  if(scrisoare == NULL){
    return -1;
  }

  tablou_linii_fisier = obtine_tablou_linii_fisier(scrisoare);
  printeaza_linii_fisier(tablou_linii_fisier);

  goleste_memorie_tablou_linii_fisier(tablou_linii_fisier);
  free(tablou_linii_fisier);
  
  fclose(scrisoare);

  return 0;
}
