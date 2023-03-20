#include <stdio.h>
#include <limits.h>

int
main(void) {
   int c = INT_MAX; //Imprime el numero mas alto que del int
   int d; 
   d = c + c; // para los TODOS = 0
   int e = c + 1; // -c

   printf("c=%d   d=%d   e=%d\n", c, d, e);
   return 0;
}
