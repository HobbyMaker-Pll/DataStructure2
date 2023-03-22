#include <stdio.h>
#include <stdlib.h>

#define arrSize 8

int vals[arrSize];

int main_Duplicates()
{
	int i, j;
	
	for(i=0; i<arrSize; i++)
	{
		scanf("%i", &vals[i]);
	}
	
	
	for(i=0; i<arrSize; i++)
	{
		for(j=i+1; j<arrSize; j++)
		{
			if(vals[i] == vals[j]) printf("Duplicated number: %i, position: %i \n", vals[i], i);
		}
	}
	return 0;
}

