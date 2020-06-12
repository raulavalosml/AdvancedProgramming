#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int comparar(int num)
{
	uint8_t var2;
    printf("Ingrese un numero decimal de max 8 bits: ");
    scanf("%d",&var2);
    
    
	int cantidadA = contar(num);
	int cantidadB = contar(var2);
	int mensaje;
	
    printf("A 1's : %d\n",cantidadA);
    printf("B 1's : %d\n",cantidadB);
    
    if(cantidadA > cantidadB)
	{
		mensaje =  1;
	}
	else if(cantidadA<cantidadB)
	{
		mensaje =  -1;
	}
	else if(cantidadA==cantidadB)
	{
		mensaje =  0;
	}
    
    return mensaje;
    
}

int contar(int num)
{
    uint8_t mask=1;
    int numB = 8; //numeros de 8 bits
	int ones=0;
    int i;
    for(i=0;i<numB;i++)
    {
        if(num & mask)
        {
            ones++;
        }
        mask<<=1;
    }
    
    return ones;
}


int main(){
    uint8_t var;
    printf("Ingrese un numero decimal de max 8 bits: ");
    scanf("%d",&var);

    int respuesta = comparar(var);
	
    printf("\nRESPUESTA: %d\n",respuesta);
	system("Pause");
}
