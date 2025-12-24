// Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// we will be solving it using two methods DFS and BFS, both methods are almost same one uses dfs algo and other uses bfs algo nothing much.
// METHOD 1: USING DFS
class Solution {
  public:
  
    bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v] && isCycleDFS(v, adj, visited, inRecursion)){
                return true;
            }
            else if(visited[v] == true && inRecursion[v] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // Making adj list from edges
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);        // Beacause its a directed graph
        }
        
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleDFS(i, adj, visited, inRecursion)){
                return true;
            }
        }
        return false;
    }
};

// METHOD 2: USING BFS

class Solution {
  public:
  
    bool isCycleBFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        queue<int> que;
        que.push(u);
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            
            for(auto &v : adj[node]){
                if(!visited[v] && isCycleBFS(v, adj, visited, inRecursion)){
                    return true;
                }
                if(visited[v] && inRecursion[v]){
                    return true;
                }
            }
        }
        
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
      vector<vector<int>> adj(V);
    	for(auto &vec : edges){
    		int u = vec[0];
    		int v = vec[1];
    
    		adj[u].push_back(v);
    	}
    	
    	vector<bool> visited(V, false);
    	vector<bool> inRecursion(V, false);
    
    	for(int i = 0; i < V; i++){
    		if(!visited[i] && isCycleBFS(i, adj, visited, inRecursion)){
    			return true;
    		}
    	}
    	return false;
    }
};
