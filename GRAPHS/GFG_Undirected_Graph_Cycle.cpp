// Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// METHOD 1: USING DFS

class Solution {
    bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent){
        visited[u] = true;

        for(auto &v : adj[u]){
            // if the node is equals to parent then leave this iteration jump to next iteration
            if(v == parent){
                continue;
            }
          // if alredy visited and not the parent node then this is the answer cycle is present 
            if(visited[v]){
                return true;
            }
          // if not visited then check if cycle is present or not
            if(isCycleDFS(v, adj, visited, u)){
                return true;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);    // making adj list
        vector<bool> visited(V, false);

      // populating adj list
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

      //
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleDFS(i, adj, visited, -1)){
                return true;
            }
        }
        return false;
    }
};


// METHOD 2: USING BFS ----> Doing the same thing just using the typical BFS algorithm.

class Solution {
    bool isCycleBFS(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent){
        visited[u] = true;
        
        queue<int> que;
        que.push(u);
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            
            for(auto &v : adj[node]){
                if(v == parent){
                    continue;
                }
                if(visited[v]){
                    return true;
                }
                if(isCycleBFS(v, adj, visited, node)){
                    return true;
                }
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleBFS(i, adj, visited, -1)){
                return true;
            }
        }
        return false;
    }
};


// METHOD 3: USING BFS ---> Iterative 

class Solution {
  public:
    bool detectBFS(vector<vector<int>> &adj, vector<bool> &visited, int u){
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto &it : adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it, node});
                }
                else if(it != parent && visited[it]){
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            int x = e[0];
            int y = e[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && detectBFS(adj, visited, i)){
                return true;
            }
        }
        
        return false;
    }
};
