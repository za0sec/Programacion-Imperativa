#ifndef __collectionADT_h
#define __collectionADT_h


typedef struct collectionCDT * collectionADT;

typedef .. elemType; // Tipo de elemento a insertar

/* Crea una nueva colección de elementos genéricos
** Inicialmente la colección está vacía
** Cada elemento a insertar será de tipo elemType
** No hay un límite para la cantidad de elementos a insertar
*/
collectionADT newCollection( ¿? );

/* Retorna cuántos elementos hay insertados */
int elementCount(collectionADT c);

/* Almacena un elemento en la posición pos.
** Si había un elemento en esa posición, lo pisa con elem
*/
void putElement(collectionADT c, elemType elem, size_t pos);

/* Elimina el elemento en la posición pos.
** Si no hay elementos en pos, no hace nada */
void deleteElement(collectionADT c, size_t pos);

/* Retorna la posición en el cual está insertado el elemento,
** o -1 si no lo encuentra
*/
int getPosition(collectionADT c, elemType elem);

/* Libera todos los recursos reservados por el TAD */
void freeCollection(collectionADT c);

#endif //__collectionADT_h

