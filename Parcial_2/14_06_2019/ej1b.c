#include <stdio.h>
#include <assert.h>
#include "../../libreria/utillist.h"
#include <stdlib.h>

void removeRepeated(TList list);

int main() {

    // Test 1
    int arr1[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    TList list1 = fromArray(arr1, 10);
    removeRepeated(list1);
    int expected1[] = {1, 2, 3, 4};
    assert(checkElems(list1, expected1, 4));
    printf("Test 1 passed!\n");

    // Test 2
    int arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    TList list2 = fromArray(arr2, 10);
    removeRepeated(list2);
    int expected2[] = {1};
    assert(checkElems(list2, expected2, 1));
    printf("Test 2 passed!\n");

    // Test 3
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TList list3 = fromArray(arr3, 10);
    removeRepeated(list3);
    int expected3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(checkElems(list3, expected3, 10));
    printf("Test 3 passed!\n");

    // Liberar memoria de las listas
    freeList(list1);
    freeList(list2);
    freeList(list3);

    return 0;
}


void removeRepeated(TList list){

  if (list == NULL || list->tail == NULL){
    return;
  }

  if (list->elem == list->tail->elem){

    TList aux = list->tail->tail;
    free(list->tail);
    list->tail = aux;
  }

    removeRepeated(list->tail);
}
