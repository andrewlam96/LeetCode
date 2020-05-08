/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Solution 1: Brute Force
//Time Complexity O(n log n)
//Space Complexity O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        
        //go through the lists
        for(auto &l : lists){
            //want to go through the nodes is a list
            while(l != nullptr){
                //push the value into the vector
                nodes.push_back(l->val);
                //go to next node
                l = l->next;
            }
        }
        
        //sort the values
        sort(nodes.begin(), nodes.end());

        //make a linked list to use
        ListNode* ll = new ListNode(-1);
        ListNode* curr = ll;
        
        //go through all values in vector
        for(auto &i : nodes){

            //set the next node in the list to the value of vector
            curr->next = new ListNode(i);
            //go to next node in list
            curr = curr->next;
        }
        //we want to return next because the first node is a dummy node
        return ll->next;
    }
};
