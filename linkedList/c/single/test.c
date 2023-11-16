#include <assert.h>
#include <stdlib.h>

#include "linkedlist.h"

#define MAX_ARRAY_SIZE  25


void inOrderFill(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
}

void randomFill(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}

void validateList(linkedList_t* list, int* arr, int n)
{
    node_t* current = list->headptr;
    int i = 0;
    while(i < n && current != NULL)
    {
        assert(arr[i] == current->data);
        ++i;
        current = current->next;
    }

    assert(i == n);
    assert(current == NULL);
}

void test_insert_head(void)
{
    // empty list
    {
        int val = rand();
        linkedList_t list = {.headptr = NULL};
        insert_head(&list, val);
        assert(list.headptr->data == val);
        assert(list.headptr->next == NULL);
        free(list.headptr);
    }

    // non-empty list
    {
        int val1 = rand();
        int val2 = rand();
        linkedList_t list = {.headptr = NULL};
        insert_head(&list, val2);
        insert_head(&list, val1);

        assert(list.headptr->data == val1);
        assert(list.headptr->next->data == val2);
        assert(list.headptr->next->next == NULL);
        free(list.headptr->next);
        free(list.headptr);
    }

    // random length list
    {
        linkedList_t list = {.headptr = NULL};
        int n = (rand() % MAX_ARRAY_SIZE) + 1;  // avoid zero length 
        int arr[n];

        randomFill(arr, n);

        for(int i = n-1; i >= 0; --i)
        {
            insert_head(&list, arr[i]);
        }

        validateList(&list, arr, n);
        delete_list(&list);
    }
}


void test_insert_tail(void)
{
    // empty list
    {
        int val = rand();
        linkedList_t list = {.headptr = NULL};
        insert_tail(&list, val);
        assert(list.headptr->data == val);
        assert(list.headptr->next == NULL);
        free(list.headptr);
    }

    // non-empty list
    {
        int val1 = rand();
        int val2 = rand();
        linkedList_t list = {.headptr = NULL};
        insert_tail(&list, val1);
        insert_tail(&list, val2);

        assert(list.headptr->data == val1);
        assert(list.headptr->next->data == val2);
        assert(list.headptr->next->next == NULL);
        free(list.headptr->next);
        free(list.headptr);
    }

    // random length list
    {
        linkedList_t list = {.headptr = NULL};
        int n = (rand() % MAX_ARRAY_SIZE) + 1;  // avoid zero length 
        int arr[n];

        randomFill(arr, n);

        for(int i = 0; i < n; ++i)
        {
            insert_tail(&list, arr[i]);
        }

        validateList(&list, arr, n);
        delete_list(&list);
    }
}


void test_search(void)
{
    // test empty list
    {
        linkedList_t list = {.headptr = NULL};
        node_t* found;
        found = search(&list, rand());
        assert(found == NULL);
    }

    // test non-empty list
    {
        linkedList_t list = {.headptr = NULL};
        int n = (rand() % MAX_ARRAY_SIZE) + 1;
        int arr[n];
        int i;

        randomFill(arr, n);
        for(i = 0; i < n; ++i)
        {
            insert_head(&list, arr[i]);
        }

        // search for values in list
        for(i = 0; i < n; ++i)
        {
            node_t* found = NULL;
            found = search(&list, arr[i]);
            assert(found->data == arr[i]);
        }

         // search for value not in list
         node_t* found = NULL;
         found = search(&list, -1);
         assert(found == NULL);

         delete_list(&list);
    }
}


#if 0
void test_delete(void)
{
    // test deleting node from empty list
    {
        linkedList_t list = {.headptr = NULL};
        delete(&list, 0);
        assert(list.headptr == NULL);
    }

    // test deleting node from head of list, list length is 1
    {
        linkedList_t list = {.headptr = NULL};
        int val = rand();
        insert_head(&list, val);
        assert(list.headptr->data == val);
        delete(&list, val);
        assert(list.headptr == NULL);
    }

    // test deleting node from head of list, list length is random
    {
        int n = (rand() % MAX_ARRAY_SIZE) + 1;
        int arr[n];
        int i;
        linkedList_t list = {.headptr = NULL};

        inOrderFill(arr, n);
        for(i = 0; i < n; i++){
            arr[i] = i;
            insert_tail(&list, arr[i]);
        }

        for(i = 0; i < n; ++i)
        {
            node_t* found = NULL;
            // confirm value is in list
            found = search(&list, arr[i]);
            assert(found != NULL);

            // confirm value has been deleted
            delete(&list, arr[i]);
            found = search(&list, arr[i]);
            assert(found == NULL);
        }

        deleteList(&list);
        assert(list.headptr == NULL);
    }


    // test deleting node from tail of list, list length is random
    {
        int n = (rand() % MAX_ARRAY_SIZE) + 1;
        int arr[n];
        int i;
        linkedList_t list = {.headptr = NULL};

        inOrderFill(arr, n);
        for(i = 0; i < n; i++){
            arr[i] = i;
            insert_head(&list, arr[i]);
        }

        for(i = 0; i < n; ++i)
        {
            node_t* found = NULL;
            // confirm value is in list
            found = search(&list, arr[i]);
            assert(found != NULL);

            // confirm value has been deleted
            delete(&list, arr[i]);
            found = search(&list, arr[i]);
            assert(found == NULL);
        }

        deleteList(&list);
        assert(list.headptr == NULL);
    }

    // test random locations 
    {
        int n = (rand() % MAX_ARRAY_SIZE) + 1;
        int arr[n];
        linkedList_t list = {.headptr = NULL};

        inOrderFill(arr, n);
        for(int i = 0; i < n; ++i)
        {
            int location = rand() % n;
            int val = arr[location];
            node_t* found;
            delete(&list, val);
            found = search(&list, val);
            assert(found == NULL);
        }

        deleteList(&list);
    }

}

#endif