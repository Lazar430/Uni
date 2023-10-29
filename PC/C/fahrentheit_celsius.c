#include<stdio.h>
#include<stdint.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
  float celsius, fahrenheit;

  printf("Celisus\t\tFahrenheit\n");

  for(fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP){
    celsius = 5.f * (fahrenheit - 32) / 9.f;
    printf("%7.f\t%18.1f\n", fahrenheit, celsius);
  }
  
  return 0;
}
