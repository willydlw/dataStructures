#include <assert.h>
#include <limits.h> 
#include <stdlib.h>

#include "test.h"


void printArray(FILE *out, const int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        fprintf(out, "%d ", arr[i]);
    }

    fprintf(out, "\n");
}


// Fill array with n unique random numbers
// selected from the range: [TEST_MIN_RANDOM_NODE_VALUE, TEST_MAX_RANDOM_NODE_VALUE]
void uniqueRandomArray(int *arr, int n)
{
    unsigned char alreadyUsed[TEST_MAX_RANDOM_NODE_VALUE + 1] = {0};

    /*  Floyd's algorithm for choosing a set S of M unique random samples 
        from a population of size N:
            N - population size
            M - set size
    */

    // random number range: [TEST_MIN_RANDOM_NODE_VALUE, TEST_MAX_RANDOM_NODE_VALUE]
    // population size is TEST_MAX_RANDOM_NODE_VALUE - TEST_MAX_RANDOM_NODE_VALUE + 1
    int N = TEST_MAX_RANDOM_NODE_VALUE - TEST_MIN_RANDOM_NODE_VALUE + 1;     
                            
    int M = n;              // unique random samples
    int in, im;             // indices

    for(in = N-M, im = 0; in < N && im < M; ++in, ++im)
    {
        assert(in != 0);
        int r = rand() % in; // assumes in will never equal zero
        if(alreadyUsed[r])
        {
            r = in;
        }
        arr[im] = r;
        alreadyUsed[r] = 1;
    }
}


struct TreeNode* createTree(funptr func, int *arr, int n)
{
    struct TreeNode *root = NULL;
    for(int i = 0; i < n; ++i)
    {
        root = func(root, arr[i]);
    }
    return root;
}


void testInsertion(int *arr, int n)
{
    {   // test iterative insert
        struct TreeNode *root = createTree(insertIterative, arr, n);
        for(int i = 0; i < n; ++i)
        {
            struct TreeNode* result = searchIterative(root, arr[i]);
            assert(result->val == arr[i]);
        }
        deleteTree(root);
        assert(root == nullptr);
    }
    
    {   // test recursive insert and search
        struct TreeNode *root = createTree(insertRecursive, arr, n);
        for(int i = 0; i < n; ++i)
        {
            struct TreeNode* result = searchRecursive(root, arr[i]);
            assert(result->val == arr[i]);
        }
        deleteTree(root);
        assert(root == nullptr);
    }
}


void testSearch()
{
    {   // search empty tree using iterative search method
        struct TreeNode* root = NULL;
        struct TreeNode* result;
        result = searchIterative(root, 1);
        assert(result == NULL);
    }

    {   // search empty tree using recursive search method
        struct TreeNode* root = NULL;
        struct TreeNode* result;
        result = searchRecursive(root, 1);
        assert(result == NULL);
    }

    {   // search for value not stored in tree
        int n = rand() % TEST_MAX_RANDOM_ARRAY_SIZE;
        int a[n];
        uniqueRandomArray(a, n);

        {   // iterative functions
            struct TreeNode *root = NULL;
            root = createTree(insertIterative, a, n);

            // tree should only contain positive numbers, so
            // searching for a negative value should produce a NULL result
            int valueNotInArray = -(rand() + 1);  
            struct TreeNode *result;  
            result = searchIterative(root, valueNotInArray);
            assert(result == NULL);
            root = deletePostOrder(root);
            assert(root == NULL);
        }

        {   // recursive functions
            struct TreeNode *root = NULL;
            root = createTree(insertRecursive, a, n);

            // tree should only contain positive numbers, so
            // searching for a negative value should produce a NULL result
            int valueNotInArray = -(rand() + 1);  
            struct TreeNode *result;  
            result = searchRecursive(root, valueNotInArray);
            assert(result == NULL);
            root = deletePostOrder(root);
            assert(root == NULL);
        }
    }
}

