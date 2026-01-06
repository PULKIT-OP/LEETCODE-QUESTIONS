// Question Link: 

// Although its a tree Question but we can solve this using graph logic as well
// MEHTOD 1: Using BFS 

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int Maxsum = INT_MIN;
        int level = 1;
        int currLevel = 1;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            int sum = 0;
          
            while(size--){
                TreeNode *temp = que.front();
                que.pop();

                sum += temp -> val;
                
                if(temp -> left){
                    que.push(temp-> left);
                }
                if(temp -> right){
                    que.push(temp -> right);
                }
            }

            if(sum > Maxsum){
                Maxsum = sum;
                level = currLevel;
            }
            currLevel++;
        }

        return level;
    }
};



// METHOD 2: Using DFS

class Solution {
public:
    unordered_map<int, int> levelSum;
    void dfs(TreeNode *root, int level){
        if(!root){
            return;
        }
        levelSum[level] += root -> val;

        dfs(root -> left, level + 1);
        dfs(root -> right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        levelSum.clear();
        dfs(root, 1);

        int level = 1;
        int maxSum = INT_MIN;

        for(auto &v : levelSum){
            if(v.second > maxSum){
                maxSum = v.second;
                level = v.first;
            }
            else if(v.second == maxSum){
                level = min(level, v.first);
            }
        }

        return level;
    }
};
