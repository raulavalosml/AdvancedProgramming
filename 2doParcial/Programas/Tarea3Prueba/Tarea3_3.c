#include <stdio.h>
#define INT_SIZE sizeof(int) * 8

char hex[]="";                          // here is the hex string

void imprime(num)
{
	int c,k;
	for (c = INT_SIZE-1-28; c >= 0; c--)
	{
	   
		k = num >> c;
	    if (k & 1)
	    {
	    	printf("1");
			strcat(hex,"1");				
		}  
	    else
	    {
	    	printf("0");
			strcat(hex,"0");	
		}    
		
	}
}

void imprime2(num)
{
	int c,k;
	for (c = INT_SIZE-1-28; c >= 0; c--)
	{
	   
		k = num >> c;
	    if (k & 1)
	    {
	    	printf("1");
			//strcat(hex,"1");				
		}  
	    else
	    {
	    	printf("0");
			//strcat(hex,"0");	
		}    
		
	}
}

int main()
{
	//los numeros deben van de 0 a 15 --> 4 bits
	//aqui se colocan los 4 numeros
	int num1,num2,num3,num4;
	printf("Coloca un entero 1: ");
	scanf("%d", &num1);
	printf("La cadena binaria de ese numero es: ");
	imprime(num1);
    printf("\n");
    
	printf("Coloca un entero 2: ");
    scanf("%d", &num2);
    printf("La cadena binaria de ese numero es: ");
	imprime(num2);
    printf("\n");
    
	printf("Coloca un entero 3: ");
    scanf("%d", &num3);
    printf("La cadena binaria de ese numero es: ");
	imprime(num3);
    printf("\n");
    
	printf("Coloca un entero 4: ");
    scanf("%d", &num4);
    printf("La cadena binaria de ese numero es: ");
	imprime(num4);
    printf("\n");
    //
    
    
    printf("\nLa cadena resultante es (Binario): ");
	//solo para juntar la cadena binaria de cada uno de los numeros
	//donde realmente se tranforma a hexadecimal y decimal la serie de caracteres es en imprime
	imprime2(num1);
    imprime2(num2);
    imprime2(num3);
	imprime2(num4);
	
	printf("\nLa cadena resultante es (Decimal): ");
	//en esta funcion se transforma del string binario a un entero
	int num = (int)strtol(hex, NULL, 2);
	printf("%d\n", num);                       
	
	printf("La cadena resultante es (Hexadecimal): ");
	printf("%X\n", num);
}
