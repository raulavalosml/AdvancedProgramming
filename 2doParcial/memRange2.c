#include <stdio.h>
#include <stdlib.h>

void myMemsetRange(char *str,char c, int init, int end)
{
	int pos = 0;
	
	while(str[pos] !=0 && pos<=end)
	{
		if(pos>=init && pos<=end)
			str[pos]=c;
		
		//str++; //incrementando el hexadecimal apuntador
		pos++;
	}
}

int main()
{
	char someStr[] = "We love C"; //
	
	myMemsetRange(someStr,'$',3,6);
	
	printf("%s",someStr);
	return 0;
}
