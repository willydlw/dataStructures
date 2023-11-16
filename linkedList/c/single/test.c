#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "linkedlist.h"

#define MAX_LIST_LENGTH 10

// gcc -Wall -g test.c linkedlist.c 
// run with valgrind to check memory: valgrind -s ./a.out 


void random_array_fill(int* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}

void compare_list(const linkedList_t* list, int* arr, int n)
{
    node_t* current = list->headptr;
    int i;
    for(i = 0; i < n && current != NULL; ++i)
    {
        assert(arr[i] == current->data);
        current = current->next;
    }

    // validate that all array and list data were compared
    assert(i == n);
    assert(current == NULL);
}

// test insert at head
void test_insert_head(void)
{
    {
        // test 1 - empty list
        linkedList_t emptyList = {.headptr = NULL};
        int val = rand();
        insert_head(&emptyList, val);
        assert(emptyList.headptr->data == val);
        assert(emptyList.headptr->next == NULL);
        free(emptyList.headptr);
    }

    {
        // test 2 - nonempty list
        linkedList_t emptyList = {.headptr = NULL};
        int val1 = rand();
        int val2 = rand();
        insert_head(&emptyList, val2);
        insert_head(&emptyList, val1);
        assert(emptyList.headptr->data == val1);
        assert(emptyList.headptr->next->data == val2);
        assert(emptyList.headptr->next->next == NULL);
        free(emptyList.headptr->next);
        free(emptyList.headptr);
    }

    {
        // random list
        linkedList_t list = {.headptr = NULL};
        int listLength = rand() % MAX_LIST_LENGTH + 1;  // avoid zero length list
        int testArray[listLength];
        random_array_fill(testArray, listLength);
        for(int i = 0; i < listLength; ++i)
        {
            insert_head(&list, testArray[i]);
        }

        // implicitly testing delete list
        delete_list(&list);
        assert(list.headptr == NULL);
    }

}


int main(void)
{
    srand(time(0));
    test_insert_head();
    return 0;
}