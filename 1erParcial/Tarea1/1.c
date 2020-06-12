# include <stdio.h>

int main()
{
	int num = 0;
	
	printf("Selecciona el numero: ");
	scanf("%d",&num);
	
	printf("%d, ",num);
	while(num!=1)
	{
		if(num%2==0)
		{
			num = num/2;
		}
		else
		{
			num=(num*3)+1;
		}
		printf("%d, ",num);
	}
}
