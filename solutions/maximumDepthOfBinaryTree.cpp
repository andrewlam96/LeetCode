/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: DFS with recursion
//Time Complexity O(n)
//Space Complexity O(n) (If balanced O(log n))
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        //check left and right nodes of root recursively and add 1 to get depth
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1); 
    }
};