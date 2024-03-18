#include<stdio.h>
#include<stdint.h>

#define STATE_INSIDE_WORD 1
#define STATE_OUTSIDE_WORD 0

int main(){
  int16_t character;

  uint64_t number_of_words = 0, number_of_lines = 0, number_of_characters = 0;

  uint8_t state = STATE_OUTSIDE_WORD;

  while((character = getchar()) != EOF){
    ++number_of_characters;

    if(character == '\n'){
      ++number_of_lines;
    }

    if(character == ' ' || character == '\t' || character == '\n'){
      state = STATE_OUTSIDE_WORD;
    } else if(state == STATE_OUTSIDE_WORD){
      state = STATE_INSIDE_WORD;
      ++number_of_words;
    }
  }

  printf("number of lines\tnumber of words\t number of characters\n");
  printf("%15ld\t%15ld\t%21ld\n", number_of_lines, number_of_words, number_of_characters);
  
  return 0;
}
