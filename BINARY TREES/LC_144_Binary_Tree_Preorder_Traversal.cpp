// Question Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

// METHOD 1: Recursion Method

class Solution {
public:
    vector<int> pre;
    void PreOrder(TreeNode *root){
        if(root == NULL){
            return;
        }

        pre.push_back(root -> val);
        PreOrder(root -> left);
        PreOrder(root -> right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        PreOrder(root);

        return pre;
    }
};
