// Question Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// METHOD 1: 

class Solution {
public:
    TreeNode* build(vector<int> &preorder, int &pre_idx, int in_st, int in_end, unordered_map<int, int> &mp){
        if(pre_idx >= preorder.size() || in_st > in_end){
            return NULL;
        }
        int root_val = preorder[pre_idx];
        TreeNode *root = new TreeNode(root_val);
        int root_idx = mp[root_val];

        pre_idx++;
        
        root -> left = build(preorder, pre_idx, in_st, root_idx-1, mp);
        root -> right = build(preorder, pre_idx, root_idx+1, in_end, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp; // -> index -> node

        for(int i = 0; i < preorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int pre_idx = 0;
        int root_val = preorder[pre_idx++];
        int root_idx = mp[root_val];
        TreeNode* root = new TreeNode(root_val);

        root -> left = build(preorder, pre_idx, 0, root_idx-1, mp); // preorder, inordr, pre_idx, in_st, in_end, mp
        root -> right = build(preorder, pre_idx, root_idx+1, inorder.size()-1, mp); 

        return root;
    }
};

// METHOD 2: Takes no extra space 

class Solution {
public:
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int &pre_idx, int in_st, int in_end){
        if(pre_idx >= preorder.size() || in_st > in_end){
            return NULL;
        }

        int root_val = preorder[pre_idx];
        int i = in_st;
        for(; i < in_end; i++){
            if(inorder[i] == root_val){
                break;
            }
        }

        pre_idx++;

        TreeNode *root = new TreeNode(root_val);
        root -> left = build(preorder, inorder, pre_idx, in_st, i-1);
        root -> right = build(preorder, inorder, pre_idx, i+1, in_end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int pre_idx = 0;

        return build(preorder, inorder, pre_idx, 0, n-1); // preorder, inorder, pre_idx, start, end
    }
};
