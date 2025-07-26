#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/heap.h"

Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap ->size = 0;
    heap -> capacity = capacity;
    heap -> array = (int*) malloc(capacity * sizeof(int));
    return heap;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(Heap* heap, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if(right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    
    if(largest != i)
        swap(&heap->array[i], &heap->array[largest]);
        max_heapify(heap, largest);
}

void build_max_heap(Heap* heap)
{
    int n = heap->size;

    for(int i = (n-1)/2; i >= 0; --i)
        max_heapify(heap, i);
}

void insertHeap(Heap* heap, int value)
{
    if(heap->size == heap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }

    heap -> size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    while(i != 0 && heap->array[(i-1)/2] < heap->array[i])
    {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i - 1)/2;
    }
}

void printHeap(Heap* heap)
{
    for(int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i]);
    printf("\n");
}

void deleteKey(Heap* heap, int index)
{
    if(index >= heap->size)
    {
        printf("Invalid index\n");
        return;
    }

    if(index == heap->size - 1)
    {
        heap->size--;
        return;
    }

    heap->array[index] = heap->array[heap->size - 1];
    heap->size--;

    max_heapify(heap, index);
}
