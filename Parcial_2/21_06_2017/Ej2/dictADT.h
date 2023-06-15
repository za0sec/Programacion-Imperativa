#include <stdio.h>


typedef struct dictCDT *dictADT;

/*
** Crea un nuevo diccionario para asociar pares de clave/valor.
** Inicialmente está vacío.
*/
dictADT newDict();

/*
** Libera todos los recursos reservados por el TAD.
*/
void freeDict(dictADT d);

/*
** Agrega un elemento al diccionario. Si key o value son NULL, no los agrega.
** key: clave. Se inserta una COPIA de la clave recibida.
** value: valor asociado a la clave. Se inserta una COPIA del valor recibido.
** Si ya existía la clave, el valor se pisa con value (se lo considera una actualización).
*/
void addKey(dictADT d, const void *key, const void *value);

/*
** Retorna una copia del valor asociado a key o NULL si no estaba la clave en el diccionario.
*/
void *getValue(dictADT d, const void *key);

/*
** Vector que contiene una copia de todas las claves.
** Cada elemento del vector es una COPIA de las claves en el diccionario.
** El vector debe finalizar en NULL.
** Si no hay claves (el diccionario está vacío), retorna un vector que solo contiene NULL.
*/
void **keys(dictADT d);
