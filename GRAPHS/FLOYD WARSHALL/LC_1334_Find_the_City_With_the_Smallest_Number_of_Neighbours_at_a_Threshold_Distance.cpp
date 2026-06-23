// Question Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// METHOD 1: Using Floyd-Warshall Algorithm

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      // Making adj list
        vector<vector<int>> adj(n, vector<int>(n, 1e8));
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;  // cost to reach itself is 0
        }
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u][v] = w;
            adj[v][u] = w;
        }

      // Relaxing the edges
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][via] != 1e8 && adj[via][j] != 1e8 && adj[i][via] + adj[via][j] < adj[i][j]){
                        adj[i][j] = adj[i][via] + adj[via][j];
                    }
                }
            }
        }

      // Finding reachable cities which are under distanceThreshold
        vector<int> cities(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= distanceThreshold){
                    cities[i]++;
                }
            }
        }
        
        pair<int, int> ans;
        ans.first = INT_MAX;
        ans.second = -1;

      // Finding final city with minimum reachable city
        for(int i = 0; i < n; i++){
            if(cities[i] <= ans.first){
                ans.first = cities[i];
                ans.second = max(ans.second, i);
            }
        }

        return ans.second;

    }
};
