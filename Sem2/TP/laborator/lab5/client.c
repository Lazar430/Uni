#include "random.h"

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define N 10

int getNewIncreasingElement(int* array, unsigned n){
  srand(time(0) + 100);
  int element = rand() % 100;

  if(n != 0){
    while(element < array[n - 1]){
      element = rand() % 100;
    }
  }

  return element;
}

int main(void){
  unsigned *randArray1;
  int *randArray2, *randArray3;

  randArray1 = makeRandArray(time(0), N);

  for(unsigned i = 0; i < N; ++i){
    printf("%u ", randArray1[i]);
  }
  printf("\n");

  randArray2 = makeRandLimitArray(rand(), N, 50, 70);
  
  for(unsigned i = 0; i < N; ++i){
    printf("%u ", randArray2[i]);
  }
  printf("\n");

  randArray3 = makeRandFlexiArray(N, &getNewIncreasingElement);

  for(unsigned i = 0; i < N; ++i){
    printf("%u ", randArray3[i]);
  }
  printf("\n");

  free(randArray1);
  free(randArray2);
  free(randArray3);
  
  return 0;
}
