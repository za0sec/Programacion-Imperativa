#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int i, n = getint("Hasta que numero quieres que llegue la tabla?");
  for (i=1; i<=n; i++ ){
  
    printf("%d\t%d\t%d\t%d\n", i, (i*10), (i*100), (i*1000));
  
  }

}
