// Question Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// METHOD 1: Using DIJKSTRA's Algorithm
// Exact same DIJKSTRA's Algorithm just some minor changes : Like you just have to add a new 'Parent' vector to store the parents of the visited nodes, then at last you just have to store the paths of nodes visited then reverse it then return it

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> minCost(n+1, INT_MAX);
        minCost[1] = 0;
        pq.push({0, 1});
        
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            for(auto &v : adj[node]){
                int neigh = v.second;
                int c = v.first;
                
                if(c + cost < minCost[neigh]){
                    minCost[neigh] = c + cost;
                    pq.push({c + cost, neigh});
                    
                    parent[neigh] = node;
                }
            }
        }
        
        if(minCost[n] == INT_MAX){
            return {-1};
        }
        
        vector<int> result;
        int node = n;
        while(parent[node] != node){
            result.push_back(node);
            node = parent[node];
        }
        
        result.push_back(1);
        result.push_back(minCost[n]);
        reverse(result.begin(), result.end());
        
        return result;
        
        
    }
};
