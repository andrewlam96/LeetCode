/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //First Solution: Recursion
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

//Solution 2: Interative
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //use stack to store nodes
        //vector only used because that is what they want returned (not neccesarily needed)
        stack<TreeNode*> myStack;
        vector<int> solution;
        
        if(!root) return solution;

        TreeNode* curr = root; //first make a temp node and set it to the root
        while(curr || !myStack.empty()){ //will keep looping until both the stack is empty and curr in null
            //this loop is used to get to the bottom left 
            //and pushing each node along the way
            while(curr){
                myStack.push(curr);
                curr = curr->left;
            }
            //we then want the top element in stack so we can put in vector and then check right nodes
            //remember inorder is left middle(parent) right 
            curr = myStack.top();
            myStack.pop(); //make sure to remove node from stack since we already have the node to use
            solution.push_back(curr->val); //put in vector
            curr = curr->right; //check right side
        }
        return solution;
    }
};