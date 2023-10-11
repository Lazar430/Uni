#include<stdio.h>
#include<stdint.h>

int main(){
  uint32_t n;
  printf("n = ");
  scanf("%u", &n);

  printf("Serie descrescatoare: ");
  while(n > 10){
    printf("%u ", n);

    n -= n / 10;
  }
  printf("\n");



  
  return 0;
}
