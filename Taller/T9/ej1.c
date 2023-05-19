#include <stdio.h>
#include "../../libreria/random.h"

#define MAX 100

typedef struct tPunto2D{

  int x;
  int y;

}tPunto2D;


typedef tPunto2D * tPosiciones;

void print(tPosiciones pos, int dim);

tPosiciones incrementParticle(int * i);

tPunto2D movement(tPunto2D particle);

int main(){

  randomize();

  int i;
 
  tPosiciones pos = incrementParticle(&i);
 
  print(pos, i);

  free(pos);
}

tPosiciones incrementParticle(int * i){
  
  tPunto2D particle;

  tPosiciones pos = NULL;

  particle.x = 0;
  particle.y = 0;

  (*i)=0;

  do{
    if((*i)%MAX== 0){
      pos = realloc(pos, ((*i)+MAX) * sizeof(tPunto2D));
    }
    pos[(*i)] = movement(particle);
    (*i)++;
  }while(pos[(*i)-1].x != 0 || pos[(*i)-1].y != 0);

  pos = realloc(pos, (*i)*sizeof(tPunto2D));


  return pos;


}

void print(tPosiciones pos, int dim){

  for (int i=0; i<dim; i++){

    printf("[%d, %d]\n", pos[i].x, pos[i].y);

  }


}

tPunto2D movement(tPunto2D particle){
  
  int increment[] = {-1, 0, 1}; 
  
  int moveX, moveY;

  moveX = randInt(0,2);
  
  moveY = randInt(0,2);
 
  particle.x += increment[moveX];
  particle.y += increment[moveY];
 
  return particle;
  
}
