#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"


void fillArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i]= rand();
    }
}

void test1(void)
{
    Stack s = createStack();
    assert(s.top == NULL);
    assert(s.numElements == 0);

    // call delete stack to ensure program
    // does not crash when stack is empty
    deleteStack(&s);
}


void test2(void)
{
    Stack s;
    deleteStack(&s);
}

void test3(int n)
{
    int a[n];
    fillArray(a, n);

    Stack s = createStack();
    for(int i = n-1; i >= 0; i--)
    {
        push(&s, a[i]);
    }

    assert(s.numElements == n);

    for(int i = 0; i < n; i++)
    {
        int val = pop(&s);
        assert(val == a[i]);
        assert(s.numElements ==   n-1-i);
    }

    deleteStack(&s);
}

void test4(int n)
{
    int a[n];
    fillArray(a, n);

    Stack s = createStack();
    for(int i = n-1; i >= 0; i--)
    {
        push(&s, a[i]);
    }

    assert(s.numElements == n);

    int val = top(&s);
    assert(val == a[0]);
    assert(s.numElements == n);

    deleteStack(&s);
}

int main(void)
{
    srand(time(NULL));
    test1();
    test2();
    test3(rand() % 100);
    return 0;
}