#include <stdio.h>
#include <string.h>



int comprimeCar(char * s, char c, int * vec, int maxDim);


int comprimeCar(char * s, char c, int * vec, int maxDim){
  

 int cont = 0, i, j, k; 
  
  for ( j=1, k=1, t=0; s[j] && t<maxDim; j++ ){

    if (s[0] == 0)
      return 0;


    if ( s[j-1] != c ){
      cont++;
      vec[k++] = s[j];

    }else if ( s[j] == c ){

      cont++;

    }else{
      s[k++] = s[j];
      vec[t++] = cont;
      cont = 0;

    }
    

  }
  
  if (cont > 0){

    vec[t++] = cont;

  }
  while(s[j] != 0){
    s[k++] = s[j++];
  }
  
  s[k] = 0;
  return k;
}


