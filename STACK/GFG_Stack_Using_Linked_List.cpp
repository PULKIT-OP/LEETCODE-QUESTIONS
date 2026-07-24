// Question Link:

// METHOD 1: 

class myStack {
  public:
    Node* dummy;
    Node* curr;
    int sizeSt = 0;
    myStack() {
        // Initialize your data members
        dummy = new Node(-1);
        curr = NULL;
        sizeSt = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return curr == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* ele = new Node(x);
        if(curr == NULL){
            ele -> next = dummy;
            curr = ele;
            curr -> next = NULL;
        }
        else{
            ele -> next = curr;
            curr = ele;
        }
        sizeSt++;
    }

    void pop() {
        // Removes the top element of the stack
        Node* temp = curr;
        curr =  curr -> next;
        temp -> next = NULL;
        delete(temp);
        sizeSt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(curr == NULL){
            return -1;
        }
        return curr -> data;
    }

    int size() {
        // Returns the current size of the stack.
        return sizeSt;
    }
};
