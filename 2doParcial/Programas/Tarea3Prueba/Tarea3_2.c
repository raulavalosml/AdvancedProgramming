#include <stdio.h>
#define INT_SIZE sizeof(int) * 8

//este programa es para numeros enteros de 32 bits

//funcion para comparar

int comparar(int a, int b)
{
	printf("Para el numero a: %d\n",a);
	int cantidadA = unos(a);
	printf("Para el numero a: %d\n",b);
	int cantidadB = unos(b);
	
	if(cantidadA > cantidadB)
	{
		return 1;
	}
	else if(cantidadA<cantidadB)
	{
		return -1;
	}
	else if(cantidadA==cantidadB)
	{
		return 0;
	}
}

//funcion para llamar contar los unos e imprimir la cadena binaria del num
int unos(int num)
{
	int ones, c,k;
	
	/*de ese numero se obtiene la cadena binaria*/
    printf("La cadena binaria del numero es: ");
    
	ones = 0;
    for (c = INT_SIZE-1; c >= 0; c--)
	{
	   
		k = num >> c;
	    if (k & 1)
	    {
	    	printf("1");
			ones++;	
		}  
	    else
	    {
	    	printf("0");	
		}
	   	    
	}
	printf("\n");
	return ones;	
}

int main()
{
    int num,num2;

    /* pide numero entero */
    printf("Coloca un entero a: ");
    scanf("%d", &num);
    
    printf("Coloca un entero b: ");
    scanf("%d", &num2);
    
    //funcion para que regrese la cantidad de unos
	//int respuesta = unos(num);   
    int respuesta = comparar(num,num2);
    
    //se cuenta la cantidad de unos
	printf("Respuesta: %d", respuesta);

    return 0;
}
