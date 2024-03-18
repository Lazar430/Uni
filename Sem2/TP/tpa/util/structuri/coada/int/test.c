#include "stiva.h"

int main(){
  st_stiva* stiva = NULL;

  push(&stiva, 0);
  push(&stiva, 1);
  push(&stiva, 2);
  push(&stiva, 3);

  afiseaza_stiva(stiva);
  
  curata_stiva(&stiva);
  
  return 0;
}
