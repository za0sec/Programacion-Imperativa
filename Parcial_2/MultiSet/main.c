#include <stdio.h>
#include <assert.h>
#include "multiSetADT.h"

int main (void){
    multiSetADT mySet=newMultiSet();
    int v[]={1,2,3,4,5,6,7,8,9,10};

    for ( int i=0 ; i<10 ; i++ ){
        assert(add(mySet,v[i])==1);
    }
    assert(size(mySet)==10);
    printf("Cantalo\n");

    int x=11;
    for ( int i=0 ; i<10 ; i++ ){
        assert(add(mySet,x )==i+1);//agrego 10 veces x
    }
    printf("Cantalo\n");

    assert(size(mySet)==11);
    int aux=count(mySet,x);
    assert(aux==10);

    for ( int i=0 ; i<(aux) ; i++ ){
        assert(removeOne(mySet,x)==(aux-1-i));
    } 

    assert(size(mySet)==10);
    assert(removeOne(mySet,x)==0);
    assert(count(mySet,x)==0);

    printf("Cantalo\n");

    removeAll(mySet,1);

    assert(size(mySet)==9);
    assert(count(mySet,1)==0);

    //lista tiene 2,3,4,5,6,7,8,9,10
    

    add(mySet,2);
    add(mySet,2);//2 tiene 3

    printf("Cantalo\n");

    add(mySet,3);
    add(mySet,3);
    add(mySet,3);//3 tiene 4

    add(mySet,4);//4 tiene 2
    
    //5,6 tiene 1

    add(mySet,7);
    add(mySet,7);//7 tiene 3

    //8,9 tiene 1
    add(mySet,10);//10 tiene 2
    add(mySet,-1);
    add(mySet,13);

    printf("Cantalo\n");

    int dim;
    int *w=minElements(mySet,&dim);
    assert(dim==6);

   /* int expectedList[]={-1,5,6,8,9,13};//para listas, porque esta ordenado ascendente
    for (size_t i = 0; i < dim; i++){
        assert(w[i]==expectedList[i]);
    }//hasta aca testlista*/

    int expectedVec[]={5,6,8,9,-1,13};//para vec (no ordenado)}
    int flagsVec[6]={0};
    int flag;
    for (size_t i=0; i < dim ; i++){
        flag=1;
        for ( size_t j=0 ; j<dim && flag ;j++){
            if ( w[i]==expectedVec[j] ){
                flagsVec[i]=1;
                flag=0;
            }
        }
    }

    for (size_t i = 0; i < dim; i++){
        assert(flagsVec[i]);   
    }
    //como no se sabe en que orden pueden salir del vector, unicamente revisamos que esten

    //es el unico test que queda diferente por si se plantea con vec o con TList
    
    free(w);
    freeMultiSet(mySet);

    printf("GOOOOLLLLL\n");
}
