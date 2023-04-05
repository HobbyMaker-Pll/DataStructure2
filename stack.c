#include "stack.h"

pilha* cria() 
{
	pilha* aux = (pilha*) malloc(sizeof(pilha));
	pilha* aux2 = (pilha*) malloc(sizeof(pilha));
	aux->top = aux2;
	aux->next = aux2;
	return aux;
}

void printPilha(pilha* stack) 
{
	int i=0;
	for(pilha* s=stack; s!=NULL; s=s->next)
		printf("pos: %i\nval: %i\n=-=-=-=-=\n", i+1, s->dado);
}

void push (pilha *p, float dado) 
{
	pilha* newItem = (pilha*) malloc(sizeof(pilha));
	newItem->dado = dado;
	newItem->next=p;
	p->next = NULL;
	p = newItem;	
}

float pop (pilha *p)
{
	float val = p->dado;
	pilha* buff = p;
	p = p->next;
	free(buff);
	return val;
}

int vazia (pilha *p)
{
	return (p==NULL) ? 0 : 1;
}
void libera (pilha *p)
{
	pilha* pt=p;
	while(pt!=NULL)
	{
		pilha* last = pt;
		pt=pt->next;
		free(last);
	}
	free(pt);
}
void concatena_pilhas (pilha *p1, pilha *p2)
{
	
}

int contanegativos(pilha *p)
{
	
}

int main_stack(int sub)
{
	printf("working");
}
