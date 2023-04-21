#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHARS_DIM 256


void analize(const char * text, char * chars);
void noCero(char * chars);

int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}


void analize(const char * text, char * chars){

  int k=0;

  for ( int t=0; t<CHARS_DIM; t++ )
    chars[k++] = '\0';

      
  for (int i = 0; text[i]; i++){
    chars[text[i]] = text[i];   
  }

  
  noCero(chars);

}

void noCero(char * chars){

  int k=0;

  for (int i=0; i<CHARS_DIM; i++){

    if (chars[i])
      chars[k++] = chars[i];

  }
  chars[k] = '\0';
}

