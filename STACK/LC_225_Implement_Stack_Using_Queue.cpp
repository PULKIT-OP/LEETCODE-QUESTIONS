// Question Link: https://leetcode.com/problems/implement-stack-using-queues/description/

// METHOD 1: 

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }

    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 1; i <= size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
