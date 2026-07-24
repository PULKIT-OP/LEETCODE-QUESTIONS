// Question Link: https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

// METHOD 1: 

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node *back;
    Node *front;
    int sizeQ;
  public:
    myQueue() {
        // Initialize your data members
        back = NULL;
        front = NULL;
        sizeQ = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(sizeQ == 0){
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *node = new Node(x);
        if(sizeQ == 0){
            front = node;
            back = node;
        }
        else{
            back -> next = node;
            back = node;
        }
        sizeQ++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(sizeQ == 0){
            return;
        }
        Node *temp = front;
        front = front -> next;
        temp -> next = NULL;
        delete(temp);
        sizeQ--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(sizeQ == 0){
            return -1;
        }
        return front -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return sizeQ;
    }
};
