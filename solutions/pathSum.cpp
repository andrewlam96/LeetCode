/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Time Complexity O(n)
 //Space Complexity O(log n) (if balanced) otherwise O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        
        sum -= root->val; //subtract from sum and try to reach zero
        if((!root->left) && (!root->right)) return sum == 0; //if both children are null check if the sum is equal to 0
        //recursion call 
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

//example tree using this code
//        5
//      /   \
//     3      7
//    /  \     \
//   1    4      8
//sum = 20
//now here is what sum would print if there was a cout statement after sum -= root->val;
//sum = 15
//sum = 12
//sum = 11 (after this, it checks if sum == 0 because 1's left and right child nodes are null)
//sum = 8 (at this point it went back and ran hasPathSum(root->right, sum) to satisfy the return statement)
//also at that point it will return as well (false)
//sum = 8 (now it has gotten all the way back to the first node and is running the right side)
//sum = 0 (reaches end and will return true) and entire statement will be true since it is F || T = T 