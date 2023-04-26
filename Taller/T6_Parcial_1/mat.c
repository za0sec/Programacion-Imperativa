#include <stdio.h>
#include <assert.h>
 
#define FILAS 7
#define COLS 6
 
#define ERROR (-1)
 
int calculaDireccion(char tablero[][COLS], int fil, int col, int posI, int posJ);

int largo(char tablero[][COLS], int posI, int posJ, int whereI, int whereJ);

int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);
 
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);
 
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);
 
     //Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);
 
    printf("OK!\n");
    return 0;
}


int calculaDireccion(char tablero[][COLS], int fil, int col, int posI, int posJ){

  if(posI >= fil || posJ >= col || posI < 0 || posJ < 0){
    return ERROR;
  }

  static int aux[2][8] = {{1,1,0,-1,-1,-1,0,1},
                          {0,-1,-1,-1,0,1,1,1}};

  int maxDir = 0;
  int dirActual = 0;
  int actual = 0;
  int anterior = 0;



    for (int j=0; j<8; j++){
      actual = largo(tablero, posI, posJ, aux[1][j], aux[0][j]);
      
      if (anterior < actual){
      
        maxDir = dirActual;
        anterior = actual;  

      } 

      dirActual += 45;   

    }
  
    return maxDir;
  }

int largo(char tablero[][COLS], int posI, int posJ, int whereI, int whereJ){

  int cont = 0;

  for (int i=posI+whereI, j=posJ+whereJ; i>=0 && i<FILAS && j>=0 && j<COLS && tablero[i][j] == '0'; i+=whereI, j+=whereJ){

      cont++;

  }

    return cont;

}
