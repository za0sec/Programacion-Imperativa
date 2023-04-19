#include <stdio.h>
#include <string.h>
#include <assert.h>

void supSpace(char * msg);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  supSpace(s);
  assert(strcmp(s, " ")==0);

  supSpace(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  supSpace(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  supSpace(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  supSpace(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  supSpace(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}
void supSpace(char * msg){

  int k;

  for ( int i = k = 0; msg[i]!='\0'; i++ ){

    char anterior = msg[i-1];

    if ( i == 0 || !(msg[i] == ' ' && msg[i] == anterior))
      msg[k++] = msg[i];


  }
  
  msg[k] = '\0';

}
