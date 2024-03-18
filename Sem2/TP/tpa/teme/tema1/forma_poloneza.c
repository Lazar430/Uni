#include "../../util/structuri/stiva/char/stiva.h"

#include<string.h>
#include<stdio.h>

void concatenare_char_la_sir(char** sir, char caracter){
  char temp[2];
  temp[0] = caracter;
  temp[1] = 0;
  strcat(*sir, temp);
}

void rezolva_prioritate_0(st_stiva** operatori, char** forma_poloneza){
  pop(&*operatori);
  char operator_prioritate_0 = pop(&*operatori);
  
  while(operator_prioritate_0 != '('){
    concatenare_char_la_sir(forma_poloneza, operator_prioritate_0);
    operator_prioritate_0 = pop(&*operatori);
  }
}

void rezolva_prioritate_2(char operator, st_stiva** operatori, char** forma_poloneza){
  char operator_prioritate_1 = pop(&*operatori);
  
  while(strchr("*/", operator_prioritate_1) != NULL){
    concatenare_char_la_sir(forma_poloneza, operator_prioritate_1);
    operator_prioritate_1 = pop(&*operatori);
  }
  
  push(&*operatori, operator_prioritate_1);
  push(&*operatori, operator);
}

void evalueaza_operator(char operator, st_stiva** operatori, char** forma_poloneza){
  if(strchr("+-*/", operator) != NULL){
    rezolva_prioritate_2(pop(&*operatori), operatori, forma_poloneza);
  } else if(strchr(")", operator) != NULL){
    rezolva_prioritate_0(operatori, forma_poloneza);
  }
}

char* obtine_forma_poloneza(char* forma_normala){
  char* forma_poloneza = malloc(100 * sizeof(char));
  forma_poloneza[0] = '\0';
  
  st_stiva* operatori = NULL;
  
  while(*forma_normala != '\0'){
    if(strchr("(+-*/)", *forma_normala) != NULL){
      push(&operatori, *forma_normala);
      evalueaza_operator(*forma_normala, &operatori, &forma_poloneza);
    } else {
      concatenare_char_la_sir(&forma_poloneza, *forma_normala);
    }
    
    ++forma_normala;
  }

  while(operatori != NULL){
    concatenare_char_la_sir(&forma_poloneza, pop(&operatori));
  }
  
  return forma_poloneza;
}

int main(void){
  char* forma_normala = "a/b*c";

  char* forma_poloneza = obtine_forma_poloneza(forma_normala);

  printf("%s\n", forma_poloneza);
  
  free(forma_poloneza);
  
  return 0;
}
