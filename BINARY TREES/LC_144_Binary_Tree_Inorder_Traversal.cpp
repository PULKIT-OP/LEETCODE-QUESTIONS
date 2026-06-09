// Question Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

// METHOD 1: Recursion Method

class Solution {
public:
    vector<int> in;
    void Inorder(TreeNode *root){
        if(root == NULL){
            return;
        }

        in.push_back(root -> val);
        Inorder(root -> left);
        Inorder(root -> right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Inorder(root);

        return in;
    }
};
