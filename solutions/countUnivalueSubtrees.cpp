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
 //Space Complexity O(n) or O(H) (height of tree)
class Solution {
    int total = 0;
    //function helps count each subtree
    bool helper(TreeNode* node){
        //set both bools to true since the last child nodes will be by itself and we want to add them to total
        bool leftNode = true, rightNode = true;
        
        //idea is to use DFS and work bottom up
        //So we go to bottom nodes, and check if the bottom node equals it's parent node
        if(node->left) leftNode = helper(node->left) && (node->val == node->left->val);
        if(node->right) rightNode = helper(node->right) && (node->val == node->right->val);
        
        //we then check if both subtree sides are the same
        if(leftNode && rightNode){
            //if they are, add to total and return true to move on to next iteration
            ++total; 
            return true;
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return total;
    }
};