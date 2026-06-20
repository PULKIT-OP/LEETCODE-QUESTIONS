// Question Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// METHOD 1: Using BFS --> But this method is not Recommneded --> Although it worked(Not because of i did it correctly bcoz of DAG properties)
// It iterated over one node multiple times 

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> result(V, -1);
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int len = e[2];
            
            adj[u].push_back({v, len});
        }
        result[0] = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int len = result[node];
            
            for(auto &e : adj[node]){
                int newL = e.second;
                int newN = e.first;
                if(result[newN] == -1){
                    result[newN] = len + newL;
                    q.push(newN);
                }
                else{
                    if(len + newL < result[newN]){
                        result[newN] = newL + len;
                        q.push(newN);
                    }
                }
            }
        }
        
        return result;
    }
};

// METHOD 2: Using Topological sort Method : Using this method because here in toposort we are going sequentially by the reachability of nodes.
// for example: toposort --> 6 5 3 7 1 2 ---> here we know we can reach to 3 via 6 and 5 only not with node 7 1 2 so there is no chance of recomputation or revisiting of nodes 
// So less time as well
// First Do the topological sort 
// then just relax the edges one by one in topological order
// it iterates over a node only one time

class Solution {
  public:
    void DFS_Topo(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int>&st, int u){
        visited[u] = true;
        
        for(auto &e : adj[u]){
            int node = e.first;
            if(!visited[node]){
                DFS_Topo(adj, visited, st, node);
            }
        }
        
        st.push(u);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int len = e[2];
            
            adj[u].push_back({v, len});
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                DFS_Topo(adj, visited, st, i);
            }
        }
        
        vector<int> result(V, 1e9);
        result[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto &e : adj[node]){
                int v = e.first;
                int len = e.second;
                if(result[node] != 1e9 && result[node] + len < result[v]){
                    result[v] = result[node] + len;
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(result[i] == 1e9){
                result[i] = -1;
            }
        }
        
        return result;
    }
};
