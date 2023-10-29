#include<stdio.h>
#include<stdint.h>

void afisare_8(uint32_t n){
  for(uint32_t i = 0; i < n; ++i){
    printf("* ");
    
    if(i == 0 || i == n - 1 || i == (n - 1) / 2){
      for(uint32_t j = 1; j < n - 1; ++j){
	printf("* ");
      }
    }

    else {
      for(uint32_t j = 1; j < 2*n - 3; ++j){
	printf(" ");
      }
    }

    printf("* \n");
    
  }
}

int main(void){
  uint32_t n;

  printf("n = ");
  scanf("%u", &n);

  afisare_8(n);
  
  return 0;
}
