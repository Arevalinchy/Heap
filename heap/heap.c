#include "heap.h"
#include <stdlib.h>

heap heap_create(int k, int (*f)(const void *, const void *)) {
  if(k!=0){
    heap bestoTSA = malloc(sizeof(*bestoTSA));
    bestoTSA->n = 0;
    bestoTSA->nmax = k;
    bestoTSA->array = malloc((k+1)*sizeof(void*));
    bestoTSA->f = f;
    return bestoTSA;
  }
  return NULL;
}

void heap_destroy(heap h) {
  while(!heap_empty(h)){
    heap_pop(h);
  }
  free(h-> array);
  free(h); 
}

bool heap_empty(heap h) {
  if(h->n != 0) return false;
  return true;
}

//manque cette fonction
bool heap_add(heap h, void *object) {   
  if(h->n == h->nmax) return true;
  h->array[++(h->n)] = object;
  int fils = h->n, parrent = 1;
  if (fils != 1) parrent = (fils%2 == 0) ? fils/2 : (fils - 1)/2;  
  while ((h->f( h->array[fils],h->array[parrent]) ) < 0){
    //j'échange
    void* temp = h->array[parrent];
    h->array[parrent] = h->array[fils];
    h->array[fils] = temp;
    //rechercer le nouveaux parrent 
    fils = parrent;
    if (fils != 1) parrent = (fils%2 == 0) ? fils/2 : (fils - 1)/2;  
  }

  return false;
}

void *heap_top(heap h) {
  if(heap_empty(h)) return NULL;
  return h->array[1];
}

//manque cette fonction

void *heap_pop(heap h) {
  if(heap_empty(h)) return NULL;
  void* premier = heap_top(h);
  h->array[1] = h->array[h->n];
  h->array[(h->n)--] = premier; 
  //rechercer le fils plus petit
  int parrent = 1;
  while( h->f(h->array[parrent],h->array[2*parrent]) > 0  || h->f(h->array[parrent],h->array[2*parrent+1]) > 0 )
  {
    void* temp = h->array[parrent];
    if(h->f(h->array[2*parrent],h->array[2*parrent+1]) < 0 ){
      h->array[parrent] = h->array[2*parrent];
      h->array[2*parrent] = temp;
      parrent = (2*parrent < (h->n)/2 ) ? 2*parrent: 1; //Preciser dans la condition de parrent 
    }else{
      h->array[parrent] = h->array[2*parrent+1];
      h->array[2*parrent+1] = temp;
      parrent = (2*parrent+1 < ((h->n) -1 )/2 ) ? 2*parrent+1: 1; //Preciser dans la condition de parrent 
    }
    //verifier si noveaux parrent à des filles 

    
      
  }
  
  return premier;
}
