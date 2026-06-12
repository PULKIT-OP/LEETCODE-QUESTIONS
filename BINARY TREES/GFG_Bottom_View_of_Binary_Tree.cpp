// Question Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// METHOD 1: Just like top view of binary tree ->> you just need to overwrite the mappping.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> result;
        if(root == NULL){
            return result;
        }
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            pair<int, Node*> temp = q.front();
            q.pop();
            int hor = temp.first;
            root = temp.second;
            
            if(root -> left){
                q.push({hor-1, root -> left});
            }
            mp[hor] = root -> data;  // overwriting the mapping (in top view of binary tree we used to check if that exist or not but here it doesnot matter)
            if(root -> right){
                q.push({hor+1, root -> right});
            }
        }
        
        for(auto &i : mp){
            result.push_back(i.second);
        }
        
        return result;
    }
};
