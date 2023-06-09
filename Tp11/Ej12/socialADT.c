#include "socialADT.h"
#include <stdlib.h>


typedef struct node * TList; 

typedef struct node{

  char close[20];
  struct node * tail;

}TNode;


typedef struct pPerson{
  
  TList * first;
  char name[20];
  struct pPerson * next;

}TPerson;

typedef struct pPerson * personList;

typedef struct socialCDT{

  personList pList;
  

}socialCDT;


socialADT newSocial(){

  socialCDT social = calloc(1, sizeof(socialCDT));

  return social;

}


static personList addPersonRec(personList listPer, const char * name){
  
  if (listPer == NULL){
    personList aux = malloc()

  }

}




 void addPerson(socialADT soc, const char * name){

  soc->pList = addPersonRec(soc->pList, name);




}

