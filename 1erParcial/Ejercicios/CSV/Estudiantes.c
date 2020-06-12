# include <stdio.h>
# include <String.h>
int op;

void crearArchivo()
{
    system("CLS");
    FILE *fp;

    fp = fopen("Estudiantes.csv", "a+");
    fprintf(fp, "Nombre, Carrera, Matematicas, Fisica, Computacion\n");
    //fputs("This is testing for fputs...\n", fp);
    fclose(fp);
    //printf("Archivo creado");
}


void mostrarArchivo()
{
    system("CLS");
    FILE *fp;

    fp = fopen("Estudiantes.csv", "r");
    char c = getc(fp);

    while (c!=EOF)
    {
        printf("%c",c);
        c=getc(fp);
    }
    

    fclose(fp);
    

}

void agregarEstudiante()
{
    FILE *fp;

    char carrera[30];
    char 

    fp = fopen("Estudiantes.csv", "a+");
    fprintf(fp, "Nombre, Carrera, Matematicas, Fisica, Computacion\n");
    fclose(fp);
}


int main()
{
    printf("***ESTUDIANTES.CSV***\n\n");
    printf("1) Crear archivo\n");
    printf("2) Mostrar archivo\n");
	printf("3) Agregar nuevo estudiante\n");
	printf("4) Promedio computacion\n");	
	printf("5) Nombre calificacion mas alta fisica\n");
    printf("6) Archivo Carrera");

    printf("Seleccione una opci%cn: "); 
    scanf("%d",&op);

    if (op==1) crearArchivo();
	if (op==2) mostrarArchivo();
	if (op==3) agregarEstudiante();
    /*if (op==3) consulta_rfc();
	if (op==4) lista_apellido();
	if (op==5) saldo_institucion();
	if (op==6) saldo_sucursal();
	if (op==7) consulta_sucursal_clave();
	if (op==8) listar_sucursales();
    */
    
    getche();
    return 0;
}

