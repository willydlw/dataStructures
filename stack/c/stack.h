#ifndef MY_C_STACK_H
#define MY_C_STACK_H

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
    int numElements;
} Stack;

/*  Return copy of locally declared Stack variable with members initialized.
        top = NULL
        numElements = 0
    
    No dynamic memory allocation.

    Equivalent of Stack s = {.top = NULL, .numElements = 0};
*/
Stack createStack(void);

/* Stores data in dynamically allocated Node at top of stack.

   Writes error messsage to stderr if malloc fails.
*/
void push(Stack* stack,  int data);

/* Returns data stored at top of stack.
   Removes Node from stack, frees Node memory.
*/
int pop(Stack* stack);

// Returns data stored at top of stack
int top(const Stack* stack); 

/* Returns 1 when stack is empty
   Otherwise, returns 0
*/
int isEmpty(const Stack* stack);

/* Removes all nodes from stack, frees dynamically allocated Node memory
   Data members
    top = NULL
    numElements = 0
*/
void deleteStack(Stack* stack);

#endif 