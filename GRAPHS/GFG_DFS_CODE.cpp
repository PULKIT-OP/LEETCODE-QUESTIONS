// Question Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
    void DFS(int n, vector<vector<int>>& adj, vector<bool> &visited, vector<int> &ans){
        if(visited[n] == true){
            return;
        }
        visited[n] = true;
        ans.push_back(n);
        
        for(auto &v : adj[n]){
            if(!visited[v]){
                DFS(v, adj, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        
        for(int i = 0; i < adj.size(); i++){      // If you want then you can just use "DFS(i, adj, visited, ans)" with i = 0 without any loop this will work perfectly fine.
            if(!visited[i]){
                DFS(i, adj, visited, ans);
            }
        }
        return ans;
    }
};
