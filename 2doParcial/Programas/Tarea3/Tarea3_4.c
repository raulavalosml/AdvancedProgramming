#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t rotate(uint8_t original, int nBits)
{
	//ejemplo para rotate nBits<0
	//0000 0001 --1
	//0000 0000 >> se dezplaza a la derecha y el ultimo se pierde
	//se camia hasta el otro lado solo importa si el ultimo es uno sino ya se hace automatico
	//1000 0000 --128
	
	//ejemplo para rotate nBits>0
	//1000 0000 --128
	//0000 0000 >> se dezplaza a la izquierda y el ultimo se pierde
	//se camia hasta el otro lado solo importa si el ultimo es uno sino ya se hace automatico
	//0000 0001 --11
	
	uint8_t mask=original;
	uint8_t mensaje;
	uint8_t aux;
	
	mensaje = original;
	if(nBits>0)
	{
		aux = original >> nBits;
		//original >>= nBits;
		mask <<=8-nBits;
		mensaje = mask | aux;		
	}
	else if (nBits<0)
	{
		//para hacer positivo el recorrido
		nBits = nBits*(-1);
		
		aux = original << nBits;
		//original <<= nBits;
		mask >>=8-nBits;
		mensaje = mask | aux;	
			
	}	
	
	//10011001
	
	return mensaje; 
}

int main()
{
	//pedir numero original de 8 bits
	
    uint8_t inicial=0;
    //el primer valor es el que se coloca mas a la izquierda
    printf("Cadena Inicial: ");
    scanf("%d",&inicial);

	int numBits=0;
	printf("Num Bits (+/-): ");
    scanf("%d",&numBits);
	
	uint8_t respuesta = rotate(inicial,numBits);
	
	//se imprimen los resultados
	printf("\nDECIMAL: %d\n",respuesta);
    printf("HEXA: %x\n",respuesta);
    

}
