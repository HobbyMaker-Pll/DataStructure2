#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define X1 0
#define X2 1

int delta(int a, int b, int c)
{
	// Calcula e retorna o delta como um valor inteiro
	return pow(b, 2) - (4*a*c);
}

void equationRoots(int a, int b, int c, double* ret)
{
	// calcula o valor das raizes e insire dentro do valor de ret
	int retDelta = delta(a, b, c); // usa a função delta e armazena o retorno
	assert(retDelta>=0); // verifica se o delta é maior que ou igual a 0
	assert(a>0); // verifica se o a é maior que 0
	
	double deltaSquare = sqrt(retDelta); // calcula a raiz de delta e armazena em um double
	// calcula a primeira e segunda raiz e armazena dentro do valor do ponteiro ret
	*(ret+X1) = ((-b)+deltaSquare)/(2*a); 
	*(ret+X2) = ((-b)-deltaSquare)/(2*a);
	
}

int main_SecondDegree(int sub)
{
	int a, b, c;
	printf("Insert a value for a: ");
	scanf("%i", &a);
	
	printf("Insert a value for b: ");
	scanf("%i", &b);
	
	printf("Insert a value for c: ");
	scanf("%i", &c);
	
	printf("Values for a:%i, b:%i, c:%i \n", a, b, c); 
	printf("Delta: %i \n", delta(a, b, c));
	
	double* roots = (double*) calloc(2, sizeof(double));
	equationRoots(a, b, c, roots);
	printf("Roots: x1-(%f) x2-(%f)",roots[X1], roots[X2]);
	
}
