// Question Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// METHOD 1: Using hashing  --->  Extra Space

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head -> next == NULL){
            return 0;
        }
        unordered_map<Node*, int> visited;
        Node *temp = head;
        int timer = 1;
        while(temp != NULL){
            if(visited[temp]){
                return timer - visited[temp];
            }
            visited[temp] = timer;
            timer++;
            temp = temp -> next;
        }
        
        return 0;
    }
};


// METHOD 2: Using Slow and fast Pointer

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head -> next == NULL){
            return 0;
        }
        Node *slow = head;
        Node *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                slow = slow -> next;
                int count = 1;
                while(slow != fast){
                    slow = slow -> next;
                    count++;
                }
                
                return count;
            }
        }
        
        return 0;
    }
};
