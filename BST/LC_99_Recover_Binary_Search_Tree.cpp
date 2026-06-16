// Question Link: https://leetcode.com/problems/recover-binary-search-tree/description/


// METHOD 1: In this method we just traverse in BST --> Inorder Traversal --> which will get me nodes in ascending order

// So i just need to check if the current node is greater than prev node or not 
// Yes yes and we encounter this condition first time then store both teh nodes
// if you encounter this contintion 2nd time so you got the target nodes just swap the values of both nodes 
// if You didnot encounter 2nd time this conditon then swap the inititally found nodes values

class Solution {
public:
    void solve(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &first_nex, TreeNode* &second){
        if(root == NULL){
            return;
        }
        solve(root -> left, prev, first, first_nex, second);
      // If current node value is smallerr than prev node value
        if(prev != NULL && root -> val < prev -> val){
          // And you encounter this condition first time as first is set to NULL
          // Then store prev node to first and curr node to first_nex(next of first)
            if(first == NULL){
                first = prev;
                first_nex = root;
            }
          // And if you encounter this condition 2nd time then just store the node where you get this condition and return from there because atmost you will get this 2 times 
            else{
                second = root;
                return;
            }
        }
        prev = root;  // after each iteration update prev
        solve(root -> right, prev, first, first_nex, second);  // call for right sub tree
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
      // Initializing pointers
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* first_nex = NULL;
        TreeNode* second = NULL;
        solve(root, prev, first, first_nex, second);  // function Call

      // If you didnot found second it means both the nodes are adjacent so just swap first and first_nex
        if(second == NULL){
            swap(first -> val, first_nex -> val);
        }
        // if found second then sawp first and second
        else{
            swap(first -> val, second -> val);
        }
    }
};

// to understand above solution better : Actual Inorder Traversal should be : 1 2 3 4 5 6 7 8 9 
// there are only two possible cases where BST is modified 
// case one if modified nodes are adjacent: 1 2 3 4 6 5 7 8 9  ---> Here 5 and 6 are swapped You will find first and first_nex and never find second in this case
// case two if modified nodes are not adjacent: 1 2 3 4 9 6 7 8 5  ---> Here 5 and 9 have swapped their positions you will find first as 4 and first_nex as 5 and later you will find second and 5
// There is no other case possible 
// At last you will swap accordingly for your solution and return
