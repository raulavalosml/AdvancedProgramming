# include <stdio.h>

int main()
{
	float x,y,z;
	int op;
	
	printf("Selecciona la opcion: ");
	scanf("%d",&op);
	
	printf("X: ");
	scanf("%f",&x);
	printf("Y: ");
	scanf("%f",&y);
	printf("Z: ");
	scanf("%f",&z);
	
	
	if(op==1)
	{
		printf("\nOPCION1\n");
		float respuesta=x;
		float incremento=y;
		while(respuesta<=z)
		{
			printf("%.2f, ",respuesta);
			respuesta=respuesta+incremento;
		}
	}

	if(op==2)
	{
		printf("\nOPCION2\n");
		float respuesta=x;
		
		float incremento = (z-x)/(y-1);
		while(respuesta<=z)
		{
			printf("%.2f, ",respuesta);
			respuesta=respuesta+incremento;
		}
	}	
}
