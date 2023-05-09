#include <stdio.h>
#include "../../libreria/getnum.h"
#include "../../libreria/random.h"
#include <stdlib.h>

#define X 5

void generarAleatorio(int icognita[]);

int cantidadRegular(int icognita[], int num[]);

int coincideNumero(int icognita[], int num[]);

int cantidadBien(int icognita[], int num[]);

void leerNumero(int num[]);

int elegirNivel();

int main(){


  randomize();

  int icognita[X];

  generarAleatorio(icognita);

  for (int i=0; i<X; i++)
    printf("%d", icognita[i]);

  puts("");
 
  int level = elegirNivel();

  
  for (int i=0; i<level; i++){
    
    int * num;

    num = malloc(X*sizeof(int));

    leerNumero(num);

    for (int j=0; j<X; j++)
      printf("%d", num[j]);


    if (coincideNumero(icognita, num)){
      puts("Ganaste!");
      return 0;
    }else{
    
    puts("Intento fallido");

    }
  
  }

  return 0;
  
  
  
}

int coincideNumero(int icognita[], int num[]){

  int bien = cantidadBien(icognita, num);

  int regular = cantidadRegular(icognita, num);

  printf("\n%d bien, %d regular\n", bien, regular);

  if (bien == X)
    return 1;

  return 0;

}

int cantidadRegular(int icognita[], int num[]){

  int i, j, cont=0;

  for(i=0; i<X; i++){

    for (j=0; j<X; j++){

      if (num[i] == icognita[j] && i!=j )
        cont++;

    }

  }

  return cont;

}


int cantidadBien(int icognita[], int num[]){

  int i, cont=0;

  for(i=0; i<X; i++){

    if (icognita[i] == num[i])
      cont++;

  }

  return cont;

}


void leerNumero(int * num){

  int aux[9] = {0};

  int elegido, i=1, ultimo, copia;

  do{
    printf("Ingrese un numero de %d digitos: ", X);
    scanf("%s", num);

  }



    
    

    if(elegido > 0 && elegido < 10 && !aux[elegido-1]){
      num[i++] = elegido;
      aux[elegido-1] = 1;
    }else{
      puts("Dato Incorrecto");
    }

    
  }

}


int elegirNivel(){

  int level;

  do{
    level = getint("Ingrese el nivel a Jugar: ");
  }while(level < 1 || level > 10);
  
  return level;

}

void generarAleatorio(int icognita[]){

  int aux[] = {1,2,3,4,5,6,7,8,9};

  int cambio, al;

  for (int i=0; i<X; i++){
   
    al = randInt(i+1,9);

    cambio = aux[i];

    aux[i] = aux[al];

    aux[al] = cambio;

    icognita[i] = aux[i];
    
  }

}

