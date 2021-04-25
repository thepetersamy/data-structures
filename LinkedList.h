#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

typedef struct{
    int data;
    struct Node* next;
}Node;

Node* insertLast(Node* head, int item){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = item;
        head->next = NULL;
    }
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

void printList(Node *head){
    Node *iterator = head;
    while(iterator->next != NULL){
        printf("%d\t", iterator->data);
        iterator = iterator->next;
    }
    printf("\n\n");
}


#endif //DATA_STRUCTURES_LINKEDLIST_H
