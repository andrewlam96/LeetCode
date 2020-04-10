/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 1: counting size and then going half way
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count  = 0;
        ListNode* curr = head; //set curr to head
        while(curr){ //loop until curr is null
            //increment both curr and head
            ++count; 
            curr = curr->next;
        }
        
        //set count / 2 so we get middle and reset curr to the head
        count /= 2;
        curr = head;
        //loop until count reaches 0
        while(count > 0){
            //decrement count and increment curr
            --count;
            curr = curr->next;
        }
        return curr; //curr should now be the middle node
    }
};
//Solution 2: 2 Pointer
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head; //set both pointers to the head
        while(fast && fast->next){ //loop until fast or fast next is null
            slow = slow->next; //increment slow once
            fast = fast->next->next; //increment fast twice 
        }
        return slow; //slow should be 1/2 way through of what fast is (the end)
    }
};