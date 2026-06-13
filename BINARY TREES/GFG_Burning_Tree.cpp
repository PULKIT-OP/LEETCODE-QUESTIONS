// Question Link: https://www.geeksforgeeks.org/problems/burning-tree/1

// METHOD 1: In this question value of target was given not the node pointer so we need to find the pointer of target because with value we cannot travel left and right in tree.

class Solution {
  public:
    Node* tar = NULL;  // to store target pointer
    void fillParent(Node* root, unordered_map<Node*, Node*> &parent, int target){
        if(root == NULL){
            return;
        }
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                root = q.front();
                if(root -> data == target){
                    tar = root;
                }
                q.pop();
                if(root -> left){
                    parent[root -> left] = root;
                    q.push(root -> left);
                }
                if(root -> right){
                    parent[root -> right] = root;
                    q.push(root -> right);
                }
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;
        unordered_map<Node*, bool> visited;
        
        fillParent(root, parent, target);
        
        queue<pair<Node*, int>> q;
        q.push({tar, 0});
        
        int maxi = INT_MIN;  // To store maximum time taken for burning the tree

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<Node*, int> temp = q.front();
                root = temp.first;
                int t = temp.second;
                maxi = max(maxi, t);
                
                visited[root] = true;
                q.pop();

                if(root -> left && !visited[root -> left]){
                    q.push({root -> left, t+1});
                }
                if(root -> right && !visited[root -> right]){
                    q.push({root -> right, t+1});
                }
                if(parent[root] && !visited[parent[root]]){
                    q.push({parent[root], t+1});
                }
            }
        }

        return maxi;
    }
};
