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

//Solution 2: Iterative
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //use stack to store nodes
        //vector only used because that is what they want returned (not neccesarily needed)
        stack<TreeNode*> myStack;
        vector<int> solution;
        
        if(!root) return solution;
        
        myStack.push(root); //put first node in stack

        //loop while the stack in not empty
        //Note that this method will get the reverse answer
        //this solution before reverse is similar to preorder interative
        while(!myStack.empty()){
            TreeNode* node = myStack.top(); //get the top node
            solution.push_back(node->val); //put its value in vector
            myStack.pop(); //delete node from stack
            //since we are doing this iteratively and using a stack, 
            //we want to use opposite logic as regular recursion since stack is LIFO (Last In First Out)
            if(node->left) myStack.push(node->left); //traverse left first
            if(node->right) myStack.push(node->right); //then traverse right afterwards
        } 
        reverse(solution.begin(), solution.end()); //reverse vector
        return solution;
    }
};