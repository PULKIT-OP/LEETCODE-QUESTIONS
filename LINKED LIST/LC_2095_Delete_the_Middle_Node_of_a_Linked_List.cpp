// Question Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

// METHOD 1: Mutliple Iteration

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL){
            return NULL;
        }
        ListNode *temp = head;
        int len = 0;

        while(temp != NULL){
            len++;
            temp = temp -> next;
        }

        int res = len/2;
        
        temp = head;
        while(temp != NULL){
            res--;
            if(res == 0){
                break;
            }
            temp = temp -> next;
        }
        ListNode *del = temp -> next;
        temp -> next = temp -> next -> next;
        del -> next = NULL;
        delete(del);
        return head;
    }
};


// METHOD 2: Optimized Method in one pass ----> slow and fast pointer method 

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = slow -> next -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *del = slow -> next;
        slow -> next = slow -> next -> next;
        del -> next = NULL;
        delete(del);
        
        return head;
    }
};
