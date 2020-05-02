/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time Complexity O(1)
//Space Complexity O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        //Since we're given the node we want to delete, and it is never the tail
        //we can just replace it with the next node
        //i.e. 4->5->1->9 (delete 5)
        //4->1->1->9 and then 4->1->9 1 (the value after 5 is not connected to anything)

        //technically don't need this, but use variable for next node
        ListNode* tempNext = node->next;   

        //change deleted node to the next node
        node->val = tempNext->val;

        //then change their pointers as well
        node->next = tempNext->next;
    }
};