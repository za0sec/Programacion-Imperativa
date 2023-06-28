#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define MAX_CHAR 256

int queContiene(const char * s1, const char * s2);

int main(void) {
   int c = queContiene("Ahora me pongo a llorar", "zaMo");
   assert(c==9);    // A o a m   o  o a   o a 

   c = queContiene("Ahora me pongo a llorar", "");
   assert(c==0);    

   c = queContiene("143 I love you", "xaprarczd");
   assert(c==0);    

}

int queContiene(const char * s1, const char * s2){

    int vecAp[MAX_CHAR] = {0};
    int count=0;
    int ch;

    for (int i=0; s2[i]; i++){
        ch = toupper(s2[i]);
        vecAp[ch] = 1;
    }

    for (int i=0; s1[i]; i++){
        ch = toupper(s1[i]); 
        if (vecAp[ch]){
            count++;
        }
    }

    return count;

}
