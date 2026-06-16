// Question Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1


// METHOD 1: Iterative Approach --> Using properties of BST  --> This method can be optimized more 
// for successor you can check if key's right child exist or not
// For predecessor you can check if key's left child exist or not

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root == NULL){
            return {NULL, NULL};
        }
        
        Node* temp = root;
        Node* ans_s = NULL;
        while(temp){
            if(temp -> data > key){
                ans_s = temp;
                temp = temp -> left;
            }
            else{
                temp = temp -> right;
            }
        }
        
        temp = root;
        Node* ans_p = NULL;
        
        while(temp){
            if(temp -> data >= key){
                temp = temp -> left;
            }
            else if(temp -> data < key){
                ans_p = temp;
                temp = temp -> right;
            }
        }
        
        return {ans_p, ans_s};
    }
};
