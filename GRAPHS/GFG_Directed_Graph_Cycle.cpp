// Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// we will be solving it using two methods DFS and BFS, both methods are almost same one uses dfs algo and other uses bfs algo nothing much.
// METHOD 1: USING DFS
class Solution {
  public:
  
    bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &v : adj[u]){
          // agar koi banda visited nahi hai to uspr dfs marke dekho, agar true aya to cycle hoga Ovsly
            if(!visited[v] && isCycleDFS(v, adj, visited, inRecursion)){
                return true;
            }
          // or agar visited hai to dfs marne ki zarurt kyu hai bas ye dekh lo ki inRecursion me hai ya nahi, agar hai to cycle hai 
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


// METHOD 3: USING BFS (KAHN's ALGORITHM)

class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
      vector<vector<int>> adj(V);
    	for(auto &vec : edges){
    		int u = vec[0];
    		int v = vec[1];
    
    		adj[u].push_back(v);
    	}
    	
    	queue<int> que;
    	vector<int> indeg(V, 0);
    	int count = 0;
    
    	for(auto &v : adj){
    	    for(int i = 0; i < v.size(); i++){
    	        indeg[v[i]]++;
    	    }
    	}
    	
    	for(int i = 0; i < V; i++){
    	    if(indeg[i] == 0){
    	        que.push(i);
    	    }
    	}
    	
    	while(!que.empty()){
    	    int node = que.front();
    	    que.pop();
    	    count++;    // Instead of adding topological order we will just count how many nodes are in ans.
    	    
    	    for(auto &v : adj[node]){
    	        indeg[v]--;
    	        
    	        if(indeg[v] == 0){
    	            que.push(v);
    	        }
    	    }
    	}

      // if the number of nodes in topological order == Number of vertices(V) means topological order worked and this is acyclic graph because topological sort will work ONLY on acyclic graph
    	if(count != V){
    	    return true;
    	}
    	
    	return false;
    }
};
