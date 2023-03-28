#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {

int item;
struct no *prox;

}lista;

lista* initList(){
    return NULL;
}

lista* insertList(int item, lista* list)
{
    lista* newList = (lista*) malloc(sizeof(lista));
    newList->item = item;
    newList->prox = list;
    return newList;
}

lista* printList(lista* list){
    int i=0;
    for(lista* l=list; l!=NULL; l=l->prox, i++)
        printf("Pos: %i\nItem: %i\n=-=-=-=-=-=-=-=");
}

// -=-=-=-=-=--=-=-=-=-=-Ex1-=-=-=-=-=--=-=-=-=-=-
int tamanho(lista* no)
{
    if(no->prox==NULL) return 1;
    return tamanho(no->prox)+1;
}

void Ex1_l2()
{
    lista* l1 = initList();
    l1 = insertList(2, l1);
    l1 = insertList(5, l1);
    l1 = insertList(8, l1);
    l1 = insertList(10, l1);
    l1 = insertList(22, l1);
    printf("Tamanho da lista: %i", tamanho(l1));
}

// -=-=-=-=-=--=-=-=-=-=-Ex2-=-=-=-=-=--=-=-=-=-=-
int sao_iguais(lista* l1, lista* l2)
{   
    if(l1->item!=l2->item) return 0;
    if((l1->prox==NULL && l2->prox!=NULL) || (l1->prox!=NULL && l2->prox==NULL)) return 0;
    if(l1->prox==NULL && l2->prox==NULL) return 1;
    if(l1->prox!=NULL && l2->prox!=NULL) return sao_iguais(l1->prox, l2->prox);
}

void Ex2_l2()
{
    lista* l1 = initList();
    l1 = insertList(2, l1);
    l1 = insertList(5, l1);
    l1 = insertList(8, l1);
    l1 = insertList(10, l1);
    l1 = insertList(22, l1);

    lista* l2 = initList();
    l2 = insertList(2, l2);
    l2 = insertList(5, l2);
    l2 = insertList(8, l2);
    l2 = insertList(10, l2);
    l2 = insertList(22, l2);

    if(sao_iguais(l1, l2))
        printf("As listas L1 e L2 sao iguais");
    else
        printf("As listas L1 e L2 sao diferentes");
    
}
// -=-=-=-=-=--=-=-=-=-=-Ex3-=-=-=-=-=--=-=-=-=-=-
int posicaoDoElemento(lista *l1, int info)
{   
    lista* l=l1;
    int i=0;
    while (l!=NULL)
    {
        i++;
        if(l->item==info) return i;
        l=l->prox;
    }
    return -1;
}

void Ex3_l2()
{
    lista* l1 = initList();
    l1 = insertList(2, l1);
    l1 = insertList(5, l1);
    l1 = insertList(8, l1);
    l1 = insertList(10, l1);
    l1 = insertList(22, l1);

    printf("Elemento encontrado em %i", posicaoDoElemento(l1, 8));
}

// -=-=-=-=-=--=-=-=-=-=-Ex4-=-=-=-=-=--=-=-=-=-=-
lista* ultimoElemento(lista* no)
{
    if(no==NULL) return NULL;
    if(no->prox==NULL) return no;
    return ultimoElemento(no->prox);
}

void Ex4_l2()
{
    lista* l1 = initList();
    l1 = insertList(2, l1);
    l1 = insertList(5, l1);
    l1 = insertList(8, l1);
    l1 = insertList(10, l1);
    l1 = insertList(22, l1);

    printf("Valor do ultimo elemento: %i", ultimoElemento(l1)->item);
}

int main_List2(int sub){
    //Ex1_l2();
    //Ex2_l2();
    //Ex3_l2();
    Ex4_l2();
}