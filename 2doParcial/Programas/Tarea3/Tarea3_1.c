#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

	int respuesta = contar(var);
	
    printf("1's : %d\n",respuesta);
    system("Pause");
}
