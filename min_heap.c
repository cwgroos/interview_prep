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

#define RIGHT(idx) (2 * idx) + 1
#define LEFT(idx) (2 * idx)

int removeElem(sMinHeap *heap) {
    int min = heap->array[1];
    int temp, tempElem;

    heap->array[1] = heap->array[heap->numElements--];
    temp = 1;
    tempElem = heap->array[temp];

    while (temp <= heap->numElements) {
        if (LEFT(temp) <= heap->numElements && tempElem > heap->array[LEFT(temp)]) {
            heap->array[temp] = heap->array[LEFT(temp)];
            heap->array[LEFT(temp)] = tempElem;
            temp = LEFT(temp);
        }
        else if (RIGHT(temp) <= heap->numElements && tempElem > heap->array[RIGHT(temp)]) {
            heap->array[temp] = heap->array[RIGHT(temp)];
            heap->array[RIGHT(temp)] = tempElem;
            temp = RIGHT(temp);
        }
        else {
            break;
        }
        tempElem = heap->array[temp];
    }

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
    int temp = removeElem(&heap);
    printf("%d\n", temp);
    temp = removeElem(&heap);
    printf("%d\n", temp);
    printHeap(&heap);

    freeHeap(&heap);

    return 0;
}