#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int contador;
float min=10000;
int creditoN=0;

typedef struct employee
{
    char nombre[10];
    int salario;
    int edad;
    int credito;

}Empleado;

void leer_csv()
{
	system("cls");
	FILE *datos;
	datos = fopen("salaries.csv", "r");
	char c = getc(datos);
	while (c != EOF) 
	{ // -1
		//putc(c, resultado);	
		printf("%c",c);
		c = getc(datos);
	}
	fclose(datos);
	printf("\n");
	system("pause");
}

int contarFilas()
{
	int lines=0,ch;
	system("cls");
	FILE *datos;
	datos = fopen("salaries.csv", "r");

	while(!feof(datos))
	{
	  ch = fgetc(datos);
	  if(ch == '\n')
	  {
	    lines++;
	  }
	}
	fclose(datos);
	return lines;
}

float DistanciaEuclidiana(int C1X, int C1Y, int C2X, int C2Y)
{
	float s = 0;
	
	s += (pow((C1X - C2X),2) + pow((C1Y - C2Y),2));
       	
    s=sqrt(s);
       		
	return s;
}

void agregar_datos(char nombre[10], int salario, int edad, int credito)
{
	FILE *salaries;
	salaries=fopen("salaries.csv","a+");
	fprintf(salaries,"%s,%d,%d,%d\n",nombre,salario,edad,credito);
	fclose(salaries);
	printf("Datos agregados\n");
	system("pause");
}

float MasParecido(float dis, int credito)
{
	//printf("Credito ini: %f\n",credito);
	if(dis<min)
	{
		min=dis;
		creditoN=credito;
	}
	//printf("min: %f\n",min);
	//printf("credito %f creditoN %f \n",credito,creditoN );
	//getche();
	return creditoN;

}

float llenarStruct(int lines, char name[10], int sal, int edad)
{
	int pos=0;
	Empleado empleados[lines-1], empleadoN;
	char str[256];
	system("cls");
	FILE *datos;
	datos = fopen("salaries.csv", "r");
	fgets (str, 256, datos);
	while(1)
	{
		if( fgets (str, 256, datos)!=NULL ) {
			char * token = strtok(str,",");
			while (token !=NULL) 
			{ 
				strcpy(empleados[pos].nombre,token);	
				token = strtok(NULL, ",");
				empleados[pos].salario=atoi(token);
				token = strtok(NULL, ",");
				empleados[pos].edad=atoi(token);		
				token = strtok(NULL, ",");
				empleados[pos].credito=atoi(token);	
				token = strtok(NULL, ",");
				pos++;
				//printf("datos empleado struct: %s, %d, %d, %d\n",empleados[pos].nombre, empleados[pos].salario, empleados[pos].edad, empleados[pos].credito );
			}	
	   	}
	   	else 
	   		break;
	}
	//printf("datos empleado: %s, %d, %d, %d\n",empleados[2].nombre, empleados[2].salario, empleados[2].edad, empleados[2].credito );
			
	
	fclose(datos);
	printf("\n");
	//system("pause");

	strcpy(empleadoN.nombre,name);	
	empleadoN.salario=sal;
	empleadoN.edad=edad;		
	empleadoN.credito=-1;	
	float dis;
	float creditoNuevo;
	int i;
	for(i=0;i<lines-1;i++)
	{
		dis=DistanciaEuclidiana(empleados[i].edad,empleados[i].salario,empleadoN.edad,empleadoN.salario);
		//printf("DistanciaEuclidiana: %f\n",dis);
		//printf("credito a enviar: %d\n",empleados[i].credito );
		creditoNuevo=MasParecido(dis,empleados[i].credito);
	}
	empleadoN.credito=creditoNuevo;
	return creditoNuevo;
}

int main()
{
	int op;

	while(op!=4)
	{
		printf("Elija una opcion\n");
		printf("1- Mostrar todos los datos del empleado.\n");
		printf("2- Agregar un nuevo empleado al archivo.\n");
		printf("3- Predecir el credito para un nuevo empleado.\n");
		printf("4- Salir.\n");
		scanf("%d",&op);
		if(op>4)
		{
			system("cls");
			printf("Esa opcion no existe\n");
			system("pause");
			system("cls");
		}
		

		if(op==1)
		{
			leer_csv();
		}

		if(op==2)
		{
			system("cls");
			char nombre[10];
		    int salario;
		    int edad;
		    int credito;
		    char falso[10];
		    gets(falso);
			printf("Nombre del empleado: ");
			gets(nombre);
			printf("Salario del empleado: ");
			scanf("%d",&salario);
			printf("Edad del empleado: ");
			scanf("%d",&edad);
			printf("Credito del empleado: ");
			scanf("%d",&credito);
			agregar_datos(nombre,salario,edad,credito);
		}

		if(op==3)
		{

			system("cls");
			contarFilas();
			char nombre[10];
		    int salario;
		    int edad;
		    int lines = contarFilas();
		    char falso[10];
		    gets(falso);
			printf("Nombre del empleado: ");
			gets(nombre);
			printf("Salario del empleado: ");
			scanf("%d",&salario);
			printf("Edad del empleado: ");
			scanf("%d",&edad);
			float final=0;

			
			final=llenarStruct(lines,nombre, salario, edad);
			
			printf("El credito seria de: %.2f\n",final);
			//compararEdad()
			system("pause");
			min=10000;
			creditoN=0;

		}	

		if(op==4)
		{
			exit(0);
		}

		system("cls");
	}
}
