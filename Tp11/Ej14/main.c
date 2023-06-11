#include "tp11_ej14.h"

int compInt(int e1, int e2) {
   return e1 - e2;
}

int
main(void) {
   listADT c = newList(compInt); // una lista, en este caso de int
   add(c, 3);   add(c, 1);   add(c, 5);   add(c, 2);
   toBegin(c);         // iterador por orden de inserción
   int n = next(c);    // n = 3
   n = next(c);        // n = 1
   toBeginAsc(c);      // iterador por orden ascendente
   n = nextAsc(c);     // n = 1
   n = next(c);        // n = 5
   n = next(c);        // n = 2
   hasNext(c);         // retorna 0 ( falso )
   n = nextAsc(c);     // n = 2
   hasNextAsc(c);      // retorna 1 ( true )
   n = nextAsc(c);     // n = 3
   return 0;
}


