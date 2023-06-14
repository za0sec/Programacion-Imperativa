#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../libreria/utillist.h"


void printList(TList list);

TList sortedList(TList list);

int main() {
    // Prueba 1: Lista vacía
    TList list1 = NULL;
    list1 = sortedList(list1);
    assert(list1 == NULL);

    // Prueba 2: Lista ordenada
    int v2[] = {1, 2, 3, 4, 5};
    TList list2 = fromArray(v2, sizeof(v2) / sizeof(int));
    printf("Lista ordenada: ");
    printList(list2);
    list2 = sortedList(list2);
    assert(checkElems(list2, v2, sizeof(v2) / sizeof(int)));
    printf("Lista ordenada(sorted): ");
    printList(list2);
    puts("");
    freeList(list2);


    // Prueba 3: Lista desordenada con elemento 1
    int v3[] = {2, 3, 4, 1};
    TList list3 = fromArray(v3, sizeof(v3) / sizeof(int));
    printf("Lista desordenada con elemento 1: ");
    printList(list3);
    list3 = sortedList(list3);
    int expected3[] = {1};
    assert(checkElems(list3, expected3, sizeof(expected3) / sizeof(int)));
    printf("Lista desordenada con elemento 1(sorted): ");
    printList(list3);
    puts("");
    freeList(list3);


    // Prueba 4: Lista desordenada sin elemento 1
    int v4[] = {2, 1, 4, 3};
    TList list4 = fromArray(v4, sizeof(v4) / sizeof(int));
    printf("Lista desordenada sin elemento 1: ");
    printList(list4);
    list4 = sortedList(list4);
    int expected4[] = {1, 3};
    assert(checkElems(list4, expected4, sizeof(expected4) / sizeof(int)));
    printf("Lista desordenada sin elemento 1(sorted): ");
    printList(list4);
    puts("");
    freeList(list4);

    // Prueba 5: Lista con elementos repetidos
    int v5[] = {1, 3, 3, 4, 2};
    TList list5 = fromArray(v5, sizeof(v5) / sizeof(int));
    printf("Lista con elementos repetidos: ");
    printList(list5);
    list5 = sortedList(list5);
    int expected5[] = {1, 2};
    assert(checkElems(list5, expected5, sizeof(expected5) / sizeof(int)));
    printf("Lista con elementos repetidos(sorted): ");
    printList(list5);
    puts("");
    freeList(list5);


    // Prueba 6: Lista con un único elemento repetido
    int v6[] = {3, 3, 3};
    TList list6 = fromArray(v6, sizeof(v6) / sizeof(int));
    printf("Lista con un único elemento repetido: ");
    printList(list6);
    list6 = sortedList(list6);
    int expected6[] = {3};
    assert(checkElems(list6, expected6, sizeof(expected6) / sizeof(int)));
    printf("Lista con un único elemento repetido(sorted): ");
    printList(list6);
    puts("");
    freeList(list6);


    // Prueba 7: Lista desordenada con elementos mixtos
    int v7[] = {3, 5, 2, 4, 3, 6};
    TList list7 = fromArray(v7, sizeof(v7) / sizeof(int));
    printf("Lista desordenada con elementos mixtos: ");
    printList(list7);
    list7 = sortedList(list7);
    int expected7[] = {2, 3, 6};
    assert(checkElems(list7, expected7, sizeof(expected7) / sizeof(int)));
    printf("Lista desordenada con elementos mixtos(sorted): ");
    printList(list7);
    freeList(list7);

    return 0;

}

void printList(TList list) {
    if (list == NULL) {
        printf("Lista vacía\n");
        return;
    }

    printf("Lista: ");
    while (list != NULL) {
        printf("%d ", list->elem);
        list = list->tail;
    }
    printf("\n");
}


TList sortedList(TList list){
    
    if (list == NULL || list->tail == NULL){
        return list;
    }

    list->tail = sortedList(list->tail);

    if (list->elem >= list->tail->elem){
        TList aux = list->tail;
        free(list);
        return aux;
    }
    
    return list;

}
