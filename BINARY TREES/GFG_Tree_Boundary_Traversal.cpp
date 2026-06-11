// Question Link:
// GFG ---> https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// LEETCODE (PREMIMUM) ---> https://leetcode.com/problems/boundary-of-binary-tree/description/

// METHOD 1: Noob approach 

class Solution {
  public:
// traversing left boundary
    void leftBoundary(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        result.push_back(root -> data);
        if(root -> left){
            leftBoundary(root -> left, result);
        }
        else if(root -> right){
            leftBoundary(root -> right, result);
        }
    }
// traversing leaf nodes
    void leaf(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            result.push_back(root -> data);
        }
        leaf(root -> left, result);
        leaf(root -> right, result);
    }
// traversing right boundary
    void rightBoundary(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        result.push_back(root -> data);
        if(root -> right){
            rightBoundary(root -> right, result);
        }
        else if(root -> left){
            rightBoundary(root -> left, result);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        result.push_back(root -> data);
        leftBoundary(root -> left, result);
        leaf(root -> left, result);
        leaf(root -> right, result);
        vector<int> temp;  // taking a temp vector to store right boundary
        rightBoundary(root -> right, temp);
        // now pushing temp values in reverse order into result vector 
        for(int i = temp.size()-1; i >= 0; i--){
            result.push_back(temp[i]);
        }
        
        return result;
    }
};


// METHOD 2: Pro Approach ---> not using extra temp vector

class Solution {
  public:
// traversing left boundary
    void leftBoundary(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        result.push_back(root -> data);
        if(root -> left){
            leftBoundary(root -> left, result);
        }
        else if(root -> right){
            leftBoundary(root -> right, result);
        }
    }
// traversing leaf nodes
    void leaf(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            result.push_back(root -> data);
        }
        leaf(root -> left, result);
        leaf(root -> right, result);
    }
// traversing right boundary
    void rightBoundary(Node *root, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        if(root -> right){
            rightBoundary(root -> right, result);
        }
        else if(root -> left){
            rightBoundary(root -> left, result);
        }
        result.push_back(root -> data);  // Just push right boundary at last of each iteration --> this way last entry will get included first 
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        result.push_back(root -> data);
        leftBoundary(root -> left, result);
        leaf(root -> left, result);
        leaf(root -> right, result);
        rightBoundary(root -> right, result);
        
        return result;
    }
};
