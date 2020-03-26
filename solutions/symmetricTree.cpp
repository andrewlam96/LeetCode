/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool helper(TreeNode* t1, TreeNode* t2){
        //if nodes are the same return true
        if(t1 == nullptr && t2 == nullptr) return true;
        //will get error if you try to call left or right and node is nullptr so it needs to be checked
        if(t1 == nullptr || t2 == nullptr) return false; 

        //return true if the values of both nodes are the same and their children are the same too
        return (t1->val == t2->val) && helper(t1->left, t2->right) && helper(t1->right, t2->left);
            
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};