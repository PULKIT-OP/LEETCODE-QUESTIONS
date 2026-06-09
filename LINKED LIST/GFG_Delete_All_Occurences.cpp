// Question Link: https://www.geeksforgeeks.org/problems/delete-keys-in-a-linked-list/1

// METHOD 1: 


// METHOD 2: 

class Solution {
  public:
    Node* deleteAllOccurances(Node* head, int x) {
        // code here
        Node *dummy = new Node(-1);
        dummy -> next = head;
        Node *temp = dummy;
        
        while(temp != NULL && temp -> next != NULL){
            if(temp -> next -> data == x){
                Node *del = temp -> next;
                temp -> next = temp -> next -> next;
                del -> next = NULL;
                delete(del);
            }
            else{
                temp = temp -> next;
            }
        }
        
        return dummy -> next;
    }
};
