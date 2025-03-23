# Binary Search Tree 

A Binary Search Tree is a special form of a binary tree. The value in each node must be greater than (or equal to) any values in its left subtree but less than (or equal to) any values in its right subtree.


## Definition

A binary search tree (BST), a special form of a binary tree, satisfies the binary search property:

1. The value in each node must be greater than (or equal to) any values stored in its left subtree.
2. The value in each node must be less than (or equal to) any values stored in its right subtree.


## Basic Operations 

- Search
- Insertion
- Deletion

### Search

Search for a target value in the tree. 

1. return the node if the target value is equal to the value of the node.
2. continue searching in the left subtree if the target value is less than the value of the node.
3. continue searching in the right subtree if the target value is greater than the value of the node.


### Insertion 

Insert a new node by minimizing the number of changes to the tree. The tree is traversed to find the proper leaf position for the target node and insert it as a leaf.

1. Search the left or right subtrees according to the relation of the value of the node and the target node value.
2. Repeat step 1 until reaching an external leaf node.
3. Add the new node as its left or right child depending on the relation of the value of the node and the value of the target node.

Note: do not add the node if it already exists in the tree.

References:

https://www.enjoyalgorithms.com/blog/insertion-in-binary-search-tree


