#include <inttypes.h>
#include<stdint.h>
#include<stdio.h>

uint64_t convert_to_decimal(uint64_t value, uint8_t base){
  uint64_t decimal_value = 0;

  uint64_t base_power = 1;
  while(value != 0){
    uint8_t coefficient = value % 10;
    
    
    if(coefficient != 0){
      decimal_value += coefficient * base_power;
    }
    
    base_power *= base;
    value /= 10;
  }

  return decimal_value;
}

int main(){
  uint64_t value = 0;
  uint8_t base = 0;

  printf("Enter value: ");
  scanf("%lu", &value);
  
  printf("Enter base: ");
  scanf("%" SCNu8, &base);

  printf("Returned decimal value: %lu\n", convert_to_decimal(value, base));
  
  return 0;
}
