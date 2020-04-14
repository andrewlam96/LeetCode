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
//Space Complexity O(h) (height of tree) or O(n)
//idea is similar to postorder traversal
class Solution {
    int height(TreeNode* root, int &diameter){
        if(!root) return 0; //base case return 0 if null
        int left = height(root->left, diameter); //check left side first
        int right = height(root->right, diameter); //then check right side
        diameter = max(diameter, left + right); //diameter is max of either current diameter or left + right side
        return max(left, right) + 1; // used to update left and right once it reaches this point
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; //start at 0 since that is the height / depth of first node
        height(root, diameter);  //we don't care what height of returned node is
        return diameter; //we want the diameter which has been updated and brought back (since it is a reference)
    }
};