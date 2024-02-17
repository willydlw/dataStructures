#include <stdlib.h>

#include "bst.h"

struct TreeNode* newNode(int val)
{
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(temp == NULL)
    {
        fprintf(stderr, "[%s] malloc failure\n", __func__);
    }
    else 
    {
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
    }

    return temp;
}

/* Binary Search Tree Insertion - recursive implementation

   Insertion occurs at a leaf node

*/
struct TreeNode* bstInsertRecursive(struct TreeNode *root, int val)
{
    if(root == NULL)
    {
        return newNode(val);
    }

    if(val < root->val)
    {
        root->left = bstInsertRecursive(root->left, val);
    }
    else if(val > root->val)
    {
        root->right = bstInsertRecursive(root->right, val);
    }

    // if val is already in tree, do not insert it again
    return root;
}


struct TreeNode* bstInsertIterative(struct TreeNode *root, int val)
{
    struct TreeNode *current = root;
    struct TreeNode *parent = NULL;

    if(root == NULL)
    {
        return newNode(val);
    }

    while(current != NULL)
    {
        parent = current;

        if(val < current->val)
        {
            current = current->left;
        }
        else if(val > current->val)
        {
            current = current->right;
        }
        else
        {
            // node already in tree, stop iterating through tree
            return root;
        }
    }

    current = newNode(val);
    if(current != NULL)
    {
        if(val < parent->val)
        {
            parent->left = current;
        }
        else if(val > parent->val)
        {
            parent->right = current;
        }
    }
    
    return root;
}


struct TreeNode* bstSearchRecursive(struct TreeNode *root, int val)
{
    if(root == NULL || root->val == val)
    {
        return root;
    }

    if(val < root->val)
    {
        return bstSearchRecursive(root->left, val);
    }
    
    return bstSearchRecursive(root->right, val);
}


struct TreeNode* bstSearchIterative(struct TreeNode* root, int val)
{
    struct TreeNode *current = root;
    while(current != NULL)
    {
        if(current->val == val)
        {
            return current;
        }
        else if(current->val > val)
        {
            current = current->left;
        }
        else 
        {
            current = current->right;
        }
    }

    return current;
}


/* Binary Search Tree - Delete (iterative implentation)

   Description: Given a binary search tree and a key value, 
   this function deletes the key and returns the root.

   Returns the updated root node pointer.

*/
struct TreeNode* bstDeleteIterative(struct TreeNode* root, int key)
{
    /* Possible cases:
        1. tree is empty
        2. key value is not in tree
        3. deleting leaf node
        4. deleting node with one child 
        5. deleting node with two children
    */
   
    struct TreeNode *current = root;
    struct TreeNode *parent = NULL;

    if(root == NULL)        // trivial case - empty tree
    {
        return root; 
    }

    // search for the node to delete
    while(current != NULL && current->val != key)
    {
        parent = current;
        if(key < current->val)
        {
            current = current->left;
        }
        else
        {   
            current = current->right;
        }
    }

    if(current == NULL) // key value not in tree
    {
        return root;
    }

    /*  If the current node has no children (leaf) or only one child,
        remove node from tree by redirecting parent's pointer to 
        the current node's child and deallocating memory of current node.
    */

    if(current-> left == NULL || current->right == NULL)
    {
        struct TreeNode *temp = NULL;
        if(current->left == NULL)
        {
            temp = current->right;
        }
        else 
        {
            temp = current->left;
        }

        // is node to be deleted the root?
        if(parent == NULL)
        {
            free(current);
            return temp;
        }

        // check if the node to be deleted is the parent's left
        // or right child and replace with temp
        if(current == parent->left)
        {
            parent->left = temp;
        }
        else 
        {
            parent->right = temp;
        }

        free(current);
    }
    else 
    {
        // current has two children. Find the in-order successor, which is the
        // smallest value in the right subtree of the current node. Copy the 
        // value of the inorder successor to the current node. Delete the inorder
        // successor.
        struct TreeNode *temp = current->right;
        parent = NULL;

        while(temp->left != NULL)
        {
            parent = temp;
            temp = temp->left;
        }

        // Check if parent of inorder successor is the current node.
        // If not, then make the left child of its parent equal to the
        // in-order successor's right child. Otherwise, make the right 
        // child of the node to be deleted equal to the right child of 
        // the inorder successor.
        if(parent != NULL)
        {
            parent->left = temp->right;
        }
        else 
        {
            current->right = temp->right;
        }

        current->val = temp->val;
        free(temp);
    }

    return root;  
}


/*  In-order traversal of a binary search tree effectively sorts
    the data into ascending order.

    In-order tree traversal steps:
        Traverse left-subtree
        Return to root
        Traverse right subtree

    Time Complexity: O(N) where N is the number of nodes
    Auxiliary space: O(h) where h is the height of tree
*/
void printInOrder(struct TreeNode *root, FILE *out)
{
    if(root == NULL)
    {
        return;
    }

    // traverse left sub tree
    printInOrder(root->left, out);

    // visit the root 
    fprintf(out, "%d ", root->val);
   
    // traverse right subtree
    printInOrder(root->right, out);

}


/*  Pre-order traversal of a binary search 

    In-order tree traversal steps:
        Visit the root and print the data
        Traverse left-subtree
        Traverse right subtree

    Time Complexity: O(N) where N is the number of nodes
    Auxiliary space: O(h) where h is the tree height
*/
void printPreOrder(struct TreeNode *root, FILE *out)
{
    if(root == NULL)
    {
        return;
    }

    // visit the root 
    fprintf(out, "%d ", root->val);

    // traverse left sub tree
    printPreOrder(root->left, out);
   
    // traverse right subtree
    printPreOrder(root->right, out);

}


/*  Post-order traversal of a binary search 

    In-order tree traversal steps:
        Traverse left-subtree
        Traverse right-subtree
        Visit the root and print the data
        
    Time Complexity: O(N) where N is the number of nodes
    Auxiliary space: O(h) where h is the tree height
*/
void printPostOrder(struct TreeNode *root, FILE *out)
{
    if(root == NULL)
    {
        return;
    }

    // traverse left sub tree
    printPostOrder(root->left, out);
   
    // traverse right subtree
    printPostOrder(root->right, out);

    // visit the root 
    fprintf(out, "%d ", root->val);
}


struct TreeNode* deletePostOrder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return root;
    }

    // traverse left sub tree
    root->left = deletePostOrder(root->left);
   
    // traverse right subtree
    root->right = deletePostOrder(root->right);

    // visit the root and free its memory
    free(root);
    return NULL;
}

