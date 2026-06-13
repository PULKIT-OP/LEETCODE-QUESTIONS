// Question Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1


// METHOD 1: 

class Solution {
  public:
    bool solve(Node *root){
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
            return true;
        }
        
        int l = 0;
        int r = 0;
        
        if(root -> left){
            l = root -> left -> data;
        }
        if(root -> right){
            r = root -> right -> data;
        }
        
        if(l + r != root -> data){
            return false;
        }
        
        bool lft = solve(root -> left);
        bool rt = solve(root -> right);
        
        return lft&&rt;
    }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
        
    }
};
