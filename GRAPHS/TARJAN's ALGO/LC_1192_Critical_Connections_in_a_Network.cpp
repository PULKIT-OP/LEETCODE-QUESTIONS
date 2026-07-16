// Question Link: https://leetcode.com/problems/critical-connections-in-a-network/description/

// METHOD 1: Using Tarjan's Algo(Modified DFS)


class Solution {
public:
    int timer = 0;
    void DFS(int u, int parent, vector<bool> &visited, vector<vector<int>> &adj, int tin[], int low[], vector<vector<int>> &result){
        visited[u] = true;
        tin[u] = low[u] = timer;
        timer++;

        for(auto &it : adj[u]){
            if(it == parent){
                continue;
            }
            if(!visited[it]){
                DFS(it, u, visited, adj, tin, low, result);
                low[u] = min(low[u], low[it]);
                // node --- it bridge??
                if(low[it] > tin[u]){
                    result.push_back({it, u});
                }
            }
            else{
                low[u] = min(low[it], low[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &e : connections){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int tin[n];
        int low[n];
        vector<vector<int>> result;
        DFS(0, -1, visited, adj, tin, low, result);

        return result;
    }
};
