// Question Link: https://leetcode.com/problems/diameter-of-binary-tree/


// METHOD 1: 

class Solution {
public:
    int solve(TreeNode *root, int &maxi){
        if(root == NULL){
            return 0;
        }

        int left = solve(root -> left, maxi);
        int right = solve(root -> right, maxi);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int ans = solve(root, maxi);
        return maxi;
    }
};
