// Question Link: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1


// METHOD 1: 

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node *dummy = new Node(-1);
        dummy -> next = head;
        head -> prev = dummy;
        Node *temp = dummy;
        
        while(temp != NULL && temp -> next != NULL){
            if(temp -> next -> data == x){
                Node *del = temp -> next;
                temp -> next = del -> next;
                if(del -> next != NULL){
                    del -> next -> prev = temp;
                    // temp -> next = temp -> next -> next;
                }
                del -> next = NULL;
                del -> prev = NULL;
                delete(del);
            }
            else{
                temp = temp -> next;
            }
        }
        
        head = dummy -> next;
        dummy -> next = NULL;
        head -> prev = NULL;
        delete(dummy);
        
        return head;
    }
};
