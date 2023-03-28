#include <stdio.h>
#include <stdlib.h>

#define arrSize 8

int vals[arrSize];

int main_Duplicates(int sub)
{
	int i, j; // Inicia variaveis i e j como inteiros 8 bytes
	
	for(i=0; i<arrSize; i++)
	{
		scanf("%i", &vals[i]); // Insere a leitura do input do usuario dentro do array de inteiros
	}
	
	
	for(i=0; i<arrSize; i++) // Passa sobre o array coletado
	{
		for(j=i+1; j<arrSize; j++) // Passa sobre o array coletado porém sobre inicia baseado no for de cima com uma posição a frente
		{
			if(vals[i] == vals[j]) printf("Duplicated number: %i, position: %i \n", vals[i], i); // Checa se existem números duplicados
		}
	}
	return 0;
}

