// Question Link: https://leetcode.com/problems/balanced-binary-tree/description/

// METHOD 1: 

class Solution {
public:
    int solve(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root -> left);
        if(left == -1){
            return -1;
        }
        int right = solve(root -> right);
        if(right == -1){
            return -1;
        }
        if(abs(left - right) == 0 || abs(left - right) == 1){
            return 1 + max(left, right);
        }

        return -1;
    }
    bool isBalanced(TreeNode* root) {
        int ans = solve(root);
        if(ans != -1){
            return true;
        }
        return false;
    }
};
