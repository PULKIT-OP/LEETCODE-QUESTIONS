// Question Link: https://leetcode.com/problems/count-complete-tree-nodes/description/


// METHOD 1: BRUTE FORCE METHOD --> Not optimal

class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = solve(root -> left);
        int right = solve(root -> right);

        return 1 + left + right;
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};


// METHOD 2: Using the property of COMPLETE BINARY TREE

class Solution {
public:
    int findLeftHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int result = findLeftHeight(root -> left);

        return 1 + result;
    }
    int findRightHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int result = findRightHeight(root -> right);

        return 1 + result;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = findLeftHeight(root);
        int right = findRightHeight(root);

        if(left == right){
            return pow(2, left) - 1;   // the property of complete binary tree.
        }

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