void testDelete(void)
{
    {   // test deletion from empty tree
        struct TreeNode* root = NULL;
        struct TreeNode* result;
        result = bstDeleteIterative(root, 1);
        assert(result == NULL);
        root = deletePostOrder(root);
        assert(root == NULL);
    }

    {   // test deletion left leaf node
        struct TreeNode* root = NULL;
        int arr[3] = {2, 1, 3};
        int valueToDelete = 1;

        root = createTree(insertRecursive, arr, 3);

        // find value in tree
        struct TreeNode* found = searchRecursive(root, valueToDelete);
        assert(found->val == valueToDelete);

        struct TreeNode* result = NULL;
        result = bstDeleteIterative(root, valueToDelete);
        assert(result == root);
        found = bstSearchRecursive(result, valueToDelete);
        assert(found == NULL);

        // free memory
        root = deletePostOrder(root);
        assert(root == NULL);
    }

    {
        // test deletion right leaf node
        struct TreeNode* root = NULL;
        int arr[3] = {2, 1, 3};
        int valueToDelete = 3;

        root = createTree(insertRecursive, arr, 3);

        // find value in tree
        struct TreeNode* found = searchRecursive(root, valueToDelete);
        assert(found->val == valueToDelete);

        struct TreeNode* result = NULL;
        result = bstDeleteIterative(root, valueToDelete);
        assert(result == root);
        found = searchRecursive(result, valueToDelete);
        assert(found == NULL);

        // free memory
        root = deletePostOrder(root);
        assert(root == NULL);
    }

    {
        // test deletion root node with 2 children
        struct TreeNode* root = NULL;
        int arr[3] = {2, 1, 3};
        int valueToDelete = 3;

        root = createTree(insertRecursive, arr, 3);

        // find value in tree
        struct TreeNode* found = searchRecursive(root, valueToDelete);
        assert(found->val == valueToDelete);

        struct TreeNode* result = NULL;
        result = deleteIterative(root, valueToDelete);
        assert(result == root);
        found = searchRecursive(result, valueToDelete);
        assert(found == NULL);

        // free memory
        root = deletePostOrder(root);
        assert(root == NULL);
    }
}


void traverseTree(travel func, struct TreeNode *root, int *arr, int n, 
                    const char* filename)
{
    FILE *fptr = fopen(filename, "w");
    assert(fptr != NULL);
    func(root, fptr);
    fclose(fptr);
    
    fptr = fopen(filename, "r");
    assert(fptr != NULL);
    fileCompare(fptr, arr, n);
    fclose(fptr);
}


void fileCompare(FILE *infile, int* arr, int n)
{
    int i = 0;
    int data;
    while(i < n && (fscanf(infile, "%d", &data) == 1))
    {
        assert(arr[i] == data);
        ++i;
    }
}


