// Question Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


// METHOD 1: Using Dijkstra Algorithm

class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &f : flights){
            int u = f[0];
            int v = f[1];
            int c = f[2];

            adj[u].push_back({v, c});
        }
        vector<vector<int>> minCost(n, vector<int>(k+2, INT_MAX)); // minCost[cost][k];
        minCost[0][0] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {src, 0}});     // {cost, {src, k}};

        while(!pq.empty()){
            auto &temp = pq.top();
            int cost = temp.first;
            int node = temp.second.first;
            int k_i = temp.second.second;
            pq.pop();
            if(node == dst){
                return cost;
            }
            if(k_i == k+1){
                continue;
            }
            for(auto &it : adj[node]){
                int neigh = it.first;
                int c = it.second;

                if(minCost[neigh][k_i+1] == INT_MAX){
                    minCost[neigh][k_i+1] = cost + c;
                    pq.push({cost + c, {neigh, k_i+1}});
                }
                else if(c + cost < minCost[neigh][k_i+1]){
                    minCost[neigh][k_i+1] = cost + c;
                    pq.push({cost + c, {neigh, k_i+1}});
                }
            }
        }

        return -1;
    }
};

// METHOD 2: Using BFS Algorithm

class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &f : flights){
            int u = f[0];
            int v = f[1];
            int c = f[2];

            adj[u].push_back({v, c});
        }
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        queue<p> pq;
        pq.push({0, {src, 0}});     // {cost, {src, k}};

        while(!pq.empty()){
            auto &temp = pq.front();
            int cost = temp.first;
            int node = temp.second.first;
            int k_i = temp.second.second;
            pq.pop();
            if(k_i == k+1){
                continue;
            }
            for(auto &it : adj[node]){
                int neigh = it.first;
                int c = it.second;
              
                if(c + cost < minCost[neigh]){
                    minCost[neigh] = c + cost;
                    pq.push({c + cost, {neigh, k_i+1}});
                }
            }
        }
        if(minCost[dst] != INT_MAX){
            return minCost[dst];
        }
        return -1;
    }
};
