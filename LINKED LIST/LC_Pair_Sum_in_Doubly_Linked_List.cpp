// Question Link: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// METHOD 1: 

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node *temp = head;
        Node *tail = NULL;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        tail = temp;
        temp = head;
        
        vector<pair<int, int>> v;
        
        while(temp -> data < tail -> data){
            if(temp -> data + tail -> data > target){
                tail = tail -> prev;
            }
            else if(temp -> data + tail -> data < target){
                temp = temp -> next;
            }
            else{
                v.push_back({temp -> data, tail -> data});
                temp = temp -> next;
                tail = tail -> prev;
            }
        }
        
        return v;
    }
};
