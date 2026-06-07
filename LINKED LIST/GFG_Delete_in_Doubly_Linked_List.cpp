// Question Link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

// METHOD 1: 

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        int count = 1;
        Node *curr = head;
        Node *prev = NULL;
        
        Node *temp = head;
        
        if(x == 1){
          // if head -> next exist then this 
            if(head -> next){
                head = head -> next;
                temp -> next = NULL;
                head -> prev = NULL;
                return head;
            }
              // if head -> next doesnot exist then return null
            else{
                return NULL;
            }
        }

      // run till the xth node
        while(temp != NULL && count <= x-1){
            prev = temp;
            temp = temp -> next;
            count++;
        }
        
        prev -> next = temp -> next;
        if(temp -> next){
            temp -> next -> prev = prev;
            temp -> next = NULL;
        }
        temp -> prev = NULL;
        
        return head;
    }
};
