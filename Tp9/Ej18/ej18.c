//Escribir una función recursiva sumMatch que reciba como único parámetro un vector 
//de enteros mayores o iguales a cero, donde la marca de final es un número negativo. 

//La función debe retornar cero si los elementos del vector están "apareados por sumas", 
//y distinto de cero si no, de acuerdo a los siguientes ejemplos:

//Para los siguientes vectores la función retorna cero:

//int v1[]={1,2,3,6,4,3,2,9,1,2,3,-1};    // 1+2+3=6, 4+3+2=9, 1+2=3
//int v2[]={1,1,2,4,5,5,14,-1};           // 14=5+5+4, 2=1+1
//int v3[]={3,3,-1};                      // 3=3
//int v4[]={1,1,2,2,90,90,-1};            // 90=90, 2=2, 1=1
//int v5[]={1,0,1,2,2,2,6,-1};            // 6=2+2+2, 1=0+1
//int v6[]={-1};
//int v7[]={0,-1};


//Para los siguientes vectores la función retorna distinto cero:

//int v1[]={1,1,2,3,6,4,3,2,9,1,2,3,-1};    
//int v2[]={1,1,2,4,5,5,14,10,-1};           
//int v3[]={4,3,-1};
//int v4[]={1,-1};
//int v5[]={1,0,1,2,1,2,2,2,-1};


//No usar variables static ni funciones o macros auxiliares

#include <stdio.h>
#include <assert.h>

int sumMatch(const int v[]);

int main(void) {

    int v1[]={1,2,3,6,4,3,2,9,1,2,3,-1};    // 1+2+3=6, 4+3+2=9, 1+2=3
    assert(sumMatch(v1)==0);
    int v2[]={1,1,2,4,5,5,14,-1};           // 14=5+5+4, 2=1+1
    assert(sumMatch(v2)==0);
    int v3[]={3,3,-1};                      // 3=3
    assert(sumMatch(v3)==0);
    int v4[]={1,1,2,2,90,90,-1};            // 90=90, 2=2, 1=1
    assert(sumMatch(v4)==0);
    int v5[]={1,0,1,2,2,2,6,-1};            // 6=2+2+2, 1=0+1
    assert(sumMatch(v5)==0);
    int v6[]={-1};
    assert(sumMatch(v6)==0);
    int v7[]={0,-1};
    assert(sumMatch(v7)==0);
     
    int w1[]={1,1,2,3,6,4,3,2,9,1,2,3,-1};
    assert(sumMatch(w1)!=0);
    int w2[]={1,1,2,4,5,5,14,10,-1};
    assert(sumMatch(w2)!=0);
    int w3[]={4,3,-1};
    assert(sumMatch(w3)!=0);
    int w4[]={1,-1};
    assert(sumMatch(w4)!=0);
    int w5[]={1,0,1,2,1,2,2,2,-1};
    assert(sumMatch(w5)!=0);

    printf ("OK!\n");
    return 0;
}

int sumMatch(const int v[]){


  if (*v == -1)
    return 0;

  int t = sumMatch(v+1);

  if (t == 0)
    return *v;
  if (t < 0)
    return t - *v;

  return t - *v;

}
