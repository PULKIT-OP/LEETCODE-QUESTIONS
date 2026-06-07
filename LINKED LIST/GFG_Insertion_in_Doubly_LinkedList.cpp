// Question Link: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
// Question Link: https://www.naukri.com/code360/problems/insertion-in-doubly-linked-list_4609682?interviewProblemRedirection=true&search=doubly%20linked%20list&leftPanelTabValue=PROBLEM
// TYPE_1: When asked to insert in Doubly LinkedList after pth index given ---> GFG
class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node *node = new Node(x);
        Node *temp = head;
        if(p == 0){
            if(head -> next){
                head -> next -> prev = node;
                node -> next = head -> next;
            }
            node -> prev = head;
            head -> next = node;
            return head;
        }
        
        int count = 0;
        while(temp -> next != NULL && count <= p-1){
                temp = temp -> next;
                count++;
        }
        
        node -> next = temp -> next;
        if(temp -> next){
            temp -> next -> prev = node;
        }
        node -> prev = temp;
        temp -> next = node;
        
        return head;
    }
};


// TYPE_2: When asked to insert in Doubly LinkedList at pth index given   ---->  Code 360
Node* insert(int k, int val, Node *head) {
    // Write Your Code Here.
    Node *node = new Node(val);
    Node *temp = head;
    if(k == 0){
        node -> next = temp;
        temp -> prev = node;
        return node;
    }
    int count = 0;
    while(temp != NULL && count < k-1){
        temp = temp -> next;
        count++;
    }
    node -> next = temp -> next;
    node -> prev = temp;
    if(temp -> next){
        temp -> next -> prev = node;
    }
    temp -> next = node;

    return head;
}
