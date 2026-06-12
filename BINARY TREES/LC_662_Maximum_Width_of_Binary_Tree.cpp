// Question Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// METHOD 1: Normalization is important otherwise overflow 

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxi = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            pair<TreeNode*, long long> f = q.front();
            pair<TreeNode*, long long> b = q.back();
            long long idx_f;
            long long idx_b;
            long long mini = f.second;  // normalization

            for(int i = 0; i < size; i++){
                root = q.front().first;
                long long idx = q.front().second - mini;  // normalization
                q.pop();
              // normalization
                if(i == 0){
                    idx_f = idx;
                }
                if(i == size - 1){
                    idx_b = idx;
                }

                if(root -> left){
                    q.push({root -> left, 2*idx+1});
                }
                if(root -> right){
                    q.push({root -> right, 2*idx+2});
                }
            }
            maxi = max(maxi, idx_b - idx_f + 1);
        }

        return maxi;
    }
};
