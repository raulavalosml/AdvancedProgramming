#include <stdio.h>
#include <stdlib.h>

int x;

void printAsterisc(int number,int auxiliar){
    int i=0;
    int b=0;
    for ( b; b < auxiliar; b++)
    {
        printf(" ");
    }
    
    for ( i ; i < number; i++)
    {
        printf("* ");
    }
}

int main(){
    
    printf("Ingrese un numero: \n");
    scanf("%d",&x);

    int i=0;
    int auxiliar=x;
    for (i ; i <= x; i++)
    {
        
        printAsterisc(i,auxiliar);
        auxiliar--;
        printf("\n");
        /* code */
    }
    
    getchar();
    getchar();

    return 0;
    
}