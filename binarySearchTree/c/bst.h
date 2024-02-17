/* Binary Search Tree

    Each node has two children: left, right.
        Left child less than parent value.
        Right child value greater than parent value.

*/

#ifndef MY_BST_H
#define MY_BST_H

#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstInsertIterative(struct TreeNode* root, int val);
struct TreeNode* bstInsertRecursive(struct TreeNode* root, int val);
struct TreeNode* bstSearchRecursive(struct TreeNode* root, int val);
struct TreeNode* bstSearchIterative(struct TreeNode* root, int val);

/* Given a binary search tree and a key value, this function
   deletes the key and returns the new root */
struct TreeNode* bstDeleteIterative(struct TreeNode* root, int val);

/* TODO: Not yet implemented
*/
struct TreeNode* bstDeleteRecursive(struct TreeNode* root, int val);


/*  Deletes all node in tree
*/
struct TreeNode* deletePostOrder(struct TreeNode *root);


void printInOrder(struct TreeNode *root, FILE *out);
void printPreOrder(struct TreeNode *root, FILE *out);
void printPostOrder(struct TreeNode *root, FILE *out);

#endif 