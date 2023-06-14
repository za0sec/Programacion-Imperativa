//Me dieron 1,5 ptos de 3
//Este ejercicio esta mal porque no verifique los casos del largo de ambos strings
//
//Esta es la correccion de la caterdra:
//La variable t es interna al ciclo y vuelve a 0 todo el tiempo. Las variables c1 y c2 las define dos veces. 
//Al usar un solo índice y evaluar únicamente si s1 se terminó, 
//si s2 o s3 son más cortos, se intentará acceder a posiciones inexistentes. 
//En esos casos, fallará.

void elimina(char * s1, const char * s2, const char * s3){

    char c1, c2;

    for (int i=0; s1[i]; i++){

        int t=0;

        char c1 = s2[i];

        char c2 = s3[i];

        if (s1[i] != c1 && s2[i] != c2)

            s1[t++] = s1[i];

    }

    s1[t] = '\0';
}
