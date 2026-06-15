// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// METHOD 1: Using a Mainn feature of BST ---> With Inorder Traversal it gives sorted order of nodes 

class Solution {
public:
  // Doing inorder traversal and storing values in result vector
    void solve(TreeNode* root, vector<int> &result){
        if(root == NULL){
            return;
        }
        solve(root -> left, result);
        result.push_back(root -> val);
        solve(root -> right, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        solve(root, result);

      // then return the required index
        return result[k-1];
    }
};

// METHOD 2: NO extra space ---> just recursive call stack

class Solution {
public:
    int solve(TreeNode* root, int &k){
        if(root == NULL){
            return -1;
        }
        int left = solve(root -> left, k);
        if(left != -1){
            return left;
        }
        k--;
        if(k == 0){
            return root -> val;
        }
        
        return solve(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};


// FOLLOW UP WILL BE UPDATED SOON
