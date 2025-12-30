// Question Link: https://leetcode.com/problems/network-delay-time/description/

// METHOD 1: Using DIJKSTRA's Algorithn

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &e : times){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({w, v});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> minTime(n+1, INT_MAX);
        minTime[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto &v : adj[node]){
                int t = v.first;
                int neigh = v.second;

                if(t + time < minTime[neigh]){
                    minTime[neigh] = t + time;
                    pq.push({t + time, neigh});
                }
            }
        }

        int total_time = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(minTime[i] > total_time){
                total_time = minTime[i];
            }
        }

        if(total_time != INT_MAX){
            return total_time;
        }

        return -1;
    }
};
