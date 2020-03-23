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
    void postorder(TreeNode* root, vector<int>& nodes){
        if(!root) return;
        
        postorder(root->left, nodes); //go to left node
        postorder(root->right, nodes); //go to right node
        nodes.push_back(root->val); //push node
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
};