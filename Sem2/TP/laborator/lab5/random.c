#include "random.h"

#include <stdlib.h>

unsigned* makeRandArray(unsigned seed, unsigned n){
  unsigned* randArray = malloc(n * sizeof(unsigned));

  srand(seed);
  for(unsigned i = 0; i < n; ++i){
    randArray[i] = rand() % 100;
  }

  return randArray;
}

int* makeRandLimitArray(int seed, unsigned n, int a, int b){
  int* randArray = malloc(n * sizeof(int));
  
  srand(seed);
  for(unsigned i = 0; i < n; ++i){
    randArray[i] = a + (rand() % (b - a));
  }

  return randArray;
}

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)){
  int* randArray = malloc(n * sizeof(int));

  for(unsigned i = 0; i < n; ++i){
    randArray[i] = getNewElem(randArray, i);
  }

  return randArray;
}
