// Question Link: https://leetcode.com/problems/reverse-linked-list/

// METHOD 1:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *nex = head -> next;
        ListNode *curr = head;

        while(curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
};
