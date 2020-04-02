/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Solution 1: Using vector
//Time Complexity O(n)
//Space Complexity O(1) 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v; //create vector to store linkedlist nodes
        ListNode* curr = head; //make temp node to move head (technically i could have just used head)
        while(curr){
            v.push_back(curr->val); //put node in vector
            curr = curr->next; //move to next node
        }
        
        for(int i = 0; i < v.size() / 2; ++i){ //only go to size / 2 because we check both half at same time
            int j = v.size() - 1 - i; //j is will be at end of vector and decrement
            if(v[i] != v[j]) return false; //if both sides are not equal return false
        }
        return true;
    }
};