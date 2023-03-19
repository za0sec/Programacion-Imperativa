#include <stdio.h>
#include <assert.h>
#include <math.h>

int esPrimo(int num){

  
if ( num == 0 || num == 1 ){ 
  return 0;
  }else if ( num == 2 ){

    return 1;

  }
int i, rest, limit = (sqrt(num));
  
if ( num%2 != 0 ){

  for ( i=2; i<=limit; i++ ){
    rest = num%i;

    if ( rest == 0 ){
      return 0;
    }    
  }
}else{
return 0;
}    
  return 1;
  }


int
main(void) {
    assert(!esPrimo(0)); // 0 no es primo (no es natural)
    assert(!esPrimo(1)); // 1 no es primo
    assert(esPrimo(2)); // 2 es primo
    assert(esPrimo(3));
    assert(!esPrimo(4));
    assert(esPrimo(5));
    assert(!esPrimo(6)); // Equivalente a assert(esPrimo(6) == 0)
    assert(esPrimo(7)); // Equivalente a assert(esPrimo(7) == 1)
    printf("OK!\n");
    return 0;
}
 
