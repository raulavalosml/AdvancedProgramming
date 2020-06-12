#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double x;
	double y;
	double w;
	double h;
}Rectangle;

typedef struct
{
	double x;
	double y;
	
}Point;

int IfContained(Rectangle *pRect, Point *point)
{
	if(point->x >= pRect->x && point->y >= pRect->y)
	{
		if(point->x <= pRect->x+pRect->w && point->y <= pRect->y+pRect->h)
		{
			return 1;
		}
	}
	return 0;	
}

int main()
{
	Rectangle rect = {0,0,2,2};
	Point p = {2,2.1};
	
	if (IfContained(&rect,&p))
		printf("Esta contenido");
	else
		printf("No esta contenido");
}
