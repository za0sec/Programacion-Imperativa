/*Escribir un programa que realice la simulación de un bingo para dos jugadores, 
 * el cual imprimirá paso a paso la bolilla extraída y los números faltantes (que aún no salieron)de cada cartón. 
 * Las bolillas están representadas por los números del 1 al 90 y cada jugador tiene un cartón con 15 números distintos. 
 * Los cartones son generados por el programa en forma aleatoria. 
 * No es necesario conservar los números que se van marcando en cada cartón (cuando hay coincidencia con la bolilla extraída) */


#include <stdio.h>
#include "../../libreria/random.h"
#include "../../libreria/getnum.h"
#include <stdlib.h>

typedef  int TipoLinea[5];
typedef  TipoLinea  TipoCarton [3]; 
#define MAX_BOLILLAS 90

int numJugadores;

void generarCarton(TipoCarton * carton);

int sacarBolilla(int bolillero[], int * cantBolillas);

int buscarBolilla(TipoCarton carton, int bolilla);

int controlarLineas(TipoLinea linea);

int controlarCarton(TipoCarton * carton, int bolilla);

void imprimirCarton(TipoCarton carton);

int jugar(int bolillero[], TipoCarton * carton);


int main(void){

  randomize();

  numJugadores = getint("Ingrese cantidad de jugadores: ");

  TipoCarton * carton = malloc(numJugadores * sizeof(TipoCarton));
  
    generarCarton(carton);

  int bolillero[MAX_BOLILLAS];

  for (int i=0; i<MAX_BOLILLAS; i++)
    bolillero[i] = i+1;

  int resultado = jugar(bolillero, carton);

  puts("Ganador representado en binario: ");
  
  for (int i = numJugadores - 1; i >= 0; i--) {
  
    printf("%d", (resultado >> i) & 1);
  
  }

  puts("");  


  free(carton);

  return 0;
}

int jugar(int bolillero[], TipoCarton * carton){
  
  int ganador = 0, bolilla, linea, jugadores = numJugadores;

  int ganadores[jugadores];
  
  for (int i = 0; i < jugadores; i++) {
    ganadores[i] = 0;
  }

  int resultado = 0;

  int cantBolillas = MAX_BOLILLAS, bandera = 0;

  for (int i=0; i<jugadores; i++){
      printf("Carton del jugador %d\n", i+1);
      imprimirCarton(carton[i]);
      puts("");
    
  }

  puts("Presione Enter para empezar: ");

  while(!ganador && cantBolillas>0 && getchar()){    
   
    bolilla = sacarBolilla(bolillero, &cantBolillas);
      printf("\n\nLa bolilla extraida es la nro %d\n\n", bolilla);

    for (int i=0; i<jugadores; i++){
        linea = controlarCarton(&carton[i], bolilla);
        if (linea == 1 && bandera == 0){
          printf("\n\nEl jugador %d completo una linea\n\n", i+1);
          bandera = 1;
        }else if (linea == 3){

          printf("El jugador %d hizo BINGO!!\n", i+1);
          ganadores[i] = 1;
          ganador = 1;
        }
          
      }

    for (int i=0; i<jugadores; i++){
    
      printf("Carton del jugador %d\n", i+1);
      imprimirCarton(carton[i]);
      puts("");
    
    }
        
    printf("\n\nBolillas Restantes: %d\n\n", cantBolillas);

    if (cantBolillas != 1)
      puts("\nPresione enter para sacar proxima bolilla.");

  }

  for (int i = 0; i < jugadores; ++i) {
    if (ganadores[i]) {
        resultado = resultado | (1 << i);
    }
}
  
  return resultado;

}

void imprimirCarton(TipoCarton carton){
  for (int i=0; i<3; i++){
    for (int j=0; j<5; j++){
      if (carton[i][j] == -1){
        printf("  "); 
      } else {
        printf("%2d ", carton[i][j]);
      }
    }
    printf("\n");
  }
}
int controlarCarton(TipoCarton * carton, int bolilla){
  
  int cont = 0;

  if ( buscarBolilla(*carton, bolilla)){
    
     for (int i=0; i<3; i++){
      if (controlarLineas((*carton)[i]) )
        cont++;
      
      }      
  }

  return cont;

}

int controlarLineas(TipoLinea linea){

  for(int i=0; i<5; i++)
    if ( linea[i] != -1)
      return 0;

  return 1;

}


int buscarBolilla(TipoCarton carton, int bolilla){


    for (int i=0; i<3; i++){
      for (int j=0; j<5; j++){
      
        if ( carton[i][j] == bolilla){
          carton[i][j] = -1; 
          return 1;
        }
      }
      
    } 
      
  return 0;

}


int sacarBolilla(int bolillero[], int * cantBolillas){

  int aux, indiceAl;
  
  indiceAl = randInt(1, (*cantBolillas)-1);

  aux = bolillero[(*cantBolillas)-1];

  bolillero[(*cantBolillas)-1] = bolillero[indiceAl];

  bolillero[indiceAl] = aux;

  (*cantBolillas)--;


  return bolillero[*cantBolillas];
}


void generarCarton(TipoCarton * carton){

  int jugadores = numJugadores;

  for(int c=0; c<jugadores; c++){

    int aux[90] = {0}, aleatorio;

    for (int i=0; i<3; i++){
      for (int j=0; j<5; j++){
      
        do{
          aleatorio = randInt(1,90);
        }while(aux[aleatorio-1]);
      
        aux[aleatorio-1] = 1;
        carton[c][i][j] = aleatorio;

      }
    } 
  }
}

