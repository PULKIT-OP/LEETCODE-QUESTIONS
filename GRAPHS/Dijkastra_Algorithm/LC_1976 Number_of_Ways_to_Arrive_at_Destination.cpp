// Question Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// METHOD 1: Using DIJKSTRA's ALGORITHM
// DIJKSTRA's Logic remain same, just a minor change for this particular problem
// total distance to reach current node will be equal to total number of ways to reach parent of current node ---> if this node is visited first time
// If you already have minimum distance to reach current node then ---> ways to reach currewnt node ---> total number of ways to reach current node(which you have already found previously) + total number of ways to reach parent
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;       //cost, node
        vector<long long> minDist(n, LLONG_MAX);
      // Vector to store number of ways to reach each node with minimum distance
        vector<int> ways(n, 0);
        minDist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : roads){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        while(!pq.empty()){
            int node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if(d > minDist[node]){
                continue;
            }
            
            for(auto &vec : adj[node]) {
                long long dist = vec.first;
                int neigh = vec.second;

                // shorter path found
                if (dist + d < minDist[neigh]) {
                    minDist[neigh] = dist + d;
                  // if you found the shortest path then update ways to reach current node which will be equal to total ways to reach parent node
                    ways[neigh] = ways[node];
                    pq.push({dist + d, neigh});
                }
                // if you found another way to reach current node which is shortest then update it with addition of ways to reach parent node
                else if (dist + d == minDist[neigh]) {
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
