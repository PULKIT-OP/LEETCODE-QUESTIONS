// Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// METHOD 1: Recursive Method 

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


// METHOD 2: Iterative Method with Stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        if(root == NULL){
            return inOrder;
        }

        TreeNode *node = root;
        stack<TreeNode*> st;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node = st.top();
                st.pop();
                inOrder.push_back(node -> val);
                node = node -> right;
            }
        }

        return inOrder;
    }
};
