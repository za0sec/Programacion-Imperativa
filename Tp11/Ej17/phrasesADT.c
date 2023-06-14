#include <string.h>
#include <stdlib.h>
#include "phrasesADT.h"


#define CHUNK 20

typedef struct element{

    char * phrase;
    size_t flag;

}element;


typedef struct phrasesCDT{

    element * vec;
    size_t dim;
    size_t used;
    size_t keyFrom;

}phrasesCDT; 



phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){

    if (keyFrom > keyTo){
        return NULL;
    }

    size_t dim = keyTo - keyFrom + 1;

    phrasesADT phrases = malloc(sizeof(phrasesCDT));

    phrases->vec = calloc(dim, sizeof(element));

    phrases->dim = dim;

    phrases->used = 0;

    phrases->keyFrom = keyFrom;

    return phrases;

}


static char * stringcpy(const char * s){
    char * ans = NULL;
    int i;
    for(i=0; s[i]; i++){
        if (!(i%CHUNK)){
            ans = realloc(ans, CHUNK+i);
        }
            
        ans[i] = s[i];
    }

    ans = realloc(ans, i+1);
    ans[i] = '\0';

    return ans;

}

int put(phrasesADT ph, size_t key, const char * phrase){

    int nkey = ((int)key - (int)ph->keyFrom);

    if ( nkey >= 0 && nkey < ph->dim ){
        
        if(!ph->vec[nkey].flag){
            ph->used++;
        } 
        ph->vec[nkey].flag = 1;
        free((ph->vec)[nkey].phrase);
        (ph->vec)[nkey].phrase = stringcpy(phrase);
        
        return 1;

    }
        
    return 0;   

}

char * get(const phrasesADT ph, size_t key){
    
    int nkey = (key - ph->keyFrom);

    if ( nkey >= 0 && nkey < ph->dim){
        return stringcpy(ph->vec[nkey].phrase); 
    }

    return NULL;

}


size_t size(const phrasesADT ph){
    return ph->used;
}

static char * doConcat(const phrasesADT ph, size_t from, size_t to){

    char * ret = NULL;

    if (ph->used){
        int i; 
        long k=0;
        for (i=from; i<to; i++){
            if (ph->vec[i].phrase != NULL){
                for(int j=0; ph->vec[i].phrase[j]; j++){
                    if ( !(k%CHUNK)){
                        ret = realloc(ret, k+CHUNK);
                    }
                    ret[k++] = ph->vec[i].phrase[j];
                }
            }
        }
    ret = realloc(ret, k+1);
    ret[k] = '\0';
    }

    return ret;

}


char * concatAll(const phrasesADT ph){

    size_t start = 0;

    char * ret = doConcat(ph, start, ph->dim);
    
    return ret;
}


char * concat(const phrasesADT ph, size_t from, size_t to){
    
    int nfrom = from - ph->keyFrom;
    int nto = to - ph->keyFrom;
   
    if (nfrom < 0 || nto < nfrom){
        return NULL;
    }

    char * ret = doConcat(ph, nfrom, nto);
    
    return ret;
}


void freePhrases(phrasesADT ph){

    if (ph != NULL){

        for (int i=0; i<ph->dim; i++){
            free(ph->vec[i].phrase);
        }
    }
        free(ph->vec);
        free(ph);
}

