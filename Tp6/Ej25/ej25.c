#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

unsigned int copyStrFromTo(const char * arregloIn, char * arregloOut, size_t desde, size_t hasta, size_t dimMax);

bool verifications(const char * arregloIn, size_t desde, size_t hasta, size_t dimMax);


int main(void) {
  char s[100];
  assert(copyStrFromTo("un texto", s,0,0,1)==0);
  assert(strcmp(s, "")==0);
  assert(copyStrFromTo("un texto", s,0,0,10)==1);
  assert(strcmp(s, "u")==0);
  assert(copyStrFromTo("un texto", s,0,10,1)==0);
  assert(strcmp(s, "")==0);

  assert(copyStrFromTo("un texto", s,45,130,1)==0);


  assert(copyStrFromTo("un texto", s,0,130,2)==1);
  assert(strcmp(s, "u")==0);

  assert(copyStrFromTo("un texto", s,0,130,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copyStrFromTo("un texto", s,0,7,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copyStrFromTo("un texto", s,0,7,9)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copyStrFromTo("un texto", s,2,5,8)==4);
  assert(strcmp(s, " tex")==0);
  
  assert(copyStrFromTo("un texto", s,45000,130000,10)==0);

  printf("OK!\n");
  return 0;
}

unsigned int copyStrFromTo(const char * arregloIn, char * arregloOut, size_t desde, size_t hasta, size_t dimMax){

  int k = 0;

  if ( verifications(arregloIn, desde, hasta, dimMax) ){

    for ( int i=desde; i <= hasta && k < dimMax-1 && arregloIn[i] != '\0'; i++ ){
  

      arregloOut[k++] = arregloIn[i];

    }
  
  }

  arregloOut[k] = '\0';
  if ( k < desde )
    k=0;

  return k;

}

bool verifications(const char * arregloIn, size_t desde, size_t hasta, size_t dimMax){

  bool ver = false;

  if ( desde >= 0 && dimMax >= desde && hasta >= desde ){
  
    ver = true;

  }

  return ver;

}
