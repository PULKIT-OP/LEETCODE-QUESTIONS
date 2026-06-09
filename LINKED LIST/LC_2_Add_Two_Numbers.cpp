// Question Link: https://leetcode.com/problems/add-two-numbers/description/

// METHOD 1: Make a new List and add the summation in that list then return that list  --->  takes extra space

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        int carry = 0;
        while(temp1 != NULL && temp2 != NULL){
            int val = temp1 -> val + temp2 -> val + carry;
            carry = val/10;
            ListNode *node = new ListNode(val%10);
            temp -> next = node;
            temp = node;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 != NULL){
            int val = temp1 -> val + carry;
            ListNode *node = new ListNode(val%10);
            temp -> next = node;
            temp = node;
            carry = val/10;
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            int val = temp2 -> val + carry;
            ListNode *node = new ListNode(val%10);
            temp -> next = node;
            temp = node;
            carry = val/10;
            temp2 = temp2 -> next;
        }

        if(carry > 0){
            ListNode *node = new ListNode(carry);
            temp -> next = node;
        }

        temp = dummy -> next;
        dummy -> next = NULL;
        delete(dummy);

        return temp;
    }
};
