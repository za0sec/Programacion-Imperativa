#include <stdio.h>
#include <assert.h>

int factoreo(int fac[]);

int main(void) {
     int factores[] = {2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 7, -1};
     long resultado = factoreo(factores);
     assert(resultado == 65318400);
     assert(factores[0] == 2);
     assert(factores[1] == 3);
     assert(factores[2] == 4);
     assert(factores[3] == 5);
     assert(factores[4] == 6);
     assert(factores[5] == 7);
     assert(factores[6] == -1);
     int factores2[] = {2, -1};
     resultado = factoreo(factores2);
     assert(resultado == 2);

     assert(factores2[0] == 2);
     assert(factores2[1] == -1);
     int factores3[] = {11, 11, 13, -1};
     resultado = factoreo(factores3);
     assert(resultado == 1573);  // 11 * 11 * 13
     assert(factores3[0] == 11);
     assert(factores3[1] == 13);
     assert(factores3[2] == -1);
     int factores4[] = {-1};
     resultado = factoreo(factores4);
     assert(resultado == 0);
     assert(factores4[0] == -1);
     int factores5[] = {1, -1};
     resultado = factoreo(factores5);
     assert(resultado == 1);
     assert(factores5[0] == 1);
     assert(factores5[1] == -1);
     puts("OK!");
     return 0;
}




int factoreo(int fac[]){

  int mult, i, t, error =0;

  if (fac[0] == -1){
    mult = 0;
  }else{
    mult = fac[0];

    
    for (i=t=1; fac[i] > 0; i++){

      mult *= fac[i];
      
      if (fac[i] != fac[i-1])
        fac[t++] = fac[i];

      if (fac[i+1] < 0 && fac[i+1] != -1)
        error = 1;
    }

    fac[t] = -1;

  }

  if (error)
    mult = 0;

  return mult;

}
