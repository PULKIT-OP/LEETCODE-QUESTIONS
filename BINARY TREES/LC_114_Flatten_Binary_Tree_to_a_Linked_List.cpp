// Question Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


// METHOD 1: One of the optimized Method. It can be solved using extra datastructure like array or stack but that would consume extra space.
// Atlthough Recursive stack gonna consume auxiliary space as well, LEAVE IT.

class Solution {
public:
    TreeNode* prev = NULL;  // To store the head of previously made linked list. Currently no linked list made so its NULL
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

      // First we need to make Linked List out of right sub tree and then work on left sub tree
        flatten(root -> right);
        flatten(root -> left);

      // if you reached the node then its right should point to previously made linked list 
      // And its left should point to NULL
      // And now new node is added to linked list so its head should get updated as well
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }
};
