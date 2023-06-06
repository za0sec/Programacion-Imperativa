#include <stdio.h>
#include "conjADT.h"

int main() {
    conjADT conj1 = newConj(f);
    conjADT conj2 = newConj(f);

    addElem(conj1, 1);
    addElem(conj1, 2);
    addElem(conj1, 3);

    printf("Conjunto 1:\n");
    printConj(conj1);

    addElem(conj2, 2);
    addElem(conj2, 3);
    addElem(conj2, 4);

    printf("Conjunto 2:\n");
    printConj(conj2);

    conjADT unionConjunto = unionConj(conj1, conj2);
    printf("Unión de conjuntos:\n");
    printConj(unionConjunto);

    conjADT interConjunto = interConj(conj1, conj2);
    printf("Intersección de conjuntos:\n");
    printConj(interConjunto);

    conjADT diffConjunto = difference(conj1, conj2);
    printf("Diferencia de conjuntos (conj1 - conj2):\n");
    printConj(diffConjunto);

    
    freeConj(conj1);
    freeConj(conj2);
    freeConj(unionConjunto);
    freeConj(interConjunto);
    freeConj(diffConjunto);    

    return 0;
}

