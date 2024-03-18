#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int seed = 12;
int *vector_random(int n)
{
  int *r = NULL, i;

  if((r = malloc(n * sizeof(int))) == NULL)
    return NULL;
  
  srand(time(NULL) + seed);
  for (i = 0; i < n; i++)
      r[i] = rand() % 2;

  seed += rand() % 150;
  return r;
}

int is_equal(int n, int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE], int precizie)
{
  int *r = NULL, i, j, br[SIZE], cr[SIZE], abr[SIZE], pas = 1;

  while(precizie)
    {
      for(i=0; i<n; i++)
	{
	  br[i] = 0;
	  cr[i] = 0;
	  abr[i] = 0;
	}
      
      r = vector_random(n);
      
      for(i=0; i<n; i++)
	{
	  for(j=0; j<n; j++)
	    br[i] = br[i] +  b[i][j] * r[j];
	}

      for(i=0; i<n; i++)
	{
	  for(j=0; j<n; j++)
	    abr[i] = abr[i] + a[i][j] * br[j];
	}

      for(i=0; i<n; i++)
	{
	  for(j=0; j<n; j++)
	    cr[i] = cr[i] + c[i][j] * r[j];
	}

      //printare
      
      printf("---------- %d ----------\n\n", pas);

      printf("r = |");
      for(i=0; i<n; i++)
	printf("%d ", r[i]);
      printf("|T\n\n");
      printf("A(Br) = |");
      
      for(i=0; i<n; i++)
	printf("%d ", a[0][i]);
      printf("| * |");
      for(i=0; i<n; i++)
	printf("%d ", b[0][i]);
      printf("| * |%d| = |", r[0]);

      for(i=0; i<n; i++)
	printf("%d ", a[0][i]);
       printf("| * |%d| = |", br[0]);

       printf("%d|\n", abr[0]);
       
      for(i=1; i<n; i++)
	{
	  printf("        |");
	  for(j=0; j<n; j++)
	    printf("%d ", a[i][j]);
	  printf("|   |");
	  for(j=0; j<n; j++)
	    printf("%d ", b[i][j]);
	  printf("|   |%d|", r[i]);

	  printf("   |");
	  for(j=0; j<n; j++)
	    printf("%d ", a[i][j]);
	  printf("|   |%d|", br[i]);

	  printf("   |%d|\n", abr[i]);
	}

      printf("\nCr = |");
      for(i=0; i<n; i++)
	printf("%d ", c[0][i]);
      printf("| * |%d| = |%d|\n", r[0], cr[0]);

      for(i=1; i<n; i++)
	{
	  printf("     |");
	  for(j=0; j<n; j++)
	    printf("%d ", c[i][j]);

	  printf("|   |%d|", r[i]);
	  printf("   |%d|\n", cr[i]);
	}
      printf("\nSe compara A(Br) cu Cr.\n\n");
      //terminare printare
      
  
      for(i=0; i<n; i++)
	if(abr[i] != cr[i])
	  return 0;
      
      free(r);
      r = NULL;
      pas ++;
      precizie --;
    }

  return 1;
}

int main(void)
{
  int n, a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], i, j, precizie;

  scanf("%d", &n);

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &(a[i][j]));

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &(b[i][j]));

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &(c[i][j]));

  scanf("%d", &precizie);

  if(is_equal(n, a, b, c, precizie) == 1)
    printf("=> AB = C\n");
  else
    printf("=> AB != C\n");
  return 0;
}



/*

  
  / 1 0 0 \
  | 0 1 0 |
  \ 0 0 1 /
  
*/
