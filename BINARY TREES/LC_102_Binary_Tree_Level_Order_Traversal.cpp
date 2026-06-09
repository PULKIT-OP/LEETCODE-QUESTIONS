// Question Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

// METHOD 1: 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode *node = que.front();
                que.pop();
                level.push_back(node -> val);
                if(node -> left){
                    que.push(node -> left);
                }
                if(node -> right){
                    que.push(node -> right);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};
