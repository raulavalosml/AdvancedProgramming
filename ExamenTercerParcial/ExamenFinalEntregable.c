#include <omp.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    float* valores;
    int filas;
    int columnas;
} Matriz;

Matriz* crearMatriz(int filas, int columnas) {
    int longitud = filas * columnas;
    Matriz *mati = (Matriz*)malloc(longitud*sizeof(Matriz));
    mati->valores = (float*)calloc(longitud , sizeof(float));
    mati->filas = filas;
    mati->columnas = columnas;
    //printf("\nArreglo creado\n");
    return mati;
}

Matriz* Multiplicar(Matriz* matriz1, Matriz* matriz2){
    float sum;
    Matriz* mult=crearMatriz(matriz1->filas, matriz2->columnas);
    if(matriz1->columnas==matriz2->filas){
        for (int c = 0 ; c < matriz1->filas ; c++ )
        {
            for (int d = 0 ; d < matriz2->columnas ; d++ )
            {
                #pragma omp parallel for reduction(+:sum)
                for (int k = 0 ; k < matriz2->filas ; k++ )
                {
                    sum += matriz1->valores[c*matriz1->columnas+k]*matriz2->valores[k*matriz2->columnas+d];
                }
                mult->valores[c*mult->columnas+d] = sum;
                //printf("Suma de mult: %f \n",sum);
                sum = 0;
            }
        }
        return mult;
    }
    else
    {
        return NULL;
    }
    
}

Matriz* Transpuesta(Matriz* matriz){
    Matriz* trans = crearMatriz(matriz->columnas,matriz->filas);
    for (int filas = 0; filas < matriz->filas;filas++){
        #pragma omp parallel for
        for (int columnas=0;columnas<matriz->columnas;columnas++) {
            trans->valores[columnas*matriz->filas+filas] = matriz->valores[filas*matriz->columnas+columnas];
        }
    }
    return trans;
}

float* SumarFilas(Matriz* matriz){
    float* sumaArreglos;
    sumaArreglos = (float*)calloc(matriz->filas , sizeof(float));
    for(int filas=0;filas<matriz->filas;filas++){
        #pragma omp parallel for reduction(+:sumaArreglos[filas])
        for(int columnas=0;columnas<matriz->columnas;columnas++){
            sumaArreglos[filas]+=matriz->valores[filas*matriz->columnas+columnas];
        }
    }
    return sumaArreglos;
}

float* SumarColumnas(Matriz* matriz){
    float* sumaArreglos;
    sumaArreglos = (float*)calloc(matriz->columnas , sizeof(float));
    for(int columnas=0;columnas<matriz->columnas;columnas++){
        #pragma omp parallel for reduction(+:sumaArreglos[columnas])
        for(int filas=0;filas<matriz->filas;filas++){
            sumaArreglos[columnas]+=matriz->valores[filas*matriz->columnas+columnas];
        }
    }
    return sumaArreglos;
}

Matriz* Broadcasting(Matriz* matriz){
    if(matriz->columnas==1||matriz->filas==1){
        if(matriz->columnas==1 && matriz->filas>1){
            int n=matriz->filas;
            Matriz* broad = crearMatriz(matriz->filas,matriz->filas);
            for(int filas=0;filas<broad->filas;filas++){
                #pragma omp parallel for
                for(int columnas=0;columnas<broad->columnas;columnas++){
                    broad->valores[columnas*broad->filas+filas]=matriz->valores[columnas];
                }
            }
            return broad;
        }
        if(matriz->filas==1 && matriz->columnas>1){
            //printf("Entro al if");
            int n=matriz->filas;
            Matriz* broad = crearMatriz(matriz->columnas,matriz->columnas);
            for(int filas=0;filas<broad->filas;filas++){
                #pragma omp parallel for
                for(int columnas=0;columnas<broad->columnas;columnas++){
                    broad->valores[filas*broad->columnas+columnas]=matriz->valores[columnas];
                }
            }
            return broad;
        }
    }
    return NULL;
    
}

int main(){

    printf("Creadores maestros:\n");
    printf("Raul Ivan Avalos Mu%coz Ledo\n",164);
    printf("Daniel Alejandro Villegas Romero\n");

    int filas=3;
    int columnas=2;
    int aux = 0;
    
    Matriz* mati1 = crearMatriz(filas,columnas);
    mati1->valores[0] = 0;
    mati1->valores[1] = 1;
    mati1->valores[2] = 11;
    mati1->valores[3] = 22;
    mati1->valores[4] = 4;
    mati1->valores[5] = 17;
    int filas2=2;
    int columnas2=4;
    Matriz* mati2 = crearMatriz(filas2,columnas2);
    mati2->valores[0] = 0;
    mati2->valores[1] = 1;
    mati2->valores[2] = 11;
    mati2->valores[3] = 22;
    mati2->valores[4] = 4;
    mati2->valores[5] = 17;
    mati2->valores[6] = 4;
    mati2->valores[7] = 17;
    printf("\nPrimera Matriz\n");
    for(int i=0;i<filas*columnas;i++){
        aux++;
        printf(" %.2f ",mati1->valores[i]);
        if(aux==columnas){
            printf("\n");
            aux=0;
        }
        
        //printf("\n");
    }
    printf("\nSegunda Matriz\n");
    aux = 0;
    for(int i=0;i<filas2*columnas2;i++){
        aux++;
        printf(" %.2f ",mati2->valores[i]);
        if(aux==columnas2){
            printf("\n");
            aux=0;
        }
        
        //printf("\n");
    }
    
    printf("\nSuma de filas\n");
    float* suma = SumarFilas(mati1);
    for(int filas=0;filas<mati1->filas;filas++){
        printf("%.2f\n",suma[filas]);
    }

    printf("\nSuma de columnas\n");
    SumarColumnas(mati1);

    Matriz* trans=Transpuesta(mati1);
    
    printf("\nMatriz transpuesta\n");
    for(int i=0;i<filas*columnas;i++){
        aux++;
        printf(" %.2f ",trans->valores[i]);
        if(aux==trans->columnas){
            printf("\n");
            aux=0;
        }
        
        //printf("\n");
    }

    Matriz* mult = Multiplicar(mati1, mati2);
    printf("\nMultiplicar la matriz: \n");
    aux = 0;
    for(int i=0;i<mult->filas*mult->columnas;i++){
        aux++;
        printf(" %.2f ",mult->valores[i]);
        if(aux==mult->columnas){
            printf("\n");
            aux=0;
        }
        
        //printf("\n");
    }

    int filas3=3;
    int columnas3=1;
    Matriz* mati3 = crearMatriz(filas3,columnas3);
    mati3->valores[0] = 0;
    mati3->valores[1] = 1;
    mati3->valores[2] = 11;
    Matriz* chida = Broadcasting(mati3);

    printf("\nBroad: \n");
    aux = 0;
    for(int i=0;i<chida->filas*chida->columnas;i++){
        aux++;
        printf(" %.2f ",chida->valores[i]);
        if(aux==chida->columnas){
            printf("\n");
            aux=0;
        }
        
        //printf("\n");
    }

    //system("pause");

}

