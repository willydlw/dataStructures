#include "bst.h"

/*
    Let h = tree height

    Time Complexity: worst case, depth of recursion is O(h) 
    Space Complexity: worst case, system stack, depth of recursion is O(h) 

*/
TreeNode* searchRecursive(TreeNode* root, int val)
{
    if(root == nullptr || root->val == val)
    {
        return root;
    }

    if(val < root->val)
    {
        root->left = searchRecursive(root->left, val);
    }

    return searchRecursive(root->right, val);    
}

/*
    Let h = tree height
    Time complexity: worst case, O(h)
    Space complexity: O(1) does not require system stack space like recursion
*/
TreeNode* searchIterative(TreeNode* root, int val)
{
    TreeNode* current = root;
    while(current != nullptr && current->val != val)
    {
        if(val < current->val)
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

/*
    Let h = tree height, n = number of nodes in tree
    Time Complexity: 
        O(h) because we have to insert node where child ptr is null
        Worst case O(n) example insert 0 in tree: 3 -> 2 -> 1
        Ideally O(log n) if tree is well balanced

    Space complexity is same at time complexity for recursive implementation
    due to stack space used.
*/
TreeNode* insertRecursive(TreeNode* root, int val)
{
    if(root == nullptr)
    {
        return new TreeNode(val);
    }

    if(val < root->val)
    {
        root->left = insertRecursive(root->left, val);
    }
    else 
    {
        root->right = insertRecursive(root->right, val);
    }

    return root;
}

TreeNode* insertIterative(TreeNode* root, int val)
{
    TreeNode *current = root;
    TreeNode *previous = nullptr;
    TreeNode *newNode = new TreeNode(val);

    if(root == nullptr)
    {
        return newNode;
    }

    while(current != nullptr)
    {
        previous = current;
        if(val > current->val)
        {
            current = current->right;
        }
        else 
        {
            current = current->left;
        }
    }

    if(val < previous->val)
    {
        previous->left = newNode;
    }
    else 
    {
        previous->right = newNode;
    }

    return root;
}


void inOrderTraversal(TreeNode* root, std::vector<int>& visited)
{
    if(root != nullptr)
    {
        inOrderTraversal(root->left, visited);
        visited.push_back(root->val);
        inOrderTraversal(root->right, visited);
    }
}

void preOrderTraversal(TreeNode* root, std::vector<int>& visited)
{
    if(root != nullptr)
    {
        visited.push_back(root->val);
        preOrderTraversal(root->left, visited);
        preOrderTraversal(root->right, visited);
    }
}


void postOrderTraversal(TreeNode* root, std::vector<int>& visited)
{
    if(root != nullptr)
    {
        postOrderTraversal(root->left, visited);
        postOrderTraversal(root->right, visited);
        visited.push_back(root->val);
    }
}


TreeNode* deleteTree(TreeNode* root)
{
    if(root != nullptr)
    {
        root->left = deleteTree(root->left);
        root->right = deleteTree(root->right);
        delete(root);
    }

    return nullptr;
}