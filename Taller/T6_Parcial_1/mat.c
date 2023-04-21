
int calculaDireccion(char tablero[][COL], int fil, int col, int posI, int posJ){


  aux[2][8] = {{1,1,0,-1,0,-1,0,1},
               {0,-1,-1,-1,0,1,1,1}};

  int maxDir = 0;
  int dirActual = 0;
  int max = 0;
  int anterior = 0;

    for (int j=0, t=0; j<=8; j++){
      int cont = 0;
      max = largo(tablero, posI, posJ, aux[1][j], aux[0][j], cont);
      
      
      maxDir  =  anterior < max ? dirActual : maxDir;
      anterior =  anterior < max ? max : anterior;
      dirActual += 45;

    }
  
    return anterior;
  }

}

int largo(char tablero[][COL], int posI, int posJ, int whereI, int whereJ, int cont){

  for (int i=posI+whereI, j=posJ+whereJ; i>=0 && i<FIL && j>=0 && j<=COL && tablero[i][j] == 0; i+=whereI, j+=whereJ){

    if ( tablero[i][j] == 0 ){

      cont++;

    }

  }

    return cont;

}
