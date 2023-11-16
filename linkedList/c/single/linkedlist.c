#include "linkedlist.h"
#include <stdlib.h>             // exit, NULL
#include <stdio.h>              // fprintf

void insert_head(linkedList_t* list, int val)
{
    // allocate memory for new node
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
    {
        fprintf(stderr, "[ERROR] %s %d, malloc failure\n", __FUNCTION__, __LINE__);
        exit(MALLOC_NODE_FAILURE);
    }

    // store data
    newNode->data = val;

    // change next of new node to point to head
    newNode->next = list->headptr;

    // change head to point to newly created node
    list->headptr = newNode;
}


void delete_list(linkedList_t* list)
{
    node_t* current = list->headptr;
    while(current != NULL)
    {
        list->headptr = current->next;
        free(current);
        current = list->headptr;
    }
}