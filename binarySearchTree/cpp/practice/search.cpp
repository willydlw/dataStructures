/** Leetcode Explore BST exercise 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*  Leetcode constraints 
        - number of nodes in tree is in the range [1, 5000]
        - 1 <= Node.val <= 10^7
        - root is a binary search tree
        - 1 <= target val <= 10^7

*/
class Solution {
public:
    // Recursive Implementation
    // Time Complexity is O(H) where H is the bst height 
    // Space Complexity is 0(H) where H is the bst height
    //      space complexity is due to the recursive solution
    //      requiring space on the stack for repeated function calls
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return root;
        }

        if(root->val == val){
            return root;
        }

        if(val < root->val){
            return searchBST(root->left, val);
        }

        // val > root->val
        return searchBST(root->right, val);
    }

    // Iterative Implementation 
    // Time complexity is O(H) where H is bst height 
    // Space complexity is O(1) because additional memory required 
    //   is for one TreeNode* 
    TreeNode* searchBST(TreeNode* root, int val){
        TreeNode *current = root;
        while(current != nullptr){
            if(current->val == val){
                break;
            }
            else if(val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }

        return current;
    }
};


void runTests(void)
{
    {
        // Leetcode example 1:
        // Input 
        //      int arr arr[5] = {4,2,7,1,3};
        //      int target = 2;
        // Output 
        //      int ans[3] = {2,1,3};
    }

    {
        // Leetcode example 2:
        // Input 
        //      int arr arr[5] = {4,2,7,1,3};
        //      int target = 5;
        // Output 
        //      int ans[];  
    }
}

int main(void)
{
    runTests();
    return 0;
}