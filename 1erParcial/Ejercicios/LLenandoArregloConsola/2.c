#include "stdio.h"

int main(void)
{
    unsigned int arraySize;

    scanf("%u", &arraySize);

    int a[arraySize];

    int i;
	int j;
    for(i=0; i<arraySize;i++)
        scanf("%u", &a[i]);

    puts("These are the elements of the array: ");
    for(i =0; i<arraySize;i++)
        printf("%u ",a[i]);
    

    printf("\n");

    for(i=0; i<arraySize;i++)
    {
        int val = a[i];
        for(j=0; j<val;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
