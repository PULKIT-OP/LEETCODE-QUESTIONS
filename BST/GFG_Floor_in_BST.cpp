// Question Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1


// METHOD 1: 

class Solution {
  public:
    void solve(Node* root, int k, int &maxi){
      // continue till root is not NULL
        while(root){
          // If root -> val == k it means we got the ans just return after storing it 
            if(root -> data == k){
                maxi = k;
                return;
            }
          // if root -> val is greater than k, we need to move left and do not store this value as its greater we need to store smaller
            if(root -> data > k){
                root = root -> left;
            }
            else{
              // and if root -> val is smaller than root -> val then store it and move to right
                maxi = root -> data;
                root = root -> right;
            }
        }
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int maxi = -1;
        solve(root, k, maxi);
        return maxi;
    }
    
};
