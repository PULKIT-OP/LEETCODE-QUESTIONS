// Question Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

// MEHTOD 1: 

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head -> next == NULL || head == NULL){
            return head;
        }
        Node *curr = head;
        Node *nex = head -> next;
        Node *prev = NULL;
        
        while(curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            curr -> prev = nex;
            prev = curr;
            curr = nex;
        }
        
        return prev;
    }
};
