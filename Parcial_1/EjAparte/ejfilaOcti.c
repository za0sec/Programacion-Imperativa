#include <stdio.h>

#define N 4

int contieneFilas(const int m1[][N], const int m2[][N]);
int aux(const int m1[][N], const int m2[][N], size_t fila);

int contieneFilas(const int m1[][N], const int m2[][N]){
    int contTotal = 0;
    int contm1 = 0;
    int contm2 = 0;
    for(int i = 0; i < N; i++){
        contm1 += aux(m1, m2, i);
        contm2 += aux(m2,m1,i);
    }
    if(contm1 == N){ //LA MATRIZ 1 ESTA CONTENIDA EN LA 2
        contTotal=1;
    }
    if(contm2 == N){
        contTotal=2;
    }
    return contTotal;
}

//MI FUNCION AUXILIAR ES LA QUE CHEQUEA UNA FILA CON TODA LA OTRA MATRIZ, Y LUEGO LA LLAMO CON LOS PARAMETROS AL REVES
//DEVUELVE 0 SI LA MATRIZ NO ESTA INCLUIDA
//DEVUELVE 1 SI LA MATRIZ ESTA INCLUIDA

int aux(const int m1[][N], const int m2[][N], size_t fila){
    int cont;
    for(int i = 0; i < N; i++){ //este es el for que se mueven entre las filas de m2
        cont = 0;
        for(int j = 0; j < N; j++){ //este es el for que se mueve entre los numeros del vector de m1
            for(int k = 0; k < N; k++){ //este es el for que se mueve entre los numeros del vector de m2
                if(m1[fila][j] == m2[i][k]){
                    cont++;
                }
            }
        if(cont == N)
            return 1;
        }
    }
    return 0;
}


int main(){
    int m1[][N] = {{1,1,2,3},{3,3,3,3},{9,8,1,2},{1,8,1,8}};
    int m2[][N] = {{1,8,9,2},{1,3,2,4},{7,7,7,7},{4,5,65,7}};
    printf("%d\n", contieneFilas(m1,m2));
    return 0;
}
