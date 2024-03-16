#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 50
#define DIRECTIONS 3
#define ALIVE '#'
#define DEAD ' '


/*
Cualquier celda viva con menos de dos vecinos vivos muere, como por subpoblación.
Cualquier celda viva con dos o tres vecinos vivos vive hasta la próxima generación.
Cualquier celda viva con más de tres vecinos vivos muere, como por sobrepoblación.
Cualquier celda muerta con exactamente tres vecinos vivos se convierte en una celda viva, como por reproducción.
*/ 


void print_world();
void initialize();
void next_gen(char world[][SIZE]);
int check(char world[][SIZE], int row, int col, int situation);

int main(){

    char world[SIZE][SIZE] = {0};

    initialize(world);
    while (1) {

        print_world(world);
        next_gen(world);
        usleep(100000); 
    }
    return 0;    
}

void initialize(char world[][SIZE]){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            world[i][j] = DEAD;
        }
    }

    // Aca se ingresa la configuracion inicial!
    int mid = SIZE / 2;
    world[mid-1][mid] = ALIVE;
    world[mid][mid-1] = ALIVE;
    world[mid][mid] = ALIVE;
    world[mid][mid+1] = ALIVE;
    world[mid+1][mid-1] = ALIVE;
}


void print_world(char world[][SIZE]) {
    printf("\033[2J");  // borra la pantalla de la terminal
    printf("\033[H");  // mueve el cursor a la esquina superior izquierda
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", world[i][j] == ALIVE ? ALIVE : DEAD);
        }
        printf("\n");
    }
}

void next_gen(char world[][SIZE]){
    char new_world[SIZE][SIZE] = {0};

    int result;

    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){

            if (i != 0 && j != 0){
        
                if (world[i][j] == ALIVE){
                    result = check(world, i, j, 1);
                    if (!result){
                        new_world[i][j] = DEAD;
                 }else {
                     new_world[i][j] = ALIVE;
                 }
                
                }else{
                    if (check(world, i, j, 0)){
                        new_world[i][j] = ALIVE;
                    }else{
                        new_world[i][j] = DEAD;
                    }
                }   
            }

        }
    }

 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            world[i][j] = new_world[i][j];
        }
    }
}



int check(char world[][SIZE], int row, int col, int situation) {

    int pos[DIRECTIONS] = {-1, 0, 1};

    int ret;

    int count = 0;

    for (int i = 0; i < DIRECTIONS; i++) {
        for (int j = 0; j < DIRECTIONS; j++) {
            if ( !(i == 1 && j == 1) ){
                int ni = row + pos[i];
                int nj = col + pos[j];
                if (ni >= 0 && nj >= 0 && ni < SIZE && nj < SIZE && world[ni][nj] == ALIVE) {
                    count++;
                }
            }
        }
    }

    if (situation) {
        ret = (count == 2 || count == 3);
    } else {
        ret = (count == 3);
    }

  return ret;

}

