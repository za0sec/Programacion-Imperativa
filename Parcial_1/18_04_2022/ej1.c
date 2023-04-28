#include <stdio.h>
#define COLS 5

void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas);

int main(){

  int filas = 6;

  int m3[][COLS] = {{0},{0},{0},{0},{0},{0}};

  const int m1[][COLS] = {{1,2,3,4,-1},
                         {3,4,5,-1},
                         {10,15,20,-1},
                         {-1},
                         {-1},
                         {5,6,7,-1}};

  const int m2[][COLS] = {{3,4,5,6,-1},
                         {3,4,5,-1},
                         {10,20,-1},
                         {1,2,3,4,-1},
                         {-1},
                         {1,2,7,-1}};


  difSim(m1,m2,m3, filas);

  for(int i=0; i<filas; i++){
    for (int j=0; m3[i][j]!= -1; j++){
      printf("%d ", m3[i][j]);
    }
    puts("");
  }

}



void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas){

  for (int i=0; i<filas; i++){

    int j=0, t=0, p=0;

    m3[i][0] = -1;

    while (m1[i][t] != -1 || m2[i][j] != -1){
      
      
      if(m1[i][t] > m2[i][j] || m1[i][t] == -1){

        m3[i][p++] = m2[i][j++];

      }else if (m1[i][t] < m2[i][j] || m2[i][j] == -1){

        m3[i][p++] = m1[i][t++];

      }else{

        t++;
        j++;

      }

      m3[i][p] = -1;

    }

  }
  
}
