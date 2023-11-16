#ifndef SINGLE_LINKED_LIST_C_H
#define SINGLE_LINKED_LIST_C_H

#define MALLOC_NODE_FAILURE 1

typedef struct node{
    int data;
    struct node* next;
} node_t;


typedef struct linkedList{
    node_t* headptr;
} linkedList_t;


void insert_head(linkedList_t* list, int val);
void insert_tail(linkedList_t* list, int val);

void delete_list(linkedList_t* list);

node_t* search(const linkedList_t* list, int key);

void printList(linkedList_t list);

#endif 