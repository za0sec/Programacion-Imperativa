#include <stdio.h>
#include <stdbool.h>
#define FINAL -1

void resta(const int v1[], const int v2[], int resta12[]);

bool belongs(int target, const int v2[]);

int main(){


  int v1[] = {1,9,2,6,3,6,-1};
  int v2[] = {3,2,8,2,-1};
  int resta12[sizeof(v1)/sizeof(v1[0])];

  resta(v1,v2,resta12);

  for (int i=0; resta12[i]!=FINAL; i++)
    printf("%d ", resta12[i]);
  
  puts("");

  int resta21[sizeof(v2)/sizeof(v2[0])];

  resta(v2,v1,resta21);

  for (int i=0; resta21[i]!=FINAL; i++)
    printf("%d ", resta21[i]);


}




void resta(const int v1[], const int v2[], int resta12[]){

  int i, t;

  for (i=0, t=0; v1[i] != FINAL; i++){

    if(!belongs(v1[i], v2))
      resta12[t++] = v1[i];

  }

  resta12[t] = FINAL;
}

bool belongs(int target, const int v2[]){

  for (int j=0; v2[j] != FINAL; j++){

    if (target == v2[j])
      return true;

  }

  return false;

}
