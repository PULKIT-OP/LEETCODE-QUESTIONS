// Question Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// METHOD 1: 

class Solution {
  public:
    void solve(Node *root, int x, int &maxi){
      // continue till root is not NULL
        while(root){
          // if found x return maxi then and there
            if(root -> data == x){
                maxi = x;
                return;
            }
          // if root -> val is smaller than x then move to right 
            if(root -> data < x){
                root = root -> right;
            }
              // and if its greater than check if its smaller than previously found value if yes then store it and move to left
            else{
                maxi = min(maxi, root -> data);
                root = root -> left;
            }
        }
    }
    int findCeil(Node* root, int x) {
        // code here
        int maxi = INT_MAX;
        solve(root, x, maxi);
        
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};
