// Question Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

// METHOD 1: Recursive METHOD 

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
      // if got the val then return its node
        if(val == root -> val){
            return root;
        }
      // if current nodes value is greater than val then move to left sub tree
        if(root -> val > val){
            return searchBST(root -> left, val);
        }
      // otherwise move to right sub tree
        return searchBST(root -> right, val);
    }
};
