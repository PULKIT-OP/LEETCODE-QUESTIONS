// Question Link: https://leetcode.com/problems/binary-tree-right-side-view/description/


// METHOD 1: Non Recursive Method --> Using map --> not optimized -> takes space

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        map<int, int> mp;
        queue<pair<int, TreeNode*>> q; // level -> node
        q.push({0, root});

        while (!q.empty()) {
            pair<int, TreeNode*> temp = q.front();
            q.pop();
            int lvl = temp.first;
            root = temp.second;
            if (mp.find(lvl) == mp.end())
                mp[lvl] = root->val;
            if (root->right) {
                q.push({lvl + 1, root->right});
            }
            if (root->left) {
                q.push({lvl + 1, root->left});
            }
        }
        for (auto& i : mp) {
            result.push_back(i.second);
        }

        return result;
    }
};


// METHOD 2: Same approach or logic as above just without using map -> reducing extra space

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; i++) {
                root = q.front();
                q.pop();

                if(i == n - 1) {
                    result.push_back(root->val);
                }

                if(root->left){
                    q.push(root->left);
                } 
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return result;
    }
};


// METHOD 3: Recursive Method --> using maps  --> Uses extra space 

class Solution {
public:
    void solve(TreeNode *root, int level, map<int, int> &mp){
        if(root == NULL){
            return;
        }
        mp[level] = root -> val;
        if(root -> left){
            solve(root -> left, level+1, mp);
        }
        if(root -> right){
            solve(root -> right, level+1, mp);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;
        solve(root, 0, mp);

        vector<int> result;
        for(auto &i : mp){
            result.push_back(i.second);
        }

        return result;
    }
};


// METHOD 4: Recursive Method ---> Optimized version of previous recurive solution --> No extra space

class Solution {
public:
    void solve(TreeNode *root, int level, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(level == result.size()){
            result.push_back(root -> val);
        }
        if(root -> right){
            solve(root -> right, level+1, result);
        }
        if(root -> left){
            solve(root -> left, level+1, result);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        solve(root, 0, result);

        return result;
    }
};