void runDataSets(void)
{
    {   // tree with root node only
        int n = 1;
        int arr[n], inorder[n], preorder[n], postorder[n];
        arr[0] = 1;
        inorder[0] = 1;
        preorder[0] = 1;
        postorder[0] = 1;
        multiTest(n, arr, inorder, preorder, postorder);
    }

    {   // tree with one left leaf node and no right leaf nodes
        int n = 2;
        int arr[2] = {3, 1};
        int inorder[2] = {1, 3};        // left, root, right
        int preorder[2] = {3, 1};       // root, left, right
        int postorder[2] = {1, 3};      // left, right, root
        multiTest(n, arr, inorder, preorder, postorder);
    }

    {   // tree with no left leaf node and one right leaf node
        int n = 2;
        int arr[2] = {3, 4};
        int inorder[2] = {3, 4};        // left, root, right
        int preorder[2] = {3, 4};       // root, left, right
        int postorder[2] = {4, 3};      // left, right, root
        multiTest(n, arr, inorder, preorder, postorder);
    }

    {   // tree with one left leaf node and one right leaf node
        int n = 3;
        int arr[3] = {3, 1, 4};
        int inorder[3] = {1, 3, 4};        // left, root, right
        int preorder[3] = {3, 1, 4};       // root, left, right
        int postorder[3] = {1, 4, 3};      // left, right, root
        multiTest(n, arr, inorder, preorder, postorder);
    }

    {   // tree with only left leaf nodes
        int n = 5;
        int arr[n];
        int inorder[n];
        int preorder[n];
        int postorder[n];

        // for a tree with left only nodes, preorder will be the same
        // as the original array used to create the tree
        for(int i = n-1; i >= 0; --i)
        {
            arr[i] = n-1-i;
            preorder[i] = n-1-i;    
        }

        for(int i = 0; i < n; ++i)
        {
            inorder[i] = i;
            postorder[i] = i;
        }

        multiTest(n, arr, inorder, preorder, postorder);
    }

    {   // tree with only right leaf nodes
        int n = 5;
        int arr[n];
        int inorder[n];
        int preorder[n];
        int postorder[n];

        // for a tree with right only nodes, inorder and preorder will be 
        // the same as the original in order array used to create the tree
        for(int i = 0; i < n; ++i)
        {
            arr[i] = i;
            inorder[i] = i; 
            preorder[i] = i;   
        }

        // post order will be in reverse order
        for(int i = 0; i < n; ++i)
        {
            postorder[i] = n-1-i;
        }

        multiTest(n, arr, inorder, preorder, postorder);
    }
 
    {   // tree with both left and right leaf nodes
        // all nodes except leaf nodes have two children
        int n = 7;
        int arr[7] = {3,1,2,0,5,4,6};
        int inorder[7] = {0,1,2,3,4,5,6};       // left, root, right
        int preorder[7] = {3,1,0,2,5,4,6};      // root, left, right
        int postorder[7] = {0,2,1,4,6,5,3};     // left, right, root
        multiTest(n, arr, inorder, preorder, postorder);
    }
 
    {   // tree with both left and right leaf nodes
        // some nodes have only one child
        // 4 has no right child
        // 8 has no left child
        int n = 9;
        int arr[9] = {5,4,7,2,3,1,6,8,9};
        int inorder[9] = {1,2,3,4,5,6,7,8,9};    // left, root, right
        int preorder[9] = {5, 4, 2, 1, 3, 7, 6, 8, 9};   // root, left, right
        int postorder[9] = {1,3,2,4,6,9,8,7,5};  // left, right, root
        multiTest(n, arr, inorder, preorder, postorder);
    }
}


void multiTest(int n, int *arr, int *inorder, int *preorder, int *postorder)
{
    {   // iterative insertion and search
        struct TreeNode *root = NULL;
        root = createTree(insertIterative, arr, n);
        assert(root != NULL);

        for(int i = 0; i < n; ++i)
        {
            struct TreeNode *result = NULL;
            result = searchIterative(root, arr[i]);
            assert(result->val == arr[i]);
        }

        traverseTree(printInOrder, root, inorder, n, "inorder.txt");
        traverseTree(printPreOrder, root, preorder, n, "preorder.txt");
        traverseTree(printPostOrder, root, postorder, n, "postorder.txt");

        root = deletePostOrder(root);
        assert(root == NULL);
    }   

     {  // recursive insertion and search
        struct TreeNode *root = NULL;
        root = createTree(bstInsertRecursive, arr, n);
        assert(root != NULL);

        for(int i = 0; i < n; ++i)
        {
            struct TreeNode *result = NULL;
            result = bstSearchRecursive(root, arr[i]);
            assert(result->val == arr[i]);
        }
    
        traverseTree(printInOrder, root, inorder, n, "inorder.txt");
        traverseTree(printPreOrder, root, preorder, n, "preorder.txt");
        traverseTree(printPostOrder, root, postorder, n, "postorder.txt");

        root = deletePostOrder(root);
        assert(root == NULL);
    }   
}


void runTests(void)
{
    runDataSets();
    testSearch();
    testDelete();
}

