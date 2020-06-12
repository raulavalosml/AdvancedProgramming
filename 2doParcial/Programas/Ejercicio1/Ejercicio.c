#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t flagBit = 0x59; //0101 1001
                           // &
    uint8_t mask = 8;       //0000 1000
                            //dos opciones que todo sea 0000 0000
                            // o que sea 0000 1000 --> cambia todo menos el 1 de la mask
                            
                            
    //con or
    //	0101 1001
    //		|
    //  0000 1000
    //	0101 0001 -->lo deja igual excepto el que tiene 1 en la mask

    //1. comprobar si es 1 o 0 el 3er bit
    // 1&1 = 1      //1&0=0
    if(flagBit & mask)
        printf("El valor del tercer bit es: %d\n",1);
    else
        printf("El valor del tercer bit es: %d\n",0);

    //2. Reiniciar el tercer bit (hacerlo 0)
    flagBit &= ~mask;
	printf("%x\n", flagBit);
	
    //3. Establecer el tercer bit (hacerlo 1)
	flagBit |= mask;
	printf("%x\n",flagBit);

    //4. Negar el tercer bit (invertir su valor)
	flagBit ^= mask;
	printf("%x\n",flagBit);
}

