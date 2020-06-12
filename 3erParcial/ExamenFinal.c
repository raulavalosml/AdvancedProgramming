#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float * valores;
    int filas;
    int columnas
} Matriz;


int main(){
    int i,j;
    int filas, colum;
    Matriz **m1;
    int **m2;
    int **m3;
    //Matriz 1
    printf("Introduce el numero de filas: ");
    scanf("%i",&filas);

    printf("Introduce el numero de columnas: ");
    scanf("%i",&colum);

    m1=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m1[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%f",&m1[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%f ",m1[i][j]);
        }
        printf("\n");
    }
    /*
    //Matriz 2
    printf("Ingrese la segunda matriz: ");
    m2=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m2[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%i",&m2[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%i ",m2[i][j]);
        }
        printf("\n");
    }
    //Matriz 3
    printf("La suma de las matrices: \n");

    m3=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m3[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){   
            m3[i][j]=m2[i][j]+ m1[i][j];
            printf("%i ",m3[i][j]);
        }
        printf("\n");
    }

    printf("Dir de matriz 3: %i",&m3);*/

    return 0;
}
