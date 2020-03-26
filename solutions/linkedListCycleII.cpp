/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 1: Using a set
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> nodes;
        while(head){
            //if found return that position
            if(nodes.find(head) != nodes.end()){
                return head;
            }
            nodes.insert(head); //put node in set
            head = head->next; //increament to next node
        }
        return nullptr;
    }
};

//Solution 2: Two Pointers
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        
        //start both at same position or else it can get stuck in infinite loop at end
        ListNode* slow = head;
        ListNode* fast = head;
        
        //loop until fast or fast next is null
        while(fast && fast->next){
            //move slow to next node and fast two nodes over
            slow = slow->next; 
            fast = fast->next->next;
            
            if(slow == fast) break; //if they land on same position leave loop
        }
        //check if loop broke because it hit null or if slow and fast hit same node
        if(slow != fast) return nullptr;
        
        //should be spaced out correctly where head will reach slow/fast at cycle position
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};