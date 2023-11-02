#include<stdio.h>

void f(int* n){
  *n = 100;
}

int main(void){
  int a = 200;
  f(&a);
  printf("%d\n", a);
  
  return 0;
}
