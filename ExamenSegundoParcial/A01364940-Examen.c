#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct
{
    uint16_t x;
    uint16_t y;
    double angulo;
    uint8_t tipo;
} Minucia;

typedef struct
{
    Minucia* arreglo;
    uint16_t longitud;
} ArregloMinucias;

ArregloMinucias* crearArregloMinucias(int sizeArreglo) 
{
    ArregloMinucias *amPtr = (ArregloMinucias*)malloc(sizeArreglo*sizeof(ArregloMinucias));
    amPtr->arreglo = (Minucia*)calloc(100, sizeof(Minucia));
    amPtr->longitud=sizeArreglo;
    return amPtr;
}

Minucia* crearMinucia(uint16_t x, uint16_t y, double angulo, uint8_t tipo)
{
    Minucia *mi = (Minucia*)malloc(sizeof(Minucia));
    mi->x=x;
    mi->y=y;
    mi->angulo=angulo;
    mi->tipo=tipo;
    return mi;
}

char * devolverTipoMinucia(Minucia *mi)
{
    //mask 00000011
    //&
    //ya que nos importa saber solo sus ultimos dos bits
    uint8_t mask=0x03;
    uint8_t tipo=mi->tipo;
    char tipoStr[]="";

    if((tipo & mask)==0){
        return "Valor Tipo Minuncia: TERMINACION\n";
    }
    if((tipo & mask)==1){
        return "Valor Tipo Minuncia: DIVISION\n";
    }
    if((tipo & mask)==2){
        return "Valor Tipo Minuncia: PUNTO\n";
    }
    if((tipo & mask)==3){
        return "Valor Tipo Minuncia: DESCONOCIDO\n";
    }
}

double calcularDistancia(Minucia *p1, Minucia *p2)
{
    double dif1 = pow(p1->x - p2->x, 2);
    double dif2 = pow(p1->y - p2->y, 2);

    double dist = sqrt(dif1+dif2);

    return dist;
}

Minucia* encontrarCentroide(ArregloMinucias *aPtr)
{
    //Minuncia minima a regresar se asume que es la primera la de menor distancia con todas
    Minucia *minuciaMinima;
    minuciaMinima=&aPtr->arreglo[0];
    
    //distancia a comparar
    //minimo que se comparara con distancia
    //empieza en infinito para que la primera vez calculada lo ingrese en minimo
    double distancia=0;
    double minimo=INFINITY;

    //Para comparar todas las minucias con hasta consigo misma sumando sus distancias
    //No se valida que no se sume consigo misma ya que la suma de eso es 0
    int i,j;
    for(i=0;i<aPtr->longitud;i++)
    {
        for(j=0;j<aPtr->longitud;j++)
        {
            //Acumular la distancia para que sea distancia con todos
            distancia = distancia + calcularDistancia(&aPtr->arreglo[i],&aPtr->arreglo[j]);
        }
        if(distancia<minimo) 
        {
            //Cambia el apuntador de la minuciaMinima si tiene menor distancia acumulada que el anterior
            minuciaMinima=&aPtr->arreglo[i];

            minimo = distancia;            
        }
        //Se reinicia el contador para seguir con otra minucia
        distancia = 0;
    }
    return minuciaMinima;
}

void freeQueue(ArregloMinucias* arregloMin)
{
    free(arregloMin->arreglo);

    free(arregloMin);
}

