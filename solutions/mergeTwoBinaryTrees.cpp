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
//Space Complexity O(n)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2; //if t1 node is null we will just use t2 node
        if(!t2) return t1; //similarly, if t2 is null we use t1
        
        t1->val += t2->val; //otherwise we will add them to t1 node

        t1->left = mergeTrees(t1->left, t2->left); //we recursively get the two left nodes
        t1->right = mergeTrees(t1->right, t2->right); //then we get the right nodes
        
        return t1;
    }
};