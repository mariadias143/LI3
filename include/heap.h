#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdlib.h>
#include <string.h>
#include "mypost.h"

typedef struct heap *Heap;

Heap initHeap();
Heap initHeapPal(char* word);
char* getHeapPal(Heap h);
Heap heap_push(Heap heap, Post post, char ord);
Post heap_pop(Heap heap, char ord);
int heap_count(Heap heap);
void heap_free(Heap heap);

#endif
