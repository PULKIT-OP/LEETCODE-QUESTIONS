// Question Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

// METHOD 1: Deleting NODE and prioritizing left part

class Solution {
public:
    TreeNode* solve(TreeNode* root){
      // if left doesnot exist then return right pointer which will be attached 
        if(root -> left == NULL){
            return root -> right;
        }
      // if left exist then 
      // Store root -> right in pointer r
        TreeNode* r = root -> right;
        root -> right = NULL;  // then mark root -> right NULL because root is our target node and we need to free it
        TreeNode* temp = root;  // making temp pointer to traverse in root
        temp = temp -> left;  // increment it once because we need to traverse it to its left now

      // traverse to left sub tree of root tilll its right most node
        while(temp -> right != NULL){
            temp = temp -> right;
        }
      // now attach right sub tree of root to its right most node of left subtree
        temp -> right = r;

        return root -> left; // now root -> right doesnot exit just return root -> left as we need to remove root

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      // if root is NULL then there is nothing to DELETE so return NULL
        if(root == NULL){
            return NULL;
        }

      // If root is equal to key then solve for root and return
        if(root -> val == key){
            return solve(root);
        }
        TreeNode* temp = root;  // Temporary pointer to traverse in BST

        // Finding Node
        while(temp != NULL){
            // if temp -> val is smaller than key AND  its right exist with value equals key
            // then solve for its right and break out from loop and return
            // otherwise move right 
            if(temp -> val < key){
                if(temp -> right != NULL && temp -> right -> val == key){
                    temp -> right = solve(temp -> right);  // what ever comes from solve will get attached to temp -> right
                    break;
                }
                else{
                    temp = temp -> right;
                }
            }
            // if temp -> val is greater than key AND its left exist with value equals key
            // then solve for its left and break out from loop and return
            // otherwise move left
            else if(temp -> val > key){
                if(temp -> left != NULL && temp -> left -> val == key){
                    temp -> left = solve(temp -> left);  // whatever comes from solve will get attached to temp -> left
                    break;
                }
                else{
                    temp = temp -> left;
                }
            }
        }
        return root;  // return root at last
    }
};
