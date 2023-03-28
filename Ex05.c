#include <stdlib.h>
#include <stdio.h>

int main_DynamicReading(int sub)
{
	int arrSize, i, sum=0;
	int* arr;
	
	printf("What is the array size: ");
	scanf("%i", &arrSize);
	
	arr = (int*) malloc(arrSize*sizeof(int));
	
	for(i=0; i<arrSize; i++)
	{
		scanf("%i", &*(arr+i));
	}
	
	for(i=0; i<arrSize; i++)
	{
		sum += arr[i];
	}
	
	printf("Total sum: %i", sum);
	
	free(arr);
	
}
