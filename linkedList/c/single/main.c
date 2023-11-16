#include <stdlib.h>
#include <time.h>

#include "test.h"

// gcc -Wall -Wextra -g main.c test.c linkedlist.c
// valgrind --leak-check=yes --log-file=valgrind.rpt ./a.out
// valgrind -s ./a.out


int main(void)
{
    srand(time(NULL));
    test_insert_head();
    test_insert_tail();
    test_search();
    //test_delete();

    return 0;
}