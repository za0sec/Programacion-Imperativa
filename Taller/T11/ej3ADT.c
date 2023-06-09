
#define MAX_LETTERS 25

typedef struct {  

  char * pal;
  char * sign;

}palSign;

typedef struct{
  int cant;
  palSign * lista;
}listaPalabras;


typedef struct diccioADT(){

  listaPalabras inicial[MAX_LETTERS];


}diccioADT;


diccioADT creaDiccionario(void){

  return calloc(1, sizeof(diccioADT));

}

int agregaPalabra(diccioADT dic, char* palabra, char* significado){

  int i = toUpper(*p) - 'A';

  size_t nSize = dic->

  void aux = agregarPalabra
  



}
