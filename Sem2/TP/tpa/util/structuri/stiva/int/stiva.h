#ifndef STIVA_H
#define STIVA_H

#include<stdint.h>
#include<stdlib.h>

typedef struct st_stiva st_stiva;

struct st_stiva{
  st_stiva* corp;
  int32_t valoare;
};

void push(st_stiva**, int32_t);
int32_t pop(st_stiva**);
void peek(st_stiva*);

void afiseaza_stiva(st_stiva*);
void curata_stiva(st_stiva**);

#endif
