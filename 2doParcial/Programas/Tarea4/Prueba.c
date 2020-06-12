#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j;
    int filas, colum;
    int **m1;
    int **m2;

    printf("Introduce el numero de filas: ");
    scanf("%i",&filas);

    printf("Introduce el numero de columnas: ");
    scanf("%i",&colum);
	
	//Se crea la primer matriz
    m1=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m1[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%i",&m1[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%i ",m1[i][j]);
        }
        printf("\n");
    }
    
    //se crea la segunda matriz
    m1=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m1[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%i",&m1[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%i ",m1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
