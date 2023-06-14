//saque un 0,5 de 3,5
//Los comentarios de la catedra: (Lo hice muy feo este ejercicio porque me volvi loco y use un strcopy y strlen que no hacia falta alto tonto)
//- Antes de invocar a belongs debería verificar si mat[i][j] == s[j] para ya marcar el verde y ahorrarse el recorrido sobre la palabra secreta 
//- Ineficiente: No corresponde invocar a strlen(s) cuando de antemano se sabe que la palabra es de COLS caracteres
//- Mal la lógica para buscar si un caracter está en la palabra: No corresponde que belongs invoque hasta dos veces a strchr. Es ineficiente utilizar un arreglo auxiliar y un strcpy. Primero debe buscar en un índice para ver si corresponde marcar verde. Si no corresponde marcar verde y strchr retorna distinto de NULL entonces la letra se encontró y corresponde marcar amarillo. Si retornó NULL corresponde marcar gris.
//Además con dos invocaciones a strchr sólo le permite saltearse el primer repetido, para contemplar que esté repetida más de una vez debería estar en un ciclo. ¿Para qué hace t[p-s] = '!';? No actúa como marca de fin.
//- Donde dice return i debe decir return i + 1
//- Accede a posiciones inválidas cuando hace aux[p-s] == 1
//- No coinciden los tipos de dato: Hace *p = strchr pero p ya es un puntero a char
//- (Es redundante preguntar por (j+1) != c en el else if porque el if anterior tenía el complemento de esta condición)
//- (En belongs, la comparación de p con NULL y el return 0 podría estar antes del strcpy y el segundo strchr porque ya se sabe que corresponde marcar un gris)




//Este comentario de abajo se lo puse en el parcial.
//Soy consciente de que este ejercicio es ultra ineficiente (y seguramente no funcione) debido al strcopy y strlen pero lo pense asi y despues no tuve otra //mejor idea. 
#define MAX_LETTER 26

int wordle(const char * s, const char mat[][COLS], int intentos, char mat2[][COLS]){

    int c, cont = 0;

    char t[strlen(s)];

    int aux[MAX_LETTER] = {0};

    for (int i=0; i<FILS || i != intentos; i++){

        for (int j=0; j<COLS; j++){
            c = belongs(mat[i][j], s, aux, t);
            if ((j+1) == c){
                mat2[i][j] = 'V';
                cont++;
            }else if (c && (j+1) != c ){
                mat2[i][j] = 'A';
            }else{
                mat2[i][j] = 'G';
            }
        }
        if (cont == COLS)
            return i;

        cont = 0;
    }
    return -1;
}



//Devuelvo 0 si el caracter no esta en el string. Si esta, devuelvo en que posicion del string esta el caracter. Si lo encontre y //ademas estaba repetido, lo saco de un string creado auxiliar para que pueda seguir con su busqueda normal. Porque sino, //confundiria repetidos.



int belongs(char target, const char * s, int aux[], char * t){

    char * p = strchr(s, target);

    if ( aux[p-s] == 1 ){

        strcopy(t, s);

        t[p-s] = '!';

        * p = strchr(t, target);

    } 

    if (p == NULL)
        return 0;

    aux[p-s] = 1;

    return p - s+1; 

}
