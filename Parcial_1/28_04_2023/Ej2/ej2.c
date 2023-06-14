//Me dieron 3,25 puntos de 3,5. (Corregido por el chelo)
//La correccion de la catedra fue la siguiente:
//Cuando i es cero no verifica si la suma coincide, 
//tendría que hacerlo sólo cuando j también es cero, 
//por ejemplo no controla la suma de la matriz en (0,3), (0,6), etc.
//aux debe tener 3*N+1 elementos, o controlar aux[m-1].



int verifica(const int mat[][N]){

    int actual, anterior;

    for (int i=0; i<N; i+=3){

        for(int j=0; j<N; j+=3){

            actual = isSubMatrix(mat, i, j);

            if(!actual || (i && actual != anterior))

                return 0;

        }

        anterior = actual;

    }

    return 1;

}

int isSubMatrix(const int mat[][N], size_t posI, size_t posJ){

    int cont = 0, m;

    int aux[3*N] = {0};

    for (int i = posI; i<(posI+3); i++){

        for (int j = posJ; j<(posJ+3); j++){

            m = mat[i][j]; 

            if( m>=1 && m<=(3*N) && !aux[m] ){

                aux[m] = 1;

                cont += m;

            }else{

                return 0;
            }
        }
    }
    return cont;
}
