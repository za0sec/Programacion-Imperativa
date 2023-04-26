#include <stdio.h>
#include <ctype.h>

enum contadores {LETTER=0, UPPER, LOWER, NOTLETTER};

void verifications(int * cont, int * letter, int c, int l);

int main(){

  int c;
  char l;
  int cont[4] = {0};
  int letter[26] = {0};
  
  while ((c = getchar()) != EOF){
 
    l = toupper(c);

    verifications(cont, letter, c, l); 
    
  }
  
  printf("Hay en total %d letras\nHay en total %d mayusculas\nHay en total %d minusculas\nHay en total %d caracteres != de letras\n", cont[0], cont[1], cont[2], cont[3]);

 for (int i = 0; i < 26; i++) {
        if (letter[i] > 0) {
            printf("%c aparece %d veces\n", 'A' + i, letter[i]);
        }
    }

}

void verifications(int * cont, int * letter, int c, int l){

  if (l >= 'A' && l <= 'Z'){
      
      cont[LETTER]++;
      letter[l - 'A']++;
      

      if (isupper(c)){
        cont[UPPER]++;
      }else{
        cont[LOWER]++;
      }
    }else{

      cont[NOTLETTER]++;

    }



}
