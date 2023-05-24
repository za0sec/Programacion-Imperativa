//Escribir una versión recursiva de la función strrchr

//strrchr busca el ultimo caracter c en la cadena s

#include <stdio.h>
#include <string.h>
#include <assert.h>

char * strRchr(char *s, char c);

int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == strRchr(s, s[i]));
	} 

	puts("OK!");
}


char * strRchr(char * s, char c){

  if (*s == '\0')
    return 0;

  char * ret = strRchr(s+1, c);

  if (ret == NULL && *s == c)
    return s;
  
  return ret;
 
}
