// Question Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1


// METHOD 1: Store values in vector --> then add 1 to it at last --> then update whole vector --> update the values of list with vector

class Solution {
  public:
    Node* addOne(Node* head) {
        // code here
        Node *temp = head;
        vector<int> v;
        
        int carry = 1;
        
        while(temp != NULL){
            v.push_back(temp -> data);
            temp = temp -> next;
        }
        
        for(int i = v.size() - 1; i >= 0; i--){
            int val = (v[i] + carry);
            v[i] = val%10;
            carry = val/10;
        }
        
        if(carry != 0){
            Node *node = new Node(carry);
            node -> next = head;
            head = node;
            temp = head -> next;
            int i = 0;
            while(temp != NULL){
                temp -> data = v[i];
                i++;
                temp = temp -> next;
            }
            
            return head;
        }
        else{
            temp = head;
            int i = 0;
            while(temp != NULL){
                temp -> data = v[i];
                i++;
                temp = temp -> next;
            }
            
            return head;
        }
        
        return NULL;
    }
};


// METHOD 2: Using Recursion ---> No extra space

class Solution {
  public:
    int solve(Node *head){
        if(head == NULL){
            return 1;
        }
        
        int carry = solve(head -> next);
        int val = head -> data + carry;
        head -> data = val%10;
        
        return val/10;
    }
    Node* addOne(Node* head) {
        // code here
        int ans = solve(head);
        if(ans > 0){
            Node *node = new Node(ans);
            node -> next = head;
            head = node;
        }
        return head;
    }
};
