/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //First Solution: Recursice
 //Time Complexity O(n)
 //Space Complexity O(n)
class Solution {
    void inorder(TreeNode* root, vector<int>& nodes){
        if(!root) return;
        
        inorder(root->left, nodes); //go to left node first
        nodes.push_back(root->val); //push that node
        inorder(root->right, nodes); //check right node after
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
};