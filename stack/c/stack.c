#include "stack.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Stack createStack(void)
{
    Stack stack = {NULL, 0};
    return stack;
}

void push(Stack* stack,  int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    if(n == NULL)
    {
        fprintf(stderr, "malloc error, data not pushed onto stack\n");
        return;
    }

    n->data = data;
    n->next = stack->top;
    stack->top = n;
    stack->numElements += 1;
}

int pop(Stack* stack)
{
    int data = INT_MIN;

    if(stack->top)
    {
        data = stack->top->data;
        Node* newTop = stack->top->next;
        free(stack->top);
        stack->top = newTop;
        stack->numElements -= 1;
    }
    
    return data;
}

int top(const Stack* stack)
{
    return stack->top->data;
}

void deleteStack(Stack* stack)
{
    while(!isEmpty(stack))
    {
        Node* next = stack->top->next;
        free(stack->top);
        stack->top = next;
    }
    
    stack->numElements = 0;
}

int isEmpty(const Stack* stack)
{
    return stack->top == NULL;
}