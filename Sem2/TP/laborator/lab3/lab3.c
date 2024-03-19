#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
  char nume[30];
  uint32_t nota;
  
} student;


int compar_studenti(const void* student_1, const void* student_2){
  student* continut_student_1 = (student*)(student_1);
  student* continut_student_2 = (student*)(student_2);
  
  if(continut_student_1->nota < continut_student_2->nota){
    return 1;
  } else if(continut_student_1->nota == continut_student_2->nota){
    if(strcmp(continut_student_1->nume, continut_student_2->nume) < 0){
      return 1;
    }
  }

  return -1;
  
}

void sorteaza_studenti(student studenti[], size_t numar_studenti){
  qsort(studenti, numar_studenti, sizeof(student), compar_studenti);
}

void citeste_studenti(student studenti[], size_t numar_studenti){
  for(size_t index = 0; index < numar_studenti; ++index){

    scanf("%29s %d", studenti[index].nume, &studenti[index].nota);
    
    //fgets(studenti[index].nume, 30, stdin);
    //    studenti[index].nume[strlen(studenti[index].nume) - 1] = '\0';
 
    //scanf("%d", &studenti[index].nota);
  }
}

void print_student(student s){
  printf("---------------\n");
  printf("%10s | %d|\n", s.nume, s.nota);
}

void afiseaza_studenti(student studenti[], size_t numar_studenti){
  for(size_t index = 0; index < numar_studenti; ++index){
    //    printf(" %s, %d\n", studenti[index].nume, studenti[index].nota);
    printStudent(studenti[index]);
    //    printf("nota: %d\n", studenti[index].nota);
  }
}

int main(void){
  size_t numar_studenti;
  scanf("%lu", &numar_studenti);
  student studenti[numar_studenti];

  citeste_studenti(studenti, numar_studenti);

  sorteaza_studenti(studenti, numar_studenti);

  afiseaza_studenti(studenti, numar_studenti);
  
  return 0;
}
