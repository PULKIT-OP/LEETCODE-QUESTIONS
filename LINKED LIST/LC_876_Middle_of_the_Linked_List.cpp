// Question Link: https://leetcode.com/problems/middle-of-the-linked-list/description/

// METHOD 1: Using fast and slow pointer

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head -> next == NULL || head == NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
};
