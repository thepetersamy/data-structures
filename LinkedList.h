#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

struct Node{
    int item;
    Node* next;
};


Node* insertLast(Node* l, int item){
    if(l == NULL){
        l = (Node*)malloc(sizeof(Node));
        l->item = item;
        l->next = NULL;
    }
    else{
        Node* iter = l;

        while(iter->next != NULL){
            iter =  iter->next;
        }

        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->item = item;
        tmp->next = NULL;

        iter->next = tmp;
    }

    return l;
}








#endif //DATA_STRUCTURES_LINKEDLIST_H
