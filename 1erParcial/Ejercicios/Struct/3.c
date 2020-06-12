#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    float E1;
    float E2;
    float T1;
    float T2;
    float EF;
    float NC;
    float NF;
}Student;//para poner un alias

int main()
{
    int num_alumnos;
    printf("Coloca el num de alumnos: ");
    scanf("%d",&num_alumnos);

    Student students[num_alumnos];

    int i;
    for(i=0;i<num_alumnos;i++)
    {
        printf("E1 alumno %d: ",i);
        scanf("%f",&students[i].E1);
        printf("E2 alumno %d: ",i);
        scanf("%f",&students[i].E2);
        printf("T1 alumno %d: ",i);
        scanf("%f",&students[i].T1);
        printf("T2 alumno %d: ",i);
        scanf("%f",&students[i].T2);
        printf("EF alumno %d: ",i);
        scanf("%f",&students[i].EF);
        students[i].NC = (students[i].E1+students[i].E2+students[i].T1+students[i].T2)/(4);
        students[i].NF = (0.7)*(students[i].NC)+(0.3)*(students[i].EF);
        printf("Su NC: %.2f y su NF: %.2f\n",students[i].NC,students[i].NF);
    }

    float sumatoria = 0;
    float promedio;
    printf("***PROMEDIO***\n");
    for(i=0;i<num_alumnos;i++)
    {
        sumatoria = sumatoria + students[i].NF;
    }
    
    promedio = sumatoria/num_alumnos;

    printf("El promedio de todas las NF es: %.2f", promedio);

    printf("\n***MAXIMO***\n");
    float maximum = students[0].NF;

    for (i = 1; i < num_alumnos; i++)
    {
        if (students[i].NF > maximum)
        {
            maximum  = students[i].NF;
        }
    }
    printf("%.2f", maximum);
    
    printf("\n***MINIMO***\n");
    float minimo = students[0].NF;
    for (i = 1; i < num_alumnos; i++)
    {
        if (students[i].NF < maximum)
        {
            minimo  = students[i].NF;
        }
    }

    printf("%.2f\n", minimo);
    getchar();
    getchar();
    return 0;
}


