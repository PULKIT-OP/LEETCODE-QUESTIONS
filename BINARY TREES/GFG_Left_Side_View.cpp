// Question Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


// METHOD 1: Non Recursive Method --> Using map --> not optimized -> takes space

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        map<int, int> mp;
        queue<pair<int, Node*>> q; // level -> node
        q.push({0, root});

        while (!q.empty()) {
            pair<int, Node*> temp = q.front();
            q.pop();
            int lvl = temp.first;
            root = temp.second;
            if (mp.find(lvl) == mp.end())
                mp[lvl] = root->data;
            if (root->left) {
                q.push({lvl + 1, root->left});
            }
            if (root->right) {
                q.push({lvl + 1, root->right});
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
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        queue<Node*> q; // level -> node
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                
                if(i == size - 1) {
                    result.push_back(root->data);
                }

                if(root->right){
                    q.push(root->right);
                }
                if(root->left){
                    q.push(root->left);
                } 
            }
        }
        return result;
    }
};

// METHOD 3: Recursive Method --> using maps  --> Uses extra space 

class Solution {
  public:
    void solve(Node *root, int level, map<int, int> &mp){
        if(root == NULL){
            return;
        }
        
        mp[level] = root -> data;
        
        if(root -> right){
            solve(root -> right, level+1, mp);
        }
        if(root -> left){
            solve(root -> left, level+1, mp);
        }
    }
    vector<int> leftView(Node *root) {
        // code here
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
    void solve(Node *root, int level, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(level == result.size()){
            result.push_back(root -> data);
        }
        if(root -> left){
            solve(root -> left, level+1, result);
        }
        if(root -> right){
            solve(root -> right, level+1, result);
        }
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        solve(root, 0, result);

        return result;
        
    }
};
