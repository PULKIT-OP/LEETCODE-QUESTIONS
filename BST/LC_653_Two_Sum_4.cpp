// Question Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/


// METHOD 1: In this method we need to optimize the Time and Space both and this is the most optimized solution so far.
// Here we construct a IteratorBST class which stores inorder and reverse inorder for the given tree 
// Then we iterate on both just like two pointers 
// if left + right == k we got our answer return then and there
// if left + right > k move right pointer towards left
// if left + right < k move left pointer towards right

// To understand this method better you must do LEETCODE 173
// there we worked with Normal Inorder 
// But here one extra thing is there, we are storing Reverse inorder --> so that greatest number will be first 
// example Normal Inorder will look like this -> 1 2 3 4 5 6 7 8 9   : Values will be in Ascending order 
// Reverse Inorder will look like this --------> 9 8 7 6 5 4 3 2 1   : Values will be in Descending order
// Now  we can just iteratte on both simplly 
// AGAIN SAYING BEFORE JUMPING TO THIS PROBLEM YOU MUST SOLVE OR TRY OR UNDERSTAND LEETCODE 173

class IteratorBST{
    stack<TreeNode*> myStack;  // Stack to store nodes
    // before --> true ---> its storing before
    // before -> false --> it stroing next
    bool before = true;  // To store if the Iterator is for Normal inorder or Reverse Inorder. By default its reverse inorder

public:
    IteratorBST(TreeNode* root, bool isBefore){    // While making a Iterator object we will provide these things ---> Root node and if the iterator is for reverse inorder or Normal inorder
        before = isBefore;
        pushAll(root);  // this pushAll function Inserts All the Elements in Stack not entirely at once but gradually 
    }

  // this Method tells us if there exist next element or not 
    bool hasNext(){
        return !myStack.empty(); 
    }

// this Method returns the next element 
    int next(){
        TreeNode* temp = myStack.top();
      // First it takes out the element 
        myStack.pop();
      // Then it checks if its for Normal Inorder or Reverse Inorder And use Accordingly
        if(!before){
            pushAll(temp -> right);
        }
        else{
            pushAll(temp -> left);
        }

      // At last return the value we stored in Starting
        return temp -> val;
    }

private:
// The PushAll Fucntion --> It takes root from where we need to store the values
    void pushAll(TreeNode* root){
        while(root != NULL){
          // first push the value in stack
            myStack.push(root);
          // then check if its Normal Inorder or Reverse Inorder
          // if its normal inorder --> then we have already pushed the values till the left most values previously and we were at left most node and there we called pushAll to insert right part of the leftmost node
          // if its reverse inorder --> then we have already pushed the values till the right most nodes previously and we were at right most node and there we called pushAll to insert left part of the rightmost node
          // Stilll didnot understand Do a dry run and try to solve LEETCODE 173 you will understand how these things works
            if(before){
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
      // if root is null then nothing to check return false
        if(!root){
            return false;
        }
        IteratorBST l(root, false);  // Make left Iterator --> Normal Inorder
        IteratorBST r(root, true);   // Make right Iterator --> Reverse Inorder

        int i = l.next();  // Pointer for left
        int j = r.next();  // Pointer for right

      // Now normal two pointer
        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }
            else if(i + j > k){
                j = r.next();
            }
        }

        return false;
    }
};
