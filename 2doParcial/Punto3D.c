#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	double x;
	double y;
	double z;
}Punto3D;

double Euclidean3D(Punto3D *p1, Punto3D *p2)
{
	//sqrt((x1-x2)^2 + (y1-y2)^2 + (z1-z2)^2 )
	double dif1 = pow(p1->x-p2->x,2);
	double dif2 = pow(p1->y-p2->y,2);
	double dif3 = pow(p1->z-p2->z,2);
	double dist = sqrt(dif1+dif2+dif3);
	
	return dist;
}

int main()
{
	Punto3D punto1 = {1,2,3};
	Punto3D punto2 = {2,3,4};
	double distancia = Euclidean3D(&punto1,&punto2);
	printf("Distancia: %.2f",distancia);
	return 0;
}
