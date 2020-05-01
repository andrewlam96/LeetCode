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
//Time Complexity O(n)
//Space Complexity O(n) 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if they're both null return true
        if(!p && !q) return true;

        //if one if them is null and other isn't return false
        if(!p || !q) return false;

        //if the values are not the same return false
        if(p->val != q->val) return false;

        //otherwise we recursively call the function to go through tree
        return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};