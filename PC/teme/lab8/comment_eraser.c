////////////////////////////////////////////////////////////////
//***********************COMMENT ERASER***********************//
////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdint.h>

/*
  
  file_state - enum for identifying of the current state of the file reading process
  
  STATE_OUTSIDE_COMMENT - the last read character is outside a comment
  STATE_INSIDE_ONE_LINE_COMMENT - the last read character is inside a one line comment
  STATE_INSIDE_MULTILINE_COMMENT - the last read character is inside a multiline comment

  pretty self-explanatory, actually
  
*/

typedef enum file_state{
  STATE_OUTSIDE_COMMENT,
  STATE_INSIDE_ONE_LINE_COMMENT,
  STATE_INSIDE_MULTILINE_COMMENT
} file_state;

int main(void){
  int16_t character;

  file_state state = STATE_OUTSIDE_COMMENT;

  while((character = getchar()) != EOF){
    if(character == '/'){
      int16_t temporary_character = getchar();

      //SET STATE
      if(temporary_character == '/'){
	state = STATE_INSIDE_ONE_LINE_COMMENT;
      }

      if(temporary_character == '*'){
	state = STATE_INSIDE_MULTILINE_COMMENT;
      }
    }

    //CHECK STATE
    if(state == STATE_INSIDE_ONE_LINE_COMMENT && character == '\n'){
      state = STATE_OUTSIDE_COMMENT;
    }

    if(state ==STATE_INSIDE_MULTILINE_COMMENT && character == '*'){
      int16_t temporary_character = getchar();
      if(temporary_character == '/'){
	character = getchar();
	state = STATE_OUTSIDE_COMMENT;
      }
    }

    if(state == STATE_OUTSIDE_COMMENT){
      putchar(character);
    }
    
  }
}
