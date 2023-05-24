/*
Programar una función recursiva BALANCE que reciba como único parámetro 
un string constante representando una expresión  matemática.  
Dicha función debe devolver el valor 0 si hay igual cantidad 
de paréntesis que abren y que cierran, y  retorna un valor distinto de cero en caso contrario. 
No definir variables ni funciones auxiliares. 
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>


int balance(const char *texto);


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}

int balance(const char *texto){

  if (*texto == '\0')
    return 0;

  if (*texto == '(')
    return 1 + balance(texto+1);
  
  if (*texto == ')')
    return -1 + balance(texto+1);

  return balance(texto+1);

}
