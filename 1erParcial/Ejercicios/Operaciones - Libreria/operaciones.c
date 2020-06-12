#include <operaciones.h>
#include <stdio.h>

double x;
double y;
int op;
double respuesta;

int main()
{
    printf("Ingrese un numero: \n");
    scanf("%lf",&x);

    printf("Ingrese un numero: \n");
    scanf("%lf",&y);

    printf("Ingrese la opcion: \n");
    scanf("%d",&op);

    if(op==1)
    {
        respuesta=sum(x,y);
    }

    if(op==2)
    {
        respuesta=diff(x,y);
    }

    printf("La respuesta es: %lf",respuesta);
}