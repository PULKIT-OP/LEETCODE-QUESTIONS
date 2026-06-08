// Question Link: https://leetcode.com/problems/odd-even-linked-list/

// METHOD 1: Using array ---> Extra space 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

      // Store odd indexes first
        ListNode *temp = head;
        vector<int> value;
        while(temp != NULL){
            value.push_back(temp -> val);
            if(temp -> next){
                temp = temp -> next -> next;
            }
            else{
                break;
            }
        }

      // then store even indexes 
        temp = head -> next;
        while(temp != NULL){
            value.push_back(temp -> val);
            if(temp -> next){
                temp = temp -> next -> next;
            }
            else{
                break;
            }
        }
      // Now update the Linked List completely
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp -> val = value[i];
            i++;
            temp = temp -> next;
        }

        return head;
    }
};


// MEHTOD 2: without extra space 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *even_start = head -> next;
        ListNode *odd = head;
        ListNode *even = head -> next;

        while(even != NULL && even -> next != NULL){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = even -> next -> next;
            even = even -> next;
        }
        odd -> next = even_start;
      
        return head;
    }
};
