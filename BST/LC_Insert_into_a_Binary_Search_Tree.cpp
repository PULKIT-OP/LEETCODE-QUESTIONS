// Question Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/


// METHOD 1: 

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);  // make new node with val
      // if root is NULL return node
        if(root == NULL){
            return node;
        }
        TreeNode *temp = root;  // temp variable to traverse in BST

        while(temp){
          // if temp -> val is smaller then check if right exist and move there
            if(temp -> val < val){
                if(temp -> right){
                    temp = temp -> right;
                }
                else{
                    break;  // otherwise break from the loop we got our end
                }
            }
            if(temp -> val > val){
              // if temp -> val is greater than val then check if left exist and move there 
                if(temp -> left){
                    temp = temp -> left;
                }
                else{
                    break;  // otherwise break from the loop we got our end
                }
            }
        }

      // Now we are at our end of BST just check if current value is greater or smaller than val
      // if its greater than val then attach new node to its left  AND AND AND  if its smaller then attach on its right
        if(temp -> val > val){
            temp -> left = node;
        }
        else{
            temp -> right = node;
        }

        return root;
    }
};


// METHOD 2: RECURSIVE Solution

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      // if root is NULL then return a new node with value = val
        if(root == NULL){
            return new TreeNode(val);
        }

      // otherwise check if root -> val is smaller than value, if yes then call recursion on its right
        if(root -> val < val){
            root -> right = insertIntoBST(root -> right, val);
        }
        else{
          // if root -> val is greater than val than call recursion to its left
            root -> left = insertIntoBST(root -> left, val);
        }

        return root;  // at last return root;
    }
};
