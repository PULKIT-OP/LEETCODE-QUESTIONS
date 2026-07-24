// Question Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

// METHOD 1: 

class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    int size = 0;
    MyQueue() {
        
    }
    
    void pushHelp(int x){
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }
    void push(int x) {
        if(st.empty()){
            st.push(x);
        }
        else{
            pushHelp(x);
        }
    }
    
    int pop() {
        int topi = st.top();
        st.pop();
        return topi;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

// METHOD 2: Optimized --> decreased cost of push operation and increased cost of other operations

class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    int size = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        else{
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        return -1;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(st.empty() && st2.empty()){
            return true;
        }

        return false;
    }
};

