/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Time Complexity O(n + m)
//Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* beforeNode = new ListNode(-1); //make a new listnode with a random value to use for answer
        
        ListNode* prev = beforeNode; //need a pointer to use to move through beforeNode
        
        //this method assumes the 
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){ //l1 < l2
                prev->next = l1; //connect l1 after our current list
                l1 = l1->next; //go to next node in l1
            }
            else{ //otherwise (l2 < l1)
                prev->next = l2; //connect l2 after our current list
                l2 = l2->next; //go to next node in l2
            }
            prev = prev->next; //increment our current list
        }
        //At this point one of the lists is null and the other is not
        //you can simply just add everything else of the non-null list to the end since it's sorted
        prev->next = l1 == nullptr ? l2 : l1;
        //we want to point prev back to beforeNode->next to start back at beginning
        //it's important to do next because beforeNode is not a part of the list
        prev = beforeNode->next; 
        return prev;
    }
};