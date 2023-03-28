#include <stdlib.h>
#include <stdio.h>



int main_Pointers(int sub)
{
	int a = 25;
	int *pa = &a;
	int b = *pa + a;
	
	printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b);
	/*
		a) 25 268433428 268433428 25 50 268433424
	*/
	
	/*
		b) valor contido no endereco defindo como a;
		endereco na memeria onde a este localizado
		endereco na memeria onde a este localizado
		valor contido no endereco defindo como a;
		soma do valor contido em a com o valor de a = 50;
		endereco de armazenamento da soma de a+a;
	*/
}

