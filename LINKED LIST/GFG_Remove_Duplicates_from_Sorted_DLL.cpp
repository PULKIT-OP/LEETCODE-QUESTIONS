// Question Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

// METHOD 1: 

class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if(headRef -> next == NULL){
            return headRef;
        }
        Node *curr = headRef;
        Node *prev = NULL;
        Node *nex = NULL;
        
        while(curr != NULL && curr -> next != NULL){
            nex = curr -> next;
            if(curr -> next -> data == curr -> data){
                curr -> next = nex -> next;
                if(nex -> next != NULL){
                    nex -> next -> prev = curr;
                    nex -> next = NULL;
                }
                nex -> prev = NULL;
                delete(nex);
            }
            else{
                curr = curr -> next;
            }
        }
        
        return headRef;
    }
};
