// Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// METHOD 1: Same solution that we use for NORMAL TREE --> this will work here as well

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        left = lowestCommonAncestor(root -> left, p, q);
        right = lowestCommonAncestor(root -> right, p, q);

        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        return root;
    }
};

// METHOD 2: Using some powers of BST --> LOOKS LITTLE MESSY  --> BUT WORKS

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* left = NULL;
        TreeNode* right = NULL;

        if(p -> val < root -> val && q -> val < root -> val){
            left = lowestCommonAncestor(root -> left, p, q);
        }
        if(p -> val > root -> val && q -> val > root -> val){
            right = lowestCommonAncestor(root -> right, p, q);
        }
        if(p -> val < root -> val && q -> val > root -> val){
            return root;
        }
        if(q -> val < root -> val && p -> val > root -> val){
            return root;
        }

        if(left == NULL && right != NULL){
            return right;
        }
        if(right == NULL && left != NULL){
            return left;
        }

        return root;
    }
};


// METHOD 3: Clean RECURSIVE CODE --> Idea is Simple --> If both p and q lies on left of root move and iterate in left sub tree 
// If both p and q lies on right part of root then iterate in right sub tree
// If cannot decide which part to traverse then current node is the LCA return that
// Will take recursive call stack
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // If p and q both are less than root then move to left sub tree
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
      // If p and q both are greater than root then move to right sub tree
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
      // Other wise return root
        return root;
    }
};


// METHOD 4: Iterative METHOD --> NO RECURSIVE CALL STACK
// Here Idea is same as well like before 
// You can say MOST OPTIMIZED SOLUTION SO FAR

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Iterate In Tree
        while(root){
          // if p and q both are less thann root then move to left subtree
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }
          // if p and q both are greater than root then move to right sub tree
            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            else{
                return root;  // otherwise return Root
            }
        }

        return NULL;  // its just to complete function. Cant leave the fucntion with no return value --> Tension Not this line will never be executed
    }
};
