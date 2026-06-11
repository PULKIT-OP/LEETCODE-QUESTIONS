// Question Link: https://leetcode.com/problems/same-tree/description/

// METHOD 1:

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL && q != NULL){
            return false;
        }
        if(p != NULL && q == NULL){
            return false;
        }

      // Check if left sub tree of both trees are same or not 
        bool left = isSameTree(p -> left, q -> left);
        if(left == false){
            return false;
        }
      // check if right sub tree of both the trees are same or not
        bool right = isSameTree(p -> right, q -> right);
        if(right == false){
            return false;
        }
      // Check if root value of both the sub trees are same or not
        bool val = p -> val == q -> val;
        if(val == false){
            return false;
        }

      // at last return true if nothing seems odd
        return true;
    }
};