int main()
{
    //Declarar variables para escanear
    uint16_t sizeArr=0,auxSize;
    uint16_t x, cordX;
    uint16_t y, cordY;
    double angulo;
    uint8_t tipo;

    //pedir dimension arreglo
    printf("Dimension de Arreglo de Minucias: ");
    scanf("%d",&sizeArr);
    //Se perdia el valor por eso se genera ese auxiliar del mismo tipo de variable
    auxSize = sizeArr;

    //Crear el arreglo de Minucias con la dimension pedida
    ArregloMinucias *arrPtr = crearArregloMinucias(auxSize);

    printf("\n");
    printf("**********************************************************\n");
    printf("***    IMPRIMIENDO DATOS MINUCIAS INICIALIZADO EN 0    ***\n");
    printf("**********************************************************\n");

    int i;    
    for(i=0;i<auxSize;i++)
    {
        printf("\n--- MINUNCIA %d ---\n",i);
        printf("Coordenada X       : %d\n", arrPtr->arreglo[i].x);
        printf("Coordenada Y       : %d\n", arrPtr->arreglo[i].y);
        printf("Angulo             : %lf\n",arrPtr->arreglo[i].angulo);
        printf("Valor Tipo Minuncia: %d\n", arrPtr->arreglo[i].tipo);
    }

    printf("\n");
    printf("**********************************************************\n");
    printf("***                  ESCANEO DE DATOS                  ***\n");
    printf("*** Tipo Segun 2 Ultimos Bits                          ***\n");
    printf("*** 00-Terminacion 01-Division 10-Punto 11-Desconocido ***\n");
    printf("**********************************************************\n");

    for(i=0;i<auxSize;i++)
    {
        //1. Pedir cada valor para cada campo de Minuncia
        printf("\n--- MINUNCIA %d ---\n",i);
        
        printf("Coordenada X       : ");
        scanf("%d",&x);
        //Se perdia el valor por eso se genera ese auxiliar del mismo tipo de variable
        cordX=x;
        
        printf("Coordenada Y       : ");
        scanf("%d",&y);
        //Se perdia el valor por eso se genera ese auxiliar del mismo tipo de variable
        cordY=y;

        printf("Angulo             : ");
        scanf("%lf",&angulo);
 
        printf("Valor Tipo Minuncia: ");
        scanf("%d",&tipo);
        
        //2. Crear Minuncia con su apuntador
        arrPtr->arreglo[i].x=crearMinucia(cordX,cordY,angulo,tipo)->x;
        arrPtr->arreglo[i].y=crearMinucia(cordX,cordY,angulo,tipo)->y;
        arrPtr->arreglo[i].angulo=crearMinucia(cordX,cordY,angulo,tipo)->angulo;
        arrPtr->arreglo[i].tipo=crearMinucia(cordX,cordY,angulo,tipo)->tipo;
        
    }

    printf("\n");
    printf("**********************************************************\n");
    printf("***       IMPRIMIENDO DATOS MINUCIAS Y SUS TIPOS       ***\n");
    printf("**********************************************************\n");
    
    for(i=0;i<auxSize;i++)
    {
        printf("\n--- MINUNCIA %d ---\n",i);
        printf("Coordenada X       : %d\n", arrPtr->arreglo[i].x);
        printf("Coordenada Y       : %d\n", arrPtr->arreglo[i].y);
        printf("Angulo             : %lf\n",arrPtr->arreglo[i].angulo);
        printf("Valor Tipo Minuncia: %d\n", arrPtr->arreglo[i].tipo);
        
        printf(devolverTipoMinucia(&arrPtr->arreglo[i]));
    
    }

    printf("\n");
    printf("**********************************************************\n");
    printf("***               ENCONTRANDO CENTROIDE                ***\n");
    printf("**********************************************************\n");
    
    Minucia* minCentroide = encontrarCentroide(arrPtr);
    printf("\n---  CENTROIDE  ---\n",i);
    printf("Coordenada X       : %d\n", minCentroide->x);
    printf("Coordenada Y       : %d\n", minCentroide->y);
    printf("Angulo             : %lf\n",minCentroide->angulo);
    printf("Valor Tipo Minuncia: %d\n", minCentroide->tipo);
    printf(devolverTipoMinucia(minCentroide));

    free(arrPtr);
    //Use esta parte de codigo para ver si seguia estando apartada la memoria
    //Funciona como esperado: Libera el arreglo de Minuncias
    //Aparece datos raros, pero lo bloqueo para evitar que funcione erroneamente con el resto del codigo
    
    /*printf("\n");
    printf("**********************************************************\n");
    printf("***   IMPRIMIENDO DATOS MINUCIAS LIBERANDO EL ESPACIO  ***\n");
    printf("**********************************************************\n");
  
    for(i=0;i<auxSize;i++)
    {
        printf("\n--- MINUNCIA %d ---\n",i);
        printf("Coordenada X       : %d\n", arrPtr->arreglo[i].x);
        printf("Coordenada Y       : %d\n", arrPtr->arreglo[i].y);
        printf("Angulo             : %lf\n",arrPtr->arreglo[i].angulo);
        printf("Valor Tipo Minuncia: %d\n", arrPtr->arreglo[i].tipo);
    }*/

    return 0;
}
