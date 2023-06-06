#include <stdio.h>
#include <assert.h>
#include "../../libreria/utillist.h"
#include <stdlib.h>


void removeOdd(TList list);

void printList(TList head);

int main() {
    // Creamos un array.
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int dim = sizeof(arr)/sizeof(arr[0]);
    
    // Creamos una lista a partir del array.
    TList head = fromArray(arr, dim);

    printf("Lista original:\n");
    printList(head);

    // Verificamos la lista antes de la modificación.
    for (int i = 0; i < dim; ++i) {
        assert(get(head, i) == arr[i]);
    }

    // Aplicamos la función removeOdd.
    removeOdd(head);

    printf("Lista después de removeOdd:\n");
    printList(head);

    // Creamos un array para comprobar los elementos pares.
    int arr_check[] = {0, 2, 4, 6};
    int dim_check = sizeof(arr_check)/sizeof(arr_check[0]);

    // Verificamos la lista después de la modificación.
    assert(checkElems(head, arr_check, dim_check));

    // Liberamos la memoria.
    freeList(head);

    return 0;
}

void printList(TList head) {
    TList temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->elem);
        temp = temp->tail;
    }
    printf("NULL\n");
}


void removeOdd(TList list){

  if (list == NULL || list->tail == NULL){
    return;
  }

  TList aux = list->tail;
    
  list->tail = aux->tail;

  free(aux);

  removeOdd(list->tail);

}
