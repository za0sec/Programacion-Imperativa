#include <stdio.h>

int main(void) {
    int c;
    while (!feof(stdin)) {
        c = getchar();
        if (c != EOF) {
            putchar(c);
        }
    }
    return 0;
}
