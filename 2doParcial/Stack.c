#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodoQueue
{
    char nombre[20];
    
    struct nodoQueue *next;
};


struct nodoQueue *primero=NULL, *actual=NULL, *ultimo=NULL, *anterior=NULL;
//struct nodoLibro primero, actual, ultimo;

void push(char nom[])
{
	//actual = malloc(sizeof(struct nodoQueue));
	actual = (struct nodoQueue*) malloc(sizeof(struct nodoQueue));
	
	strcpy(actual->nombre,nom);
	
	// creacion de nodos tipo struct
    if(primero == NULL)
    {
        primero = actual;
        primero->next = NULL;
        
        printf("\nPrimer Nodo Libro creado...");
    }
    else
    {
        actual->next = primero;
        primero = actual;
        
        printf("\nNuevo Nodo Libro creado...");
    }
    printf("\nNodo creado en el stack");
}

void consultarQueue()
{
	//int i=1;
    
    if(primero == NULL)
    {
    	printf("Queue vacia...");	
	}
	else
    {
        actual = primero;
        
        while(actual != NULL)
        {
            printf("\n%s",actual->nombre);
            
            actual = actual->next;
            //i++;
        }
    }
}

void pop()
{
	if(primero==NULL)
	{
		printf("QUEUE vacio...");
	}
	else
	{
		printf("\nNodo eliminado del Queue: %s",primero->nombre);
		primero = primero->next;
	}
}


void opciones()
{
    int opcion;
    char name[20];
    
    do
    {
        printf("\n\nQUEUES EN C\n");
        printf("1) PUSH\n");
        printf("2) POP\n");
        printf("3) Consultar QUEUE\n");
        printf("7) Exit\n");
        printf("Opcion = ");
        scanf("%d",&opcion);
        
        if(opcion == 1)
        {
        	printf("Nombre: ");
        	gets(name);
        	gets(name);
        	push(name);
        }
        
        if(opcion == 2)
        {
        	pop();
        }
        
        if(opcion == 3)
        {
        	consultarQueue();
        }
        
       

        
    }while(opcion != 7);
    
    //datosListaArchivo();
}



int main()
{
    //datosArchivoLista();
    opciones();
}
