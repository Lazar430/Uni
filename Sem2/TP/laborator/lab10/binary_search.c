#include<time.h>
#include<stdio.h>
#include<stdlib.h> 
#include<stdint.h>

#define N 100

void swap(int32_t* a, int32_t* b);

void quicksort(int32_t*, int8_t, int8_t);
int16_t binary_search(int32_t element, int32_t vector[], uint16_t left, uint16_t right);

int main(void){
  int32_t v[N];

  srand(time(NULL));
  for(uint8_t i = 0; i < N; ++i){
    v[i] = rand() % 100;
  }

  for(uint8_t i = 0; i < N; ++i){
    printf("%d ", v[i]);
  }
  printf("\n\n"); 

  quicksort(v, 0, N - 1);

  for(uint8_t i = 0; i < N; ++i){
    printf("%d ", v[i]);
  }
  printf("\n\n"); 

  printf("%u\n", binary_search(101, v, 0, N - 1));
  
  return 0;
}

void swap(int32_t* a, int32_t* b){
  int32_t copy = *a;
  *a = *b;
  *b = copy;
}

void quicksort(int32_t* array, int8_t left_endpoint, int8_t right_endpoint){
  if(left_endpoint < right_endpoint){
    int8_t midpoint = (left_endpoint + right_endpoint) / 2;

    swap(&array[left_endpoint], &array[midpoint]);

    int8_t i = left_endpoint, j = right_endpoint, increment = 0;

    while(i < j){
      
      if(array[i] > array[j]){
	swap(&array[i], &array[j]);
	increment = 1 - increment;
      }

      i += increment;
      j -= 1 - increment;
    
    }

    quicksort(array, left_endpoint, i - 1);
    quicksort(array, i + 1 , right_endpoint);
  }
  
}

int16_t binary_search(int32_t element, int32_t vector[], uint16_t left, uint16_t right){
  uint16_t middle = (left + right) / 2;

  printf("%");

  if(vector[middle] == element){
    return middle;
  } else if(left < right){
    if(vector[middle] < element){
      return binary_search(element, vector, middle, right);
    } else {
      return binary_search(element, vector, left, middle);
    }
  }
  
  return -1;
}
