#include "bibleADT.h"

#include <stdlib.h>

#define BOOKS 76
#define CHUNK 10

typedef struct book{
    char ** versicle;
    size_t verCount;
}book;

typedef struct bibleCDT{
    book books[BOOKS];
}bibleCDT;

bibleADT newBible(){

    return calloc(1, sizeof(bibleCDT));

}



/*
** Agrega un versículo a la Biblia. Si ya estaba ese número de versículo en ese
** número de libro, no lo agrega ni modifica y retorna 0. Si lo agregó retorna 1
** bookNbr: número de libro
** verseNbr: número de versículo
*/


static char * stringCopy(const char * verse){

    char * aux = NULL;
    int i;

    for (i=0; verse[i]; i++){
        if ( !(i%CHUNK) ){
            aux = realloc(aux, (CHUNK+i) * sizeof(char));
        }

        aux[i] = verse[i];
    }
    
    aux = realloc(aux, (i+1) * sizeof(char));
    aux[i] = '\0';

    return aux;

}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    
    if (bookNbr < 1 || bookNbr > BOOKS) {
        return 0;
    }

    if (bible->books[bookNbr-1].verCount >= verseNbr && bible->books[bookNbr-1].versicle[verseNbr-1] != NULL){
        return 0;
    }   
    
    if (bible->books[bookNbr-1].verCount < verseNbr){
        bible->books[bookNbr-1].versicle = realloc(bible->books[bookNbr-1].versicle, verseNbr*sizeof(char*));
        for (int i=bible->books[bookNbr-1].verCount; i<verseNbr; i++){
            bible->books[bookNbr-1].versicle[i] = NULL;
        }
    }

    bible->books[bookNbr-1].versicle[verseNbr-1] = stringCopy(verse);
    bible->books[bookNbr-1].verCount = verseNbr;

    return 1;
}


/*
** Retorna una copia de un versículo o NULL si no existe.
** bookNbr: número de libro
** verseNbr: número de versículo
*/

char *getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr)
{
    if (bookNbr == 0 || bookNbr > BOOKS || verseNbr > bible->books[bookNbr - 1].verCount) {
        return NULL;
    }

    if (bible->books[bookNbr - 1].versicle[verseNbr - 1] != NULL) {
        return stringCopy(bible->books[bookNbr - 1].versicle[verseNbr - 1]);
    }

    return NULL;
}

void freeBible(bibleADT bible){

    for (int i=0; i<BOOKS; i++){
        for (int j=0; j<bible->books[i].verCount; j++){
            free(bible->books[i].versicle[j]);
        }
        
    }

    free(bible);
}
