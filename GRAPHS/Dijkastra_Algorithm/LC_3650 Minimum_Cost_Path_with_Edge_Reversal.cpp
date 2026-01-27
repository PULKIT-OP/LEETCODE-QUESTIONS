// Question Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

// METHOD 1: USING DIJKSTRA ALGORITHM    --->  PURE DIJSKTRA ALGO COPY PASTE with little twist

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({w, v});
            adj[v].push_back({2*w, u});  // The little twist 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // w, source

        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            for(auto &v : adj[node]){
                int w_ = v.first;
                int neigh = v.second;

                if(w + w_ < minDist[neigh]){
                    minDist[neigh] = w + w_;
                    pq.push({w+w_, neigh});
                }
            }
        }

      // The little twist
        if(minDist[n-1] == INT_MAX){
            return -1;
        }

        return minDist[n-1];
    }
};
