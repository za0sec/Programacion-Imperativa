#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define COLS 4


int sonAmigas(int m1[][COLS], int fils1, int m2[][COLS], int fils2);

bool esAmiga(int m1[][COLS], int m2[][COLS], int f, int fils);

bool belongs(int target, int m1[][COLS], int i);





int 
main(void)
{
  int m1[][COLS] = {{0,1,3,2}, {4,6,5,6}, {9,8,7,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,9,8,7}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  puts("OK!");

  return 0;
}


int sonAmigas(int m1[][COLS], int fils1, int m2[][COLS], int fils2){

  int contA = 0;
  int contB = 0;

  for ( int i=0; i<fils1; i++ ){
    
    if (esAmiga(m1, m2, i, fils2))
      contA++;
    
  }

  if (contA == fils1)
    return 1;

  for ( int i=0; i<fils2; i++ ){

    if (esAmiga(m2, m1, i, fils1))
      contB++;

  }

  if (contB == fils2)
    return 2;



  return 0; 


}


bool esAmiga(int m1[][COLS], int m2[][COLS], int f, int fils){


  for(int i=0; i<fils; i++){

    int c = 0;

    for(int j=0; j<COLS; j++){
       
      if (belongs(m1[f][j], m2, i)){

        c++;

      }
         
    }
  
  if( c == COLS )
    return true;
  
  }


  return false;

}

bool belongs(int target, int m1[][COLS], int i){

  for(int j=0; j<COLS; j++){

    if ( target == m1[i][j] )
      return true;

  } 

  return false;

}


