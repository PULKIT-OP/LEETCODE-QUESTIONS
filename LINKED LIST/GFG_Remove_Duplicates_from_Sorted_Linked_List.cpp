// Question Link: https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

// METHOD 1: 

class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if(headRef -> next == NULL){
            return headRef;
        }
        Node *curr = headRef;
        Node *nex = NULL;
        
        while(curr != NULL && curr -> next != NULL){
            nex = curr -> next;
            if(curr -> next -> data == curr -> data){
                curr -> next = nex -> next;
                nex -> next = NULL;
                delete(nex);
            }
            else{
                curr = curr -> next;
            }
        }
        
        return headRef;
    }
};
