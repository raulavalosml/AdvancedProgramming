#include <stdio.h>
#include <omp.h>

void sumas(int id, int *a)
{
	int suma = a[2*id]+a[2*id+1];
	printf("La suma del hilo %d es: %d + %d = %d\n",id,a[2*id],a[2*id+1],suma);
}

int main()
{
	int *A = calloc(8,sizeof(int));
	int i;
	for (i = 0; i<8;i++)
	{
		A[i] = i +1;
	}
	omp_set_num_threads(4);
	
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		sumas(ID,A);
	}
	free(A);
	printf("Programa Terminado\n");
}
