#include "stiva.h"

int main(){
  st_stiva* stiva = NULL;

  push(&stiva, '+');
  push(&stiva, '-');
  push(&stiva, '*');
  push(&stiva, '/');

  afiseaza_stiva(stiva);
  
  curata_stiva(&stiva);
  
  return 0;
}
