#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "puntos.h"

struct punto{
    float x,y;
};

struct distPunto{
    float dist;
    float x,y,xx,yy;
};





int main(){

    printf("Daniel Alejandro Villegas Romero A01365286\n");
    printf("Raul Ivan Avalos Mu%coz Ledo A01364940\n",164);

    int pNum;
    printf("Cuantos puntos en el plano: ");
    scanf("%d",&pNum);

    struct punto puntoComp[pNum];
    struct distPunto puntoMax[pNum];
    
    
    for (int i = 0; i < pNum; i++)
    {
        printf("Ingrese el punto %d x: ",i+1);
        scanf("%f",&puntoComp[i].x);
        printf("Ingrese el punto %d y: ",i+1);
        scanf("%f",&puntoComp[i].y);
    }


int c=0;
    for(int i =0; i<pNum;i++)
    {
        for(int j=i+1;j<pNum;j++)
        {
            
            puntoMax[c].dist=POINTdist(puntoComp[i].x,puntoComp[i].y,puntoComp[j].x,puntoComp[j].y);
            puntoMax[c].x=puntoComp[i].x;
            puntoMax[c].y=puntoComp[i].y;
            puntoMax[c].xx=puntoComp[j].x;
            puntoMax[c].yy=puntoComp[j].y;

            c++;
        }
        printf("%0.1f\n",puntoMax[i].dist);
    }

    float minimo=puntoMax[0].dist;
 
    float x1=puntoMax[0].x;
    float y1=puntoMax[0].y;
    float x2=puntoMax[0].xx;
    float y2=puntoMax[0].yy;

    float s,p;

    for(int i=0;i<pNum;i++){
        if(puntoMax[i].dist<minimo)
        {
            minimo=puntoMax[i].dist;
            x1=puntoMax[i].x;
            printf("%0.1f",x1);
            y1=puntoMax[i].y;
            printf("%0.1f",y1);
            x2=puntoMax[i].xx;
            printf("%0.1f",x2);
            y2=puntoMax[i].yy;
            printf("%0.1f",y2);
        }
        s=s+puntoMax[i].dist;
    }
    p=s/pNum;
    printf("MINIMO: %0.1f ENTRE LOS PUNTOS: %0.1f,%0.1f  Y %0.1f,%0.1f \nPROM:%0.1f",minimo,x1,y1,x2,y2,p);
    getche();
}

