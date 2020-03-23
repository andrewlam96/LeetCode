/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //First Solution: recursion
 //Time complexity O(n)
 //Space complexity O(n)
class Solution {
    void preorder(TreeNode* root, vector<int>& nodes){ //helper function so preorder can be called recursively
        if(!root) return;
        
        nodes.push_back(root->val); //push first node to vector
        //traverse through tree be going through left then right child nodes recursively
        preorder(root->left, nodes);
        preorder(root->right, nodes);
        
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
};