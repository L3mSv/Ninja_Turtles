#ifndef HEAP_H
#define HEAP_H

typedef struct Heap{
    int* array;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity);
void max_heapify(Heap* heap, int i);
void build_max_heap(Heap* heap);
void swap(int* a, int* b);
void insertHeap(Heap* heap, int value);
void printHeap(Heap* heap);
void deleteKey(Heap* heap, int index);


#endif HEAP_H