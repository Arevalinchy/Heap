#include "heap.h"
#include <stdlib.h>

heap heap_create(int k, int (*f)(const void *, const void *)) {
  if(k!=0){
    heap bestoTSA = (heap*) malloc(sizeof(heap));
    bestoTSA.f = f
  }

  return NULL;
}

void heap_destroy(heap h) {
  
}

bool heap_empty(heap h) {
  ;
  ;
  ;
  return true;
}

bool heap_add(heap h, void *object) {
  ;
  ;
  ;
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