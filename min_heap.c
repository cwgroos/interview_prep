/*
 * Chris Gross
 * Min Heap implementation
 */
#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int *array;
    int capacity;
    int numElements;
} sMinHeap;

// 
void createHeap(sMinHeap *heap, int size) {
    heap->array = malloc(sizeof(int) * (size+1));
    heap->capacity = size;
    heap->numElements = 0;
}

void freeHeap(sMinHeap *heap) {
    
    if (heap->array) {
        free(heap->array); 
        heap->array = NULL;
    }
    heap->capacity = 0;
    heap->numElements = 0; 
}

#define PARENT(idx) idx / 2

void insertElem(sMinHeap *heap, int value) {

    if (heap->numElements >= heap->capacity) {
        return;
    }

    // add it
    heap->array[++(heap->numElements)] = value;
    int temp = heap->numElements;
    int tempElem = heap->array[temp];

    // bubble it upheap
    while (tempElem <= heap->array[PARENT(temp)] && temp > 1) {
        heap->array[temp] = heap->array[PARENT(temp)];
        heap->array[PARENT(temp)] = tempElem;

        temp = PARENT(temp);
        tempElem = heap->array[temp];
    }
}

void printHeap(sMinHeap *heap) {
    for (int i = 1; i <= heap->numElements; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int removeElem(sMinHeap *heap) {
    int min = heap->array[1];

    heap->array[1] = heap->array[numElements];

    return min;
}

int main(void) {

    sMinHeap heap;

    createHeap(&heap, 10);
    
    insertElem(&heap, 5);
    printHeap(&heap);
    insertElem(&heap, 4);
    printHeap(&heap);
    insertElem(&heap, 3);
    printHeap(&heap);
    insertElem(&heap, 2);
    printHeap(&heap);
    insertElem(&heap, 1);
    printHeap(&heap);
    //int temp = remove(&heap);
    //printf("%d\n", temp);
    //int temp = remove(&heap);
    //printf("%d\n", temp);

    freeHeap(&heap);

    return 0;
}