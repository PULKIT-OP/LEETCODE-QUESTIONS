// Question Link: https://leetcode.com/problems/symmetric-tree/

// METHOD 1: Recursive Method 

lass Solution {
public:
    bool solve(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == NULL && tree2 == NULL) {
            return true;
        }
        if (tree1 != NULL && tree2 == NULL) {
            return false;
        }
        if (tree1 == NULL && tree2 != NULL) {
            return false;
        }

        if (tree1->val != tree2->val) {
            return false;
        }

        return solve(tree1->left, tree2->right) &&
               solve(tree1->right, tree2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return solve(root->left, root->right);
    }
};
