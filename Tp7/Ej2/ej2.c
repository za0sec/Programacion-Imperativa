#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int base_to_decimal(int num, int base) {
    int decimal = 0;
    int pos = 0;

    while (num > 0) {
        int digit = num % 10;
        decimal += digit * pow(base, pos);
        num /= 10;
        pos++;
    }

    return decimal;
}

int decimal_to_base(int num, int base, int *output) {
    int pos = 0;

    while (num > 0) {
        output[pos++] = num % base;
        num /= base;
    }

    return pos;
}

int main() {
    int base_in, base_out;

    printf("Ingrese la base de entrada y la base de salida: ");
    scanf("< %d > %d", &base_in, &base_out);

    if (base_in < 2 || base_in > 10 || base_out < 2 || base_out > 10) {
        printf("Las bases deben estar entre 2 y 10.\n");
        return 1;
    }

    int num_in;
    printf("Ingrese el número en base %d: ", base_in);
    scanf("%d", &num_in);

    int decimal = base_to_decimal(num_in, base_in);

    int output[32];
    int output_len = decimal_to_base(decimal, base_out, output);

    printf("El número en base %d es: ", base_out);
    for (int i = output_len - 1; i >= 0; i--) {
        printf("%d", output[i]);
    }
    printf("\n");

    return 0;
}

