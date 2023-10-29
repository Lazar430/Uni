#include<stdio.h>
#include<stdint.h>

void afisare_patrat(uint32_t n){
  for(uint32_t i = 0; i < n; ++i){
    printf("* ");
    
    if(i == 0 || i == n - 1){
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

void afisare_litera_N(uint32_t n){
  uint32_t contor_diagonala = 0;
  
  for(uint32_t i = 0; i < n; ++i){
    printf("*");
    
   
    for(uint32_t j = 1; j < n - 1; ++j){

      if(j == contor_diagonala){
	printf("*");
      } else {
	printf(" ");
      }
      
    }

    printf("*\n");
    ++contor_diagonala;
    
  }
}

int main(){
  uint32_t n = 0;
  printf("n = ");
  scanf("%u", &n);

  afisare_patrat(n);
  afisare_litera_N(n);
  
  printf("\n");
  
  return 0;
}

/*
****
*  *
*  *
****
*/
