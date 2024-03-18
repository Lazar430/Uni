#ifndef COADA_H
#define COADA_H

#include<stdint.h>
#include<stdlib.h>

typedef struct st_coada st_coada;

struct st_coada{
  st_coada* corp;
  int32_t valoare;
};

void push(st_coada**, int32_t);
int32_t pop(st_coada**);
void peek(st_coada*);

void afiseaza_coada(st_coada*);
void curata_coada(st_coada**);

#endif
