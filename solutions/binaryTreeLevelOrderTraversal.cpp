/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: Recursion
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
    vector<vector<int>> levels; //2D vector to store nodes
    void helper(TreeNode* node, int level){ //helper function to keep track of level
        if(levels.size() == level)
            levels.push_back(vector<int>());
        
        levels[level].push_back(node->val);
        
        if(node->left) //check left node of current node
            helper(node->left, level + 1); //recursively call left side
        if(node->right) //check right node of current node
            helper(node->right, level + 1); //recursively call right side
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return levels;
        
        helper(root, 0);
        return levels;
    }
};