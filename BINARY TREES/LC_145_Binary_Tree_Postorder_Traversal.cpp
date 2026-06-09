// Question Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

// METHOD 1: Using Recursion

class Solution {
public:
    vector<int> post;
    void PostOrder(TreeNode *root){
        if(root == NULL){
            return;
        }

        PostOrder(root -> left);
        PostOrder(root -> right);
        post.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        PostOrder(root);
        return post;
    }
};
