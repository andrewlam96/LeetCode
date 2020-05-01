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
//Time Complexity O(max(n,m))
//Space Complexity O(max(n,m))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node = new ListNode(0); //need listnode to store solution
        ListNode *curr = node; //need something to traverse through and add new nodes
        int carry = 0; //if the addition requires a carry
        //want to keep looping until both lists are empty
        while(l1 || l2){
            //want to check if the list are not null
            //if not use the value otherwise use 0
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            //the sum is the 2 values plus the carry
            int sum = x + y + carry;

            //to get carry we can divide by 10 (if < 10) it will be 0 (if > 10) will be 1
            carry = sum / 10;

            //we want to use modulo for sum because it can be > 9
            sum %= 10;

            //add the sum to list
            curr->next = new ListNode(sum);

            //go to next node in every list
            //Note we need if statements because onoe of the original lists could be null
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        //finally we check if carry > 1 and add 1 to list if it is
        if(carry > 0) curr->next = new ListNode(1);

        //we return node next because the first node is technically a dummy Node
        return node->next;
    }
};