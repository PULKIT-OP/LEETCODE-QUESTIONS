// Question Link: https://leetcode.com/problems/min-stack/description/

// METHOD 1: 

class MinStack {
public:
    stack<int> q;
    stack<int> minq;
    MinStack() {
    }
    
    void push(int value) {
        q.push(value);
        if(minq.empty()){
            minq.push(value);
        }
        else{
            minq.push(min(minq.top(), value));
        }
    }
    
    void pop() {
        q.pop();
        minq.pop();
    }
    
    int top() {
        return q.top();
    }

    int getMin() {
        return minq.top();
    }
};
