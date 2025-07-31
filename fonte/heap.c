#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/heap.h"

Heap* createHeap(int capacity)
{
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct Mission*) malloc(capacity * sizeof(Mission));
    return heap;
}

void swap(struct Mission* a, struct Mission* b)
{
    struct Mission temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(Heap* heap, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->array[left].level > heap->array[largest].level)
        largest = left;

    if(right < heap->size && heap->array[right].level > heap->array[largest].level)
        largest = right;
    
    if(largest != i)
    {
        swap(&heap->array[i], &heap->array[largest]);
        max_heapify(heap, largest);
    }
}

void build_max_heap(Heap* heap)
{
    int n = heap->size;

    for(int i = (n-1)/2; i >= 0; --i)
        max_heapify(heap, i);
}

void insertHeap(Heap* heap, struct Mission* mission)
{
    if(heap->size == heap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }

    heap -> size++;
    int i = heap->size - 1;
    heap->array[i] = *mission;

    while(i != 0 && heap->array[(i-1)/2].level < heap->array[i].level)
    {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i - 1)/2;
    }
}

void printHeap(Heap* heap)
{
    for(int i = 0; i < heap->size; ++i)
    {
        printf("\nID[%d]-------------\n", i);
        printf("Local: %s ", heap->array[i].local);
        printf("Description: %s ", heap->array[i].description);
        printf("Level: %d \n\n", heap->array[i].level);
    }
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
