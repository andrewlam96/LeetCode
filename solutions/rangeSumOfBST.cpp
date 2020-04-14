/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: recursion
//Time Complexity O(n)
//Space Complexity O(h) where h is height of tree or O(n)
//basically any traversal method will work
class Solution {
    int total = 0;
    void helper(TreeNode* root, int L, int R){
        if(!root) return;
        if(root->val >= L && root->val <= R) total += root->val; 
        if(root->left) helper(root->left, L, R);
        if(root->right) helper(root->right, L, R);
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        helper(root, L, R);
        return total;
    }
};

//Solution 2: Iteration
//Time Complexity O(n)
//Space Complexity O(h) where h is height of tree or O(n)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        //idea is using preorder iteratively
        //use stack to store nodes
        stack<TreeNode*> myStack;
        int total = 0; //keeps track of sum
        
        if(!root) return total;
        myStack.push(root); //need to push in root node first
        //want to keep looping until stack is empty
        while(!myStack.empty()){ 
            TreeNode* node = myStack.top(); //check top node
            //if it is not null and within the given range, add it to total
            if(node && node->val >= L && node->val <= R) total += node->val;
            myStack.pop(); //make sure to delete if from stack afterwrads
            
            //traverse through the right and left nodes
            if(node->right) myStack.push(node->right);
            if(node->left) myStack.push(node->left);
        }
        return total;
    }
};