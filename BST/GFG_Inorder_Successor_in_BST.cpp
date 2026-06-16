// Question Link: https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

// METHOD 1: BruteForce Approach ---> NOOB Approach
// Store INRODER of BST and try to find k if found then return k+1th node from vector

class Solution {
  public:
// Storing INORDER Traversal
    void solve(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root -> left){
            solve(root -> left, ans);
        }
        ans.push_back(root -> data);
        if(root -> right){
            solve(root -> right, ans);
        }
    }
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        vector<int> ans;
        solve(root, ans);

      // finding k node in vector before the last element --> because if k is present at last then there is no way k+1th element would be present so im checking till n-1th node
        int i = 0;
        bool found = false;
        while(i < ans.size()-1){
            if(k -> data == ans[i]){
                found = true;
                break;
            }
            i++;
        }
        if(found){
            return ans[i+1];
        }
        
        return -1;
    }
};


// METHOD 2: Doing Inorder Traversal like before --> The moment i found node greater than k that is my answer i store it and return 
// Because in Inorder Traversal Nodes are in sorted order ---> So the moment i found node greater than k thats the very next node so thats my answer return it.

class Solution {
  public:
    void solve(Node* root, Node* k, int &ans){
        if(root == NULL){
            return;
        }
        
        solve(root -> left, k, ans);
        
        if(ans != -1){
            return;
        }
        
        if(root -> data > k -> data){
            ans = root -> data;
            return;
        }

        solve(root -> right, k, ans);
    }
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(k == NULL){
            return -1;
        }
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};


// METHOD 3: Now in this METHOD I am using power of BST
// Most Optimized Solution So far

class Solution {
  public:
    void solve(Node* root, Node* k, int &ans){
        if(root == NULL){  // if root is NULL then return
            return;
        }

      // If root -> data is greater than k -> data, Yes i want that so just store this root and move to left, because you want greater value but then immidiate greater so there may exist something smaller
        if(root -> data > k -> data){
            ans = min(ans, root -> data);
            solve(root -> left, k, ans);
        }

      // If root -> data is smaller than k -> data then move to right cuz you need to find something bigger
      // and also if both are equal you need something bigger so move right
        if(root -> data <= k -> data){
            solve(root -> right, k, ans);
        }
    }
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(k == NULL){
            return -1;
        }
        int ans = INT_MAX;
        solve(root, k, ans);
        
        return (ans == INT_MAX) ? -1 : ans;  // At last return answer accordingly
    }
};


// METHOD 4: If dont want to use recursive call stack space then There is a iterative approcah as well

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(k == NULL || root == NULL){
            return -1;
        }
        int ans = INT_MAX;
        while(root){
            if(root -> data > k -> data){
                ans = min(ans, root -> data);
                root = root -> left;
            }
            else{
                root = root -> right;
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};


// METHOD 5: More optimized approach of iterative method --> If there exist k -> right then its confirm our answer will be in right subtree of k 
// Answer will be left most child of right subtree of k 

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if(k == NULL || root == NULL){
            return -1;
        }
      
      // Checking right subtree of k 
        if(k -> right){
            Node* temp = k -> right;
            while(temp -> left){
                temp = temp -> left;
            }
            
            return temp -> data;
        }
      // now normal method
        int ans = INT_MAX;
        while(root){
            if(root -> data > k -> data){
                ans = root -> data;
                root = root -> left;
            }
            else{
                root = root -> right;
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};
