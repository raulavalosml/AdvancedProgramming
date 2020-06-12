#include<stdio.h>
int main() {
    int pisos, num=1, space, i, j;
    
	printf("Numero de pisos: ");
    
	scanf("%d", &pisos);
    
	for (i=0; i<pisos; i++) 
	{
        for (space=1; space <= pisos-i; space++)
            printf("  ");
        
		for (j=0; j<=i; j++) 
		{
            if (j==0 || i==0)
                num = 1;
            else
                num=num*(i-j+1)/j;
            printf("%4d", num);
        }
        printf("\n");
    }
    return 0;
}

