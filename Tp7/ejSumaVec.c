#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    printf("Ingrese el tamaño del primer arreglo: ");
    scanf("%d", &n1);

    // Asignamos memoria usando malloc para el primer arreglo
    int *arreglo1 = (int *)malloc(n1 * sizeof(int));
    if (arreglo1 == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese los elementos del primer arreglo:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arreglo1[i]);
    }

    printf("Ingrese el tamaño del segundo arreglo: ");
    scanf("%d", &n2);

    // Asignamos memoria usando calloc para el segundo arreglo
    int *arreglo2 = (int *)calloc(n2, sizeof(int));
    if (arreglo2 == NULL) {
        printf("Error al asignar memoria.\n");
        free(arreglo1); // Liberamos la memoria del primer arreglo antes de salir
        return 1;
    }

    printf("Ingrese los elementos del segundo arreglo:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arreglo2[i]);
    }

    // Reasignamos memoria usando realloc para unir ambos arreglos
    int *arreglo_total = (int *)realloc(arreglo1, (n1 + n2) * sizeof(int));
    if (arreglo_total == NULL) {
        printf("Error al reasignar memoria.\n");
        free(arreglo1);
        free(arreglo2);
        return 1;
    }

    // Copiamos los elementos del segundo arreglo al arreglo total
    for (int i = 0; i < n2; i++) {
        arreglo_total[n1 + i] = arreglo2[i];
    }

    // Calculamos la suma de los elementos de ambos arreglos
    int suma = 0;
    for (int i = 0; i < n1 + n2; i++) {
        suma += arreglo_total[i];
    }

    printf("La suma de los elementos de ambos arreglos es: %d\n", suma);

    // Liberamos la memoria asignada
    free(arreglo_total);
    free(arreglo2);

    return 0;
}

