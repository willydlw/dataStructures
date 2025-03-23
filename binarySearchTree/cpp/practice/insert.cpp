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
        - number of nodes in tree is in the range [0, 10^4]
        - -10^8 <= Node.val <= 10^8
        - All the values Node.val are unique
        - -10^8 <= val <= 10^8
        - It is guaranteed that val does not exist in the original BST
*/
class Solution {
public:
    // Recursive Implementation
    // Time Complexity is O(H) where H is the bst height 
    // Space Complexity is 0(H) where H is the bst height
    //      space complexity is due to the recursive solution
    //      requiring space on the stack for repeated function calls
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }

        if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        else if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        
        return root;
    }

    // Iterative Implementation 
    // Time complexity is O(H) where H is bst height 
    // Space complexity is O(1) because additional memory required 
    //   is for two TreeNode* 
    TreeNode* insertIntoBST(TreeNode* root, int val){
        TreeNode *current = root;
        TreeNode *prev = nullptr;

        while(current != nullptr){
            prev = current;

            if(val < current->val){
                current = current->left;
            }
            else if(val > current->val){
                current = current->right;
            }
            else 
            {   // val == current->val which constraints say will not happen
                // so we could leave this out
                return root;
            }
        }

        if(prev == nullptr){    // empty tree inserting at root
            root = new TreeNode(val);
        }
        else if(val < prev->val){
            prev->left = new TreeNode(val);
        }
        else{   // val > prev->val
            prev->right = new TreeNode(val);
        }
  
        return root;
    }
};


void runTests(void)
{
    {
        // Leetcode example 1:
        // Input 
        //      root = {4,2,7,1,3};
        //      target = 5;
        // Output 
        //      ans = {4,2,7,1,3,5};
    }

    {
        // Leetcode example 2:
        // Input 
        //      root = {40,20,60,10,30,50,70};
        //      target = 25
        // Output 
        //      ans = {40,20,60,10,30,50,70,null,null,25}  
    }


    {
        // Leetcode example 3:
        // Input 
        //      root = {4,2,7,1,3,null,null,null,null,null,null};
        //      target = 5
        // Output 
        //      ans = {4,2,7,1,3,5}  
    }
}

int main(void)
{
    runTests();
    return 0;
}