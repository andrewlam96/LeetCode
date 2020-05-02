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
//Space Complexity O(n) 
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

//Solution 2: Using reverse (Note that time is slower but space is better)
//Time Complecity O(n)
//Space Complexity O(1)
class Solution {
    //This function reverses a linked list
    ListNode* reverse(ListNode* node){
        ListNode* curr = node;
        ListNode* prev = nullptr; //previous node

        //go through all nodes
        while(curr){

            //need something to be next node
            ListNode* temp = curr->next;

            //we want to point backwards so the current next should point to the previous node
            //then we set the prev pointer at curr place
            //finally we update curr to curr next
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        //at this point prev should be the "end" pointing in reverse direction
        return prev;
    }
    
    //This function returns half of the linked list
    ListNode* halfList(ListNode* node){

        //two pointers one at "head" and another at "head next"
        ListNode* slow = node, *fast = node->next;

        //want to keep going until the fast pointer or fast pointer next is null
        while(fast && fast->next){

            //increment both pointers respectively
            slow = slow->next;
            fast = fast->next->next;
        }

        //want to return slow because that should be half of what fast is
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        //if either the first two nodes are null return true
        if(!head || !head->next) return true;

        //this will get half the list
        //the we will reverse the second half to compare to head->half
        ListNode* endOfHalf = halfList(head);
        ListNode* secondHalf = reverse(endOfHalf->next);
        
        ListNode* first = head, *second = secondHalf;

        //go until either reaches the end
        while(first && second){

            //if the values aren't the same return false
            if(first->val != second->val) return false;

            //update the both lists
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};