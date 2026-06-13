// Question Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// METHOD 1: This is a Tree --> Convert it into graph --> make a map which stores parent of each node --> this way its converted into graph --> now do simple BFS and you will get your answer

class Solution {
public:
  // Filling out the parent MAP with BFS
    void fillParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                root = q.front();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;  // To store parent of each node
        unordered_map<TreeNode*, bool> visited;  // To track if the node is visited or not

        fillParent(root, parent);  // filling parent MAP

        vector<int> result;  // to store answer
      
      // Now normal BFS traversal
        queue<pair<TreeNode*, int>> q;  
        q.push({target, 0});

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<TreeNode*, int> temp = q.front();
                root = temp.first;
                int len = temp.second;
                if(len == k){
                    result.push_back(root -> val);
                }
                visited[root] = true;
                q.pop();

                if(root -> left && !visited[root -> left]){
                    q.push({root -> left, len+1});
                }
                if(root -> right && !visited[root -> right]){
                    q.push({root -> right, len+1});
                }
                if(parent[root] && !visited[parent[root]]){
                    q.push({parent[root], len+1});
                }
            }
        }

        return result;
    }
};
