#ifndef BST_TREE_TEST_H
#define BST_TREE_TEST_H

#include <stdio.h>
#include "bst.h"


// Preprocessor Constants

// range of randomly generated tree node values
#define TEST_MIN_RANDOM_NODE_VALUE 0
#define TEST_MAX_RANDOM_NODE_VALUE 999

#define TEST_MAX_RANDOM_ARRAY_SIZE 256


// Type definitons - function pointers
typedef struct TreeNode* (*funptr)(struct TreeNode*, int val);
typedef void (*travel)(struct TreeNode* root, FILE *fptr);

// Function Prototypes

// Contains test data sets for the mu function
void runDataSets(void);

void runTests(void);

void testDelete(void);
void testInsertion(int *arr, int n);


void traverseTree(travel func, struct TreeNode *root, int *arr, int n, 
                    const char* filename);

void testSearch();

/* Creates a binary search tree using the function passed as
   the func argument. Allows for testing both recursive and 
   iterative implementions of bstInsert.

   The array is traversed in order from index 0 to n-1, inserting
   the elements into the bst.

   Returns a pointer to tree root node.
*/
struct TreeNode* createTree(funptr func, int *arr, int n);

// compares array elements to file contents
void fileCompare(FILE *infile, int* arr, int n);


/* Fills array with n unique random numbers selected 
   from the range: [0, MAX_RANGE]
*/
void uniqueRandomArray(int *arr, int n);

// writes array values to file stream out
void printArray(FILE *out, const int *arr, int n);


/* Tests insert, search, and tree traversal functions.
   Uses deleteTree to delete all nodes and free memory.
*/
void multiTest(int n, int *arr, int *inorder, int *preorder, int *postorder);

#endif 