#include <string.h>
#include <stdlib.h>
#include "phrasesADT.h"


#define CHUNK 20

typedef struct element{

    char * phrase;
    size_t key;

}element;


typedef struct phrasesCDT{

    element * vec;
    size_t dim;
    size_t used;
    size_t keyFrom;

}phrasesCDT; 



phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){

    if (keyFrom >= keyTo || keyFrom < 0){
        return NULL;
    }

    size_t dim = ketTo - keyFrom + 1;

    phrasesADT phrases = malloc(sizeof(phrasesCDT));

    phrases->vec = calloc(dim, sizeof(TNode));

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

    key = (ph->keyFrom - key + 1);

    if ( key >= 0 && key < ph->dim ){

        (ph->vec)[key].phrase = stringcpy(phrase);
        ph->used++;
        return 1;

    }
        
    return 0;   

}

char * get(const phrasesADT ph, size_t key){
    
    key = (ph->keyFrom - key + 1);

    if ( key >= 0 && key < ph->dim && ph->vec[key].size > 0){
        return stringcpy(phrase); 
    }

    return NULL;

}


size_t size(const phrasesADT ph){
    return ph->used;
}


char * concatAll(const phrasesADT ph){

    char * ret = NULL;

    if (used){
        int i, k=0;
        for (i=0; i<ph->dim; i++){
            if (ph->vec[i].phrase != NULL){
                for(int j=0; ph->vec[i].phrase[j]; j++){
                    ret[k++] = ph->vec[i].phrase[j];
                }
            }
        }
    ret[k] = '\0';
    }
    return ret;
}


char * concat(const phrasesADT ph, size_t from, size_t to){
    
    from = ph->keyFrom - from + 1;
    to = ph->keyFrom - from + 1;
    
    
    
}
