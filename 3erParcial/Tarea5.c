#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//Daniel Alejandro Villegas Romero
//Raul Ivan Avalos Muñoz Ledo


/*Ejercicio 1: Factorial*/

int main()
{
    char *str;
    str = (char *) malloc(15);
    int n, i, hilos;
    unsigned long long fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Enter an integer hilos: ");
    scanf("%d", &hilos);

    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        omp_set_num_threads(hilos);
        #pragma omp parallel for reduction(* : fact)
        for (i = 1; i <= n; ++i) {
            int ID = omp_get_thread_num();
            fact *= i;
            printf("El hilo %d tiene: %d\n",ID,fact);
        }
        printf("Factorial of %d = %llu", n, fact);
    }
}




//Ejercicio 2 Multiplicacion de Matrices

/*
int main(){  
    int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;    
    printf("Multiplicacion de Matrices cuadradas (Max 10x10)");
    system("cls");  
    printf("enter the number of n (nxn):");    
    scanf("%d",&r);    
    //printf("enter the number of column=");    
    //scanf("%d",&c);    
    printf("enter the first matrix element=\n");    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<r;j++)    
        {    
            scanf("%d",&a[i][j]);    
        }    
    }    
    
    printf("enter the second matrix element=\n");    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<r;j++)    
        {    
            scanf("%d",&b[i][j]);    
        }    
    }    
    
    int hilos;
    printf("Numero de Hilos: ");
    scanf("%d",&hilos);
    omp_set_num_threads(hilos);   
    int ID; //para saber en que va de hilo
    
    #pragma omp parallel for
    for(i=0;i<r;i++)    
    {
        ID = omp_get_thread_num(); 
        printf("Thread=%d did row=%d\n",ID,i);       
        for(j=0;j<r;j++)    
        {    
            mul[i][j]=0;   
            for(k=0;k<r;k++)    
            {       
                mul[i][j]+=a[i][k]*b[k][j];
            }
        } 
    }        
    

    //for printing result    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<r;j++)    
        {    
            printf("%d\t",mul[i][j]);    
        }    
            printf("\n");    
    }    
    return 0;  
} */