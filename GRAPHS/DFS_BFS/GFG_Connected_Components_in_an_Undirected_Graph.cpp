// Question Link: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

// METHDO 1: USING DFS

class Solution {
  public:
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result){
        if(visited[u]){
            return;
        }
        visited[u] = true;
        result.push_back(u);
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(v, adj, visited, result);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
      // Making adjacency list out of edges
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);  // to mark visited
        vector<vector<int>> result;  // to store final result
        
        for(int i = 0; i < V; i++){
          // if node is not visited then call DFS
            if(!visited[i]){
                vector<int> component;  // temp vector to store component and then pushing it to main result
                DFS(i, adj, visited, component);
                result.push_back(component);
            }
        }
        return result;
    }
};

// METHOD 2: USING BFS

class Solution {
  public:
    void BFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result){
        visited[u] = true;
        
        queue<int> que;
        que.push(u);
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            result.push_back(node);
            
            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        vector<vector<int>> result;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                vector<int> component;
                BFS(i, adj, visited, component);
                result.push_back(component);
            }
        }
        return result;
    }
};
