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
//Time Complexity O(n)
//Space Complexityb O(1)
class Solution {
    //helper function to reverse list
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    //helper function to get second half of list
    ListNode* halfList(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        
        //first we want to get second half of list in reverse order
        //also NOTE that since we use half and not half->next
        //even numbered lists will include extra node (important for later)
        ListNode* half = halfList(head);
        ListNode* revSecondHalf = reverse(half);
 
        ListNode* first = head, *second = revSecondHalf, *temp = nullptr;

        //want to keep going until second half next is null
        //we want second->next not second because of the extra node
        //i.e. 1234 first = 123 second = 43 and 12345 first = 123 second 543
        //you can see we don't care about the last node on second since first already has it      
        while(second->next){
            //update temp to be first next
            temp = first->next;

            //then we update the next of first should be the beginning of second
            first->next = second;

            //now we can update first to be temp
            first = temp;

            //since we re-updated first as temp, we can reset temp to be second->next
            temp = second->next;

            //we can then update second next to point to first (since it is not first next)
            second->next = first;

            //finally update second by moving it to temp (second->next)
            second = temp;

        }
    }
};