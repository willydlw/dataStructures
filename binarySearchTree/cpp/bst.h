#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left, TreeNode* right) : 
        val(data), left(left), right(right) {}

};

/*
    Let h = tree height

    Time Complexity: worst case, depth of recursion is O(h) 
    Space Complexity: worst case, system stack, depth of recursion is O(h) 

*/
TreeNode* searchRecursive(TreeNode* root, int val);

/*
    Let h = tree height
    Time complexity: worst case, O(h)
    Space complexity: O(1) does not require system stack space like recursion
*/
TreeNode* searchIterative(TreeNode* root, int val);


/*
    Let h = tree height, n = number of nodes in tree
    Time Complexity: 
        O(h) because we have to insert node where child ptr is null
        Worst case O(n) example insert 0 in tree: 3 -> 2 -> 1
        Ideally O(log n) if tree is well balanced

    Space complexity is same at time complexity for recursive implementation
    due to stack space used.
*/
TreeNode* insertRecursive(TreeNode* root, int val);

/*
    Let h = tree height, n = number of nodes in tree

    Time Complexity:
        O(h) because we move down the height of the tree to find 
        insertion location

        Completely Unbalanced tree (a linear chain of nodes): worst case O(n)
        Balanced tree: best case O(log n)

    Space Complexity: O(1)
*/
TreeNode* insertIterative(TreeNode* root, int val);

void inOrder(TreeNode* root, std::vector<int>& visited);

TreeNode* deleteTree(TreeNode* root);


void inOrderTraversal(TreeNode* root, std::vector<int>& visited);
void preOrderTraversal(TreeNode* root, std::vector<int>& visited);
void postOrderTraversal(TreeNode* root, std::vector<int>& visited);

#endif 