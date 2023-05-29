#include <stdio.h>
#include <assert.h>
#include "../../libreria/utillist.h"

void printList(TList list);

int main(void) {
    int v1 [] = {1, 2, 3, 4, 5};
    TList l1 = fromArray(v1, 5);

    printf("Antes de eliminar: ");
    printList(l1);
    l1 = delete(l1, 3);
    printf("Despues de eliminar: ");
    printList(l1);
    puts("");
    printf("Tercer elemento de la lista: %d\n\n", get(l1, 2));
    freeList(l1);

    int v2 [] = {1, 2, 3, 2, 1};
    TList l2 = fromArray(v2, 5);

    printf("Antes de eliminar: ");
    printList(l2);
    l2 = delete(l2, 1);
    printf("Despues de eliminar: ");
    printList(l2);
    puts("");
    printf("Primer elemento de la lista: %d\n\n", get(l2, 0));
    freeList(l2);

    return 0;
}

void printList(TList list) {
    printf("[");
    while (list != NULL) {
        printf(" %d", list->elem);
        list = list->tail;
        if (list != NULL) {
            printf(",");
        }
    }
    printf(" ]\n");
}
