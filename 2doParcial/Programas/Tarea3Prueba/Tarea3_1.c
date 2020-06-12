#include <stdio.h>
#define INT_SIZE sizeof(int) * 8
//este programa es para numeros enteros de 32 bits

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
	
	return ones;	
}

int main()
{
    int num;

    /* pide numero entero */
    printf("Coloca un entero: ");
    scanf("%d", &num);
    
    //funcion para que regrese la cantidad de unos
	int respuesta = unos(num);   
    
    //se cuenta la cantidad de unos
	printf("\nCantidad de 1's: %d", respuesta);

    return 0;
}
