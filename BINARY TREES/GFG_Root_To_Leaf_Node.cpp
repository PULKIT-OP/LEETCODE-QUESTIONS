// Question Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

// METHOD 1: 

class Solution {
  public:
    void solve(Node *root, vector<vector<int>> &result, vector<int> &temp){
        if(root == NULL){
            return;
        }
        temp.push_back(root -> data);
        
        if(root -> left == NULL && root -> right == NULL){
            result.push_back(temp);
        }
        
        if(root -> left){
            solve(root -> left, result, temp);
        }
        if(root -> right){
            solve(root -> right, result, temp);
        }
        
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        vector<int> temp;
        solve(root, result, temp);
        
        return result;
    }
};
