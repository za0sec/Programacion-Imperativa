#ifndef __CONJADT__H
#define __CONJADT__H

typedef int elemType;

typedef struct conjCDT * conjADT;

int f (elemType elem1, elemType elem2);

void printConj(conjADT conj);

//Funcion compare...
conjADT newConj(int (f*)(elemType, elemType));

// agrega un elemento al conjunto. Devuelve 1 si fue exitoso y 0 si no estaba el elemento.
int addElem(conjADT conj, elemType elem); //

// elimina un elemento del conjunto. Devuelve 1 si fue exitoso y 0 si no estaba el elemento.
int deleteElem(conjADT conj, elemType elem); //

// retorna la union de dos conjuntos.
conjADT unionConj(conjADT conj1, conjADT conj2); //

// retorna la intersección de dos conjuntos.
conjADT interConj(conjADT conj1, conjADT conj2); //

// retorna la diferencia entre dos conjuntos.
conjADT difference(conjADT conj1, conjADT conj2); //

#endif //__CONJADT__H
