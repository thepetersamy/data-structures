#ifndef REPO_CHARARRAYSTACK_H
#define REPO_CHARARRAYSTACK_H


struct Stack {
    char* arr;
    int sp;
    int size;

    Stack() {
        sp = -1;
        size = 0;
        arr = NULL;
    }
};


bool init(Stack* s, int size) {

    s->arr = (char*)malloc(sizeof(char) * size);

    if (s->arr == NULL)
        return false;

    s->size = size;

    return true;
}


int push(Stack* s, char item) {

    // check if initialised
    if (s->arr == NULL) {
        return -1;
    }

    // check for overflow
    if (s->sp + 1 == s->size) {
        return -2;
    }

    s->sp++;
    s->arr[s->sp] = item;
}


int pop(Stack* s, char* item) {

    // check if initialized
    if (s->arr == NULL) {
        return -1;
    }

    // check for underflow
    if (s->sp == -1) {
        return -2;
    }

    *item = s->arr[s->sp];
    s->sp--;

    return 1;
}

int peek(Stack s, char* item){

    // check for init
    if (s.arr == NULL)
        return -1;

    // check for underflow
    if (s.sp == -1) {
        return -2;
    }

    *item = s.arr[s.sp];

    return 1;
}



bool isStackEmpty(Stack s) {
    return s.sp == -1;
}

int getCurrentStackSize(Stack s) {
    return s.size;
}

bool stackContains(Stack s, char item) {
    for (int i = 0; i < s.sp; i++) {
        if (s.arr[i] == item) {
            return true;
        }
    }
    return false;
}

int getFrequencyOf(Stack s, int item) {

    int frequencyCounter = 0;
    for (int i = 0; i < s.sp; i++) {
        if (s.arr[i] == item) {
            frequencyCounter++;
        }
    }
    return frequencyCounter;
}


#endif //REPO_CHARARRAYSTACK_H
