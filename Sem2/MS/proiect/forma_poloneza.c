/*
Se dă o expresie aritmetică în formă normală şi valorile fiecărui 
operand al expresiei. Să se calculeze rezultatul expresiei aritmetice.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 200

int prioritate(char ch)
{
  if(ch == '(' || ch == ')')
    return 0;
  
  else if(ch == '*' || ch == '/')
    return 1;

  else
    return 2;

}

int operatie(char ch, int op1, int op2)
{
  if(ch == '+')
    return (op1 + op2);

  else if(ch == '-')
    return (op1 - op2);

  else if(ch == '*')
    return (op1 * op2);

  else
    return (op1 / op2);
}

char *forma_poloneza(char expresie[SIZE])
{
  char *array = NULL;
  char st[SIZE], fp[SIZE];
  int pozitie_st = 0, pozitie_fp = 0, i, j, con;

  for(i=0; i<strlen(expresie); i++)
    {
      if(isalpha(expresie[i]) != 0)
	{
	  fp[pozitie_fp] = expresie[i];
	  pozitie_fp ++;
	}
      else
	{
	  if(expresie[i] == '(')
	    {
	      st[pozitie_st] = expresie[i];
	      pozitie_st ++;
	    }
	  else if(prioritate(expresie[i]) == 1 || prioritate(expresie[i]) == 2)
	    {
	      con = 0;
	      for(j = pozitie_st - 1; j>=0; j--)
		{
		  if(prioritate(st[j]) == 1)
		    {
		      fp[pozitie_fp] = st[j];
		      pozitie_fp ++;
		      con++;
		    }
		  else break;
		}
	      pozitie_st -= con;
	      st[pozitie_st] = expresie[i];
	      pozitie_st ++;
	    }
	  else if(expresie[i] == ')')
	    {
	      con = 0;
	      for(j = pozitie_st - 1; j>=0; j--)
		{
		  if(st[j] == '(')
		    break;
		  else
		    {
		      fp[pozitie_fp] = st[j];
		      pozitie_fp ++;
		      con++;
		    }
		}
	      pozitie_st -= (con + 1);
	    }
	}
    }
  
  if(pozitie_st != 0)
    {
      for(j = pozitie_st - 1; j>=0; j--)
	{
	  fp[pozitie_fp] = st[j];
	  pozitie_fp ++;
	}
    }

  if((array = malloc((pozitie_fp + 1) * sizeof(char))) == NULL)
    return NULL;

  for(i=0; i<pozitie_fp; i++)
    array[i] = fp[i];
  array[pozitie_fp] = 0;
  
  return array;
}

int calcul_expresie(char *array, int valori[SIZE])
{
  int i, rezultat_partial, poz_st = 0, op1, op2;
  char st[SIZE];

  for(i=0; i<strlen(array); i++)
    {
      if(isalpha(array[i]) != 0)
	{
	  st[poz_st] = array[i];
	  poz_st ++;
	}
      else
	{
	  if(isalpha(st[poz_st - 2]) != 0)
	    op1 = valori[st[poz_st - 2] - 'a'];
	  else
	    op1 = (int)st[poz_st - 2];
		     
	  if(isalpha(st[poz_st - 1]) != 0)
	    op2 = valori[st[poz_st - 1] - 'a'];
	  else
	    op2 = (int)st[poz_st - 1];
	  
	  rezultat_partial = operatie(array[i], op1, op2);
	  st[poz_st - 2] = (char)rezultat_partial;
	  poz_st --;
	}
    }
  
  return rezultat_partial; 
}

int main(void)
{
  char expresie[SIZE], *array = NULL;
  int valori[SIZE], nr, size = 0;

  if((fgets(expresie, SIZE, stdin)) == NULL)
    {
      printf("S-a produs o eroare la citire\n");
      exit(-1);
    }

  if(expresie[strlen(expresie) - 1] == '\n')
    expresie[strlen(expresie) - 1] = 0;

  while(scanf("%d", &nr) == 1)
    {
      valori[size] = nr;
      size ++;
    }

  if((array = forma_poloneza(expresie)) != NULL)
    {
      printf("forma poloneza: ");
      printf("%s\n", array);
      printf("rezultatul expresiei: ");
      printf("%d\n", calcul_expresie(array, valori));
    }

  free(array);
  return 0;
}
