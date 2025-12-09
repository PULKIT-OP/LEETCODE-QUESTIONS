// Question Link: https://leetcode.com/problems/add-two-numbers/

class Solution {
    ListNode *reverse(ListNode *head){
        ListNode * curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(ListNode *&head, ListNode *&tail, int val){
        ListNode *temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    ListNode *add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;
        
        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL){
                val1 = l1 -> val;
            }
            
            int val2 = 0;
            if(l2 != NULL){
                val2 = l2 -> val;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            if(l1 != NULL){
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                l2 = l2 -> next;
            }
        }
        return ansHead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1 ---> reverse the list
        // As the Question says its already in the reverse order so we dont have to do this reversal again...
        //l1 = reverse(l1);
        //l2 = reverse(l2);
        
        // Add lists
        ListNode *ans = add(l1, l2);
        
        // Step 3 ---> reverse the result list to get the final answer
        //ans = reverse(ans);
        return ans;
    }
};
