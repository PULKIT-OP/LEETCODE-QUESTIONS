// Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// METHOD 1: 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
      
        queue<TreeNode*> q;
        q.push(root);
      
        bool leftToRight = true;  // string what i did, here i pushed root from left to right so i marked it true

      // Now normal level order traversal
        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++) {
              // here we need to find index to store, because its a zig zag traversal so do it accordingly. If earlier you were storing left to right then now you will store from back
                int index = (leftToRight) ? (size - 1 - i) : i;
                root = q.front();
                q.pop();
                ans[index] = root -> val;
                if (root->right) {
                    q.push(root->right);
                }
                if (root->left) {
                    q.push(root->left);
                }
            }
          // then after for loop or current level update your flag and store the answer
            leftToRight = !leftToRight;

            result.push_back(ans);
        }

      // at last return your result
        return result;
    }
};
