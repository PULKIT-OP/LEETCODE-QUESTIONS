// Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

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
