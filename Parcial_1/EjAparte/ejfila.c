/*
Escribir una función contieneFilas que reciba dos matrices de enteros de NxN, donde N es una constante previamente definida.
Se dice que una fila A está contenida en la fila B si todos los elementos de A (sin importar el orden y repetición) están en la fila B. Por ejemplo la fila {1,3,1,4} está contenida en la fila {2,3,4,1}, la fila {1,1,1,1} está contenida en la fila {3,1,4,5}
Se dice que una fila A está contenida en una matriz M si la fila A está contenida en alguna de las filas de M.
Se dice que una matriz M1 está contenida en la matriz M2 si todas las filas de M1 están contenidas en M2.
La función debe retornar:
    • 1 si la primera matriz está contenida en la segunda
    • 2 si la segunda matriz está contenida en la primera matriz
    • 0 si no se cumple ninguna de las condiciones anteriores
*/
#include <stdio.h>

#define N 4

int contained(int mat1[][N], int mat2[][N]);

int contieneFilas(int mat1[][N], int mat2[][N]);

int belongs(int c, int * fil);


int main(){
    int mat1[][N] = {{1,1,2,3},{3,3,3,3},{9,8,1,2},{1,8,1,8}};
    int mat2[][N] = {{1,8,9,2},{1,3,2,4},{7,7,7,7},{4,5,65,7}};
    printf("%d\n", contieneFilas(mat1,mat2));
    return 0;
}


int contieneFilas(int mat1[][N], int mat2[][N]){

    if (contained(mat1, mat2)){
        return 1;
    }else if (contained(mat2, mat1)){
        return 2;
    }
    return 0;

}

int contained(int mat1[][N], int mat2[][N]){

    int countContained;
    int countChecked = 0, flag;

    for (int i=0; i<N; i++){ // Recorre las filas de la matriz
        countContained=0;

        for (int k=0; k<N && countContained != N; k++){ //Este recorre la fila que voy a chequear
            flag = 0;
            for (int j=0; j<N && !flag; j++){// Recorre las columnas de la matriz
                if (belongs(mat1[i][j], mat2[k])){ 
                    countContained++;
                }else{
                    flag = 1;
                }
            }
        if (countContained == N){
            countChecked++;
        }else{
            return 0;
        }

        } 
    }

    if (countChecked == N){
        return 1;
    }

    return 0;

        
}

int belongs(int c, int fil[N]){
    
    for (int i=0; i<N; i++){
        if (c == fil[i])
            return 1;
    }
    return 0;
}
