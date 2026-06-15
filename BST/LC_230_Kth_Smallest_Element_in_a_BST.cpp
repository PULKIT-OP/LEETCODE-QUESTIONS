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


// FOLLOW UP METHOD
// Altering the structure of BST for the solution 
class Solution {
public:

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        int lCount; // count of nodes in left subtree

        TreeNode(int x){
            val = x;
            left = right = NULL;
            lCount = 0;
        }
    };

    // maintain lCount while inserting nodes. Similar thiing needs to be done while deleting the nodes
    TreeNode* insert(TreeNode* root, int x){
        if(root == NULL){
            return new TreeNode(x);
        }
        // if node is inserted in its left subtree then increment lCount of this node
        if(x < root -> val){
            root -> left = insert(root -> left, x);
            root -> lCount++;
        }
        else if(x > root -> val){
            root -> right = insert(root -> right, x);
        }

        return root;
    }

    // TreeNode* delet(TreeNode* root, int x){

    // }

    TreeNode* solve(TreeNode* root, int &k){
        if(root == NULL){
            return NULL;
        }
        int count = root -> lCount+1;
        if(count == k){
            return root;
        }
        if(count > k){
            return solve(root -> left, k);
        }
        return solve(root -> right, k-count);
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k) -> val;
    }
};
