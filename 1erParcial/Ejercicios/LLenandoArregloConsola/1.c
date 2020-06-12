#include "stdio.h"

int main(void)
{
    unsigned int arraySize;

    scanf("%u", &arraySize);

    int a[arraySize];

    int i;

    for(i=0; i<arraySize;i++)
        scanf("%u", &a[i]);

    puts("These are the elements of the array: ");
    for(i =0; i<arraySize;i++)
        printf("%u ",a[i]);

    return 0;
}