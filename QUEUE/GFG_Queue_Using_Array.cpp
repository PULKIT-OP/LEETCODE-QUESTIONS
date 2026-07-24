// Question Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

// METHOD 1: 

class myQueue {

  public:
    int *que;
    int back;
    int size;
    int front;
    int currSize;
    myQueue(int n) {
        // Define Data Structures
        que = new int[n];
        size = n;
        back = -1;
        front = -1;
        currSize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currSize == 0;
    }

    bool isFull() {
        // check if the queue is full
        return currSize == size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(currSize == size){
            return;
        }
        if(currSize == 0){
            front = 0;
            back = 0;
        }
        else{
            back = (back+1)%size;
        }
        que[back] = x;
        currSize++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(currSize == 0){
            return;
        }
        int ele = que[back];
        if(currSize == 1){
            front = -1;
            back = -1;
        }
        else{
            front = (front + 1)%size;
        }
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(currSize == 0){
            return -1;
        }
        return que[front];
    }

    int getRear() {
        // Return the last element of queue
        if(currSize == 0){
            return -1;
        }
        
        return que[back];
    }
};
