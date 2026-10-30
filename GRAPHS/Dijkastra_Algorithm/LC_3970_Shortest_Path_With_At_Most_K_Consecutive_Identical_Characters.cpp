// Question Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description


// METHOD 1: Using Dijsktra's Algorithm

class Solution {
public:
    typedef tuple<int, int, int> tp;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>> adj; // u -> {v, w}, {v, w}

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // You have to go from 0 to n-1 node, and find a path which has minimum total weight and and and it should have atmost k consecutive identical character
        vector<vector<int>> dist(n+1, vector<int> (51, INT_MAX));  // node count (count <= k)
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while(!pq.empty()){
            auto [w, node, count] = pq.top();
            pq.pop();

            if(w > dist[node][count]){
                continue;
            }
            if(node == n-1){
                return w;
            }

            for(auto &n : adj[node]){
                int neigh = n.first;
                int weig = n.second;
                int newCount = 1;

                if(labels[node] == labels[neigh]){
                    newCount = count + 1;
                }
                if(newCount > k){
                    continue;
                }

                if(weig + w < dist[neigh][newCount]){
                    dist[neigh][newCount] = w + weig;
                    pq.push({weig + w, neigh, newCount});
                }
            }
        } 

        return -1;

    }
};
