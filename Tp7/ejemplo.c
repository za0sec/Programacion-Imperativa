#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = NULL; // Inicialmente, no se asigna memoria
    int capacidad = 0; // Capacidad inicial del arreglo
    int size = 0; // Cantidad de números ingresados
    int suma = 0;
    int numero;

    printf("Ingrese números enteros (termina con 0):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break; // Termina la lectura de números cuando se ingresa 0
        }

        if (size == capacidad) {
            // Si el arreglo está lleno, aumentamos la capacidad
            capacidad = (capacidad == 0) ? 1 : capacidad * 2;
            int *temp = (int *)realloc(numeros, capacidad * sizeof(int));

            if (temp == NULL) {
                printf("Error: no se pudo asignar memoria en el heap.\n");
                free(numeros);
                return 1;
            }

            numeros = temp;
        }

        numeros[size++] = numero; // Agrega el número al arreglo y aumenta el tamaño
    }

    // Calcular la suma de los números ingresados
    for (int i = 0; i < size; i++) {
        suma += numeros[i];
    }

    printf("La suma de los números ingresados es: %d\n", suma);

    // Liberar la memoria asignada
    free(numeros);

    return 0;
}

