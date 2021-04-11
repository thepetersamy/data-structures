#ifndef REPO_INTARRAYQUEUE_H
#define REPO_INTARRAYQUEUE_H

// create flag to check if init

struct Queue{
    int size;
    int* arr;
    int frontPointer;
    int backPointer;

    Queue(){
        size = 0;
        arr = NULL;
        frontPointer = -1;
        backPointer = -1;
    }
};


bool init(Queue* q, int size){

    q->arr = (int*)malloc(sizeof(int) * size);
    q->size = size;

    if (q->arr == NULL)
        return false;

    return true;
}

int enqueue(Queue* q, int item) {

    //check if init
    if (q->arr == NULL)
        return -1;

    // check for overflow
    if ((q->backPointer + 1) % q->size == q->frontPointer) {
        return -2;
    }

    if (q->backPointer == -1)
        q->frontPointer = q->backPointer = 0;
    else
        q->backPointer = (q->backPointer + 1) % q->size;

    q->arr[q->backPointer] = item;

    return 1;
}
// *** BUG HERE DONT USE YET****
int dequeue(Queue* q, int *item){

    // check if init
    if(q->arr == NULL)
        return -1;

    // check for underflow
    if(q->frontPointer == -1){
        return -2;
    }

    *item = q->arr[q->frontPointer];

    if(q->backPointer == q->frontPointer){
        q->backPointer = q->backPointer = -1;
    }
    else{
        q->frontPointer = (q->frontPointer+1) % q->size;
    }
    return 1;
}

bool isQueueEmpty(Queue q){
    if (q.frontPointer == -1) {
        return true;
    }
    else {
        return false;
    }
}


#endif //REPO_INTARRAYQUEUE_H
