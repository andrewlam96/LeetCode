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
    bool isCousins(TreeNode* root, int x, int y) {
        //Idea is to use BFS cause it should be faster 
        //since cousins should be in same level
        //We could use DFS but we don't necessarily want to go to the bottom level if unnecessary

        //use queue since it's BFS and push root node it
        queue<TreeNode*> q;
        q.push(root);
        
        //go until the q is empty
        while(!q.empty()){

            //have two flags, one for siblings, and another for cousins
            bool siblings = false, cousins = false;
            
            //we want to go level by level, so the queue size at a time will represent the level size
            int levelSize = q.size();
            
            //go through the level
            for(int i = 0; i < levelSize; ++i){
                //get the first node
                TreeNode* node = q.front();
                q.pop();
                
                //later when we add nodes, we will also add a nullptr
                //that nullptr will help us differentiate siblings from cousins
                //because if we see a nullptr then the nodes before it are siblings
                //so by definition the ones after are cousins if found
                if(!node) siblings = false;
                else{

                    //check if node is one of the 2 values
                    if(node->val == x || node->val == y){
                        //if it is, set the two flags as true
                        if(!cousins) siblings = cousins = true;
                        //otherwise it means we found the second one so return 
                        //the opposite of siblings (siblings is false if we found nullptr so that means they are cousins)
                        //otherwise the if statement before makes siblings true which would return false
                        else return !siblings;
                    }
                    //add the children nodes to the queue
                    //also add a nullptr to separate children
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    q.push(nullptr);
                }
            }
            //if one value is found (only way this can be true)
            //then return false since the other was not found on same level so it cannot be a cousin
            if(cousins) return false;
        }
        return false;
    }
};