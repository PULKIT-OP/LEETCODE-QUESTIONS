// Question Link: https://leetcode.com/problems/validate-binary-search-tree/description/

// METHOD 1: 

class Solution {
public:
    bool solve(TreeNode* root, long long left_end, long long right_end){
      // if root is NULL then return true bcoz NULL node means left and right are same
        if(root == NULL){
            return true;
        }
      // if root -> val is not in range then return false
        if(root -> val <= left_end || root -> val >= right_end){
            return false;
        }
      // Now check for left and right subTree
        return solve(root -> left, left_end, root -> val) && solve(root -> right, root -> val, right_end);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
