// Question Link: https://leetcode.com/problems/binary-search-tree-iterator/description/


// METHOD 1: Recursive Method ---> Using Stack to Store nodes

class BSTIterator {
public:
    stack<TreeNode*> st;
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        st.push(root);
        if(root -> left){
            solve(root -> left);
        }
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode* ans = st.top();
        st.pop();
        solve(ans -> right);
        return ans -> val;
    }
    
    bool hasNext() {
        return (st.empty()) ? false : true;
    }
};


// METHDO 2: Iterative Method to Reduce the Recustive call Stack Space

class BSTIterator {
public:
    stack<TreeNode*> st;
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        while(root){
            st.push(root);
            root = root -> left;
        }
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode* ans = st.top();
        st.pop();
        solve(ans -> right);
        return ans -> val;
    }
    
    bool hasNext() {
        return (st.empty()) ? false : true;
    }
};
