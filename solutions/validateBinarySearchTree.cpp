/**
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

//Solution 1: Iterative Inorder
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true; //if null return true

        //use stack since we are doing inorder
        stack<TreeNode*> myStack;

        //this will be the value we compare to 
        //NOTE to use long because an input can be smallest int in which we need a smaller number (hence we use long)
        long val = numeric_limits<long>::min();

        //want first node
        TreeNode* curr = root;
        //keep going until the node is null and the stack is empty
        while(curr || !myStack.empty()){
            //want to keep getting left values
            while(curr){
                myStack.push(curr);
                curr = curr->left;
            }
            
            //get the first (last) value
            curr = myStack.top();
            myStack.pop(); //don't forget to delete node
            //compare if it is less than the previous (we set first value to smallest long to compare to since inputs are ints)
            //if it is not larger than previous return false (NOTE it cannot be same value)
            if(curr->val <= val) return false;

            //reset value to current value
            val = curr->val;

            //move right
            curr = curr->right;
        }
        return true;
    }
};