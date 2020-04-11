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

//Solution 2: Iterative
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //use stack to store nodes
        //vector only used because that is what they want returned (not neccesarily needed)
        stack<TreeNode*> myStack;
        vector<int> solution;
        
        if(!root) return solution; //if root node is null return
        
        myStack.push(root); //push the first node into the stack
        //will loop until stack is empty
        while(!myStack.empty()){
            TreeNode* node = myStack.top(); //we want to work with the top node of the stack
            solution.push_back(node->val); //in this case we want to put it in vector
            myStack.pop(); //then delete it since it has been used
            //since we are doing this iteratively and using a stack, 
            //we want to use opposite logic as regular recursion since stack is LIFO (Last In First Out)
            if(node->right) myStack.push(node->right); //do right first since it will go out last
            if(node->left) myStack.push(node->left); //traverse left second since it will go out first
        }
        return solution;
    }
};
