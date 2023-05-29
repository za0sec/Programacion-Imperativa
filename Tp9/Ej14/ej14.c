//Similar al ejercicio 12 pero el string contiene únicamente paréntesis 
//y debe retornar cero sólo si los paréntesis están apareados. 
//Consideramos que los paréntesis de una expresión están apareados si
//para cada paréntesis de apertura hay uno de cierre en una posición posterior. 
//La funcion debe ser recursiva
//No definir macros ni funciones auxiliares. 

#include <stdio.h>
#include <string.h>
#include <assert.h>

int apareados(const char *texto);

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  printf ("OK!\n");
  return 0;
}



int apareados(const char * s){

  if (*s == '\0')
    return 0;

  int i = apareados(s+1);

  if (i < 0)
    return i;

  int t = (*s == '(' ? -1 : 1); 

  return i + t;
}

