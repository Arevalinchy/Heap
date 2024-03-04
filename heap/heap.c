#include "heap.h"
#include <stdlib.h>

heap heap_create(int k, int (*f)(const void *, const void *)) {
  if(k!=0){
    heap bestoTSA = malloc(sizeof(bestoTSA));
    bestoTSA
    bestoTSA->n = 0;
    bestoTSA->nmax = 10;
    bestoTSA->f = f;
  }
  
  return NULL;
}

void heap_destroy(heap h) {
  while(!heap_empty(h)){
    heap_top(h);
  }
  free(h-> array);
  free(h); 
}

bool heap_empty(heap h) {
  ;
  ;
  ;
  return true;
}

bool heap_add(heap h, void *object) {
 //insert le 
  return false;
}

void *heap_top(heap h) {
  ;
  ;
  ;
  return NULL;
}

void *heap_pop(heap h) {
  ;
  ;
  ;
  return NULL;
}
