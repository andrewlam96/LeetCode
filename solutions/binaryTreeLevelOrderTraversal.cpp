/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: Recursion
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
    vector<vector<int>> levels; //2D vector to store nodes
    void helper(TreeNode* node, int level){ //helper function to keep track of level
        if(levels.size() == level)
            levels.push_back(vector<int>());
        
        levels[level].push_back(node->val);
        
        if(node->left) //check left node of current node
            helper(node->left, level + 1); //recursively call left side
        if(node->right) //check right node of current node
            helper(node->right, level + 1); //recursively call right side
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return levels;
        
        helper(root, 0);
        return levels;
    }
};

//Solution 2: Iterative
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Since this is BFS we will use a queue
        //2D vector only used because that is what they want returned (not neccesarily needed)
        queue<TreeNode*> myQueue;
        vector<vector<int>> solution;
        
        if(!root) return solution;
        
        myQueue.push(root); //push initial node into queue
        int level = 0; //keep track of the level we are on
        //loop until queue is empty
        while(!myQueue.empty()){
            //everytime we get back to beginning of the loop, that means we are on a new level
            //so we need to add another vector
            solution.push_back(vector<int>());

            //the amount of nodes in the queue currently is how many are going to be in the level 
            int levelLength = myQueue.size();
            
            //so we will loop through that many times to push them into the vector
            for(int i = 0; i < levelLength; ++i){
                //first get the node
                //the push into the vector and delete it from queue
                TreeNode* node = myQueue.front();
                solution[level].push_back(node->val);
                myQueue.pop();
                
                //then check if that node has has children and push them into queue
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
            }
            ++level; //go to next level
        }
        return solution;
    }
};