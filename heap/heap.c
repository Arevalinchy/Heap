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
  void* temp; 
  while(h->f(h->array[n],h->array[n/2]) < 0){
    temp = h->array[n/2];
    h->array[n/2] = h->array[n];
    h->array[n] = temp;
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
  return premier;
}
