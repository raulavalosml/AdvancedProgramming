#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	//aunque pide de 8 bits, se coloca de 32 para poder hacer el desplazamiento
    uint32_t a=0;
    uint32_t b=0;
    uint32_t c=0;
    uint32_t d=0;
    uint32_t final=0;
    
    //el primer valor es el que se coloca mas a la izquierda
    printf("Cadena A: ");
    scanf("%d",&a);
    a<<=24;
    final|=a;
    
    printf("Cadena B: ");
    scanf("%d",&b);
    b<<=16;
    final|=b;

    printf("Cadena C: ");
    scanf("%d",&c);
    c<<=8;
    final|=c;
    
    printf("Cadena D: ");
    scanf("%d",&d);
    final|=d;


	//se imprimen los resultados
	printf("\nDECIMAL: %d\n",final);
    printf("HEXA: %x\n",final);
    

}

