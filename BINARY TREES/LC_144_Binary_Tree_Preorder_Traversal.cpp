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

// MEHTOD 2: Iterative Method with Stack

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL){
            return preOrder;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();
            preOrder.push_back(root -> val);
            if(root -> right){
                st.push(root -> right);
            }
            if(root -> left){
                st.push(root -> left);
            }
        }
        return preOrder;
    }
};


