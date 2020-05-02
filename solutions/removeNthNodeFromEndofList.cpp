/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//Solution 1: Two pass
//Time Complexity O(n)
//Space Complexity O(1) 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        //go through list and update count
        while(curr){
            ++count;
            curr = curr->next;
        }
        
        //to find the index that we want to remove, subtract n from count
        count -= n;

        //reset the pointer to head
        curr = head;

        //use prev pointer to have access to node before
        ListNode* prev = nullptr;

        //go to point we wnat to delete
        while(count > 0){
            //update prev and curr
            prev = curr;
            curr = curr->next;
            --count;
        }

        //if it is the first node we just want everything afterwards
        if(curr == head) return head->next;

        //otherwise we want to set the prev->next to the curr->next
        else prev->next = curr->next;
        return head;
    }
};