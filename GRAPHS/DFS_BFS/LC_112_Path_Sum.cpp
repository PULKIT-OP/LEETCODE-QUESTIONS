// Question Link: https://leetcode.com/problems/path-sum/description/

// MEHTOD 1: RECURSIVE Solution

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      // check if root exist if No then empty tree return false
        if(root == NULL){
            return false;
        }

      // Subtract current node value from targetSum 
        targetSum = targetSum - root -> val;

      // If you reached Leaf Node and TargetSum is 0 means you got your path reutrn true otherwise return false
        if(root -> left == NULL && root -> right == NULL){
            return targetSum == 0;
        }

      // if not at leaft node then recursively got to left and right subtree and check if you get any path
        return hasPathSum(root -> left, targetSum) || hasPathSum(root -> right, targetSum);
    }
};

// METHOD 2: Iterative DFS

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, root -> val});
        
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int val = st.top().second;
            st.pop();

            if(!node -> left && !node -> right && val == targetSum){
                return true;
            }
            if(node -> right){
                st.push({node -> right, val + node -> right -> val});
            }
            if(node -> left){
                st.push({node -> left, val + node -> left -> val});
            }
        }

        return false;
    }
};
