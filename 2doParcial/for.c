#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main()
{
	int i;
	
    int longitud;
    scanf("%d",&longitud);
    int aux = longitud;
	for(i=0;i<aux;i++)
	{
		uint16_t x,y;
	    uint8_t tipo;
	    double angulo;
        printf("Ingrese los valores de la minucia %d\n",i);
        printf("x= ");
        scanf("%d",&x);
        printf("y= ");
        scanf("%d",&y);
        printf("tipo= (0=terminacion, 1=division, 2=punto, 3=desconocido)  ");
        scanf("%d",&tipo);
        printf("Angulo= ");
        scanf("%lf",&angulo);
        //printf("longitud= %d",longitud);
        //longitud = aux;
	}
}
