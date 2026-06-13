// Question Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// METHOD 1: Just like LEETCODE 105 (construct Binary tree from inorder and preorder) with a little change

class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &post_idx, int st, int end){
        if(st > end){
            return NULL;
        }
        int root_val = postorder[post_idx];
        int i = st;
        for(; i < end; i++){
            if(inorder[i] == root_val){
                break;
            }
        }

        post_idx--;  // the little change (As in postorder traversal root is at last)

      // in post order traversal iteration is like this ----> LEFT -> RIGHT -> ROOT
      // But here we are traversing from last so it becomes ---> ROOT RIGHT LEFT 
      // thats why lines given below are in the this pattern
      // but in the case of LC 105 we build left before right
        TreeNode* root = new TreeNode(root_val);
        root -> right = build(inorder, postorder, post_idx, i+1, end);  
        root -> left = build(inorder, postorder, post_idx, st, i-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int post_idx = n-1;

        return build(inorder, postorder, post_idx, 0, n-1);
    }
};
