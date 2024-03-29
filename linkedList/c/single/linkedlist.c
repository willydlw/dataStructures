#include "linkedlist.h"
#include <stdlib.h>             // exit, NULL
#include <stdio.h>              // fprintf


/*
    Algo:
        allocate memory for new node
        store data in new node
        change next of new node to headptr
        change headptr to new node
*/
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

/*
    Algo:
        allocate memory for new node
        store data in new node
        traverse to last node
        change next of last node to new node
*/
void insert_tail(linkedList_t* list, int val)
{
    // allocate memory for a new node
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if(newNode == NULL)
    {
        fprintf(stderr, "[ERROR] %s %d, malloc failure\n", __FUNCTION__, __LINE__);
        exit(MALLOC_NODE_FAILURE);
    }

    // store data
    newNode->data = val;

    // change next of new node to null to indicate end of list
    newNode->next = NULL;

    // empty list?
    if(list->headptr != NULL)
    {
        // traverse list to find last node
        node_t* temp = list->headptr;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        
    }
    else // empty list
    {
        list->headptr = newNode;
    }
}

/* Traverses list in order, deallocating memory
*/
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


node_t* search(const linkedList_t* list, int key)
{
    node_t* location = list->headptr;
    while(location != NULL && location->data != key)
    {
        location = location->next;
    }

    return location;
}


void printList(linkedList_t list)
{
    node_t* current = list.headptr;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}