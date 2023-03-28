#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct 
{
	float x, y;
}point;

float calculateDistance(point p1, point p2)
{
	return sqrt( (pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2)) );
}

int main_RegisterDefinition(int sub)
{
	point p1, p2;
	
	p1.x = 5;
	p2.x = 2;
	
	p1.y = 2;
	p2.y = 2;
	
	printf("Distance from (%f,%f) to (%f,%f) is %f", p1.x, p1.y, p2.x, p2.y, calculateDistance(p1, p2));
}
