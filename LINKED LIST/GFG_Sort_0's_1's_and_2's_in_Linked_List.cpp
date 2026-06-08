// Question Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


// METHOD 1: Iteration -> count 0's, 1's and 2's then put them into the Linked List

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt_1 = 0;
        int cnt_2 = 0;
        int cnt_0 = 0;
        
        Node *temp = head;
        
        while(temp != NULL){
            if(temp -> data == 0){
                cnt_0++;
            }
            else if(temp -> data == 1){
                cnt_1++;
            }
            else{
                cnt_2++;
            }
            temp = temp -> next;
        }
        
        temp = head;
        
        while(temp != NULL){
            if(cnt_0 > 0){
                temp -> data = 0;
                cnt_0--;
            }
            else if(cnt_1 > 0){
                temp -> data = 1;
                cnt_1--;
            }
            else if(cnt_2 > 0){
                temp -> data = 2;
                cnt_2--;
            }
            
            temp = temp -> next;
        }
        
        return head;
    }
};

// METHOD 2: In one pass

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *temp = head;
        
        // Dummmy node Heads
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        // Dummy node iterator
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        
        while(temp != NULL){
            Node *nex = temp -> next;
            temp -> next = NULL;
            if(temp -> data == 0){
                zero -> next = temp;
                zero = temp;
            }
            else if(temp -> data == 1){
                one -> next = temp;
                one = temp;
            }
            else if(temp -> data == 2){
                two -> next = temp;
                two = temp;
            }
            temp = nex;
        }
        
        zero -> next = (oneHead -> next) ? oneHead -> next : twoHead -> next;
        one -> next = twoHead -> next;
        
        head = zeroHead -> next;
        
        return head;
    }
};
