#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;


Node* insertLast(Node* head, int item){
    // if no linked list is empty, malloc and place item
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = item;
        head->next = NULL;
    }

    // else iterate over all nodes until the next Node is NULL and place item
    else{
        Node *iterator = head;

        while(iterator->next != NULL){
            iterator = iterator->next;
        }

        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = item;
        tmp->next = NULL;

        iterator->next = tmp;
    }
    return head;
}

Node* insertFirst(Node *head, int item){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = item;
        head->next = NULL;
    }
    else{
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = item;
        tmp->next = head;
        head = tmp;
    }
    return head;
}

Node* removeLast(Node* head, int *item){

    if(head == NULL)
        return NULL;

    else if(head->next == NULL){
        *item = head->data;
        free(head);
        head = NULL;
    }
    else{

        Node *iterator = head;
        while(iterator->next->next != NULL){
            iterator = iterator->next;
        }
        *item = iterator->next->data;
        free(iterator->next);

        iterator->next = NULL;
    }
    return head;
}


Node* removeFirst(Node* head, int *item){

    // if list is empty return NULL
    if(head == NULL){
        return NULL;
    }

    *item = head->data;    // return item to be removed
    Node* tmp = head;    // receive head in a temp Node
    head = head->next;    // pointing head to the next Node
    free(tmp);    // freeing the old head

    return head;

}

Node* removeNode(Node *head, int item, bool *removalResult){

    int removed;
    if(head->data == item) {
        // no need to free head here bc removeFirst does that
        head = removeFirst(head, &removed);
    }

    else{
        Node *iterator = head;
        while(iterator->next != NULL){
            // if next Node contains desired data
            if(iterator->next->data == item){

                Node *tmp = iterator->next; // place Node to be deleted in tmp Node
                iterator->next = iterator->next->next; // join ptrs
                free(tmp);  // free memory

                *removalResult = true;
                return head;
            }
            iterator = iterator->next;
        }
        if(iterator->next == NULL){
            *removalResult = false;
            return head;
        }

    }
    *removalResult = true;
    return head;
}


void printList(Node *head){
    Node *iterator = head;
    while(iterator != NULL){
        printf("%d\t", iterator->data);
        iterator = iterator->next;
    }
    printf("\n\n");
}



#endif //DATA_STRUCTURES_LINKEDLIST_H
