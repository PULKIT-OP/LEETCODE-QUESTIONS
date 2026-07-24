// Question Link: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1


// METHOD 1: Using Array:

class myStack {
  public:
    int *st;  // making pointer to store array
    int top;
    int size;
    myStack(int n) {
        // Define Data Structures
        st = new int[n];  // making new array of size n
        top = -1;  // to store the top index
        size = n;  // to store the size of array
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top == -1){
            return true;
        }
        
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top == size - 1){
            return true;
        }
        
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top == size - 1){
            return;
        }
        
        st[top+1] = x;
        top++;
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(top == -1){
            return;
        }
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top == -1){
            return -1;
        }
        
        return st[top];
    }
};
