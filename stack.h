#ifndef _STACK_H_
#define STACK_H

// Stack application
// made by > Pillon

// libs
#include <stdlib.h>
#include <stdio.h>

// variables
typedef struct p{
	float dado;
	struct p* next; 
	struct p* top;
}pilha;

// Methods
pilha* cria();
void printPilha();
void push (pilha *p, float dado);
float pop (pilha *p);
int vazia (pilha *p);
void libera (pilha *p);
void concatena_pilhas (pilha *p1, pilha *p2);
void concatena_pilhas (pilha *p1, pilha *p2);
int contanegativos(pilha *p);

// main method to run
int main_stack(int sub);

#endif
