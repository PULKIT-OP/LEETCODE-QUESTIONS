// Question Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// METHOD 1: Using BFS

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
      // Adj List
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      // Storing path to all the nodes as -1 bcoz we havnt visited them yet
        vector<int> result(V, -1);
        result[src] = 0;  // reaching to source is 0 cuz we are on source in starting
        queue<int> q;
        q.push(src);
        // start BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // if the neightbour is not visited yet so just visit it and update its path lenght in result and push in q
            for(auto &it : adj[node]){
                if(result[it] == -1){
                    q.push(it);
                    result[it] = result[node] + 1;
                }
                  // otherwise if you have already visited it then check if current path lenght you are getting is lower than the already stored path length if yes then update it and push in que otherise leave it
                else{
                    if(result[node] + 1 < result[it]){
                        result[it] = result[node] + 1;
                        q.push(it);
                    }
                }
            }
        }
        
        return result;
    }
};
