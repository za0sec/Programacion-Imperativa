
typedef struct node * TList;

typedef struct node{

  elemType value;
  struct node * next;

}TNode;


typedef struct queueCDT{

  TList first;
  TList last;


}queueCDT;


queueADT newQueue(void){

  queueADT new = calloc(1, sizeof(queueCDT));

  return new;

}

void queue(queueADT q, elementType n){

  TNode * myNode = calloc(1, sizeof(TNode));
  myNode->value = n;

  if(q->first == NULL){        
    q->first = myNode;
  }else{
    q->last->next = myNode;
  }
    q->last = myNode;
}

void dequeue(queueADT q, elementType * out){
 

  if (q->first == NULL){
    exit(1);
  }

  struct node * aux = q->first;
 
  if (aux == queue->last){
    q->last = q->first = NULL;
  }else{
    q->first = aux->next;
  }
  
   *out = aux->elem;
    free(aux);

}

int isEmpty(){

  return 

}

void freeQueue(queueADT q){

  freeRec(q->first);
  free(q);

}

static void freeRec(TNode * l){

  if (l == NULL){
    return;
  }

  freeRec(l->first);
  //falta algo
}
