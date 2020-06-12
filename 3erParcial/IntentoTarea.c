#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk, n=3;
double	a[n][n],           /* matrix A to be multiplied */
	b[n][n],           /* matrix B to be multiplied */
	c[n][n];           /* result matrix C */

chunk = 10;                    /* set loop iteration chunk size */

/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Starting matrix multiple example with %d threads\n",nthreads);
    printf("Initializing matrices...\n");
    }
  /*** Initialize matrices ***/
  #pragma omp for schedule (static, chunk) 
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      a[i][j]= i+j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      b[i][j]= i*j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      c[i][j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
  printf("Thread %d starting matrix multiply...\n",tid);
  #pragma omp for schedule (static, chunk)
  for (i=0; i<n; i++)    
    {
    printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<n; j++)       
      for (k=0; k<n; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }   /*** End of parallel region ***/

/*** Print results ***/
printf("******************************************************\n");
printf("A Matrix:\n");
for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++) 
    printf("%6.2f   ", a[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf("B Matrix:\n");
for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++) 
    printf("%6.2f   ", b[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf("Result Matrix:\n");
for (i=0; i<n; i++)
  {
  for (j=0; j<n; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf ("Done.\n");
}

