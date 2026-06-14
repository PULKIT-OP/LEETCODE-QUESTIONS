// Question Link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1


// METHOD 1: 

class Solution {
  public:
    int minValue(Node* root) {
        // If root is NULL then return NULL
        if(root == NULL){
            return NULL;
        }
      // If root -> left doesnot exist then it means you have reached to left most node of the tree and in BST it will be the node with SMALLEST VALUE, return its value
        if(root -> left == NULL){
            return root -> data;
        }
        return minValue(root -> left); // otherise continue to go to left node 
    }
};
