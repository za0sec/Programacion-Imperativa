//Dada una lista de caracteres cuya definicion de tipos es la siguiente:
//typedef struct node * TList;
//
//typedef struct node {
//    char elem;
//    struct node * tail;
//}TNode;

//
//Escribir una funcion 
//recursiva merge que reciba unicamente dos listas de letras (sin orden, con posibles repeticiones) 
//y retorne una nueva lista la cual contenga las letras de la primera y las de la segunda, pero en forma intercalada. 
//Si una lista es mas corta que la otra, al final completara con las letras que "sobran" de la lista mas larga.

#include <stdio.h>
#include "../../libreria/utillist.h"
#include <stdlib.h>
#include <assert.h>

TList merge(const TList list1, const TList list2);

void printList(TList list);

int main(void) {
    TList list1, list2, mergedList;

    // Ejemplo 1
    list1 = fromArray((const int[]){'H', 'L'}, 2);
    list2 = fromArray((const int[]){'O', 'A'}, 2);
    mergedList = merge(list1, list2);

    printf("Ejemplo 1:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(checkElems(mergedList, (const int[]){'H', 'O', 'L', 'A'}, 4));
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n");

    // Ejemplo 2
    list1 = fromArray((const int[]){'H', 'L'}, 2);
    list2 = fromArray((const int[]){'O', 'A', 'J', 'U', 'A', 'N'}, 6);
    mergedList = merge(list1, list2);

    printf("Ejemplo 2:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(checkElems(mergedList, (const int[]){'H', 'O', 'L', 'A', 'J', 'U', 'A', 'N'}, 8));
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n");

    // Ejemplo 3
    list1 = fromArray((const int[]){'H', 'O', 'L', 'A'}, 4);
    list2 = NULL;
    mergedList = merge(list1, list2);

    printf("Ejemplo 3:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(checkElems(mergedList, (const int[]){'H', 'O', 'L', 'A'}, 4));
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n");

    // Ejemplo 4
    list1 = NULL;
    list2 = fromArray((const int[]){'H', 'O', 'L', 'A'}, 4);
    mergedList = merge(list1, list2);

    printf("Ejemplo 4:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(checkElems(mergedList, (const int[]){'H', 'O', 'L', 'A'}, 4));
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n");

    // Ejemplo 5
    list1 = fromArray((const int[]){'H', 'O', 'L', 'A'}, 4);
    list2 = fromArray((const int[]){'-', '-', '-'}, 3);
    mergedList = merge(list1, list2);

    printf("Ejemplo 5:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(checkElems(mergedList, (const int[]){'H', '-', 'O', '-', 'L', '-', 'A'}, 7));
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n");

    // Ejemplo 6
    list1 = NULL;
    list2 = NULL;
    mergedList = merge(list1, list2);

    printf("Ejemplo 6:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);
    printf("Lista fusionada: ");
    printList(mergedList);
    assert(mergedList == NULL);
    freeList(list1);
    freeList(list2);
    freeList(mergedList);
    printf("------------------------------------------------\n\n\n");



    puts("OK GUACHO ALTO EJERCICIO TE MANDASTE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    return 0;
}

// Función para imprimir los elementos de una lista
void printList(TList list) {
    while (list != NULL) {
        printf("%c ", list->elem);
        list = list->tail;
    }
    printf("\n");
}

 
TList merge(const TList list1, const TList list2){
    
    if (list1 == NULL && list2 == NULL){
        return NULL;
    }

    if (list1 == NULL){
        TList aux = malloc(sizeof(TNode));
        aux->elem = list2->elem;
        aux->tail = merge(list1, list2->tail);
        return aux;
    }
    
    
    TList aux = malloc(sizeof(TNode));
    aux->elem = list1->elem;

    if (list2 == NULL){
        aux->tail = merge(list1->tail, list2);
        return aux;
    }

    aux->tail = merge(list2, list1->tail);
    return aux;

    
}
