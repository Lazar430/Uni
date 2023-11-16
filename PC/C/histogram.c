#include<stdio.h>
#include<stdint.h>

#define NUMBER_OF_LETTERS 52
#define CAPITAL_LETTER_OFFSET 65
#define SMALL_LETTER_OFFSET 6

typedef struct letter_frequency{
  char letter;
  uint32_t frequency;
} letter_frequency;

int main(void){
  int16_t character;
  letter_frequency letters_frequencies[NUMBER_OF_LETTERS];

  uint64_t number_of_letters = 0;

  for(uint8_t letter = 'A'; letter <= 'Z'; ++letter){
    letters_frequencies[letter - CAPITAL_LETTER_OFFSET].letter = letter;
    letters_frequencies[letter - CAPITAL_LETTER_OFFSET].frequency = 0;
  }

  for(uint8_t letter = 'a'; letter <= 'z'; ++letter){
    letters_frequencies[letter - SMALL_LETTER_OFFSET].letter = letter;
    letters_frequencies[letter - SMALL_LETTER_OFFSET].frequency = 0;
  }

  while((character = getchar()) != EOF){
  
    if(character >= 'A' && character <= 'Z'){
      ++letters_frequencies[character - CAPITAL_LETTER_OFFSET].frequency;
      ++number_of_letters;
    } else if(character >= 'a' && character <= 'z'){
      ++letters_frequencies[character - SMALL_LETTER_OFFSET].frequency;
      ++number_of_letters;
    }
    
  }

  for(uint8_t letter = 'A'; letter <= 'Z'; ++letter){
    printf(
	   "%c : %ld%%\n",
	   letters_frequencies[letter - CAPITAL_LETTER_OFFSET].letter,
	   ( letters_frequencies[letter - CAPITAL_LETTER_OFFSET].frequency * 100) / number_of_letters
	   );
  }

  printf("\n");

  for(uint8_t letter = 'a'; letter <= 'z'; ++letter){
    printf(
	   "%c : %ld%%\n",
	   letters_frequencies[letter - SMALL_LETTER_OFFSET].letter,
	   ( letters_frequencies[letter - SMALL_LETTER_OFFSET].frequency * 100) / number_of_letters
	   );
  }
  
  return 0;
}
