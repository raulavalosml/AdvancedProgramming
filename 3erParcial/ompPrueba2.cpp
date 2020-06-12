#include <omp.h>
#include <stdio.h>

int main(void)
{
	{
		int id= omp_get_thread_num();
		printf("Thread id: %d\n",id);
	}
}
