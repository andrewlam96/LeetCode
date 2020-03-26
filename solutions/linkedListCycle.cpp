/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 1: using a set
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodes; //need a container/hash to check if node has been visited
        while(head){ 
            if(nodes.find(head) != nodes.end()) return true; //if node is found return true
            else nodes.insert(head); //otherwise insert into set

            head = head->next; //go to next node
        }
        return false;
    }
};

//Solution 2: Two Pointers
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false; //check if head or head next is null
        
        ListNode* slow = head; //start one pointer at beginning
        ListNode* fast = head->next; //start the other after it (so they won't be the same)
        
        //loop until they are the same or it reaches the end
        while(slow != fast){
            if(!fast || !fast->next) return false; //use fast to see if it reaches the end (should reach end faster than slow if true)

            //iterate both pointers (usually fast is 2x whatever slow is)
            slow = slow->next; 
            fast = fast->next->next;
        }
        return true;
    }
};