// Question Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// METHOD 1:  Using Level Order Traversal Method --> non recursive

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
        }

        return level;
    }
};

// METHOD 2: Recursive Method

class Solution {
public:
    int solve(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root -> left);  // Find out the height of left sub tree
        int right = solve(root -> right);  // Find out the height of right sub tree

        return 1 + max(left, right);  // then return 1 + maximum of both sub tree
    }
    int maxDepth(TreeNode* root) {

        return solve(root);
    }
};
