#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
void* value;
} QueueNode;

typedef struct {
QueueNode* arr;
} Queue;

Queue* initializeQueue() {
Queue* queuePtr = (Queue*)malloc(sizeof(Queue));
queuePtr->arr = (QueueNode*)calloc(100, sizeof(QueueNode));
return queuePtr;
}

void freeQueue(Queue* queuePtr) {
free(queuePtr->arr);
free(queuePtr);
}

int main(void) {
Queue* queuePtr = initializeQueue();
int someIntValue = 20;
queuePtr->arr[0].value = &someIntValue;
int someIntValue1 = 30;
queuePtr->arr[1].value = &someIntValue1;
printf("Element 0: %d\n", *((int*)queuePtr->arr[0].value));
printf("Element 1: %d\n", *((int*)queuePtr->arr[1].value));
freeQueue(queuePtr);
}



//0000 0000 mask
//&
//0000 0001 tipo
//---------





