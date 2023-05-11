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
  void * auxData;
  int auxPrio , padre , posActual = pq->size;

  //aumento capacidad
  if(pq->size == pq->capac){
    pq->capac *= 2;
    pq->capac += 1;
    pq = realloc(pq , pq->capac);
  }

  //insertar el nuevo nodo
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  
  while(true){
    if(posActual == 0)
      break;
    //posicion del padre 
    if(posActual % 2 == 0)
      padre = posActual / 2 - 1;
    else
      padre = posActual / 2;
    
    //correctamente posicionado
    if(pq->heapArray[padre].priority > pq->heapArray[posActual].priority)
      break;
      
    //cambio de posicion
    else
    {
      auxData = pq->heapArray[padre].data;
      auxPrio = pq->heapArray[padre].priority;
      
      pq->heapArray[padre].data = pq->heapArray[posActual].data;
      pq->heapArray[padre].priority = pq->heapArray[posActual].priority;
      
      pq->heapArray[posActual].data = auxData;
      pq->heapArray[posActual].priority = auxPrio;
      
      posActual = padre;
    }
  }
}


void heap_pop(Heap* pq){
  int pos = 0 , auxPrio;
  void * auxData;

  for(int i = 0 ; i < pq->size ; i++)
    printf("%d ", pq->heapArray[i].priority);
  printf("\n");
  pq->heapArray[pos].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[pos].priority = pq->heapArray[pq->size-1].priority;
  pq->size--;

  for(int i = 0 ; i < pq->size ; i++)
    printf("%d ", pq->heapArray[i].priority);
  printf("\n");
  
  while(true){
    int hijoIzq = pq->heapArray[2 * pos + 1].priority;
    int hijoDer = pq->heapArray[2 * pos + 2].priority;

    auxData = pq->heapArray[pos].data;
    auxPrio = pq->heapArray[pos].priority;
    break;
    if(pq->heapArray[pos].priority > hijoIzq && pq->heapArray[pos].priority > hijoDer)
      break;
    
    if(hijoIzq > pq->heapArray[pos].priority){
      pq->heapArray[pos].data = pq->heapArray[2 * pos + 1].data;
      pq->heapArray[pos].priority = hijoIzq;
      pq->heapArray[2 * pos + 1].data = auxData;
      pq->heapArray[2 * pos + 1].priority = auxPrio;
      pos = 2*pos+1;
    }
    else if (hijoDer > pq->heapArray[pos].priority){
      pq->heapArray[pos].data = pq->heapArray[2 * pos + 2].data;
      pq->heapArray[pos].priority = hijoDer;
      pq->heapArray[2 * pos + 2].data = auxData;
      pq->heapArray[2 * pos + 2].priority = auxPrio;
      pos = 2*pos+2;
    }
    
    break;    
  }
    
}

Heap* createHeap(){
  Heap * aux = (Heap *) malloc(sizeof(Heap));
  aux->heapArray = malloc(sizeof(heapElem) * 3);
  aux->capac = 3;
  aux->size = 0;
  return aux;
}
