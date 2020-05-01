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

//Solution 1: Recursion
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //base case
        if(!root) return nullptr;
        
        //order does not matter
        //but we check left roots then right
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        //one we have the two roots, we switch them
        //remember root moves so it's not really the "root" but the current root of the subtree
        root->right = left;
        root->left = right;

        return root;
    }
};

//Solution 2: Iterative
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr; //if it is empty return nullptr
        
        //using BFS so use a queue
        queue<TreeNode*> q;

        //need to add first node
        q.push(root); 

        //want to keep going until queue is empty
        while(!q.empty()){

            //get the next node
            TreeNode* curr = q.front();
            q.pop(); //don't forget to delete it (can do this anywhere before if statements)

            //swap left and right
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            //traverse through tree
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return root;
    }
};