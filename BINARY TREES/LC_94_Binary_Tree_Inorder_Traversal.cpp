// Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// METHOD 1: 

class Solution {
public:
    vector<int> in;
    void Inorder(TreeNode *root){
        if(root == NULL){
            return;
        }

        Inorder(root -> left);
        in.push_back(root -> val);
        Inorder(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);

        return in;
    }
};
