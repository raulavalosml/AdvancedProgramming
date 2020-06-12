# include "stdio.h"

int main()
{
	int *aPtr;
	int a=10;
	
	aPtr = &a;
	
	printf("%d\n",a);
	printf("%p\n",&a);
	
	printf("%p\n",aPtr);
	printf("%p\n",&aPtr);
	printf("%d\n",*aPtr);
	
	system("pause");
}
