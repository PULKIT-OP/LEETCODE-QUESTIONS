// Question Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

// METHOD 1: Basic Approach --> Traverse through all nodes and Insert it in BST

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val){
        if(root == NULL){
            return new TreeNode(val);  // if root is null Then return NEW NODE
        }
        if(val < root -> val){
            root -> left = solve(root -> left, val);  // If val is smaller than root node then go to left sub tree
        }

        if(val > root -> val){
            root -> right = solve(root -> right, val);  // If val is greater than root node then go to right subtree
        }

        return root;  // At last return root
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);  // creating root node
        for(int i = 1; i < preorder.size(); i++){  // iterating over each element of preorder traveersal and insertting it to tree 
            solve(root, preorder[i]);
        }

        return root;
    }
};


// METHOD 2: Traditional Method to build TREE from PREORDER and INORDER
// In this method from given preorder we will make inorder by sortiing preorder 
// After that we will build normal tree using both
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &pre_idx, int st, int end){
      // if start crosses end --> then return NULL tree completed
        if(st > end){
            return NULL;
        }

        int root_val = preorder[pre_idx];  // storing value of root.

      // Finding root_val in inorder --> inorder gives us the orientation of nodes left and right position
        int i = st;
        for(; i < end; i++){
            if(inorder[i] == root_val){
                break;
            }
        }
        pre_idx++;  // increment pre_idx
        TreeNode* root = new TreeNode(root_val);  // created new node
        root -> left = build(preorder, inorder, pre_idx, st, i-1);  // Now build root -> left, starting from start to left of inorder(i)
        root -> right = build(preorder, inorder, pre_idx, i+1, end);  // Now build root -> right, starting from right of inorder(i) to end

        return root; // Then return root
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> pre = preorder;  // preorder
        sort(preorder.begin(), preorder.end());  //inorder 
        int n = preorder.size();  // storing size of array
        int pre_idx = 0;  // preorder index

        return build(pre, preorder, pre_idx, 0, n-1);  // preorder, inorder, preorder_index, starting(inorder), ending(inorder)
    }
};


// METHOD 3: Most Optimized Solution --> Using Recustion Call stack space

class Solution {
public:
    TreeNode* build(vector<int> &preorder, int &idx, int bound){
      // if idx is out of bound it means we iterated over all the nodes so return NULL
      // if value in preorder vector is out of bound then also return NULL  --> Do a dry run you willl understand why this paritcular condition is here
        if(idx >= preorder.size() || preorder[idx] > bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx]);  // making root node
        idx++;                                         // incrementing idx iterator
        root -> left = build(preorder, idx, root -> val);  // build left sub tree --> its upper bound is root -> val because it is on left side of root so it cant be bigger than root value as per BST RULE
        root -> right = build(preorder, idx, bound);  // build right sub tree --> its upper bound will be bound because its on right part of tree where no limit on bigger numbers

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;  // index to iterate over preorder
        return build(preorder, i, INT_MAX);  // int_max is the upperbound where the values could reach 
    }
};
