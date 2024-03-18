#include "coada.h"

#include<stdio.h>

void push(st_coada** coada, int32_t valoare){
  if(*coada == NULL){
    if( (*coada = malloc(sizeof(st_coada))) == NULL ){
      perror("nu s-a putut aloca dinamic o coada");
      exit(-1);
    }
    (*coada)->valoare = valoare;
    (*coada)->corp = NULL;
  } else{
    st_coada* cap;  
    if( (cap = malloc(sizeof(st_coada))) == NULL ){
      perror("nu s-a putut aloca dinamic o coada");
      exit(-1);
    }

    cap->valoare = valoare;
    cap->corp = *coada;
    *coada = cap;
  }
}

int32_t pop(st_coada** coada){
  int32_t valoare = 0;

  if(*coada != NULL){
    st_coada* copie = *coada;
    *coada = (*coada)->corp;
    copie->corp = NULL;
    //printf("\n\n%d\n\n", (*coada)->corp->valoare);
    
    valoare = copie->valoare;
    free(copie);
  } else{
    printf("Tentativa de apelare a functiei pop() pentru o coada goala.\n");
  }
  
  return valoare;
}

void peek(st_coada* coada){
  printf("%d\n", coada->valoare);
}

void curata_coada(st_coada** coada){
  if(*coada != NULL){
    if((*coada)->corp != NULL){
      curata_coada(&(*coada)->corp);
    }
    free(*coada);
  } else{
    printf("Tentativa de curatare a unei stive goale.\n");
  }
}

void afiseaza_coada(st_coada* coada){
  if(coada != NULL){
    printf("%d\n", coada->valoare);
    if(coada->corp != NULL){
      afiseaza_coada(coada->corp);
    }
  } else{
    printf("Tentativa de afisare a unei stive goale.\n");
  } 
}
