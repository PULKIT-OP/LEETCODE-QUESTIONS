// Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/


// METHOD 1: 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> result;  // to store result

        while(curr != NULL){
          // if curr -> left is NULL means left traversal is complete so we can add our ans to result
          // LEFT -> ROOT -> RIGHT
          // after adding value move to right part
            if(curr -> left == NULL){
                result.push_back(curr -> val);
                curr = curr -> right;
            }
              // if left is not NULL then go to right most child of left sub tree
            else{
                TreeNode *leftChild = curr -> left;
                while(leftChild -> right != NULL){
                    leftChild = leftChild -> right;
                }

              // then add a pointer bw rightmost child of left subtree and curr node
              // then move the curr to its left child and break the connection
                leftChild -> right = curr;
                // Now mark left NULL
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL;  // breaking the connection
            }
        }

        return result;
    }
};



// STILL DID NOT UNDERSTAND ?? DO A SIMPLE DRY RUN AS PER THE CODE YOU WILL UNDERSTAND
// STILL DID NOT UNDERSTAND ?? THEN TRY SELLING MANOGES ON ROADS
