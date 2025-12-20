// Question Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    void BFS(int n, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans){
        if(visited[n] == true){
            return;
        }
        visited[n] = true;
        
        queue<int> que;
        que.push(n);
        ans.push_back(n);
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            
            for(auto &it : adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    que.push(it);
                    ans.push_back(it);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        for(int i = 0; i < adj.size(); i++){      // Instead of it if you use just initialize this "BFS(i, adj, visited, ans)" with i = 0 it will work perfectly.
            if(!visited[i]){
                BFS(i, adj, visited, ans);
            }
        }
        
        return ans;
    }
};
