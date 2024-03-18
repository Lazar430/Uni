#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define MEMORIE_DISCRETA_LINIE 8
#define MEMORIE_DISCRETA_TABLOU 10

FILE* obtine_fisier(const char* cale_fisier){
  FILE* fisier;

  if( (fisier = fopen(cale_fisier, "r")) == NULL ){
    printf("Eroare: nu s-a putut citi fisierul introdus. Abandonare program...\n");
    exit(-1);
  }

  return fisier;
}

//FOARTE IMPORTANT: functia modifica valoarea liniei.
void verifica_memorie_actuala_linie(char** linie, uint32_t* memorie_actuala_linie, uint32_t decalaj_curent){
  if(decalaj_curent == *memorie_actuala_linie){
    *memorie_actuala_linie += MEMORIE_DISCRETA_LINIE;
    //Stiu ca, teoretic, sizeof(char) e 1, dar ca principiu...
    if( (*linie = realloc(*linie, *memorie_actuala_linie * sizeof(char))) == NULL ){
      printf("Eroare: nu s-a putut (re)aloca dinamic o linie. Abandonare program...\n");
      exit(-1);
    }
  }
}

//FOARTE IMPORTANT: functia modifica valoarea tabloului.
void verifica_memorie_actuala_tablou_linii(char*** tablou_linii, uint32_t* memorie_actuala_tablou_linii, uint32_t decalaj_curent){
  if(decalaj_curent == *memorie_actuala_tablou_linii){
    *memorie_actuala_tablou_linii += MEMORIE_DISCRETA_TABLOU;
    if( (*tablou_linii = realloc(*tablou_linii, *memorie_actuala_tablou_linii * sizeof(char*))) == NULL ){
      printf("Eroare: nu s-a putut (re)aloca dinamic tabloul de linii. Abandonare program...\n");
      exit(-1);
    }
  }
}

char* obtine_linie(FILE* fisier){
  char *linie = NULL;
  char caracter;
  uint32_t memorie_actuala_linie = 0;
  uint32_t decalaj_curent = 0;
  
  while( (caracter = fgetc(fisier)) != EOF){
    verifica_memorie_actuala_linie(&linie, &memorie_actuala_linie, decalaj_curent);

    if(caracter != '\n'){
      *(linie + decalaj_curent++) = caracter;
    } else{
      *(linie + decalaj_curent) = '\0';
      break;
    }
  }

  return linie;
}

void salvare_linii(FILE* fisier, char*** tablou_linii){
  char* linie = NULL;
  uint32_t memorie_actuala_tablou_linii = 0;
  uint32_t decalaj_curent = 0;

  //Ultimul element salvat va fi NULL - alternativa pentru salvarea dimensiunii tabloului intr-o variabila
  do {
    linie = obtine_linie(fisier);
    verifica_memorie_actuala_tablou_linii(tablou_linii, &memorie_actuala_tablou_linii, decalaj_curent);

    *(*tablou_linii + decalaj_curent++) = linie;
  } while( linie != NULL );
}

void afisare_linii(char** tablou_linii){
  while(*tablou_linii != NULL){
    printf("%s\n", *tablou_linii);
    ++tablou_linii;
  }
}

void golire_memorie_tablou_linii(char** tablou_linii){
  while(*tablou_linii != NULL){
    free(*tablou_linii);
    ++tablou_linii;
  }
  free(*tablou_linii);
}

void salveaza_campuri(char* linie, char** titlu, char** an, char** buget){
  char* jeton;
  uint8_t numar_camp;
  for(jeton = strtok(linie, ","), numar_camp = 1; jeton && *jeton && numar_camp < 8; jeton = strtok(NULL, ","), ++numar_camp){
    if(numar_camp == 1){
      *an = strdup(jeton);
    }
    if(numar_camp == 3){
      *titlu = strdup(jeton);
    }
    if(numar_camp == 7){
      *buget = strdup(jeton);
    }
  }
}

void afisare_campuri_filme(char** tablou_linii){
  char *titlu, *an, *buget;
  
  ++tablou_linii;
  while(*tablou_linii != NULL){
    salveaza_campuri(*tablou_linii, &titlu, &an, &buget);
    printf("%-100s\t%s\t%s\n", titlu, an, buget);

    free(titlu);
    free(an);
    free(buget);
    
    ++tablou_linii;
  }
}

int main(int numar_argumente, char** argumente){
  if(numar_argumente != 2){
    if(numar_argumente < 2){
      printf("Eroare: insuficiente argumente in linia de comanda (utilizare corecta: ./nume_program nume_fisier). Abandonare program...\n");
      exit(-1);
    } else{
      printf("Eroare: prea multe argumente in linia de comanda (utilizare corecta: ./nume_program nume_fisier). Abandonare program...\n");
      exit(-1);
    }
  }

  /*
    FILE* fisier;
    char** tablou_linii = NULL;

    fisier = obtine_fisier(argumente[1]);

    salvare_linii(fisier, &tablou_linii);

    //afisare_linii(tablou_linii);
    afisare_campuri_filme(tablou_linii);

    golire_memorie_tablou_linii(tablou_linii);
    free(tablou_linii);

    fclose(fisier);
  */

  /*
    FILE* fisier = fopen(argumente[1], "w");

    uint32_t var = 432;
    char hex[5];
    sprintf(hex, "%04X", var);
    fwrite(hex, sizeof(char), sizeof(hex) - 1, fisier);
  */

  FILE* in = fopen("integers.bin", "r");
  FILE* out = fopen("out", "w");

  uint32_t var = 0;
  fread(&var, sizeof(uint32_t), 1, in);
  printf("%d\n", var);

  uint32_t var2 = 0;
  fread(&var2, sizeof(uint32_t), 1, in);
  printf("%d\n", var2);

  uint32_t var3 = 0;
  fread(&var3, sizeof(uint32_t), 1, in);
  printf("%d\n", var3);

  fwrite(&var, sizeof(uint32_t), 1, out);
  fwrite(&var2, sizeof(uint32_t), 1, out);
  fwrite(&var3, sizeof(uint32_t), 1, out);
  
  return 0;
}
