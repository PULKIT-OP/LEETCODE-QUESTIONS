// Question Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// METHOD 1: 

class Solution {
public:
    void solve(TreeNode *root, int vertical, int level, map<int, map<int, vector<int>>> &mp){
        if(root == NULL){
            return;
        }
        queue<pair<TreeNode*, pair<int, int>>> q; // ---> Node --> {vertical, level}
        q.push({root, {vertical, level}});

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                root = q.front().first;
                int ver = q.front().second.first;
                int lvl = q.front().second.second;
                q.pop();

                mp[ver][lvl].push_back(root -> val);
                if(root -> right){
                    q.push({root -> right, {ver+1, lvl+1}});
                }
                if(root -> left){
                    q.push({root -> left, {ver-1, lvl+1}});
                }
            }
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;   // vertical -> level -> <vector>

        solve(root, 0, 0, mp);   // root, vertical, level, map
        vector<vector<int>> result;

        for(auto i : mp){
            //i -> pair<vertical, <level, vector>>>
            vector<int> ans;
            for(auto j : i.second){
                // j -> pair<level, vector>
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    // k -> iterate on vector
                    ans.push_back(k);
                }
            }
                result.push_back(ans);
        }

        return result;
    }
};
