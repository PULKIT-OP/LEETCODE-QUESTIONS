// Question Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// METHOD 1: 

class Solution {
public:
    int solve(TreeNode *root, int &maxi){
        if(root == NULL){
            return 0;
        }

        int left = max(0, solve(root -> left, maxi));
        int right = max(0, solve(root -> right, maxi));

        maxi = max(maxi, left + right + root -> val);

        return root -> val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = solve(root, maxi);

        return maxi;
    }
};
