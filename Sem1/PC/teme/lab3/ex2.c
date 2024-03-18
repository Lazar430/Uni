#include<stdio.h>
#include<stdint.h>

uint32_t suma_recursiva(uint32_t n){
  if(n > 0)
    return n + suma_recursiva(n - 1);
  else return 0;
}

uint32_t suma_iterativa(uint32_t n){
  uint32_t suma = 0;
  while(n > 0){
    suma += n--;
  }

  return suma;
}

uint32_t suma_Gauss(uint32_t n){
  return ( n * (n + 1) ) / 2;
}

int main(){
  uint32_t n = 0;
  printf("n = ");
  scanf("%u", &n);

  printf("Suma recursiva: %u\n", suma_recursiva(n));
  printf("Suma iterativa: %u\n", suma_iterativa(n));
  printf("Suma Gauss: %u\n", suma_Gauss(n));
  
  printf("\n");
  
  return 0;
}
