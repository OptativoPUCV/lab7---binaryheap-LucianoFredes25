#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"
#include <stdbool.h>

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){ 
  if(pq->size == 0)
    return NULL;
  
  void * first = pq->heapArray[0].data;
  
  return first;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    pq->capac *= 2;
    pq->capac += 1;
    pq = realloc(pq , pq->capac);
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;

  int numero = (3 / 2);
  printf("%d",numero);
  while(true){
    break;
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * aux = (Heap *) malloc(sizeof(Heap));
  aux->heapArray = malloc(sizeof(heapElem) * 3);
  aux->capac = 3;
  aux->size = 0;
  return aux;
}
