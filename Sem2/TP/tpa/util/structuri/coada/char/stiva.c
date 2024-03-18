#include "stiva.h"

#include<stdio.h>

void push(st_stiva** stiva, char valoare){
  if(*stiva == NULL){
    if( (*stiva = malloc(sizeof(st_stiva))) == NULL ){
      perror("nu s-a putut aloca dinamic o stiva");
      exit(-1);
    }
    (*stiva)->valoare = valoare;
    (*stiva)->corp = NULL;
  } else{
    st_stiva* cap;  
    if( (cap = malloc(sizeof(st_stiva))) == NULL ){
      perror("nu s-a putut aloca dinamic o stiva");
      exit(-1);
    }

    cap->valoare = valoare;
    cap->corp = *stiva;
    *stiva = cap;
  }
}

char pop(st_stiva** stiva){
  char valoare = 0;

  if(*stiva != NULL){
    st_stiva* copie = *stiva;
    *stiva = (*stiva)->corp;
    copie->corp = NULL;
    //printf("\n\n%c\n\n", (*stiva)->corp->valoare);
    
    valoare = copie->valoare;
    free(copie);
  } else{
    printf("Tentativa de apelare a functiei pop() pentru o stiva goala.\n");
  }
  
  return valoare;
}

void peek(st_stiva* stiva){
  printf("%c\n", stiva->valoare);
}

void curata_stiva(st_stiva** stiva){
  if(*stiva != NULL){
    if((*stiva)->corp != NULL){
      curata_stiva(&(*stiva)->corp);
    }
    free(*stiva);
  } else{
    printf("Tentativa de curatare a unei stive goale.\n");
  }
}

void afiseaza_stiva(st_stiva* stiva){
  if(stiva != NULL){
    printf("%c\n", stiva->valoare);
    if(stiva->corp != NULL){
      afiseaza_stiva(stiva->corp);
    }
  } else{
    printf("Tentativa de afisare a unei stive goale.\n");
  } 
}
