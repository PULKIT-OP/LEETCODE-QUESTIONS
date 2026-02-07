// Question Link: https://leetcode.com/problems/odd-even-linked-list/description/

// MEHTOD 1: Using EVEN and ODD pointers

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode *even = head -> next;
        ListNode *odd = head;

        ListNode *even_st = even;
        while(even != NULL && even -> next != NULL){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = even -> next -> next;
            even = even -> next;
        }
        odd -> next = even_st;

        return head;
    }
};
