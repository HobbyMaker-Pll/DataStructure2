#include <stdio.h>
#include <stdlib.h>


typedef struct link{
    int val;
    struct link* prox;
} LinkedList;

LinkedList* initLinkedList()
{
    return NULL;
}

void printLinkedList(LinkedList * list){
    if (list == NULL) {
        printf("List is cleared");
        return;
    }
    
    for (LinkedList* l = list; l != NULL; l = l->prox)
       printf("Info stored = %d\n", l->val);
}

LinkedList* insertLinkedList(LinkedList* list, int val){
    LinkedList* newItem = (LinkedList*) malloc(sizeof(LinkedList));
    newItem->val = val;
    newItem->prox = list;
    return newItem;
}

void appendLinkedList(LinkedList** list, int val){

    LinkedList* newItem = (LinkedList*) malloc(sizeof(LinkedList));

    if (*list == NULL) {
        newItem->val = val;
        newItem->prox = NULL;
        *list = newItem;
        return;
    }

    LinkedList* l = *list; 
    while (l->prox!=NULL) l = l->prox;
    newItem->prox = NULL;
    newItem->val = val;
    l->prox = newItem;
}

LinkedList* clearLinkedList(LinkedList* list){
    LinkedList* l = list;
    while (l != NULL)
    {
        LinkedList* nextItem = l->prox;
        free(l);
        l = nextItem;
    }
    return initLinkedList();
}

LinkedList* searchValueLinkedList(LinkedList* list, int val){
    for(LinkedList* l = list; l != NULL; l=l->prox)
        if (l->val == val) return l;
    return NULL;
}

int getLinkedListEvens(LinkedList* list){
    int evenCount = 0;
    for (LinkedList* l = list; l != NULL; l=l->prox)
        if( (l->val%2) == 0 ) evenCount ++;
    return evenCount;
}

int getLinkedListEvens_recursive(LinkedList* list)
{
    if(list != NULL)
    {
        if(list->val%2==0) return 1+getLinkedListEvens_recursive(list->prox);
        else return getLinkedListEvens_recursive(list->prox);
    }
}

LinkedList* copyList(LinkedList* list){
    if(list == NULL) return NULL;

    LinkedList* newList = initLinkedList();

    for (LinkedList* l = list; l != NULL; l=l->prox)
        appendLinkedList(&newList, l->val);

    return newList;   
}

int main_LinkedList(){
    LinkedList* teste = initLinkedList();
    teste = insertLinkedList(teste, 5);
    teste = insertLinkedList(teste, 6);
    teste = insertLinkedList(teste, 7);
    teste = insertLinkedList(teste, 8);
    appendLinkedList(&teste, 10);
    printLinkedList(teste);
    printf("Evens found: %d\n", getLinkedListEvens(teste));
    printf("=-=-=-=-=-=-=-=-=-=-\n");

    LinkedList* teste2 = initLinkedList();
    teste2 = copyList(teste);
    appendLinkedList(&teste2, 15);
    appendLinkedList(&teste2, 10);
    printLinkedList(teste2);
    printf("Evens found: %d\n", getLinkedListEvens_recursive(teste2));
    return 0;
}
